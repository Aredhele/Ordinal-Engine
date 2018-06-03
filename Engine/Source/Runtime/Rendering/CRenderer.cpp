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

/// \file       CRenderer.cpp
/// \date       03/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering
/// \author     Vincent STEHLY--CALISTO

#include "Runtime/Core/Debug/SLogger.hpp"
#include "Runtime/Rendering/CRenderer.hpp"
#include "Runtime/Rendering/Helper/VulkanHelper.hh"

/// \namespace ord
namespace ord
{

/// \brief  Default constructor
CRenderer::CRenderer()
{
    // None
}

/// \brief  Destructor
CRenderer::~CRenderer()
{
    vkDestroyInstance(mp_instance, nullptr);
}

/// \brief Initializes the renderer with an info structure
/// \param renderer_info The structure that contains info
///        about the renderer initialization
/// \throw Can throw runtime errors exceptions
void CRenderer::Initialize(const SRendererCreateInfo& renderer_info)
{
    SLogger::LogInfo("Initializing vulkan renderer ...");

    InitializeInstance(renderer_info);
    InitializePhysicalDevice(renderer_info);

    SLogger::LogInfo("Vulkan renderer fully initialized.");
}

/// \brief Initializes the vulkan instance
/// \param renderer_info The structure that contains info
///        about the renderer initialization
/// \throw Can throw runtime errors exceptions
void CRenderer::InitializeInstance(const SRendererCreateInfo& renderer_info)
{
    VkApplicationInfo application_info {};
    application_info.sType                = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    application_info.pEngineName          = renderer_info.p_engine_name;
    application_info.pApplicationName     = renderer_info.p_application_name;
    application_info.apiVersion           = renderer_info.api_version;
    application_info.engineVersion        = renderer_info.engine_version;
    application_info.applicationVersion   = renderer_info.application_version;

    VkInstanceCreateInfo instance_create_info {};
    instance_create_info.sType            = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instance_create_info.pApplicationInfo = &application_info;

    VkResult result = vkCreateInstance(&instance_create_info, nullptr, &mp_instance);

    if(result != VK_SUCCESS)
    {
        throw std::runtime_error("Error while creating vulkan instance.");
    }

    SLogger::LogInfo("Vulkan instance initialized.");
}

/// \brief Initializes vulkan physical devices
/// \param renderer_info The structure that contains info
///        about the renderer initialization
/// \throw Can throw runtime errors exceptions
void CRenderer::InitializePhysicalDevice(const SRendererCreateInfo &renderer_info)
{
    uint32_t physical_device_count = 0;
    vkEnumeratePhysicalDevices(mp_instance, &physical_device_count, nullptr);

    m_physical_devices.resize(physical_device_count, VK_NULL_HANDLE);
    vkEnumeratePhysicalDevices(mp_instance, &physical_device_count, m_physical_devices.data());

    DisplayPhysicalDeviceProperties(m_physical_devices);

    SLogger::LogInfo("%u Physical device(s) found.", m_physical_devices.size());
    SLogger::LogInfo("Vulkan physical devices initialized.");
}

} // !namespace
