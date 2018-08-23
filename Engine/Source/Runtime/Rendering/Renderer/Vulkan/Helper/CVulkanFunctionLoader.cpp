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

/// \file       CVulkanFunctionLoader.cpp
/// \date       21/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Renderer/Helper
/// \author     Vincent STEHLY--CALISTO

#include "Runtime/Core/Assertion/Assert.hpp"
#include "Runtime/Core/StringHash/StringHash.hpp"
#include "Runtime/Rendering/Renderer/Vulkan/Helper/CVulkanFunctionLoader.hpp"

/// \namespace Ord
namespace Ord
{

/// \namespace Rendering
namespace Rendering
{

/// \brief Loads the given function from its name
/// \param instance The vulkan instance
/// \param sz_function_name The name of the function as a c-string
/// \throw runtime_error if the function cannot be loaded
void CVulkanFunctionLoader::LoadFunction(VkInstance instance, const char* sz_function_name)
{
    ORD_ASSERT_TRUE(sz_function_name != nullptr);
    ORD_ASSERT_TRUE(instance         != VK_NULL_HANDLE);

    PFN_vkVoidFunction function = vkGetInstanceProcAddr(instance, sz_function_name);

    if(function == nullptr)
    {
        std::string message = "Unable to load " + std::string(sz_function_name);
        throw std::runtime_error(message.c_str());
    }

    m_function_pointers.emplace(DSID(sz_function_name), function);
}

/// \brief Returns the amount of loaded functions
/// \return The number of loaded functions
std::size_t CVulkanFunctionLoader::GetFunctionCount() const
{
    return m_function_pointers.size();
}

/// \brief Releases the function loader, clear all registered functions
void CVulkanFunctionLoader::Release()
{
    m_function_pointers.clear();
}

} // !namespace

} // !namespace