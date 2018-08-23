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

/// \file       CVulkanRenderer.hpp
/// \date       21/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Renderer
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_C_VULKAN_RENDERER_HPP__
#define ORDINAL_ENGINE_C_VULKAN_RENDERER_HPP__

#include <vector>
#include <stdexcept>

#include "Runtime/Rendering/Renderer/IRenderer.hpp"

#include "Runtime/Rendering/Renderer/Vulkan/CVulkanWindow.hpp"
#include "Runtime/Rendering/Renderer/Vulkan/CVulkanLogicalDevice.hpp"
#include "Runtime/Rendering/Renderer/Vulkan/Debug/CVulkanDebugReporter.hpp"
#include "Runtime/Rendering/Renderer/Vulkan/Helper/CVulkanFunctionLoader.hpp"

/// \namespace Ord
namespace Ord
{

/// \namespace Rendering
namespace Rendering
{

/// \brief Vulkan renderer
/// \class CVulkanRenderer
class CVulkanRenderer : public IRenderer
{
public:

    /// \brief Initializes the renderer from the create info structure
    /// \param renderer_info Contains all needed information to initialize a renderer
    /// \throw runtime_error Throws on initialization failure
    void Initialize(const SRendererCreateInfo& renderer_info) final;

    /// \brief Releases the renderer
    void Release() final;

    /// \brief  Creates a window
    /// \param  window_create_info The window create info
    /// \return A pointer on the window
    IWindow* OpenWindow(const SWindowCreateInfo& window_create_info) final;

private:

#ifdef ORDINAL_DEBUG
    /// \brief Fills the vector of layers to enable
    void InitializeInstanceLayers();

    /// \brief Fills the vector of extensions to enable
    void InitializeInstanceExtensions();

    /// \brief Initializes the vulkan debug callback
    void InitializeDebugCallback();

    /// \brief Releases the vulkan debug callback
    void ReleaseDebugCallback();
#endif

    /// \brief Initializes the renderer from the create info structure
    /// \param renderer_info Contains all needed information to initialize a renderer
    /// \throw runtime_error Throws on initialization failure
    void InitializeInstance(const SRendererCreateInfo& renderer_info);

    /// \brief Loads all required vulkan functions
    void InitializeFunctions();

    /// \brief Initializes logical devices from physical devices
    /// \throw runtime_error Throws on initialization failure
    void InitializeLogicalDevices();

    /// \brief Releases all logical devices
    void ReleaseLogicalDevice();

    /// \brief Releases all loaded functions
    void ReleaseFunctions();

    /// \brief Releases the vulkan instance
    void ReleaseInstance();

private:

    VkInstance                          mp_instance        = VK_NULL_HANDLE; ///< The vulkan instance handle
    CVulkanFunctionLoader               m_function_loader;                   ///< The helper to load function
    std::vector<CVulkanLogicalDevice *> m_logical_devices;                   ///< Contains all logical devices

#ifdef ORDINAL_DEBUG
    CVulkanDebugReporter                m_debug_reporter;                    ///< Vulkan debug reporter
    VkDebugReportCallbackEXT            mp_report_callback = VK_NULL_HANDLE; ///< The vulkan debug report callback handle
#endif

    std::vector<const char *>           m_instance_layers;                   ///< TODO
    std::vector<const char *>           m_instance_extensions;               ///< TODO
    CVulkanWindow*                      mp_window = nullptr;                 ///< TODO
};

} // !namespace

} // !namespace

#endif // !ORDINAL_ENGINE_C_VULKAN_RENDERER_HPP__