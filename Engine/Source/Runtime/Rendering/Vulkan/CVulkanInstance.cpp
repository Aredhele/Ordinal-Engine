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

/// \file       CVulkanInstance.cpp
/// \date       23/05/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Vulkan/
/// \author     Vincent STEHLY--CALISTO

#include "Runtime/Core/Debug/SLogger.hpp"
#include "Runtime/Rendering/Vulkan/CVulkanInstance.hpp"

/// \namespace ord
namespace ord
{

/// \brief  Creates the vulkan instance
/// \return True on success, else false
bool CVulkanInstance::CreateInstance()
{
    VkApplicationInfo appInfo = {};
    appInfo.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName   = "Ordinal Runtime";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName        = "Ordinal Engine";
    appInfo.engineVersion      = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion         = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo = {};
    createInfo.sType                = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-stack-address"
    createInfo.pApplicationInfo     = &appInfo;
#pragma clang diagnostic pop

    uint32_t glfwExtensionCount = 0;
    const char ** glfwExtensions;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;
    createInfo.enabledLayerCount = 0;

    if (vkCreateInstance(&createInfo, nullptr, &m_vk_instance) != VK_SUCCESS)
    {
        SLogger::LogError("Failed to create vulkan instance");
        return false;
    }

    return true;
}

/// \brief  Destroys the vulkan instance
void CVulkanInstance::DestroyInstance()
{
    vkDestroyInstance(m_vk_instance, nullptr);
}

} // !namespace

