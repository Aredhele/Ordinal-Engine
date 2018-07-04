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

/// \file       Vector_SSE2.hpp
/// \date       04/07/2018
/// \project    Ordinal Engine
/// \package    Runtime/Platform/Hardware
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_VECTOR_SSE_2_HPP__
#define ORDINAL_ENGINE_VECTOR_SSE_2_HPP__

#include "Runtime/Core/Assertion/Assert.hh"
#include "Runtime/Platform/Hardware/Configuration.hpp"

/// \namespace Ord
namespace Ord
{

/// \namespace Platform
namespace Platform
{

using VectorRegister128       = __m128;  ///< A vector based on 4 floats
using VectorRegister128Int    = __m128i; ///< A vector based on 4 ints
using VectorRegister128Double = __m128d; ///< A vector based on 2 doubles

/// \brief  Shuffles vector index
/// \param  A0 Selects the A0 element into the first vector
/// \param  A1 Selects the A1 element into the first vector
/// \param  B2 Selects the B2 element into the second vector
/// \param  B3 Selects the B3 element into the second vector
/// \return The mask to shuffle the vector
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
UInt32 MakeShuffleMask(const UInt8 A0, const UInt8 A1, const UInt8 B2, const UInt8 B3) ORDINAL_NOEXCEPT
{
    return ((A0) | ((A1) << 2) | ((B2) << 4) | ((B3) << 6));
}

/// \brief  Returns a 4 floats vector
/// \param  x The first  component
/// \param  y The second component
/// \param  z The third  component
/// \param  w The fourth component
/// \return A vector of 4 floats
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
VectorRegister128 MakeVectorRegister128(const float x, const float y, const float z, const float w) ORDINAL_NOEXCEPT
{
    return _mm_setr_ps(x, y, z, w);
}

/// \brief  Returns a 4 I32 vector
/// \param  x The first  I32 component
/// \param  y The second I32 component
/// \param  z The third  I32 component
/// \param  w The fourth I32 component
/// \return A vector of 4 I32
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
VectorRegister128Int MakeVectorRegister128Int(const Int32 x, const Int32 y, const Int32 z, const Int32 w) ORDINAL_NOEXCEPT
{
    return _mm_setr_epi32(x, y, z, w);
}

/// \brief  Returns a 2 doubles vector
/// \param  x The first  double component
/// \param  y The second double component
/// \return A vector of 2 double
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
VectorRegister128Double MakeVectorRegister128Double(const double x, const double y) ORDINAL_NOEXCEPT
{
    return _mm_set_pd(x, y);
}

/// \brief  Returns a vector initialized to 0
/// \return {0.0f, 0.0f, 0.0f, 0.0f}
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
VectorRegister128 VectorZero() ORDINAL_NOEXCEPT
{
    return _mm_setzero_ps();
}

/// \brief  Returns a vector initialized to 0
/// \return {0, 0, 0, 0}
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
VectorRegister128Int VectorZeroInt() ORDINAL_NOEXCEPT
{
    return _mm_setzero_si128();
}

/// \brief  Returns a vector initialized to 0
/// \return {0.0, 0.0}
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
VectorRegister128Double VectorZeroDouble() ORDINAL_NOEXCEPT
{
    return _mm_setzero_pd();
}

/// \brief  Returns a vector initialized to 1
/// \return {1.0f, 1.0f, 1.0f, 1.0f}
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
VectorRegister128 VectorOne() ORDINAL_NOEXCEPT
{
    return _mm_set1_ps(1.0f);
}

/// \brief  Returns a vector initialized to 1
/// \return {1, 1, 1, 1}
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
VectorRegister128Int VectorOneInt() ORDINAL_NOEXCEPT
{
    return _mm_set1_epi32(1);
}

/// \brief  Returns a vector initialized to 1
/// \return {1.0, 1.0}
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
VectorRegister128Double VectorOneDouble() ORDINAL_NOEXCEPT
{
    return _mm_set1_pd(1.0);
}

/// \brief  Returns the component at the given index
/// \param  vector The vector register
/// \param  ComponentIndex	Which component to get, X=0, Y=1, Z=2, W=3
/// \return The wanted component as a float
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
float GetVector128Component(const VectorRegister128 vector, UInt32 index) ORDINAL_NOEXCEPT
{
    ORD_ASSERT_TRUE(index >= 0);
    ORD_ASSERT_TRUE(index <= 3);

    return (static_cast<float*>(&vector))[index];
}

/// \brief  Returns the component at the given index
/// \param  vector The vector register
/// \param  ComponentIndex	Which component to get, X=0, Y=1, Z=2, W=3
/// \return The wanted component as an int
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
Int32 GetVector128IntComponent(const VectorRegister128Int vector, UInt32 index) ORDINAL_NOEXCEPT
{
    ORD_ASSERT_TRUE(index >= 0);
    ORD_ASSERT_TRUE(index <= 3);

    return (static_cast<Int32*>(&vector))[index];
}

/// \brief  Returns the component at the given index
/// \param  vector The vector register
/// \param  ComponentIndex	Which component to get, X=0, Y=1
/// \return The wanted component as a double
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
double GetVector128DoubleComponent(const VectorRegister128Double vector, UInt32 index) ORDINAL_NOEXCEPT
{
    ORD_ASSERT_TRUE(index >= 0);
    ORD_ASSERT_TRUE(index <= 1);

    return (static_cast<double*>(&vector))[index];
}

/// \brief  Loads 4 floats from unaligned memory
/// \param  vector Unaligned memory pointer to 4 floats
/// \return VectorRegister128(vector[0], vector[1], vector[2], vector[3])
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
VectorRegister128 LoadUnalignedFloat4(const float* vector) ORDINAL_NOEXCEPT
{
    ORD_ASSERT_NOT_NULL(vector);

    return _mm_loadu_ps(vector);
}

/// \brief  Loads 3 floats from unaligned memory
///         Sets the last float to 0.0f
/// \param  vector Unaligned memory pointer to 3 floats
/// \return VectorRegister128(vector[0], vector[1], vector[2], 0.0f)
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
VectorRegister128 LoadUnalignedFloat3(const float* vector) ORDINAL_NOEXCEPT
{
    ORD_ASSERT_NOT_NULL(vector);

    return MakeVectorRegister128(vector[0], vector[1], vector[2], 0.0f);
}

/// \brief  Loads 4 ints from unaligned memory
/// \param  vector Unaligned memory pointer to 4 ints
/// \return VectorRegister128Int(vector[0], vector[1], vector[2], vector[3])
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
VectorRegister128Int LoadUnalignedInt4(const Int32* vector) ORDINAL_NOEXCEPT
{
    ORD_ASSERT_NOT_NULL(vector);

    return MakeVectorRegister128Int(vector[0], vector[1], vector[2], vector[3]);
}

/// \brief  Loads 3 ints from unaligned memory
/// \param  vector Unaligned memory pointer to 3 ints
/// \return VectorRegister128Int(vector[0], vector[1], vector[2], 0.0)
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
VectorRegister128Int LoadUnalignedInt3(const Int32* vector) ORDINAL_NOEXCEPT
{
    ORD_ASSERT_NOT_NULL(vector);

    return MakeVectorRegister128Int(vector[0], vector[1], vector[2], 0);
}

/// \brief  Loads 2 doubles from unaligned memory
/// \param  vector Unaligned memory pointer to 2 doubles
/// \return VectorRegister128Double(vector[0], vector[1])
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
VectorRegister128Double LoadUnalignedDouble(const double* vector) ORDINAL_NOEXCEPT
{
    ORD_ASSERT_NOT_NULL(vector);

    return _mm_loadu_pd(vector);
}

/// \brief  Makes a vector from 4 floats
/// \param  X The first  component
/// \param  Y The second component
/// \param  Z The third  component
/// \param  W The fourth component
/// \return VectorRegister128(X, Y, Z, W)
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
VectorRegister128 Set(const float x, const float y, const float z, const float w) ORDINAL_NOEXCEPT
{
    return MakeVectorRegister128(x, y, z, w);
}

/// \brief  Makes a vector from 3 floats, sets w to 0
/// \param  X The first  component
/// \param  Y The second component
/// \param  Z The third  component
/// \return VectorRegister128(X, Y, Z, 0.0f)
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
VectorRegister128 Set(const float x, const float y, const float z) ORDINAL_NOEXCEPT
{
    return MakeVectorRegister128(x, y, z, 0.0f);
}

/// \brief  Makes a vector from 4 ints
/// \param  X The first  component
/// \param  Y The second component
/// \param  Z The third  component
/// \param  W The fourth component
/// \return VectorRegister128Int(X, Y, Z, W)
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
VectorRegister128Int Set(const Int32 x, const Int32 y, const Int32 z, const Int32 w) ORDINAL_NOEXCEPT
{
    return MakeVectorRegister128Int(x, y, z, w);
}

/// \brief  Makes a vector from 3 ints, sets w to 0
/// \param  X The first  component
/// \param  Y The second component
/// \param  Z The third  component
/// \return VectorRegister128Int(X, Y, Z, 0)
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
VectorRegister128Int Set(const Int32 x, const Int32 y, const Int32 z) ORDINAL_NOEXCEPT
{
    return MakeVectorRegister128Int(x, y, z, 0);
}

/// \brief  Makes a vector from 2 doubles
/// \param  X The first  component
/// \param  Y The second component
/// \return VectorRegister128Double(X, Y)
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
VectorRegister128Double Set(const double x, const double y) ORDINAL_NOEXCEPT
{
    return MakeVectorRegister128Double(x, y);
}

/// \brief  Duplicates the given element index of the vector and returns it in a new vector
/// \param  vector The vector
/// \param  INDEX The index (0-3)
/// \return VectorRegister(VECTOR[INDEX], VECTOR[INDEX], VECTOR[INDEX], VECTOR[INDEX])
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
VectorRegister128 ReplicateVector128Component(const VectorRegister128 vector, const UInt8 index) ORDINAL_NOEXCEPT
{
    return _mm_shuffle_ps(vector, vector, MakeShuffleMask(index, index, index, index));
}

/// \brief  Duplicates the given element index of the vector and returns it in a new vector
/// \param  vector The vector
/// \param  INDEX The index (0-3)
/// \return VectorRegister128Int(VECTOR[INDEX], VECTOR[INDEX], VECTOR[INDEX], VECTOR[INDEX])
ORDINAL_CONSTEXPR ORDINAL_FORCE_INLINE
VectorRegister128Int ReplicateVector128IntComponent(const VectorRegister128Int vector, const UInt8 index) ORDINAL_NOEXCEPT
{
    // TODO
}






























/// \brief  Adds two vectors
/// \param  V1 The first  vector
/// \param  V2 The second vector
/// \return VectorRegister(V1.x + V2.x, V1.y + V2.y, V1.z + V2.z, V1.w + V2.w)
#define VectorAdd(V1, V2) _mm_add_ps(V1, V2)

/// \brief  Subtracts two vectors
/// \param  V1 The first  vector
/// \param  V2 The second vector
/// \return VectorRegister(V1.x - V2.x, V1.y - V2.y, V1.z - V2.z, V1.w - V2.w)
#define VectorSubtract(V1, V2) _mm_sub_ps(V1, V2)

/// \brief  Multiplies two vectors
/// \param  V1 The first  vector
/// \param  V2 The second vector
/// \return VectorRegister(V1.x * V2.x, V1.y * V2.y, V1.z * V2.z, V1.w * V2.w)
#define VectorMultiply(V1, V2) _mm_mul_ps(V1, V2)

/// \brief  Multiplies two vectors and adds the result to the third vector
/// \param  Vec1 The first vector
/// \param  Vec2 The second vector
/// \param  Vec3 The third vector
/// \return VectorRegister(V1.x * V2.x + V3.x, V1.y * V2.y + V3.y, V1.z * V2.z + V3.z, V1.w * V2.w + V3.w)
#define VectorMultiplyAdd(V1, V2, V3) _mm_add_ps(_mm_mul_ps(V1, V2), V3)


} // !namespace

} // !namespace

#endif // !ORDINAL_ENGINE_VECTOR_SSE_2_HPP__