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

/// \file       UnitTest_CStackAllocator.hpp
/// \date       26/06/2018
/// \project    Ordinal Engine
/// \package    UnitTest/Runtime/Core/Memory
/// \author     Vincent STEHLY--CALISTO

#include <gtest/gtest.h>
#include "Runtime/Core/Memory/Allocator/CStackAllocator.hpp"

using namespace ord::core;

TEST(CStackAllocatorUnitTest, CStackAllocatorConstructorUnitTest)
{
    CStackAllocator stack_allocator;

    ASSERT_EQ(0, stack_allocator.GetHead());
    ASSERT_EQ(0, stack_allocator.GetSize());
    ASSERT_EQ(nullptr, stack_allocator.GetData());
}

TEST(CStackAllocatorUnitTest, CStackAllocatorSmallInitializeUnitTest)
{
    CStackAllocator stack_allocator;
    stack_allocator.Initialize(1024);

    ASSERT_EQ(0,       stack_allocator.GetHead());
    ASSERT_EQ(1024,    stack_allocator.GetSize());
    ASSERT_NE(nullptr, stack_allocator.GetData());

    stack_allocator.Release();
}

TEST(CStackAllocatorUnitTest, CStackAllocatorMediumInitializeUnitTest)
{
    CStackAllocator stack_allocator;
    stack_allocator.Initialize(1024 * 1024);

    ASSERT_EQ(0,           stack_allocator.GetHead());
    ASSERT_EQ(1024 * 1024, stack_allocator.GetSize());
    ASSERT_NE(nullptr,     stack_allocator.GetData());

    stack_allocator.Release();
}

TEST(CStackAllocatorUnitTest, CStackAllocatorBigInitializeUnitTest)
{
    CStackAllocator stack_allocator;
    stack_allocator.Initialize(1024 * 1024 * 32);

    ASSERT_EQ(0,                stack_allocator.GetHead());
    ASSERT_EQ(1024 * 1024 * 32, stack_allocator.GetSize());
    ASSERT_NE(nullptr,          stack_allocator.GetData());

    stack_allocator.Release();
}

TEST(CStackAllocatorUnitTest, CStackAllocatorTooBigInitializeUnitTest)
{
    CStackAllocator stack_allocator;
    ASSERT_THROW(stack_allocator.Initialize(1024 * 1024 * 1024), std::bad_alloc);

    ASSERT_EQ(0,       stack_allocator.GetHead());
    ASSERT_EQ(0,       stack_allocator.GetSize());
    ASSERT_EQ(nullptr, stack_allocator.GetData());

    stack_allocator.Release();
}

TEST(CStackAllocatorUnitTest, CStackAllocatorTooSmallInitializeUnitTest)
{
    CStackAllocator stack_allocator;
    ASSERT_THROW(stack_allocator.Initialize(0), std::bad_alloc);

    ASSERT_EQ(0,       stack_allocator.GetHead());
    ASSERT_EQ(0,       stack_allocator.GetSize());
    ASSERT_EQ(nullptr, stack_allocator.GetData());

    stack_allocator.Release();
}

TEST(CStackAllocatorUnitTest, CStackAllocatorReleaseInitializeUnitTest)
{
    CStackAllocator stack_allocator;
    stack_allocator.Release();

    ASSERT_EQ(0,       stack_allocator.GetHead());
    ASSERT_EQ(0,       stack_allocator.GetSize());
    ASSERT_EQ(nullptr, stack_allocator.GetData());
}

TEST(CStackAllocatorUnitTest, CStackAllocatorReleaseNoInitializeUnitTest)
{
    CStackAllocator stack_allocator;

    stack_allocator.Initialize(1024);
    stack_allocator.Release();

    ASSERT_EQ(0,       stack_allocator.GetHead());
    ASSERT_EQ(0,       stack_allocator.GetSize());
    ASSERT_EQ(nullptr, stack_allocator.GetData());
}

TEST(CStackAllocatorUnitTest, CStackAllocatorClearInitializeUnitTest)
{
    CStackAllocator stack_allocator;

    stack_allocator.Initialize(1024);
    stack_allocator.Clear();

    ASSERT_EQ(0, stack_allocator.GetHead());

    stack_allocator.Release();
}

TEST(CStackAllocatorUnitTest, CStackAllocatorClearNoInitializeUnitTest)
{
    CStackAllocator stack_allocator;
    stack_allocator.Clear();

    ASSERT_EQ(0, stack_allocator.GetHead());
}

TEST(CStackAllocatorUnitTest, CStackAllocatorClearHeadMovedUnitTest)
{
    CStackAllocator stack_allocator;

    stack_allocator.Initialize(1024);
    stack_allocator.Allocate  (512);
    stack_allocator.Clear();

    ASSERT_EQ(0, stack_allocator.GetHead());

    stack_allocator.Release();
}

TEST(CStackAllocatorUnitTest, CStackAllocatorAllocateUnitTest)
{
    CStackAllocator stack_allocator;
    stack_allocator.Initialize(1024);

    void * pointer = nullptr;
    ASSERT_NO_THROW(pointer = stack_allocator.Allocate(64));

    ASSERT_NE  (nullptr, pointer);
    ASSERT_EQ  (pointer, stack_allocator.GetData() + stack_allocator.GetHead() - 64);
    ASSERT_EQ  (64,      stack_allocator.GetHead());
    ASSERT_EQ  (1024,    stack_allocator.GetSize());
    ASSERT_NE  (nullptr, stack_allocator.GetData());

    stack_allocator.Release();
}

TEST(CStackAllocatorUnitTest, CStackAllocatorAllocateNoInitializeUnitTest)
{
    CStackAllocator stack_allocator;

    ASSERT_THROW(stack_allocator.Allocate(512), std::bad_alloc);
    ASSERT_EQ   (0,       stack_allocator.GetHead());
    ASSERT_EQ   (0,       stack_allocator.GetSize());
    ASSERT_EQ   (nullptr, stack_allocator.GetData());
}

TEST(CStackAllocatorUnitTest, CStackAllocatorAllocateTooSmallUnitTest)
{
    CStackAllocator stack_allocator;
    stack_allocator.Initialize(1024);

    ASSERT_THROW(stack_allocator.Allocate(0), std::bad_alloc);
    ASSERT_EQ   (0,       stack_allocator.GetHead());
    ASSERT_EQ   (1024,    stack_allocator.GetSize());
    ASSERT_NE   (nullptr, stack_allocator.GetData());

    stack_allocator.Release();
}

TEST(CStackAllocatorUnitTest, CStackAllocatorAllocateTooBigUnitTest)
{
    CStackAllocator stack_allocator;
    stack_allocator.Initialize(1024);

    ASSERT_THROW(stack_allocator.Allocate(2048), std::bad_alloc);
    ASSERT_EQ   (0,       stack_allocator.GetHead());
    ASSERT_EQ   (1024,    stack_allocator.GetSize());
    ASSERT_NE   (nullptr, stack_allocator.GetData());

    stack_allocator.Release();
}

TEST(CStackAllocatorUnitTest, CStackAllocatorGetSizeUnitTest)
{
    CStackAllocator stack_allocator;
    stack_allocator.Initialize(1024);

    ASSERT_EQ(1024, stack_allocator.GetSize());

    stack_allocator.Release();
}

TEST(CStackAllocatorUnitTest, CStackAllocatorGetDataUnitTest)
{
    CStackAllocator stack_allocator;
    stack_allocator.Initialize(1024);

    ASSERT_NE(nullptr, stack_allocator.GetData());

    stack_allocator.Release();
}

TEST(CStackAllocatorUnitTest, CStackAllocatorGetHeadUnitTest)
{
    CStackAllocator stack_allocator;
    stack_allocator.Initialize(1024);

    ASSERT_EQ(0,   stack_allocator.GetHead());
    stack_allocator.Allocate(64);
    ASSERT_EQ(64,  stack_allocator.GetHead());
    stack_allocator.Allocate(64);
    ASSERT_EQ(128, stack_allocator.GetHead());
    stack_allocator.Clear();
    ASSERT_EQ(0,   stack_allocator.GetHead());

    stack_allocator.Release();
}