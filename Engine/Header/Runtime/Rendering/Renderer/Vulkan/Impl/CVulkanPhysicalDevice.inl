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

/// \file       CVulkanPhysicalDevice.inl
/// \date       22/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Renderer/Vulkan/Impl
/// \author     Vincent STEHLY--CALISTO

/// \namespace Ord
namespace Ord
{

/// \namespace Rendering
namespace Rendering
{

/// \brief Returns the vulkan physical device handle
/// \return The handle on the vulkan physical device
inline VkPhysicalDevice CVulkanPhysicalDevice::GetPhysicalDeviceHandle() const
{ return mp_physical_device; }

/// \brief  Returns the amount of queue families
/// \return The amount of queue families
inline uint32_t CVulkanPhysicalDevice::GetQueueFamilyCount() const
{ return static_cast<uint32_t>(m_queue_families.size()); }

/// \brief  Returns the array of queue families
/// \return The array of queue families
inline const std::vector<CVulkanQueueFamily> &CVulkanPhysicalDevice::GetQueueFamilies() const
{ return m_queue_families; }

} // !namespace

} // !namespace