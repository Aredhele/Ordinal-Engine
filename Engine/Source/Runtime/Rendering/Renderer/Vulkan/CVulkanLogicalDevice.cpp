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

#include "Runtime/Core/Debug/SLogger.hpp"
#include "Runtime/Core/Assertion/Assert.hh"
#include "Runtime/Rendering/Renderer/Vulkan/CVulkanLogicalDevice.hpp"

/// \namespace ord
namespace ord
{

/// \namespace rendering
namespace rendering
{

/// \brief Initializes the logical device
/// \param physical_device The vulkan physical device
void CVulkanLogicalDevice::Initialize(VkPhysicalDevice physical_device)
{
    SLogger::LogInfo("\tVulkan Logical Device initialization ...");
    // Pre-conditions
    ASSERT_NULL(mp_physical_device);
    ASSERT_TRUE(physical_device != VK_NULL_HANDLE);
    ASSERT_TRUE(CVulkanPhysicalDevice::IsPhysicalDeviceSuitable(physical_device));

    mp_physical_device = new CVulkanPhysicalDevice();
    mp_physical_device->Initialize(physical_device);


    // TODO
    /*float queue_priority = 1.0f;
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
    VkResult result = vkCreateDevice(physical_device, &device_create_info, nullptr, &logical_device);*/

    SLogger::LogInfo("\tVulkan Logical Device initialized");
}

/// \brief Releases the logical device
void CVulkanLogicalDevice::Release()
{
    // TODO
}

} // !namespace

} // !namespace