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

/// \file       CVulkanLogicalDevice.cpp
/// \date       22/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Renderer/Vulkan
/// \author     Vincent STEHLY--CALISTO

#include <stdexcept>

#include "Runtime/Core/Debug/SLogger.hpp"
#include "Runtime/Core/Assertion/Assert.hpp"
#include "Runtime/Rendering/Renderer/Vulkan/CVulkanLogicalDevice.hpp"

/// \namespace Ord
namespace Ord
{

/// \namespace Rendering
namespace Rendering
{

/// \brief Initializes the logical device
/// \param physical_device The vulkan physical device
void CVulkanLogicalDevice::Initialize(VkPhysicalDevice physical_device)
{
    SLogger::LogInfo("\tVulkan Logical Device initialization ...");

    // Pre-conditions
    ORD_ASSERT_NULL(mp_physical_device);
    ORD_ASSERT_TRUE(physical_device != VK_NULL_HANDLE);
    ORD_ASSERT_TRUE(CVulkanPhysicalDevice::IsPhysicalDeviceSuitable(physical_device));

    mp_physical_device = new CVulkanPhysicalDevice();
    mp_physical_device->Initialize(physical_device);

#ifdef ORDINAL_DEBUG
    InitializeDeviceLayers();
    InitializeDeviceExtensions();
    InitializeLogicalDevice();
#else
    InitializeDeviceExtensions();
    InitializeLogicalDevice();
#endif

    SLogger::LogInfo("\tVulkan Logical Device initialized");
}

/// \brief Releases the logical device
void CVulkanLogicalDevice::Release()
{
    SLogger::LogInfo("\tReleasing logical device.");

    ReleasePhysicalDevice();
    ReleaseLogicalDevice();

    SLogger::LogInfo("\tLogical device Released.");
}

/// \brief Adds to device extensions list all required extensions
void CVulkanLogicalDevice::InitializeDeviceExtensions()
{
    m_device_extensions.push_back(VK_KHR_SWAPCHAIN_EXTENSION_NAME);
}

#ifdef ORDINAL_DEBUG
/// \brief Adds to the device layers list all required layers
void CVulkanLogicalDevice::InitializeDeviceLayers()
{
    m_device_layers.push_back("VK_LAYER_LUNARG_standard_validation");
}
#endif

/// \brief Initializes the vulkan logical device
void CVulkanLogicalDevice::InitializeLogicalDevice()
{
    // Initializes a vector to contain all create info
    // structure about device queues
    const auto& queue_families = mp_physical_device->GetQueueFamilies();

    std::vector<float>                   device_queue_priorities       (queue_families.size(), 1.0f);
    std::vector<VkDeviceQueueCreateInfo> device_queue_create_info_array(queue_families.size());

    for(const auto& queue_family : queue_families)
    {
        VkDeviceQueueCreateInfo device_queue_create_info {};
        {
            device_queue_create_info.sType            = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
            device_queue_create_info.queueFamilyIndex = queue_family.GetQueueFamilyIndex();
            device_queue_create_info.queueCount       = queue_family.GetQueueFamilyCount();
            device_queue_create_info.pQueuePriorities = device_queue_priorities.data();
        }

        device_queue_create_info_array.push_back(device_queue_create_info);
    }

    VkPhysicalDeviceFeatures deviceFeatures     {};
    VkDeviceCreateInfo       device_create_info {};
    {
        device_create_info.sType                   = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        device_create_info.pQueueCreateInfos       = device_queue_create_info_array.data();
        device_create_info.queueCreateInfoCount    = static_cast<uint32_t>(device_queue_create_info_array.size());

        device_create_info.enabledLayerCount       = static_cast<uint32_t>(m_device_layers.size());
        device_create_info.enabledExtensionCount   = static_cast<uint32_t>(m_device_extensions.size());
        device_create_info.ppEnabledLayerNames     = m_device_layers.data();
        device_create_info.ppEnabledExtensionNames = m_device_extensions.data();
        device_create_info.pEnabledFeatures        = &deviceFeatures;
    }

    // TODO : Fix
    mp_logical_device = VK_NULL_HANDLE;
    VkResult result = vkCreateDevice(mp_physical_device->GetPhysicalDeviceHandle(), &device_create_info, nullptr, &mp_logical_device);

    if(result != VK_SUCCESS)
        throw std::runtime_error("Error while creating vulkan logical device.");
}

/// \brief Releases the attached physical device
void CVulkanLogicalDevice::ReleasePhysicalDevice()
{
    if(mp_physical_device != nullptr)
    {
        mp_physical_device->Release();
        delete mp_physical_device;
        mp_physical_device = nullptr;
    }
}

/// \brief Releases the logical device
void CVulkanLogicalDevice::ReleaseLogicalDevice()
{
    vkDestroyDevice(mp_logical_device, nullptr);
    mp_logical_device = VK_NULL_HANDLE;
}

} // !namespace

} // !namespace