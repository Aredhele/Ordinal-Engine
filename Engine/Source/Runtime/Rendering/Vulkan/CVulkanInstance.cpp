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

/// \file       CVulkanInstance.cpp
/// \date       23/05/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Vulkan/
/// \author     Vincent STEHLY--CALISTO

#include "Runtime/Core/Debug/SLogger.hpp"
#include "Runtime/Rendering/Vulkan/CVulkanInstance.hpp"

#ifdef ORDINAL_DEBUG
    const bool enable_validation_layers = true;
#   else
    const bool enable_validation_layers = false;
#endif

/// \namespace ord
namespace ord
{

VkResult CreateDebugReportCallbackEXT(
        VkInstance instance,
        const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
        const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback)
{
    auto func = (PFN_vkCreateDebugReportCallbackEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugReportCallbackEXT");

    if (func != nullptr)
    {
        return func(instance, pCreateInfo, pAllocator, pCallback);
    }
    else
    {
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}

void DestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator)
{
    auto func = (PFN_vkDestroyDebugReportCallbackEXT) vkGetInstanceProcAddr(instance, "vkDestroyDebugReportCallbackEXT");
    if (func != nullptr) {
        func(instance, callback, pAllocator);
    }
}

/// \brief Validation layer debug call back
VKAPI_ATTR VkBool32 VKAPI_CALL CVulkanInstance::DebugCallback(
    VkDebugReportFlagsEXT flags,
    VkDebugReportObjectTypeEXT objType,
    uint64_t obj,
    size_t location,
    int32_t code,
    const char * layerPrefix,
    const char * msg,
    void * userData)
{
    SLogger::LogError("Validation layer : %s", msg);
    return VK_FALSE;
}

/// \brief  Creates the vulkan instance
/// \return True on success, else false
bool CVulkanInstance::CreateInstance()
{
    // Validation layer
    m_validation_layers.emplace_back("VK_LAYER_LUNARG_standard_validation");

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCSimplifyInspection"
    if (enable_validation_layers && !checkValidationLayerSupport()) // NOLINT
#pragma clang diagnostic pop
    {
        SLogger::LogError("Validation layers requested, but not available");
        return false;
    }

    VkApplicationInfo appInfo = {};
    appInfo.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName   = "Ordinal Runtime";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName        = "Ordinal Engine";
    appInfo.engineVersion      = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion         = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo = {};
    createInfo.sType                = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCSimplifyInspection"
    if (enable_validation_layers)
#pragma clang diagnostic pop
    {
        createInfo.enabledLayerCount   = static_cast<uint32_t>(m_validation_layers.size());
        createInfo.ppEnabledLayerNames = m_validation_layers.data();
    }
    else
    {
        createInfo.enabledLayerCount = 0;
    }


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-stack-address"
    createInfo.pApplicationInfo     = &appInfo;
#pragma clang diagnostic pop

    auto extensions = GetRequiredExtensions();
    createInfo.enabledExtensionCount   = static_cast<uint32_t>(extensions.size());
    createInfo.ppEnabledExtensionNames = extensions.data();

    if (vkCreateInstance(&createInfo, nullptr, &m_vk_instance) != VK_SUCCESS)
    {
        SLogger::LogError("Failed to create vulkan instance");
        return false;
    }

    if(!SetupCallback())
        return false;

    PickPhysicalDevice();
    return true;
}

/// \brief  Destroys the vulkan instance
void CVulkanInstance::DestroyInstance()
{

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCSimplifyInspection"
    if (enable_validation_layers)
    {
        DestroyDebugReportCallbackEXT(m_vk_instance, m_vk_callback, nullptr);
    }
#pragma clang diagnostic pop

    vkDestroyInstance(m_vk_instance, nullptr);
}

/// \brief Checks if all requested layers are present
/// \return True or false
bool CVulkanInstance::checkValidationLayerSupport()
{
    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

    std::vector<VkLayerProperties> availableLayers(layerCount);
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

    for (const char * layer_name : m_validation_layers)
    {
        bool layerFound = false;
        for (const auto& layerProperties : availableLayers)
        {
            if (strcmp(layer_name, layerProperties.layerName) == 0)
            {
                layerFound = true;
                break;
            }
        }

        if (!layerFound)
            return false;
    }

    return true;
}

/// \brief  Returns all required extensions by the application
/// \return A vector of extensions
std::vector<const char *> CVulkanInstance::GetRequiredExtensions()
{
    uint32_t glfwExtensionCount = 0;
    const char ** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
    std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCSimplifyInspection"
    if (enable_validation_layers)
    {
        extensions.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
    }
#pragma clang diagnostic pop

    return extensions;
}

/// \brief Setups the callback for validation layers
bool CVulkanInstance::SetupCallback()
{

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCSimplifyInspection"
    if (!enable_validation_layers)
        return true;
#pragma clang diagnostic pop

    VkDebugReportCallbackCreateInfoEXT createInfo = {};
    createInfo.sType       = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
    createInfo.flags       = VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT;
    createInfo.pfnCallback = DebugCallback;

    if (CreateDebugReportCallbackEXT(m_vk_instance, &createInfo, nullptr, &m_vk_callback) != VK_SUCCESS)
    {
        SLogger::LogError("Failed to set up callback");
        return false;
    }

    SLogger::LogInfo("Callback successfully set up");
    return true;
}

bool CVulkanInstance::PickPhysicalDevice()
{
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(m_vk_instance, &deviceCount, nullptr);

    if (deviceCount == 0)
    {
        SLogger::LogError("Failed to find GPUs with Vulkan support !");
        return false;
    }

    std::vector<VkPhysicalDevice> devices(deviceCount);
    vkEnumeratePhysicalDevices(m_vk_instance, &deviceCount, devices.data());

    for (const auto& device : devices)
    {
        if (isDeviceSuitable(device))
        {
            m_vk_physical_device = device;
            break;
        }
    }

    if (m_vk_physical_device == VK_NULL_HANDLE)
    {
        SLogger::LogError("Failed to find a suitable GPU!");
        return false;
    }

    SLogger::LogInfo("Physical device found");

    VkPhysicalDeviceProperties prop;
    vkGetPhysicalDeviceProperties(m_vk_physical_device, &prop);

    SLogger::LogInfo("\tAPI version    : %u", prop.apiVersion);
    SLogger::LogInfo("\tDevice id      : %u", prop.deviceID);
    SLogger::LogInfo("\tDevice name    : %s", prop.deviceName);
    SLogger::LogInfo("\tDriver version : %u", prop.driverVersion);
    SLogger::LogInfo("\tVendor id      : %u", prop.vendorID);
    return true;
}

bool CVulkanInstance::isDeviceSuitable(VkPhysicalDevice device)
{
    VkPhysicalDeviceProperties deviceProperties;
    VkPhysicalDeviceFeatures deviceFeatures;
    vkGetPhysicalDeviceProperties(device, &deviceProperties);
    vkGetPhysicalDeviceFeatures(device, &deviceFeatures);

    return deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU &&
           deviceFeatures.geometryShader;
}

} // !namespace

