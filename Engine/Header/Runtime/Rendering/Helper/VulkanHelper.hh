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

/// \file       VulkanHelper.hh
/// \date       03/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Helper
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_VULKAN_HELPER_HPP__
#define ORDINAL_ENGINE_VULKAN_HELPER_HPP__

#include <string>
#include <vector>
#include "vulkan/vulkan.h"
#include <Runtime/Core/Debug/SLogger.hpp>
#include <iostream>

/// \namespace ord
namespace ord
{

/// \brief  Returns a readable string of the physical device type
/// \param  physical_device_type The type of the physical device
/// \return A readable string of the physical device type
/// \note   Makes a pre-made structure containing strings
std::string GetReadableDeviceType(VkPhysicalDeviceType physical_device_type)
{
    switch(physical_device_type)
    {
        case VK_PHYSICAL_DEVICE_TYPE_OTHER:          return std::string("VK_PHYSICAL_DEVICE_TYPE_OTHER");
        case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU: return std::string("VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU");
        case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:   return std::string("VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU");
        case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:    return std::string("VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU");
        case VK_PHYSICAL_DEVICE_TYPE_CPU:            return std::string("VK_PHYSICAL_DEVICE_TYPE_CPU");
        default:
            return std::string("None");
    }
}

/// \brief  Returns a readable string of the physical memory heap flag
/// \param  memory_heap_flag The memory heap flag
/// \return A readable string of the physical memory heap flag
/// \note   Makes a pre-made structure containing strings
std::string GetReadableMemoryHeapFlag(VkMemoryHeapFlagBits memory_heap_flag)
{
    switch(memory_heap_flag)
    {
        case VK_MEMORY_HEAP_DEVICE_LOCAL_BIT:       return std::string("VK_MEMORY_HEAP_DEVICE_LOCAL_BIT");
        case VK_MEMORY_HEAP_MULTI_INSTANCE_BIT:     return std::string("VK_MEMORY_HEAP_MULTI_INSTANCE_BIT");
        default:
            return std::string("None");
    }
}

/// \brief Displays the properties of the given physical devices
/// \param physical_devices The list of physical devices
void DisplayPhysicalDeviceProperties(const std::vector<VkPhysicalDevice>& physical_devices)
{
    for(auto nPhysicalDevice = 0; nPhysicalDevice < physical_devices.size(); ++nPhysicalDevice)
    {
        SLogger::LogInfo("Physical device %u : ", nPhysicalDevice);

        VkPhysicalDeviceProperties device_properties {};
        vkGetPhysicalDeviceProperties(physical_devices[nPhysicalDevice], &device_properties);

        uint32_t api_version    = device_properties.apiVersion;
        uint32_t driver_version = device_properties.driverVersion;
        SLogger::LogInfo("Physical device name     : %s",         device_properties.deviceName);
        SLogger::LogInfo("Physical device id       : %u",         device_properties.deviceID);
        SLogger::LogInfo("Physical Physical type   : %s",         GetReadableDeviceType(device_properties.deviceType).c_str());
        SLogger::LogInfo("Physical Physical vendor : %u",         device_properties.vendorID);
        SLogger::LogInfo("Physical Physical api    : %u.%u.%u",   VK_VERSION_MAJOR(api_version),    VK_VERSION_MINOR(api_version),    VK_VERSION_PATCH(api_version));
        SLogger::LogInfo("Physical Physical driver : %u.%u.%u\n", VK_VERSION_MAJOR(driver_version), VK_VERSION_MINOR(driver_version), VK_VERSION_PATCH(driver_version));

        VkPhysicalDeviceLimits device_limits = device_properties.limits;
        SLogger::LogInfo("Physical device limits :");
        SLogger::LogInfo("Physical device max image dimension 1D       : %u",   device_limits.maxImageDimension1D);
        SLogger::LogInfo("Physical device max image dimension 2D       : %u",   device_limits.maxImageDimension2D);
        SLogger::LogInfo("Physical device max image dimension 3D       : %u",   device_limits.maxImageDimension3D);
        SLogger::LogInfo("Physical device max memory allocation count  : %u",   device_limits.maxMemoryAllocationCount);
        SLogger::LogInfo("Physical device max sampler allocation count : %u",   device_limits.maxSamplerAllocationCount);
        SLogger::LogInfo("Physical device max framebuffer width        : %u",   device_limits.maxFramebufferWidth);
        SLogger::LogInfo("Physical device max framebuffer height       : %u\n", device_limits.maxFramebufferHeight);

        VkPhysicalDeviceMemoryProperties physical_device_memory_properties {};
        vkGetPhysicalDeviceMemoryProperties(physical_devices[nPhysicalDevice], &physical_device_memory_properties);

        SLogger::LogInfo("Physical device memory :");
        SLogger::LogInfo("Physical device memory heap count : %u", physical_device_memory_properties.memoryHeapCount);

        for(uint32_t nHeap = 0; nHeap < physical_device_memory_properties.memoryHeapCount; ++nHeap)
        {
            uint64_t heap_size_bytes = physical_device_memory_properties.memoryHeaps[nHeap].size;
            auto heap_flag           = static_cast<VkMemoryHeapFlagBits>(physical_device_memory_properties.memoryHeaps[nHeap].flags);

            SLogger::LogInfo("Physical device memory heap flag : %s",            GetReadableMemoryHeapFlag(heap_flag).c_str());
            SLogger::LogInfo("Physical device memory heap size %u : %llu B",     nHeap, heap_size_bytes);
            SLogger::LogInfo("Physical device memory heap size %u : %llu MB",    nHeap, heap_size_bytes / (1024 * 1024));
            SLogger::LogInfo("Physical device memory heap size %u : %4.3f GB\n", nHeap, heap_size_bytes / (float)(1024 * 1024 * 1024));
        }
    }
}

} // !namespace

#endif // !ORDINAL_ENGINE_VULKAN_HELPER_HPP__