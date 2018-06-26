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

/// \file       CStackAllocator.inl
/// \date       26/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Core/Memory/Allocator/Impl
/// \author     Vincent STEHLY--CALISTO

/// \namespace ordinal
namespace ordinal
{

/// \namespace core
namespace core
{

/// \brief  Resets the head
/* inline */ void CStackAllocator::Clear()
{
    m_head = 0;
}

/// \brief  Allocates nBytes at the top of the stack
///         and returns a pointer on the allocated memory
/// \param  size The amount of bytes to allocate
/// \return A pointer on the allocated memory
/* inline */ void* CStackAllocator::Allocate(std::size_t size)
{
    ASSERT_LT      (m_head + size, m_size);
    ASSERT_NOT_NULL(mp_data);

    void* pointer = mp_data + m_head;
    m_head += size;

    return pointer;
}

/// \brief  Returns the size of the allocator
/// \return The amount of allocated memory in bytes
/* inline */ std::size_t CStackAllocator::GetSize() const
{
    return m_size;
}

} // !namespace

} // !namespace