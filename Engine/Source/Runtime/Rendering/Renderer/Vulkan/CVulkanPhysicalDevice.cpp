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

/// \file       CVulkanPhysicalDevice.cpp
/// \date       21/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Renderer/Vulkan
/// \author     Vincent STEHLY--CALISTO

#include <vector>
#include "Runtime/Core/Assertion/Assert.hh"
#include "Runtime/Rendering/Renderer/Vulkan/CVulkanPhysicalDevice.hpp"

/// \namespace ord
namespace ord
{

/// \namespace rendering
namespace rendering
{

/// \brief Initializes the physical device
/// \param physical_device The vulkan physical device
void CVulkanPhysicalDevice::Initialize(VkPhysicalDevice physical_device)
{
    // Pre-conditions
    ASSERT_TRUE(physical_device != VK_NULL_HANDLE);
}

/// \brief Releases the physical device
void CVulkanPhysicalDevice::Release()
{
    // TODO
}

/// \brief Returns the amount of physical devices detected
/// \param instance The vulkan instance
/// \return The amount of physical devices detected
/* static */ uint32_t CVulkanPhysicalDevice::GetPhysicalDeviceCount(VkInstance instance)
{
    ASSERT_TRUE(instance != VK_NULL_HANDLE);

    uint32_t physical_device_count = 0;
    vkEnumeratePhysicalDevices(instance, &physical_device_count, nullptr);

    return physical_device_count;
}

/// \brief Stores at the given address the list of physical device handles
/// \param instance The vulkan instance
/// \param count The count of physical devices to get
/// \param p_physical_devices The address where to store physical device handles
/* static */ void CVulkanPhysicalDevice::GetPhysicalDevices(VkInstance instance, uint32_t count, VkPhysicalDevice* p_physical_devices)
{
    ASSERT_TRUE    (instance != VK_NULL_HANDLE);
    ASSERT_NOT_NULL(p_physical_devices);

    vkEnumeratePhysicalDevices(instance, &count, p_physical_devices);
}

/// \brief Tells if the physical devices is suitable for rendering
/// \param physical_device The physical devices to test
/// \return True if the device is suitable, else false
bool CVulkanPhysicalDevice::IsPhysicalDeviceSuitable(VkPhysicalDevice physical_device)
{
    uint32_t family_count = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(physical_device, &family_count, nullptr);

    std::vector<VkQueueFamilyProperties> family_properties(family_count);
    vkGetPhysicalDeviceQueueFamilyProperties(physical_device, &family_count, family_properties.data());

    for (const auto& family_property : family_properties)
    {
        if(family_property.queueFlags & VK_QUEUE_GRAPHICS_BIT)
            return true;
    }

    return false;
}

} // !namespace

} // !namespace