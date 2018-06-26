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

/// \file       CMemoryManager.cpp
/// \date       26/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Core/Memory
/// \author     Vincent STEHLY--CALISTO

#include "Runtime/Core/Memory/CMemoryManager.hpp"

/// \namespace ord
namespace ord
{

/// \namespace core
namespace core
{

/// \brief  Allocates the given amount of bytes and returns a pointer on the allocated memory
/// \param  size The amount of bytes to allocate
/// \param  array_allocation Is this an array allocation ?
/// \param  sz_function_name The caller function name
/// \param  line The called line
/// \return A pointer on the allocated memory
void *CMemoryManager::Allocate(std::size_t size, bool array_allocation, const char *sz_function_name, unsigned int line)
{
    return std::malloc(size);
}

/// \brief  Deallocates the memory at the given address
/// \param  array_allocation Was the allocation an array allocation ?
/// \param  sz_function_name The caller function name
/// \param  line The called line
void CMemoryManager::Deallocate(void *pointer, bool array_allocation, const char *sz_function_name, unsigned int line)
{
    std::free(pointer);
}

} // !namespace

} // !namespace