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

/// \file       CVulkanRenderer.cpp
/// \date       21/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Renderer
/// \author     Vincent STEHLY--CALISTO

#include "Runtime/Core/Debug/SLogger.hpp"
#include "Runtime/Rendering/Renderer/CVulkanRenderer.hpp"

/// \namespace ord
namespace ord
{

/// \namespace rendering
namespace rendering
{

/// \brief Initializes the renderer from the create info structure
/// \param s_renderer_info Contains all needed information to initialize a renderer
void CVulkanRenderer::Initialize(const SRendererCreateInfo& renderer_info)
{
    VkApplicationInfo application_info {};
    {
        application_info.sType                       = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        application_info.pApplicationName            = renderer_info.p_application_name;
        application_info.applicationVersion          = renderer_info.application_version;
        application_info.pEngineName                 = renderer_info.p_engine_name;
        application_info.engineVersion               = renderer_info.engine_version;
        application_info.apiVersion                  = renderer_info.api_version;
    }

    VkInstanceCreateInfo instance_create_info {};
    {
        instance_create_info.sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        instance_create_info.pApplicationInfo        = &application_info;
        instance_create_info.enabledLayerCount       = 0; // static_cast<uint32_t>(m_instance_layers.size());
        instance_create_info.enabledExtensionCount   = 0; // static_cast<uint32_t>(m_instance_extensions.size());
        instance_create_info.ppEnabledLayerNames     = nullptr; // m_instance_layers.data();
        instance_create_info.ppEnabledExtensionNames = nullptr; // m_instance_extensions.data();
    }

    VkResult result = vkCreateInstance(&instance_create_info, nullptr, &mp_instance);

    if(result != VK_SUCCESS)
    {
        throw std::runtime_error("Error while creating vulkan instance.");
    }

    SLogger::LogInfo("Vulkan instance initialized.");
}

/// \brief Releases the renderer
void CVulkanRenderer::Release()
{
   // None
}

} // !namespace

} // !namespace
