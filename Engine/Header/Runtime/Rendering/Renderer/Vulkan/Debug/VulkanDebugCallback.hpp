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

/// \file       VulkanDebugCallback.hpp
/// \date       21/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Renderer/Vulkan/Debug
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_VULKAN_DEBUG_CALLBACK_HPP__
#define ORDINAL_ENGINE_VULKAN_DEBUG_CALLBACK_HPP__

#include "Runtime/Platform/Configuration/Configuration.hh"

/// \namespace ord
namespace ord
{

/// \namespace rendering
namespace rendering
{

/// \brief The debug report callback
/// \param flags Indicates the VkDebugReportFlagBitsEXT that triggered this callback
/// \param object_type Specifies the type of object being used or created when event was triggered
/// \param source_object Gives the object where the issue was detected
/// \param location Indicates the location of the trigger
/// \param message_code This is a layer-defined value indicating what test triggered this callback
/// \param p_layer_prefix This is the abbreviation of the component making the callback
/// \param p_message This a null-terminated string detailing the trigger conditions
/// \param p_user_data This the user data given when the DebugReportCallback was created
/// \return VK_TRUE to abort the vulkan call, else VK_FALSE
VKAPI_ATTR VkBool32 VKAPI_CALL VulkanDebugCallback
(
    VkDebugReportFlagsEXT      flags,
    VkDebugReportObjectTypeEXT object_type,
    uint64_t                   source_object,
    size_t                     location,
    int32_t                    message_code,
    const char*                p_layer_prefix,
    const char*                p_message,
    void*                      p_user_data
);

} // !namespace

} // !namespace

#endif // !ORDINAL_ENGINE_VULKAN_DEBUG_CALLBACK_HPP__