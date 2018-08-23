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

/// \file       CMemoryTracker.hpp
/// \date       26/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Core/Memory
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_C_MEMORY_TRACKER_HPP__
#define ORDINAL_ENGINE_C_MEMORY_TRACKER_HPP__

#include <cstddef> ///< std::size_t
#include <cstdint> ///< uint8_t

/// \namespace Ord
namespace Ord
{

/// \namespace Core
namespace Core
{

/// \brief Keeps track of the allocated memory within the engine
/// \class CMemoryTracker
class CMemoryTracker
{
public:

    /// \brief  Custom structure to store information about
    ///         allocated / freed memory
    /// \struct SBlock
    struct SBlock
    {
        std::size_t  block_size;        ///< The allocated amount of bytes
        unsigned int block_token;       ///< The token of the block (allocated or freed)
        unsigned int caller_line;       ///< The line of the caller
        SBlock *     p_prev_block;      ///< The previous block
        SBlock *     p_next_block;      ///< The next block
        const char*  p_caller_function; ///< The file of the caller
        bool         is_array;          ///< Was the allocation an array allocation ?
    };

public:

    /// \brief Records an allocation in the memory tracker
    /// \param pointer The allocated block
    /// \param size The size of the allocated memory
    /// \param is_array Tells if the allocation is an array allocation
    /// \param p_caller_function The caller function
    /// \param caller_line Thee caller line
    static void RecordAllocation(uint8_t * pointer, std::size_t size, bool is_array, const char*  p_caller_function, unsigned int caller_line);

    /// \brief Records a deallocation in the memory tracker
    /// \param pointer The allocated block
    /// \param is_array Tells if the allocation is an array allocation
    /// \param p_caller_function The caller function
    /// \param caller_line Thee caller line
    static void RecordDeallocation(uint8_t * pointer, bool is_array, const char*  p_caller_function, unsigned int caller_line);

private:

    friend class CMemoryManager;

    /// \brief Default constructor
    CMemoryTracker() = default;

    /// \brief Destructor
    ~CMemoryTracker();

    /// \brief Initializes the memory tracker
    static void Initialize();

    /// \brief Releases the memory tracker
    static void Release();

private:

    static constexpr int s_allocated_token = 0xFFFF; ///< The token of allocated blocks
    static constexpr int s_freed_token     = 0xFEFE; ///< The token of freed blocks

    static bool         s_initialized;      ///< Is the manager initialized ?
    static SBlock       s_block_list;       ///< The list of blocks
    static std::size_t  s_allocated_size;   ///< The current amount of allocated memory
    static unsigned int s_allocated_block;  ///< The current amount of allocated blocks
    static unsigned int s_allocation_count; ///< The total amount of allocations
};

} // !namespace

} // !namespace

#endif // !ORDINAL_ENGINE_C_MEMORY_TRACKER_HPP__