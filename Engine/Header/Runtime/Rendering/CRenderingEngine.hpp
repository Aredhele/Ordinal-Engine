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

/// \file       CRenderingEngine.hpp
/// \date       23/05/2018 
/// \project    Ordinal Engine
/// \package    Runtime/Rendering
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_C_RENDERING_ENGINE_HPP__
#define ORDINAL_ENGINE_C_RENDERING_ENGINE_HPP__

#include "Runtime/Rendering/Window/CWindow.hpp"
#include "Runtime/Rendering/Vulkan/CVulkanInstance.hpp"

/// \namespace ord
namespace ord
{

/// \brief Holds the renderer
/// \class CRenderingEngine
class CRenderingEngine
{
public:

    /// \brief  Initializes the renderer
    /// \return True on success, else false
    bool Initialize();

    /// \brief Starts rendering
    void Run();

private:

    CWindow         m_window;
    CVulkanInstance m_vk_instance;
};

} // !namespace 

#endif // !ORDINAL_ENGINE_C_RENDERING_ENGINE_HPP__