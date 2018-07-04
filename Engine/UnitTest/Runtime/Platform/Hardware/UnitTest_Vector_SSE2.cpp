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
#include "Runtime/Platform/Hardware/Vector_SSE2.hpp"

using namespace Ord::Platform;

TEST(Vector_SSE2UnitTest, Vector_SSE2VectorZero128UnitTest)
{
    VectorRegister128 vector = VectorZero128();

    ASSERT_EQ(0.0f, GetVectorRegister128Component(vector, 0));
    ASSERT_EQ(0.0f, GetVectorRegister128Component(vector, 1));
    ASSERT_EQ(0.0f, GetVectorRegister128Component(vector, 2));
    ASSERT_EQ(0.0f, GetVectorRegister128Component(vector, 3));
}

TEST(Vector_SSE2UnitTest, Vector_SSE2VectorZero128IntUnitTest)
{
    VectorRegister128Int vector = VectorZero128Int();

    ASSERT_EQ(0, GetVectorRegister128IntComponent(vector, 0));
    ASSERT_EQ(0, GetVectorRegister128IntComponent(vector, 1));
    ASSERT_EQ(0, GetVectorRegister128IntComponent(vector, 2));
    ASSERT_EQ(0, GetVectorRegister128IntComponent(vector, 3));
}

TEST(Vector_SSE2UnitTest, Vector_SSE2VectorZero128DoubleUnitTest)
{
    VectorRegister128Double vector = VectorZero128Double();

    ASSERT_EQ(0.0, GetVectorRegister128DoubleComponent(vector, 0));
    ASSERT_EQ(0.0, GetVectorRegister128DoubleComponent(vector, 1));
}

TEST(Vector_SSE2UnitTest, Vector_SSE2VectorOne128UnitTest)
{
    VectorRegister128 vector = VectorOne128();

    ASSERT_EQ(1.0f, GetVectorRegister128Component(vector, 0));
    ASSERT_EQ(1.0f, GetVectorRegister128Component(vector, 1));
    ASSERT_EQ(1.0f, GetVectorRegister128Component(vector, 2));
    ASSERT_EQ(1.0f, GetVectorRegister128Component(vector, 3));
}

TEST(Vector_SSE2UnitTest, Vector_SSE2VectorOne128IntUnitTest)
{
    VectorRegister128Int vector = VectorOne128Int();

    ASSERT_EQ(1, GetVectorRegister128IntComponent(vector, 0));
    ASSERT_EQ(1, GetVectorRegister128IntComponent(vector, 1));
    ASSERT_EQ(1, GetVectorRegister128IntComponent(vector, 2));
    ASSERT_EQ(1, GetVectorRegister128IntComponent(vector, 3));
}

TEST(Vector_SSE2UnitTest, Vector_SSE2VectorOne128DoubleUnitTest)
{
    VectorRegister128Double vector = VectorOne128Double();

    ASSERT_EQ(1.0, GetVectorRegister128DoubleComponent(vector, 0));
    ASSERT_EQ(1.0, GetVectorRegister128DoubleComponent(vector, 1));
}

TEST(Vector_SSE2UnitTest, Vector_SSE2MakeVectorRegister128UnitTest)
{
    VectorRegister128 vector1 = MakeVectorRegister128(1.0f, 2.0f, 3.0f);
    VectorRegister128 vector2 = MakeVectorRegister128(1.0f, 2.0f, 3.0f, 4.0f);

    ASSERT_EQ(1.0f, GetVectorRegister128Component(vector1, 0));
    ASSERT_EQ(2.0f, GetVectorRegister128Component(vector1, 1));
    ASSERT_EQ(3.0f, GetVectorRegister128Component(vector1, 2));
    ASSERT_EQ(0.0f, GetVectorRegister128Component(vector1, 3));

    ASSERT_EQ(1.0f, GetVectorRegister128Component(vector2, 0));
    ASSERT_EQ(2.0f, GetVectorRegister128Component(vector2, 1));
    ASSERT_EQ(3.0f, GetVectorRegister128Component(vector2, 2));
    ASSERT_EQ(4.0f, GetVectorRegister128Component(vector2, 3));
}

TEST(Vector_SSE2UnitTest, Vector_SSE2MakeVectorRegister128IntUnitTest)
{
    VectorRegister128Int vector1 = MakeVectorRegister128Int(1, 2, 3);
    VectorRegister128Int vector2 = MakeVectorRegister128Int(1, 2, 3, 4);

    ASSERT_EQ(1, GetVectorRegister128IntComponent(vector1, 0));
    ASSERT_EQ(2, GetVectorRegister128IntComponent(vector1, 1));
    ASSERT_EQ(3, GetVectorRegister128IntComponent(vector1, 2));
    ASSERT_EQ(0, GetVectorRegister128IntComponent(vector1, 3));

    ASSERT_EQ(1, GetVectorRegister128IntComponent(vector2, 0));
    ASSERT_EQ(2, GetVectorRegister128IntComponent(vector2, 1));
    ASSERT_EQ(3, GetVectorRegister128IntComponent(vector2, 2));
    ASSERT_EQ(4, GetVectorRegister128IntComponent(vector2, 3));
}

TEST(Vector_SSE2UnitTest, Vector_SSE2MakeVectorRegister128DoubleUnitTest)
{
    VectorRegister128Double vector1 = MakeVectorRegister128Double(1.0);
    VectorRegister128Double vector2 = MakeVectorRegister128Double(1.0, 2.0);

    ASSERT_EQ(1.0, GetVectorRegister128DoubleComponent(vector1, 0));
    ASSERT_EQ(0.0, GetVectorRegister128DoubleComponent(vector1, 1));

    ASSERT_EQ(1.0, GetVectorRegister128DoubleComponent(vector2, 0));
    ASSERT_EQ(2.0, GetVectorRegister128DoubleComponent(vector2, 1));
}

TEST(Vector_SSE2UnitTest, Vector_SSE2MakeVectorRegister128FromUnalignedFloatsUnitTest)
{
    const float data[4] = {1.0f, 2.0f, 3.0f, 4.0f};

    VectorRegister128 vector1 = MakeVectorRegister128FromUnaligned3Floats(data);
    VectorRegister128 vector2 = MakeVectorRegister128FromUnaligned4Floats(data);

    ASSERT_EQ(1.0f, GetVectorRegister128Component(vector1, 0));
    ASSERT_EQ(2.0f, GetVectorRegister128Component(vector1, 1));
    ASSERT_EQ(3.0f, GetVectorRegister128Component(vector1, 2));
    ASSERT_EQ(0.0f, GetVectorRegister128Component(vector1, 3));

    ASSERT_EQ(1.0f, GetVectorRegister128Component(vector2, 0));
    ASSERT_EQ(2.0f, GetVectorRegister128Component(vector2, 1));
    ASSERT_EQ(3.0f, GetVectorRegister128Component(vector2, 2));
    ASSERT_EQ(4.0f, GetVectorRegister128Component(vector2, 3));
}

TEST(Vector_SSE2UnitTest, Vector_SSE2MakeVectorRegister128FromUnalignedIntsUnitTest)
{
    const Ord::Int32 data[4] = {1, 2, 3, 4};

    VectorRegister128Int vector1 = MakeVectorRegister128IntFromUnaligned3Ints(data);
    VectorRegister128Int vector2 = MakeVectorRegister128IntFromUnaligned4Ints(data);

    ASSERT_EQ(1, GetVectorRegister128IntComponent(vector1, 0));
    ASSERT_EQ(2, GetVectorRegister128IntComponent(vector1, 1));
    ASSERT_EQ(3, GetVectorRegister128IntComponent(vector1, 2));
    ASSERT_EQ(0, GetVectorRegister128IntComponent(vector1, 3));

    ASSERT_EQ(1, GetVectorRegister128IntComponent(vector2, 0));
    ASSERT_EQ(2, GetVectorRegister128IntComponent(vector2, 1));
    ASSERT_EQ(3, GetVectorRegister128IntComponent(vector2, 2));
    ASSERT_EQ(4, GetVectorRegister128IntComponent(vector2, 3));
}

TEST(Vector_SSE2UnitTest, Vector_SSE2MakeVectorRegister128FromUnalignedDoublesUnitTest)
{
    const double data[2] = {1.0, 2.0};
    VectorRegister128Double vector = MakeVectorRegister128DoubleFromUnaligned2Doubles(data);

    ASSERT_EQ(1.0, GetVectorRegister128DoubleComponent(vector, 0));
    ASSERT_EQ(2.0, GetVectorRegister128DoubleComponent(vector, 1));
}

TEST(Vector_SSE2UnitTest, Vector_SSE2GetVectorRegister128ComponentUnitTest)
{
    VectorRegister128 vector = MakeVectorRegister128(10.0f, -20.0f, -30.0f, 40.0f);

    ASSERT_EQ( 10.0f, GetVectorRegister128Component(vector, 0));
    ASSERT_EQ(-20.0f, GetVectorRegister128Component(vector, 1));
    ASSERT_EQ(-30.0f, GetVectorRegister128Component(vector, 2));
    ASSERT_EQ( 40.0f, GetVectorRegister128Component(vector, 3));
}

TEST(Vector_SSE2UnitTest, Vector_SSE2GetVectorRegister128IntComponentUnitTest)
{
    VectorRegister128Int vector = MakeVectorRegister128Int(10, -20, -30, 40);

    ASSERT_EQ( 10, GetVectorRegister128IntComponent(vector, 0));
    ASSERT_EQ(-20, GetVectorRegister128IntComponent(vector, 1));
    ASSERT_EQ(-30, GetVectorRegister128IntComponent(vector, 2));
    ASSERT_EQ( 40, GetVectorRegister128IntComponent(vector, 3));
}

TEST(Vector_SSE2UnitTest, Vector_SSE2GetVectorRegister128DoubleComponentUnitTest)
{
    VectorRegister128Double vector = MakeVectorRegister128Double(10.0, 32.0);

    ASSERT_EQ(10.0, GetVectorRegister128DoubleComponent(vector, 0));
    ASSERT_EQ(32.0, GetVectorRegister128DoubleComponent(vector, 1));
}

TEST(Vector_SSE2UnitTest, Vector_SSE2ReplicateVectorRegister128ComponentUnitTest)
{
    VectorRegister128 vector0 = MakeVectorRegister128(10.0f, 0.0f, 0.0f, 20.0f);
    VectorRegister128 vector1 = ReplicateVectorRegister128Component<0>(vector0);
    VectorRegister128 vector2 = ReplicateVectorRegister128Component<3>(vector0);

    ASSERT_EQ(10.0f, GetVectorRegister128Component(vector1, 0));
    ASSERT_EQ(10.0f, GetVectorRegister128Component(vector1, 1));
    ASSERT_EQ(10.0f, GetVectorRegister128Component(vector1, 2));
    ASSERT_EQ(10.0f, GetVectorRegister128Component(vector1, 3));

    ASSERT_EQ(20.0f, GetVectorRegister128Component(vector2, 0));
    ASSERT_EQ(20.0f, GetVectorRegister128Component(vector2, 1));
    ASSERT_EQ(20.0f, GetVectorRegister128Component(vector2, 2));
    ASSERT_EQ(20.0f, GetVectorRegister128Component(vector2, 3));
}

TEST(Vector_SSE2UnitTest, Vector_SSE2ReplicateVectorRegister128IntComponentUnitTest)
{
    VectorRegister128Int vector0 = MakeVectorRegister128Int(10, 0, 0, 20);
    VectorRegister128Int vector1 = ReplicateVector128IntComponent<0>(vector0);
    VectorRegister128Int vector2 = ReplicateVector128IntComponent<3>(vector0);

    ASSERT_EQ(10, GetVectorRegister128IntComponent(vector1, 0));
    ASSERT_EQ(10, GetVectorRegister128IntComponent(vector1, 1));
    ASSERT_EQ(10, GetVectorRegister128IntComponent(vector1, 2));
    ASSERT_EQ(10, GetVectorRegister128IntComponent(vector1, 3));

    ASSERT_EQ(20, GetVectorRegister128IntComponent(vector2, 0));
    ASSERT_EQ(20, GetVectorRegister128IntComponent(vector2, 1));
    ASSERT_EQ(20, GetVectorRegister128IntComponent(vector2, 2));
    ASSERT_EQ(20, GetVectorRegister128IntComponent(vector2, 3));
}

TEST(Vector_SSE2UnitTest, Vector_SSE2ReplicateVectorRegister128DoubleComponentUnitTest)
{
    VectorRegister128Double vector0 = MakeVectorRegister128Double(10.0, 20.0);
    VectorRegister128Double vector1 = ReplicateVector128DoubleComponent<0>(vector0);
    VectorRegister128Double vector2 = ReplicateVector128DoubleComponent<1>(vector0);

    ASSERT_EQ(10.0, GetVectorRegister128DoubleComponent(vector1, 0));
    ASSERT_EQ(10.0, GetVectorRegister128DoubleComponent(vector1, 1));

    ASSERT_EQ(20.0, GetVectorRegister128DoubleComponent(vector2, 0));
    ASSERT_EQ(20.0, GetVectorRegister128DoubleComponent(vector2, 1));
}

TEST(Vector_SSE2UnitTest, Vector_SSE2AddVectorRegister128UnitTest)
{
    float result[4] = {-1.0f};

    VectorRegister128 vector0 = MakeVectorRegister128(10.0f, 20.0f, 30.0f, 40.0f);
    VectorRegister128 vector1 = MakeVectorRegister128(40.0f, 30.0f, 20.0f, 10.0f);
    VectorRegister128 vector2 = AddVectorRegister128(vector0, vector1);

    StoreVectorRegister128Unaligned(result, vector2);

    ASSERT_EQ(50.0f, result[0]);
    ASSERT_EQ(50.0f, result[1]);
    ASSERT_EQ(50.0f, result[2]);
    ASSERT_EQ(50.0f, result[3]);
}

TEST(Vector_SSE2UnitTest, Vector_SSE2AddVectorRegister128IntUnitTest)
{
    Ord::Int32 result[4] = {-1};

    VectorRegister128Int vector0 = MakeVectorRegister128Int(10, 20, 30, 40);
    VectorRegister128Int vector1 = MakeVectorRegister128Int(40, 30, 20, 10);
    VectorRegister128Int vector2 = AddVectorRegister128Int(vector0, vector1);

    StoreVectorRegister128IntUnaligned(result, vector2);

    ASSERT_EQ(50, result[0]);
    ASSERT_EQ(50, result[1]);
    ASSERT_EQ(50, result[2]);
    ASSERT_EQ(50, result[3]);
}

TEST(Vector_SSE2UnitTest, Vector_SSE2AddVectorRegister128DoubleUnitTest)
{
    double result[2] = {-1.0};

    VectorRegister128Double vector0 = MakeVectorRegister128Double(10.0, 20.0);
    VectorRegister128Double vector1 = MakeVectorRegister128Double(40.0, 30.0);
    VectorRegister128Double vector2 = AddVectorRegister128Double(vector0, vector1);

    StoreVectorRegister128DoubleUnaligned(result, vector2);

    ASSERT_EQ(50.0, result[0]);
    ASSERT_EQ(50.0, result[1]);
}

TEST(Vector_SSE2UnitTest, Vector_SSE2SubtractVectorRegister128UnitTest)
{
    float result[4] = {-1.0f};

    VectorRegister128 vector0 = MakeVectorRegister128(10.0f, 20.0f, 30.0f, 40.0f);
    VectorRegister128 vector1 = MakeVectorRegister128(40.0f, 30.0f, 20.0f, 10.0f);
    VectorRegister128 vector2 = SubtractVectorRegister128(vector0, vector1);

    StoreVectorRegister128Unaligned(result, vector2);

    ASSERT_EQ(-30.0f, result[0]);
    ASSERT_EQ(-10.0f, result[1]);
    ASSERT_EQ( 10.0f, result[2]);
    ASSERT_EQ( 30.0f, result[3]);
}

TEST(Vector_SSE2UnitTest, Vector_SSE2SubtractVectorRegister128IntUnitTest)
{
    Ord::Int32 result[4] = {-1};

    VectorRegister128Int vector0 = MakeVectorRegister128Int(10, 20, 30, 40);
    VectorRegister128Int vector1 = MakeVectorRegister128Int(40, 30, 20, 10);
    VectorRegister128Int vector2 = SubtractVectorRegister128Int(vector0, vector1);

    StoreVectorRegister128IntUnaligned(result, vector2);

    ASSERT_EQ(-30, result[0]);
    ASSERT_EQ(-10, result[1]);
    ASSERT_EQ( 10, result[2]);
    ASSERT_EQ( 30, result[3]);
}

TEST(Vector_SSE2UnitTest, Vector_SSE2SubtractVectorRegister128DoubleUnitTest)
{
    double result[2] = {-1.0};

    VectorRegister128Double vector0 = MakeVectorRegister128Double(10.0, 20.0);
    VectorRegister128Double vector1 = MakeVectorRegister128Double(40.0, 30.0);
    VectorRegister128Double vector2 = SubtractVectorRegister128Double(vector0, vector1);

    StoreVectorRegister128DoubleUnaligned(result, vector2);

    ASSERT_EQ(-30.0, result[0]);
    ASSERT_EQ(-10.0, result[1]);
}




TEST(Vector_SSE2UnitTest, Vector_SSE2MultiplyVectorRegister128UnitTest)
{
    float result[4] = {-1.0f};

    VectorRegister128 vector0 = MakeVectorRegister128(10.0f, 20.0f, 30.0f, 40.0f);
    VectorRegister128 vector1 = MakeVectorRegister128(40.0f, 30.0f, 20.0f, 10.0f);
    VectorRegister128 vector2 = MultiplyVectorRegister128(vector0, vector1);

    StoreVectorRegister128Unaligned(result, vector2);

    ASSERT_EQ(400.0f, result[0]);
    ASSERT_EQ(600.0f, result[1]);
    ASSERT_EQ(600.0f, result[2]);
    ASSERT_EQ(400.0f, result[3]);
}

TEST(Vector_SSE2UnitTest, Vector_SSE22MultiplyVectorRegister128IntUnitTest)
{
    Ord::Int32 result[4] = {-1};

    VectorRegister128Int vector0 = MakeVectorRegister128Int(10, 20, 30, 40);
    VectorRegister128Int vector1 = MakeVectorRegister128Int(40, 30, 20, 10);
    VectorRegister128Int vector2 = MultiplyVectorRegister128Int(vector0, vector1);

    StoreVectorRegister128IntUnaligned(result, vector2);

    ASSERT_EQ(400, result[0]);
    ASSERT_EQ(600, result[1]);
    ASSERT_EQ(600, result[2]);
    ASSERT_EQ(400, result[3]);
}

TEST(Vector_SSE2UnitTest, Vector_SSE22MultiplyVectorRegister128DoubleUnitTest)
{
    double result[2] = {-1.0};

    VectorRegister128Double vector0 = MakeVectorRegister128Double(10.0, 20.0);
    VectorRegister128Double vector1 = MakeVectorRegister128Double(40.0, 30.0);
    VectorRegister128Double vector2 = MultiplyVectorRegister128Double(vector0, vector1);

    StoreVectorRegister128DoubleUnaligned(result, vector2);

    ASSERT_EQ(400.0, result[0]);
    ASSERT_EQ(600.0, result[1]);
}