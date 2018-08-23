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

/// \file       TPoolAllocator.inl
/// \date       04/07/2018 
/// \project    Ordinal Engine
/// \package    Runtime/Core/Memory/Allocator/Impl
/// \author     Vincent STEHLY--CALISTO

/// \namespace Ord
namespace Ord
{

/// \namespace Core
namespace Core
{

/// \brief  Constructor
template<typename Tp, typename TAllocator>
/* inline */ TPoolAllocator<Tp, TAllocator>::TPoolAllocator() ORDINAL_NOEXCEPT
{
    // TODO
}

/// \brief  Destructor
template<typename Tp, typename TAllocator>
/* inline */ TPoolAllocator<Tp, TAllocator>::~TPoolAllocator() ORDINAL_NOEXCEPT
{
    // TODO
}

/// \brief Initializes the pool allocator with the given size
/// \param capacity The count of object of type T to allocate
template<typename Tp, typename TAllocator>
/* inline */ void TPoolAllocator<Tp, TAllocator>::Initialize(UInt32 capacity)
{
    // TODO
}

/// \brief Clear the allocator and free the allocated memory
template<typename Tp, typename TAllocator>
/* inline */ void TPoolAllocator<Tp, TAllocator>::Release()
{
    // TODO
}

/// \brief Deallocates all memory block in the pool but
///        it doesn't free any memory
template<typename Tp, typename TAllocator>
/* inline */ void TPoolAllocator<Tp, TAllocator>::Clear() ORDINAL_NOEXCEPT
{
    // TODO
}

/// \brief  Allocates an element in the pool
/// \return A pointer on the block of data
template<typename Tp, typename TAllocator>
/* inline */ typename TPoolAllocator<Tp, TAllocator>::pointer TPoolAllocator<Tp, TAllocator>::Allocate()
{
    return nullptr;
}

/// \brief  Allocates an element in the pool
///         and call the copy constructor
/// \param  A reference on the object to copy
/// \return A pointer on the new constructed object
template<typename Tp, typename TAllocator>
/* inline */ Tp* TPoolAllocator<Tp, TAllocator>::Allocate(const_reference object)
{
    return nullptr;
}

/// \brief  Allocates an element in the pool
///         and construct the object with given arguments
/// \param  args Variadic arguments
/// \return A pointer on the new constructed object
template<typename Tp, typename TAllocator>
template<typename... Args>
/* inline */ Tp* TPoolAllocator<Tp, TAllocator>::Allocate(Args &&... args)
{
    return nullptr;
}

/// \brief  Deallocates the given block in the pool
/// \param  index The index of the block to deallocate
template<typename Tp, typename TAllocator>
/* inline */ void TPoolAllocator<Tp, TAllocator>::Deallocate(UInt32 index)
{
    // TODO
}

/// \brief  Deallocates the given block in the pool
/// \param  p The pointer on the block to deallocate
template<typename Tp, typename TAllocator>
/* inline */ void TPoolAllocator<Tp, TAllocator>::Deallocate(TPoolAllocator::pointer p)
{
    // TODO
}

/// \brief  Returns the memory usage of the pool allocator
/// \return The number of bytes used by the allocator
template<typename Tp, typename TAllocator>
/* inline */ UInt32 TPoolAllocator<Tp, TAllocator>::GetMemoryUsage() const ORDINAL_NOEXCEPT
{
    return 0;
}

/// \brief  Returns the current capacity of the pool allocator
/// \return The capacity of the allocator
template<typename Tp, typename TAllocator>
/* inline */ UInt32 TPoolAllocator<Tp, TAllocator>::GetCapacity() const ORDINAL_NOEXCEPT
{
    return 0;
}

/// \brief  Returns the next free index
/// \return The next free index
template<typename Tp, typename TAllocator>
/* inline */ Int32 TPoolAllocator<Tp, TAllocator>::GetNextIndex(const Int32 index) const ORDINAL_NOEXCEPT
{
    return 0;
}

/// \brief  Writes index at the next index
/// \param  index The index to write in
/// \param  next_index The index to write
template<typename Tp, typename TAllocator>
/* inline */ void TPoolAllocator<Tp, TAllocator>::WriteIndex(const Int32 index, const Int32 next_index) ORDINAL_NOEXCEPT
{
    // TODO
}

/// \brief  Retrieves the index of pObject from the address
/// \param  p A pointer on the object
/// \return The index of the given object
template<typename Tp, typename TAllocator>
/* inline */ Int32 TPoolAllocator<Tp, TAllocator>::RetrieveIndex(TPoolAllocator::const_pointer p) const ORDINAL_NOEXCEPT
{
    return 0;
}

} // !namespace

} // !namespace