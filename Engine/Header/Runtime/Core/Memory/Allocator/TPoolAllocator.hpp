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

/// \file       TPoolAllocator.hpp
/// \date       04/07/2018
/// \project    Ordinal Engine
/// \package    Runtime/Core/Memory/Allocator
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_T_POOL_ALLOCATOR_HPP__
#define ORDINAL_ENGINE_T_POOL_ALLOCATOR_HPP__

#include "Runtime/Core/Memory/Allocator/TBaseAllocator.hpp"

/// \namespace Ord
namespace Ord
{

/// \namespace Core
namespace Core
{

/// \class  TPoolAllocator
/// \tparam Tp The type of the objects to allocate
/// \tparam TAllocator The allocator to use
/// \brief  Allocator based on memory pooling
template <typename Tp, typename TAllocator = TBaseAllocator<Tp>>
class TPoolAllocator
{
public:

    using size_type       = size_t;
    using value_type      = Tp;
    using difference_type = ptrdiff_t;
    using pointer         = Tp*;
    using reference       = Tp &;
    using const_pointer   = const Tp*;
    using const_reference = const Tp&;

public:

    /// \brief  Constructor
    inline ORDINAL_EXPLICIT TPoolAllocator() ORDINAL_NOEXCEPT;

    /// \brief  Destructor
    inline ~TPoolAllocator() ORDINAL_NOEXCEPT;

    /// \brief Initializes the pool allocator with the given size
    /// \param capacity The count of object of type T to allocate
    inline void Initialize(UInt32 capacity);

    /// \brief Clear the allocator and free the allocated memory
    inline void Release();

    /// \brief Deallocates all memory block in the pool but
    ///        it doesn't free any memory
    inline void Clear() ORDINAL_NOEXCEPT;

    /// \brief  Allocates an element in the pool
    /// \return A pointer on the block of data
    inline pointer Allocate();

    /// \brief  Allocates an element in the pool
    ///         and call the copy constructor
    /// \param  A reference on the object to copy
    /// \return A pointer on the new constructed object
    inline pointer Allocate(const_reference object);

    /// \brief  Allocates an element in the pool
    ///         and construct the object with given arguments
    /// \param  args Variadic arguments
    /// \return A pointer on the new constructed object
    template <typename... Args>
    inline pointer Allocate(Args&&... args);

    /// \brief  Deallocates the given block in the pool
    /// \param  index The index of the block to deallocate
    inline void Deallocate(UInt32 index);

    /// \brief  Deallocates the given block in the pool
    /// \param  p The pointer on the block to deallocate
    inline void Deallocate(pointer p);

    /// \brief  Returns the memory usage of the pool allocator
    /// \return The number of bytes used by the allocator
    inline UInt32 GetMemoryUsage() const ORDINAL_NOEXCEPT;

    /// \brief  Returns the current capacity of the pool allocator
    /// \return The capacity of the allocator
    inline UInt32 GetCapacity() const ORDINAL_NOEXCEPT;

private:

    /// \brief  Returns the next free index
    /// \return The next free index
    inline Int32 GetNextIndex(const Int32 index) const ORDINAL_NOEXCEPT;

    /// \brief  Writes index at the next index
    /// \param  index The index to write in
    /// \param  next_index The index to write
    inline void WriteIndex(const Int32 index, const Int32 next_index) ORDINAL_NOEXCEPT;

    /// \brief  Retrieves the index of pObject from the address
    /// \param  p A pointer on the object
    /// \return The index of the given object
    inline Int32 RetrieveIndex(const_pointer p) const ORDINAL_NOEXCEPT;

private:

    pointer    mp_head       = ORDINAL_NULLPTR;  ///< The base address of the pool
    Int32      m_free        = -1;               ///< The next free index
    UInt32     m_capacity    = 0;                ///< The capacity of the pool in byte
    bool       m_initialized = false;            ///< Tells if the pool allocator is initialized
    TAllocator m_allocator;                      ///< The pool allocator internal allocator
};

} // !namespace

} // !namespace

#include "Runtime/Core/Memory/Allocator/Impl/TPoolAllocator.inl"

#endif // !ORDINAL_ENGINE_T_POOL_ALLOCATOR_HPP__