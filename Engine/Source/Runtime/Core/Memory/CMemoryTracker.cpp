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

/// \file       CMemoryTracker.cpp
/// \date       26/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Core/Memory
/// \author     Vincent STEHLY--CALISTO

#include <Runtime/Core/Assertion/Assert.hpp>
#include "Runtime/Core/Debug/SLogger.hpp"
#include "Runtime/Core/Memory/CMemoryTracker.hpp"

/// \namespace ord
namespace ord
{

/// \namespace core
namespace core
{

/* static */ bool                   CMemoryTracker::s_initialized      = false;
/* static */ CMemoryTracker::SBlock CMemoryTracker::s_block_list       = {};
/* static */ std::size_t            CMemoryTracker::s_allocated_size   = 0;
/* static */ unsigned int           CMemoryTracker::s_allocated_block  = 0;
/* static */ unsigned int           CMemoryTracker::s_allocation_count = 0;

/// \brief Destructor
CMemoryTracker::~CMemoryTracker()
{
    Release();
}

/// \brief Records a deallocation in the memory tracker
/// \param pointer The allocated block
/// \param is_array Tells if the allocation is an array allocation
/// \param p_caller_function The caller function
/// \param caller_line Thee caller line
/* static */ void core::CMemoryTracker::RecordAllocation(uint8_t* pointer, std::size_t size, bool is_array, const char* p_caller_function, unsigned int caller_line)
{
    ORD_ASSERT_GT      (size, 0);
    ORD_ASSERT_NOT_NULL(pointer);

    auto* p_block = reinterpret_cast<SBlock *>(pointer);

    // Filling block information
    p_block->block_token       = s_allocated_token;
    p_block->block_size        = size;
    p_block->p_prev_block      = s_block_list.p_prev_block;
    p_block->p_next_block      = &s_block_list;
    p_block->caller_line       = caller_line;
    p_block->p_caller_function = p_caller_function;

    // Updating the block list
    s_block_list.p_prev_block               = p_block;
    s_block_list.p_prev_block->p_next_block = p_block;

    // Updating stats
    s_allocated_size  += size;
    s_allocated_block ++;
    s_allocation_count++;
}

/// \brief Records an allocation in the memory tracker
/// \param { The allocated block
/// \param size The size of the allocated memory
/// \param is_array Tells if the allocation is an array allocation
/// \param p_caller_function The caller function
/// \param caller_line Thee caller line
/* static */ void core::CMemoryTracker::RecordDeallocation(uint8_t* pointer, bool is_array, const char* p_caller_function, unsigned int caller_line)
{
    ORD_ASSERT_NOT_NULL(pointer);

    auto* p_block = reinterpret_cast<SBlock *>(pointer);

    // Token validity check
    if (p_block->block_token != s_allocated_token)
    {
        if(p_block->block_token == s_freed_token)
        {
            SLogger::LogError("Double delete of pointer.");
        }
        else
        {
            SLogger::LogError("Delete of a dangling pointer.");
        }

        return;
    }

    // Deletion policy check
    if (p_block->is_array != is_array)
    {
        SLogger::LogWaring("Use delete[] after new[].");
    }

    // Updating list
    p_block->block_token = s_freed_token;
    p_block->p_prev_block->p_next_block = p_block->p_next_block;
    p_block->p_next_block->p_prev_block = p_block->p_prev_block;

    // Updating stats
    s_allocated_block--;
    s_allocated_size -= p_block->block_size;
}

/// \brief Initializes the memory tracker
void CMemoryTracker::Initialize()
{
    SLogger::LogInfo("Memory tracker initialization ...");

    if(s_initialized)
    {
        Release();
    }

    s_block_list.block_size        = 0;
    s_block_list.block_token       = 0;
    s_block_list.caller_line       = 0;
    s_block_list.is_array          = false;
    s_block_list.p_prev_block      = nullptr;
    s_block_list.p_next_block      = nullptr;
    s_block_list.p_caller_function = nullptr;

    s_initialized = true;
    SLogger::LogInfo("Memory tracker fully initialized.");
}

/// \brief Releases the memory tracker
void CMemoryTracker::Release()
{
    if(!s_initialized)
    {
        return;
    }

    if (s_allocated_block == 0)
    {
        SLogger::LogInfo("No memory leak detected in the %u recorded allocations", s_allocation_count);
    }
    else
    {
        SLogger::LogWaring("No memory leak detected");

        SBlock* p_block = s_block_list.p_next_block;
        while (p_block != &s_block_list)
        {

            SLogger::LogWaring("-- %p : %llu bytes allocated at unknown position.", static_cast<void *>(p_block + sizeof(SBlock)), p_block->block_size);

            void* pointer = p_block;
            p_block       = p_block->p_next_block;

            std::free(pointer);
        }

        SLogger::LogWaring("%llu bytes leaked (%u blocks).", s_allocated_size, s_allocated_block);
    }

    s_initialized = false;
}

} // !namespace

} // !namespace