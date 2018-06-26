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

/// \file       CStackAllocator.hpp
/// \date       26/06/2018
/// \project    Ordinal Engine
/// \package
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_C_STACK_ALLOCATOR_HPP__
#define ORDINAL_ENGINE_C_STACK_ALLOCATOR_HPP__

#include "Runtime/Core/Assertion/Assert.hh"

/// \namespace ordinal
namespace ordinal
{

/// \namespace core
namespace core
{

/// \class StackAllocator
/// \brief Simple stack allocator
class CStackAllocator
{
public:

    /// \brief Constructor
    CStackAllocator() = default;

    /// \brief Destructor
    ~CStackAllocator();

    /// \brief  Allocates nBytes at the top of the stack
    ///         and returns a pointer on the allocated memory
    /// \param  size The total amount of available memory in the allocator
    /// \return A pointer on the allocated memory
    void Initialize(std::size_t size);

    /// \brief Releases the allocator memory
    void Release();

    /// \brief  Resets the head
    inline void Clear();

    /// \brief  Allocates nBytes at the top of the stack
    ///         and returns a pointer on the allocated memory
    /// \param  size The amount of bytes to allocate
    /// \return A pointer on the allocated memory
    inline void * Allocate(std::size_t size);

    /// \brief  Returns the size of the allocator
    /// \return The amount of allocated memory in bytes
    inline std::size_t GetSize() const;

private:

    std::size_t  m_size  = 0;       ///< The size in bytes of the allocator
    std::size_t  m_head  = 0;       ///< The current position in the stack
    uint8_t *    mp_data = nullptr; ///< The memory buffer
};

using CFrameAllocator = CStackAllocator;

} // !namespace

} // !namespace

#include "Runtime/Core/Memory/Allocator/Impl/CStackAllocator.inl"

#endif // !ORDINAL_ENGINE_C_STACK_ALLOCATOR_HPP__