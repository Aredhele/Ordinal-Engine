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

/// \file       CStackAllocator.cpp
/// \date       26/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Core/Memory/Allocator
/// \author     Vincent STEHLY--CALISTO

#include "Runtime/Core/Memory/Allocator/CStackAllocator.hpp"

/// \namespace ord
namespace ord
{

/// \namespace core
namespace core
{

/// \brief Destructor
CStackAllocator::~CStackAllocator()
{
    Release();
}

/// \brief  Allocates nBytes at the top of the stack
///         and returns a pointer on the allocated memory
/// \param  size The total amount of available memory in the allocator
/// \return A pointer on the allocated memory
void CStackAllocator::Initialize(std::size_t size)
{
    if(size == 0 || size >= 1024 * 1024 * 64)
        throw std::bad_alloc();

    Release();

    m_head  = 0;
    m_size  = size;
    mp_data = new uint8_t[m_size];

    if(!mp_data)
        throw std::bad_alloc();
}

/// \brief Releases the allocator memory
void CStackAllocator::Release()
{
    delete[] mp_data;

    m_head  = 0;
    m_size  = 0;
    mp_data = nullptr;
}

} // !namespace

} // !namespace