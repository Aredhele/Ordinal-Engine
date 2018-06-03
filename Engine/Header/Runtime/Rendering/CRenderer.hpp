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

/// \file       CRenderer.hpp
/// \date       03/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_C_RENDERER_HPP__
#define ORDINAL_ENGINE_C_RENDERER_HPP__

#include <string>
#include <stdexcept>

#include "vulkan/vulkan.h"

/// \namespace ord
namespace ord
{

/// \brief  Contains all needed information
///         to initialize the window
/// \struct SWindowCreateInfo
struct SWindowCreateInfo
{
    int                     window_width;   ///< The width of the window
    int                     window_height;  ///< The height of the window
    const char*             p_window_name;  ///< The name of the window
};

/// \brief  Contains all needed information
///         to initialize the renderer
/// \struct SRendererCreateInfo
struct SRendererCreateInfo
{
    const char*             p_engine_name;  ///< The name of the engine
    SWindowCreateInfo       p_window_info;  ///< The info about the window
};

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

private:

};
    
} // !namespace 

#endif // !ORDINAL_ENGINE_C_RENDERER_HPP__