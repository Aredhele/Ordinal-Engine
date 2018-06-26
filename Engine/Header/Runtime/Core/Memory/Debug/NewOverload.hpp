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

/// \file       NewOverload.hpp
/// \date       26/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Core/Memory/Debug
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_NEW_OVERLOAD_HPP__
#define ORDINAL_ENGINE_NEW_OVERLOAD_HPP__

#include <cstddef> ///< std::size_t
#include <cstdlib> ///< malloc, free

#ifdef ORDINAL_DEBUG

/// \brief  Overload of the global operator new
/// \param  size The amount of bytes to allocate
/// \return A pointer on the allocated memory
void* operator new(std::size_t size)
{
    /* TMP */ return malloc(size);
}

/// \brief  Overload of the global operator new[]
/// \param  size The amount of bytes to allocate
/// \return A pointer on the allocated memory
void* operator new[](std::size_t size)
{
    /* TMP */ return malloc(size);
}

/// \brief  Overload of the global operator delete
/// \param  pointer The address of the allocated memory to free
void operator delete(void* pointer) noexcept
{
    /* TMP */ free(pointer);
}

/// \brief  Overload of the global operator delete[]
/// \param  pointer The address of the allocated memory to free
void operator delete[](void* pointer) noexcept
{
    /* TMP */ free(pointer);
}

#endif // !ORDINAL_DEBUG

#endif // !ORDINAL_ENGINE_NEW_OVERLOAD_HPP__