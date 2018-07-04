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

/// \file       TMallocAllocator.inl
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

/// \brief  Allocates n * sizeof(Tp) bytes
/// \param  n The number of elements to allocate
/// \return A pointer on the allocated memory
template<typename Tp>
/* inline */ Tp* TMallocAllocator<Tp>::Allocate(size_type n)
{
    return static_cast<Tp*>(malloc(n * sizeof(Tp)));
}

/// \brief  Allocates n * sizeof(Tp) bytes
/// \param  n The number of elements to allocate
/// \return A pointer on the allocated memory
template<typename Tp>
/* inline */ void TMallocAllocator<Tp>::Deallocate(pointer p)
{
    free(p);
}

/// \brief  Constructs an object at given memory location
/// \tparam Up The pointer type
/// \tparam Args The arguments to construct the object
/// \param  p The pointer to the memory
/// \param  args The arguments to construct the object
template<typename Tp>
template<typename Up, typename... Args>
/* inline */ void TMallocAllocator<Tp>::Construct(Up* p, Args&&... args)
{
    ::new((void *)p) Up(std::forward<Args>(args)...);
}

/// \brief  Destroys an object at the given memory location
/// \tparam Up The pointer type
/// \param  p The pointer on the object
template<typename Tp>
template<typename Up>
/* inline */ void TMallocAllocator<Tp>::Destroy(Up* p)
{
    p->~Up();
}

} // !namespace

} // !namespace