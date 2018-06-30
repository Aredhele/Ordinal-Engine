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

/// \file       CVulkanRenderer.cpp
/// \date       21/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Renderer
/// \author     Vincent STEHLY--CALISTO

#include "Runtime/Core/Debug/SLogger.hpp"
#include "Runtime/Core/Assertion/Assert.hh"
#include "Runtime/Core/StringHash/StringHash.hpp"

#include "Runtime/Rendering/Renderer/Vulkan/CVulkanRenderer.hpp"
#include "Runtime/Rendering/Renderer/Vulkan/CVulkanPhysicalDevice.hpp"
#include "Runtime/Rendering/Renderer/Vulkan/Debug/VulkanDebugCallback.hpp"

/// \namespace ord
namespace ord
{

/// \namespace rendering
namespace rendering
{

/// \brief Initializes the renderer from the create info structure
/// \param s_renderer_info Contains all needed information to initialize a renderer
void CVulkanRenderer::Initialize(const SRendererCreateInfo& renderer_info)
{
    SLogger::LogInfo("    Vulkan initialization ...");

#ifdef ORDINAL_DEBUG
    InitializeInstanceLayers();
    InitializeInstanceExtensions();
    InitializeInstance(renderer_info);
    InitializeFunctions();
    InitializeDebugCallback();
    InitializeLogicalDevices();
#else
    InitializeInstance(renderer_info);
    InitializeFunctions();
    InitializeLogicalDevices();
#endif

    SLogger::LogInfo("    Vulkan renderer fully initialized.");
}

/// \brief Releases the renderer
void CVulkanRenderer::Release()
{
    SLogger::LogInfo("    Releasing the vulkan renderer ...");

#ifdef ORDINAL_DEBUG
   ReleaseDebugCallback();
   ReleaseLogicalDevice();
   ReleaseInstance();
   ReleaseFunctions();
#else
    ReleaseLogicalDevice();
    ReleaseInstance();
    ReleaseFunctions();
#endif

    SLogger::LogInfo("    Vulkan renderer successfully released.");
}

/// \brief  Creates a window
/// \param  window_create_info The window create info
/// \return A pointer on the window
platform::CWindow* CVulkanRenderer::OpenWindow(const platform::SWindowCreateInfo& window_create_info)
{
    // TODO (Release)
    auto* p_window = new platform::CWindow();
    p_window->Initialize(window_create_info);

    return p_window;
}

#ifdef ORDINAL_DEBUG
/// \brief Fills the vector of layers to enable
void CVulkanRenderer::InitializeInstanceLayers()
{
    m_instance_layers.push_back("VK_LAYER_LUNARG_standard_validation");
}

/// \brief Fills the vector of extensions to enable
void CVulkanRenderer::InitializeInstanceExtensions()
{
    m_instance_extensions.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
}

/// \brief Initializes the vulkan debug callback
void CVulkanRenderer::InitializeDebugCallback()
{
    VkDebugReportCallbackCreateInfoEXT debug_report_create_info = {};
    {
        debug_report_create_info.sType       = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
        debug_report_create_info.flags       = VK_DEBUG_REPORT_ERROR_BIT_EXT   |
                                               VK_DEBUG_REPORT_WARNING_BIT_EXT |
                                               VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT;

        debug_report_create_info.pfnCallback = VulkanDebugCallback;
        debug_report_create_info.pUserData   = &m_debug_reporter;
    }

    // Getting the create debug report callback
    auto create_function = m_function_loader.GetFunction<PFN_vkCreateDebugReportCallbackEXT>(SSID("vkCreateDebugReportCallbackEXT"));

    // Creating the callback
    if (create_function(mp_instance, &debug_report_create_info, nullptr, &mp_report_callback) != VK_SUCCESS)
    {
        SLogger::LogError("    Failed to set up callback");
        throw std::runtime_error("Failed to set up callback");
    }

    SLogger::LogInfo("    Callback successfully set up.");
}

/// \brief Releases the vulkan debug callback
void CVulkanRenderer::ReleaseDebugCallback()
{
    SLogger::LogInfo("    Releasing the debug callback.");

    // Getting the destroy debug report callback
    auto destroy_function = m_function_loader.GetFunction<PFN_vkDestroyDebugReportCallbackEXT>(SSID("vkDestroyDebugReportCallbackEXT"));

    ORD_ASSERT_NOT_NULL(mp_instance);
    ORD_ASSERT_NOT_NULL((void *)destroy_function);

    destroy_function(mp_instance, mp_report_callback, nullptr);

    mp_report_callback = VK_NULL_HANDLE;

    SLogger::LogInfo("    Debug callback released.");
}
#endif

/// \brief Initializes the renderer from the create info structure
/// \param renderer_info Contains all needed information to initialize a renderer
/// \throw runtime_error Throws on initialization failure
void CVulkanRenderer::InitializeInstance(const SRendererCreateInfo& renderer_info)
{
    VkApplicationInfo application_info {};
    {
        application_info.sType                       = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        application_info.pApplicationName            = renderer_info.p_application_name;
        application_info.applicationVersion          = renderer_info.application_version;
        application_info.pEngineName                 = renderer_info.p_engine_name;
        application_info.engineVersion               = renderer_info.engine_version;
        application_info.apiVersion                  = renderer_info.api_version;
    }

    VkInstanceCreateInfo instance_create_info {};
    {
        instance_create_info.sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        instance_create_info.pApplicationInfo        = &application_info;
        instance_create_info.enabledLayerCount       = static_cast<uint32_t>(m_instance_layers.size());
        instance_create_info.enabledExtensionCount   = static_cast<uint32_t>(m_instance_extensions.size());
        instance_create_info.ppEnabledLayerNames     = m_instance_layers.data();
        instance_create_info.ppEnabledExtensionNames = m_instance_extensions.data();
    }

    VkResult result = vkCreateInstance(&instance_create_info, nullptr, &mp_instance);

    if(result != VK_SUCCESS)
        throw std::runtime_error("Error while creating vulkan instance.");

    SLogger::LogInfo("    Vulkan instance initialized.");
}

/// \brief Loads all required vulkan functions
void CVulkanRenderer::InitializeFunctions()
{
    ORD_ASSERT_NOT_NULL(mp_instance);

#ifdef ORDINAL_DEBUG
    m_function_loader.LoadFunction(mp_instance, "vkCreateDebugReportCallbackEXT" );
    m_function_loader.LoadFunction(mp_instance, "vkDestroyDebugReportCallbackEXT");
#endif

    SLogger::LogInfo("    %lu functions loaded.", m_function_loader.GetFunctionCount());
}

/// \brief Initializes logical devices from physical devices
/// \throw runtime_error Throws on initialization failure
void CVulkanRenderer::InitializeLogicalDevices()
{
    // Gets the amount of physical devices
    uint32_t physical_device_count = CVulkanPhysicalDevice::GetPhysicalDeviceCount(mp_instance);

    // Gets the list of physical device handles
    std::vector<VkPhysicalDevice> physical_devices(physical_device_count, VK_NULL_HANDLE);
    CVulkanPhysicalDevice::GetPhysicalDevices(mp_instance, physical_device_count, physical_devices.data());

    // Searches for suitable devices
    for(const auto& physical_device : physical_devices)
    {
        if(CVulkanPhysicalDevice::IsPhysicalDeviceSuitable(physical_device))
        {
            m_logical_devices.push_back(new CVulkanLogicalDevice());
            m_logical_devices.back()->Initialize(physical_device);
        }
    }

    if(m_logical_devices.empty())
        throw std::runtime_error("No suitable GPU found.");

    SLogger::LogInfo("    Logical devices initialized.");
}

/// \brief Releases all logical devices
void CVulkanRenderer::ReleaseLogicalDevice()
{
    SLogger::LogInfo("    Releasing all logical devices.");

    // Destroying
    for(CVulkanLogicalDevice * p_logical_device : m_logical_devices)
    {
        p_logical_device->Release();
        delete p_logical_device;
    }

    // Clearing vectors
    m_logical_devices.clear();
    m_instance_layers.clear();
    m_instance_extensions.clear();

    SLogger::LogInfo("    Logical devices released.");
}

/// \brief Releases the vulkan instance
void CVulkanRenderer::ReleaseInstance()
{
    SLogger::LogInfo("    Releasing the instance.");

    // Destroying the vulkan instance
    vkDestroyInstance(mp_instance, nullptr);
    mp_instance = VK_NULL_HANDLE;

    SLogger::LogInfo("    Vulkan instance released.");
}

/// \brief Releases all loaded functions
void CVulkanRenderer::ReleaseFunctions()
{
    m_function_loader.Release();
}

} // !namespace

} // !namespace
