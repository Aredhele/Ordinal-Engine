/// Copyright (C) 2018-2019, Ordinal Engine
/// Vincent STEHLY--CALISTO, vincentstehly@hotmail.fr
/// See https://vincentcalisto.com/ordinal-engine/
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

/// \file       CRenderer.hpp
/// \date       03/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_C_RENDERER_HPP__
#define ORDINAL_ENGINE_C_RENDERER_HPP__

#include <string>
#include <vector>
#include <stdexcept>

#include "Runtime/Platform/Configuration/Configuration.hh"

#include "Runtime/Rendering/Window/CWindow.hpp"

/// \namespace ord
namespace ord
{

/// \brief  Contains all needed information
///         to initialize the window
/// \struct SWindowCreateInfo
typedef struct SWindowCreateInfo
{
    int                     window_width;           ///< The width of the window
    int                     window_height;          ///< The height of the window
    const char*             p_window_name;          ///< The name of the window

} SWindowCreateInfo;

/// \brief  Contains all needed information
///         to initialize the renderer
/// \struct SRendererCreateInfo
typedef struct SRendererCreateInfo
{
    const char*             p_engine_name;          ///< The name of the engine
    const char*             p_application_name;     ///< The name of the application
    SWindowCreateInfo       p_window_info;          ///< The info about the window
    uint32_t                api_version;            ///< The version of the vulkan api
    uint32_t                engine_version;         ///< The version of the engine
    uint32_t                application_version;    ///< The version of the application

} SRendererCreateInfo;

/// \brief Manages rendering using Vulkan api
/// \class CRenderer
class CRenderer
{
public:

    /// \brief  Default constructor
    CRenderer();

    /// \brief  Destructor
    ~CRenderer();

    /// \brief Initializes the renderer with an info structure
    /// \param renderer_info The structure that contains info
    ///        about the renderer initialization
    /// \throw Can throw runtime errors exceptions
    void Initialize(const SRendererCreateInfo& renderer_info);

    /// \brief TODO
    /// \param width  TODO
    /// \param height TODO
    /// \param name   TODO
    /// \return TODO
    CWindow * OpenWindow(uint32_t width, uint32_t height, const std::string & name);

private:

    /// \brief Initializes the vulkan instance
    /// \param renderer_info The structure that contains info
    ///        about the renderer initialization
    /// \throw Can throw runtime errors exceptions
    void InitializeInstance(const SRendererCreateInfo& renderer_info);

    /// \brief Initializes vulkan physical devices
    /// \param renderer_info The structure that contains info
    ///        about the renderer initialization
    /// \throw Can throw runtime errors exceptions
    void InitializePhysicalDevice(const SRendererCreateInfo& renderer_info);

    /// \brief TODO
    void SetupDebug();

    /// \brief TODO
    void InitializeDebug();

    /// \brief TODO
    void UninitializeDebug();

public:

    VkInstance                      mp_instance       = VK_NULL_HANDLE;         ///< TODO
    std::vector <VkQueue>           m_queues;                                   ///< TODO
    std::vector <VkPhysicalDevice>  m_physical_devices;                         ///< TODO
    std::vector <VkDevice>          m_logical_devices;                          ///< TODO
    std::vector <const char*>       m_instance_layers;                          ///< TODO
    std::vector <const char*>       m_instance_extensions;                      ///< TODO

    uint32_t                        m_family_properties_index = 0;
    VkDebugReportCallbackEXT        m_debug_report_callback   = VK_NULL_HANDLE; ///< TODO

    CWindow *                       mp_window = nullptr;
};
    
} // !namespace 

#endif // !ORDINAL_ENGINE_C_RENDERER_HPP__