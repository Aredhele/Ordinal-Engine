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

/// \file       CVulkanFunctionLoader.inl
/// \date       21/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Rendering/Renderer/Vulkan/Helper/Impl
/// \author     Vincent STEHLY--CALISTO

/// \namespace Ord
namespace Ord
{

/// \namespace Rendering
namespace Rendering
{

/// \brief  Returns a function referenced by the given key
///         The function pointer is automatically casted to match the T param
/// \tparam T The true type of the function pointer
/// \param  key The key of the function
/// \return The function referenced by the given key, if not found, return nullptr
template<typename T>
T CVulkanFunctionLoader::GetFunction(uint32_t key) const
{
    static_assert(std::is_pointer<T>::value);

    const auto const_iterator = m_function_pointers.find(key);
    if(m_function_pointers.cend() != const_iterator)
        return reinterpret_cast<T>(const_iterator->second);

    return nullptr;
}

} // !namespace

} // !namespace