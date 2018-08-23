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

/// \file       CVulkanQueueFamily.hpp
/// \date       22/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Renderer/Vulkan
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_C_VULKAN_QUEUE_FAMILY_HPP__
#define ORDINAL_ENGINE_C_VULKAN_QUEUE_FAMILY_HPP__

#include "Runtime/Platform/Configuration/Configuration.hpp"

/// \namespace Ord
namespace Ord
{

/// \namespace Rendering
namespace Rendering
{

/// \brief Stores all available queue family for a given physical device
/// \class CVulkanQueueFamily
class CVulkanQueueFamily
{
public:

    /// \brief Constructor
    /// \param index The index of the queue family
    /// \param queue_family_properties The properties of the queue family
    explicit CVulkanQueueFamily(uint32_t index, const VkQueueFamilyProperties& queue_family_properties);

public:

    /// \brief Returns the index of the queue family
    /// \return The index of the queue family
    inline uint32_t GetQueueFamilyIndex() const;

    /// \brief Returns the amount of queues
    /// \return The amount of queues
    inline uint32_t GetQueueFamilyCount() const;

    /// \brief Returns the flags of the queue family
    /// \return The flags of the queue family
    inline VkQueueFlags GetQueueFamilyFlags() const;

    /// \brief Returns the properties of the queue family
    /// \return The properties of the queue family
    inline const VkQueueFamilyProperties& GetQueueFamilyProperties() const;

private:

    uint32_t                m_queue_index = 0;         ///< The index of the queue family
    VkQueueFamilyProperties m_queue_family_properties; ///< The properties of the queue family
};

} // !namespace

} // !namespace

#include "Runtime/Rendering/Renderer/Vulkan/Impl/CVulkanQueueFamily.inl"

#endif // !ORDINAL_ENGINE_C_VULKAN_QUEUE_FAMILY_HPP__