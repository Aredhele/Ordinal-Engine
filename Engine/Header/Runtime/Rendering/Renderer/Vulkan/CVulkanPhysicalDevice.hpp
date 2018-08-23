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

/// \file       CVulkanPhysicalDevice.hpp
/// \date       21/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Renderer/Vulkan
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_C_VULKAN_PHYSICAL_DEVICE_HPP__
#define ORDINAL_ENGINE_C_VULKAN_PHYSICAL_DEVICE_HPP__

#include <vector>

#include "Runtime/Platform/Configuration/Configuration.hpp"
#include "Runtime/Rendering/Renderer/Vulkan/CVulkanQueueFamily.hpp"

/// \namespace Ord
namespace Ord
{

/// \namespace Rendering
namespace Rendering
{

/// \brief Manages a vulkan physical devices
/// \class CVulkanPhysicalDevice
class CVulkanPhysicalDevice
{
public:

    /// \brief Initializes the physical device
    /// \param physical_device The vulkan physical device
    /// \throw runtime_error Throws on initialization failure
    void Initialize(VkPhysicalDevice physical_device);

    /// \brief Releases the physical device
    void Release();

public:

    /// \brief  Returns the vulkan physical device handle
    /// \return The handle on the vulkan physical device
    inline VkPhysicalDevice GetPhysicalDeviceHandle() const;

    /// \brief  Returns the amount of queue families
    /// \return The amount of queue families
    inline uint32_t GetQueueFamilyCount() const;

    /// \brief  Returns the array of queue families
    /// \return The array of queue families
    inline const std::vector<CVulkanQueueFamily>& GetQueueFamilies() const;

public:

    /// \brief  Returns the amount of physical devices detected
    /// \param  instance The vulkan instance
    /// \return The amount of physical devices detected
    static uint32_t GetPhysicalDeviceCount(VkInstance instance);

    /// \brief Stores at the given address the list of physical device handles
    /// \param instance The vulkan instance
    /// \param count The count of physical devices to get
    /// \param p_physical_devices The address where to store physical device handles
    static void GetPhysicalDevices(VkInstance instance, uint32_t count, VkPhysicalDevice* p_physical_devices);

    /// \brief  Tells if the physical devices is suitable for rendering
    /// \param  physical_device The physical devices to test
    /// \return True if the device is suitable, else false
    static bool IsPhysicalDeviceSuitable(VkPhysicalDevice physical_device);

private:

    /// \brief Initializes all queue families
    /// \throw runtime_error Throws on initialization failure
    void InitializeQueueFamilies();

private:

    VkPhysicalDevice                mp_physical_device = VK_NULL_HANDLE; ///< TODO
    std::vector<CVulkanQueueFamily> m_queue_families;                    ///< TODO
};

} // !namespace

} // !namespace

#include "Runtime/Rendering/Renderer/Vulkan/Impl/CVulkanPhysicalDevice.inl"

#endif // !ORDINAL_ENGINE_C_VULKAN_PHYSICAL_DEVICE_HPP__