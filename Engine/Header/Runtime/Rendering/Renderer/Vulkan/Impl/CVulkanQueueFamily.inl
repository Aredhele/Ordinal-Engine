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

/// \file       CVulkanQueueFamily.inl
/// \date       22/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Renderer/Vulkan/Impl
/// \author     Vincent STEHLY--CALISTO

#include "Runtime/Rendering/Renderer/Vulkan/CVulkanQueueFamily.hpp"

/// \namespace Ord
namespace Ord
{

/// \namespace Rendering
namespace Rendering
{

/// \brief Returns the index of the queue family
/// \return The index of the queue family
uint32_t CVulkanQueueFamily::GetQueueFamilyIndex() const
{ return m_queue_index; }

/// \brief Returns the amount of queues
/// \return The amount of queues
uint32_t CVulkanQueueFamily::GetQueueFamilyCount() const
{ return m_queue_family_properties.queueCount; }

/// \brief Returns the flags of the queue family
/// \return The flags of the queue family
VkQueueFlags CVulkanQueueFamily::GetQueueFamilyFlags() const
{ return m_queue_family_properties.queueFlags; }

/// \brief Returns the properties of the queue family
/// \return The properties of the queue family
const VkQueueFamilyProperties& CVulkanQueueFamily::GetQueueFamilyProperties() const
{ return m_queue_family_properties; }

} // !namespace

} // !namespace