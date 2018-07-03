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

/// \file       CVulkanFunctionLoader.hpp
/// \date       21/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Renderer/Helper
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_C_VULKAN_FUNCTION_LOADER_HPP__
#define ORDINAL_ENGINE_C_VULKAN_FUNCTION_LOADER_HPP__

#include <unordered_map>
#include "Runtime/Platform/Configuration/Configuration.hpp"

/// \namespace ord
namespace ord
{

/// \namespace rendering
namespace rendering
{

/// \brief TODO
/// \class CVulkanFunctionLoader
class CVulkanFunctionLoader
{
public:

    /// \brief Loads the given function from its name
    /// \param instance The vulkan instance
    /// \param sz_function_name The name of the function as a c-string
    /// \throw runtime_error if the function cannot be loaded
    void LoadFunction(VkInstance instance, const char * sz_function_name);

    /// \brief  Returns a function referenced by the given key
    ///         The function pointer is automatically casted to match the T param
    /// \tparam T The true type of the function pointer
    /// \param  key The key of the function
    /// \return The function referenced by the given key, if not found, return nullptr
    template<typename T>
    T GetFunction(uint32_t key) const;

    /// \brief Returns the amount of loaded functions
    /// \return The number of loaded functions
    std::size_t GetFunctionCount() const;

    /// \brief Releases the function loader, clear all registered functions
    void Release();

private:

    std::unordered_map<uint32_t, PFN_vkVoidFunction> m_function_pointers; ///< The map of loaded functions
};

} // !namespace

} // !namespace

#include "Runtime/Rendering/Renderer/Vulkan/Helper/Impl/CVulkanFunctionLoader.inl"

#endif // !ORDINAL_ENGINE_C_VULKAN_FUNCTION_LOADER_HPP__