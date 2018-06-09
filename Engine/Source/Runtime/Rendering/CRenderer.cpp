/// Copyright (C) 2018-2019, Ordinal Engine
/// Vincent STEHLY--CALISTO, vincentstehly@hotmail.fr
///
/// This program is free software; you can redistribute it and/or modify
/// it under the terms of the GNU General Public License as published by
/// the Free Software Foundation; either version 2 of the License, or
/// (at your option) any later version.
///
/// This program is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
/// GNU General Public License for more details.
///
/// You should have received a copy of the GNU General Public License along
/// with this program; if not, write to the Free Software Foundation, Inc.,
/// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

/// \file       CRenderer.cpp
/// \date       03/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering
/// \author     Vincent STEHLY--CALISTO

#include "Runtime/Core/Debug/SLogger.hpp"
#include "Runtime/Rendering/CRenderer.hpp"
#include "Runtime/Rendering/Helper/VulkanHelper.hh"

/// \namespace ord
namespace ord
{

/// \brief  Default constructor
CRenderer::CRenderer()
{
    // None
}

/// \brief  Destructor
CRenderer::~CRenderer()
{
    for(const auto& device : m_logical_devices)
        vkDestroyDevice(device, nullptr);

    UninitializeDebug();

    vkDestroyInstance(mp_instance, nullptr);
}

/// \brief Initializes the renderer with an info structure
/// \param renderer_info The structure that contains info
///        about the renderer initialization
/// \throw Can throw runtime errors exceptions
void CRenderer::Initialize(const SRendererCreateInfo& renderer_info)
{
    SLogger::LogInfo("Initializing vulkan renderer ...");

    SetupDebug();
    InitializeInstance(renderer_info);
    InitializeDebug();
    InitializePhysicalDevice(renderer_info);

    SLogger::LogInfo("Vulkan renderer fully initialized.");
}

/// \brief Initializes the vulkan instance
/// \param renderer_info The structure that contains info
///        about the renderer initialization
/// \throw Can throw runtime errors exceptions
void CRenderer::InitializeInstance(const SRendererCreateInfo& renderer_info)
{
    VkApplicationInfo application_info {};
    application_info.sType                = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    application_info.pEngineName          = renderer_info.p_engine_name;
    application_info.pApplicationName     = renderer_info.p_application_name;
    application_info.apiVersion           = renderer_info.api_version;
    application_info.engineVersion        = renderer_info.engine_version;
    application_info.applicationVersion   = renderer_info.application_version;

    VkInstanceCreateInfo instance_create_info {};
    instance_create_info.sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instance_create_info.pApplicationInfo        = &application_info;
    instance_create_info.enabledLayerCount       = static_cast<uint32_t>(m_instance_layers.size());
    instance_create_info.enabledExtensionCount   = static_cast<uint32_t>(m_instance_extensions.size());
    instance_create_info.ppEnabledLayerNames     = m_instance_layers.data();
    instance_create_info.ppEnabledExtensionNames = m_instance_extensions.data();

    VkResult result = vkCreateInstance(&instance_create_info, nullptr, &mp_instance);

    if(result != VK_SUCCESS)
    {
        throw std::runtime_error("Error while creating vulkan instance.");
    }

    SLogger::LogInfo("Vulkan instance initialized.");
}

/// \brief TODO
/// \param width  TODO
/// \param height TODO
/// \param name   TODO
CWindow * CRenderer::OpenWindow(uint32_t width, uint32_t height, const std::string &name)
{
    mp_window = new CWindow();
    return mp_window;
}

/// \brief Initializes vulkan physical devices
/// \param renderer_info The structure that contains info
///        about the renderer initialization
/// \throw Can throw runtime errors exceptions
void CRenderer::InitializePhysicalDevice(const SRendererCreateInfo &renderer_info)
{
    uint32_t physical_device_count = 0;
    vkEnumeratePhysicalDevices(mp_instance, &physical_device_count, nullptr);

    m_physical_devices.resize(physical_device_count, VK_NULL_HANDLE);
    vkEnumeratePhysicalDevices(mp_instance, &physical_device_count, m_physical_devices.data());

    DisplayPhysicalDeviceProperties(m_physical_devices);

    uint32_t instance_layer_properties_count = 0;
    vkEnumerateInstanceLayerProperties(&instance_layer_properties_count, nullptr);

    std::vector<VkLayerProperties> instance_layer_properties(instance_layer_properties_count);
    vkEnumerateInstanceLayerProperties(&instance_layer_properties_count, instance_layer_properties.data());

    DisplayInstanceLayerProperties(instance_layer_properties);

    for(const auto& physical_device : m_physical_devices)
    {
        uint32_t family_count = 0;
        vkGetPhysicalDeviceQueueFamilyProperties(physical_device, &family_count, nullptr);

        std::vector<VkQueueFamilyProperties> family_properties(family_count);
        vkGetPhysicalDeviceQueueFamilyProperties(physical_device, &family_count, family_properties.data());

        bool found = false;
        for(uint32_t nFamilyProperties = 0; nFamilyProperties < family_properties.size(); ++nFamilyProperties)
        {
            if(family_properties[nFamilyProperties].queueFlags & VK_QUEUE_GRAPHICS_BIT)
            {
                found = true;
                m_family_properties_index = nFamilyProperties;
                break;
            }
        }

        if(!found)
        {
            throw std::runtime_error("No graphics queue found.");
        }

        float queue_priority = 1.0f;
        VkDeviceQueueCreateInfo device_queue_create_info {};
        device_queue_create_info.sType            = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        device_queue_create_info.queueFamilyIndex = m_family_properties_index;
        device_queue_create_info.queueCount       = 1;
        device_queue_create_info.pQueuePriorities = &queue_priority;

        VkDeviceCreateInfo device_create_info {};
        device_create_info.sType                   = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        device_create_info.queueCreateInfoCount    = 1;
        device_create_info.pQueueCreateInfos       = &device_queue_create_info;

        VkDevice logical_device = VK_NULL_HANDLE;
        VkResult result = vkCreateDevice(physical_device, &device_create_info, nullptr, &logical_device);

        if(result != VK_SUCCESS)
        {
            throw std::runtime_error("Error while creating vulkan logical device.");
        }

        m_logical_devices.push_back(logical_device);

        m_queues.push_back(VK_NULL_HANDLE);
        vkGetDeviceQueue(logical_device, m_family_properties_index, 0, &m_queues.back());
    }

    SLogger::LogInfo("%u Physical device(s) found.",  m_physical_devices.size());
    SLogger::LogInfo("%u Logical device(s) created.", m_logical_devices.size());
    SLogger::LogInfo("Vulkan physical devices initialized.");
}

VKAPI_ATTR VkBool32 VKAPI_CALL
VulkanDebugCallback(
    VkDebugReportFlagsEXT       flags,
    VkDebugReportObjectTypeEXT  object_type,
    uint64_t                    source_object,
    size_t                      location,
    int32_t                     msg_code,
    const char *                layer_prefix,
    const char *                message,
    void *                      user_date
    )
{
    if(flags & VK_DEBUG_REPORT_INFORMATION_BIT_EXT)
    {
        return VK_TRUE;
    }

    std::string readable_flag = GetReadableValidationLayerFlag(static_cast<VkDebugReportFlagBitsEXT>(flags));
    SLogger::LogError("@[%s] - [%s] Validation Layer : %s", layer_prefix, readable_flag.c_str(), message);
    return VK_FALSE;
}

/// \brief TODO
void CRenderer::SetupDebug()
{
    m_instance_layers.push_back    ("VK_LAYER_LUNARG_standard_validation");
    m_instance_extensions.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
}

PFN_vkCreateDebugReportCallbackEXT  fvkCreateDebugReportCallbackEXT  = VK_NULL_HANDLE;
PFN_vkDestroyDebugReportCallbackEXT fvkDestroyDebugReportCallbackEXT = VK_NULL_HANDLE;

/// \brief TODO
void CRenderer::InitializeDebug()
{
    fvkCreateDebugReportCallbackEXT  = reinterpret_cast<PFN_vkCreateDebugReportCallbackEXT>(vkGetInstanceProcAddr(mp_instance,   "vkCreateDebugReportCallbackEXT"));
    fvkDestroyDebugReportCallbackEXT = reinterpret_cast<PFN_vkDestroyDebugReportCallbackEXT>(vkGetInstanceProcAddr(mp_instance,  "vkDestroyDebugReportCallbackEXT"));

    if(fvkCreateDebugReportCallbackEXT == VK_NULL_HANDLE || fvkDestroyDebugReportCallbackEXT == VK_NULL_HANDLE)
    {
        throw std::runtime_error("Can't fetch function pointer from vulkan loader");
    }

    VkDebugReportCallbackCreateInfoEXT debug_callback_create_info {};
    debug_callback_create_info.sType            = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
    debug_callback_create_info.pfnCallback      = VulkanDebugCallback;
    debug_callback_create_info.flags            =
            VK_DEBUG_REPORT_INFORMATION_BIT_EXT         | VK_DEBUG_REPORT_WARNING_BIT_EXT |
            VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT | VK_DEBUG_REPORT_ERROR_BIT_EXT   |
            VK_DEBUG_REPORT_DEBUG_BIT_EXT;

    VkResult result = fvkCreateDebugReportCallbackEXT(mp_instance, &debug_callback_create_info, nullptr, &m_debug_report_callback);

    if(result != VK_SUCCESS)
    {
        throw std::runtime_error("Error while initializing debug callbacks");
    }
}

/// \brief TODO
void CRenderer::UninitializeDebug()
{
    fvkDestroyDebugReportCallbackEXT(mp_instance, m_debug_report_callback, nullptr);
}

} // !namespace
