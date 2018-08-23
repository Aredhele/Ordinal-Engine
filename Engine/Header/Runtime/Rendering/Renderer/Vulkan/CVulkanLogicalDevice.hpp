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

/// \file       CVulkanLogicalDevice.hpp
/// \date       21/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Renderer/Vulkan
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_C_VULKAN_LOGICAL_DEVICE_HPP__
#define ORDINAL_ENGINE_C_VULKAN_LOGICAL_DEVICE_HPP__

#include "Runtime/Platform/Configuration/Configuration.hpp"
#include "Runtime/Rendering/Renderer/Vulkan/CVulkanPhysicalDevice.hpp"

/// \namespace Ord
namespace Ord
{

/// \namespace Rendering
namespace Rendering
{

/// \brief Manages a vulkan logical device
/// \class CVulkanLogicalDevice
class CVulkanLogicalDevice
{
public:

    /// \brief Initializes the logical device
    /// \param physical_device The vulkan physical device
    void Initialize(VkPhysicalDevice physical_device);

    /// \brief Releases the logical device
    void Release();

public:

    /// \brief Returns the vulkan logical device handle
    /// \return The handle on the vulkan logical device
    inline VkDevice GetLogicalDeviceHandle() const;

private:

    /// \brief Adds to device extensions list all required extensions
    void InitializeDeviceExtensions();

#ifdef ORDINAL_DEBUG
    /// \brief Adds to the device layers list all required layers
    void InitializeDeviceLayers();
#endif

    /// \brief Initializes the vulkan logical device
    void InitializeLogicalDevice();

    /// \brief Releases the attached physical device
    void ReleasePhysicalDevice();

    /// \brief Releases the logical device
    void ReleaseLogicalDevice();

private:

    VkDevice                 mp_logical_device  = VK_NULL_HANDLE;   ///< TODO
    CVulkanPhysicalDevice *  mp_physical_device = nullptr;          ///< TODO

    std::vector<const char*> m_device_layers;                       ///< TODO
    std::vector<const char*> m_device_extensions;                   ///< TODO
};

} // !namespace

} // !namespace

#include "Runtime/Rendering/Renderer/Vulkan/Impl/CVulkanLogicalDevice.inl"

#endif // !ORDINAL_ENGINE_C_VULKAN_LOGICAL_DEVICE_HPP__