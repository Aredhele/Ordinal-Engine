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

#include "Runtime/Core/Assertion/Assert.hpp"
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
ORDINAL_CONSTEXPR
inline UInt32 MakeShuffleMask(
    const UInt8 A0, const UInt8 A1,
    const UInt8 B2, const UInt8 B3) ORDINAL_NOEXCEPT
{
    return ((A0) | ((A1) << 2) | ((B2) << 4) | ((B3) << 6));
}

/// \brief  Returns a vector filled with zeroes
/// \return {0.0f, 0.0f, 0.0f, 0.0f}
inline VectorRegister128 VectorZero128() ORDINAL_NOEXCEPT
{
    return _mm_setzero_ps();
}

/// \brief  Returns a vector filled with zeroes
/// \return {0, 0, 0, 0}
inline VectorRegister128Int VectorZero128Int() ORDINAL_NOEXCEPT
{
    return _mm_setzero_si128();
}

/// \brief  Returns a vector filled with zeroes
/// \return {0.0, 0.0}
inline VectorRegister128Double VectorZero128Double() ORDINAL_NOEXCEPT
{
    return _mm_setzero_pd();
}

/// \brief  Returns a vector initialized filled with 1
/// \return {1.0f, 1.0f, 1.0f, 1.0f}
inline VectorRegister128 VectorOne128() ORDINAL_NOEXCEPT
{
    return _mm_set1_ps(1.0f);
}

/// \brief  Returns a vector initialized filled with 1
/// \return {1, 1, 1, 1}
inline VectorRegister128Int VectorOne128Int() ORDINAL_NOEXCEPT
{
    return _mm_set1_epi32(1);
}

/// \brief  Returns a vector initialized filled with
/// \return {1.0, 1.0}
inline VectorRegister128Double VectorOne128Double() ORDINAL_NOEXCEPT
{
    return _mm_set1_pd(1.0);
}

/// \brief  Returns a 4 floats vector
/// \param  x The first  component
/// \param  y The second component
/// \param  z The third  component
/// \param  w The fourth component
/// \return A vector of 4 floats
inline VectorRegister128 MakeVectorRegister128(
    const float x, const float y,
    const float z, const float w) ORDINAL_NOEXCEPT
{
    return _mm_setr_ps(x, y, z, w);
}

/// \brief  Returns a 4 floats vector
///         Initializes w to 0
/// \param  x The first  component
/// \param  y The second component
/// \param  z The third  component
/// \return A vector of 4 floats
inline VectorRegister128 MakeVectorRegister128(
        const float x, const float y, const float z) ORDINAL_NOEXCEPT
{
    return _mm_setr_ps(x, y, z, 0.0f);
}

/// \brief  Returns a 4 I32 vector
/// \param  x The first  I32 component
/// \param  y The second I32 component
/// \param  z The third  I32 component
/// \param  w The fourth I32 component
/// \return A vector of 4 I32
inline VectorRegister128Int MakeVectorRegister128Int(
    const Int32 x, const Int32 y,
    const Int32 z, const Int32 w) ORDINAL_NOEXCEPT
{
    return _mm_setr_epi32(x, y, z, w);
}

/// \brief  Returns a 4 I32 vector
///         Initializes w to 0
/// \param  x The first  I32 component
/// \param  y The second I32 component
/// \param  z The third  I32 component
/// \return A vector of 4 I32
inline VectorRegister128Int MakeVectorRegister128Int(
        const Int32 x, const Int32 y, const Int32 z) ORDINAL_NOEXCEPT
{
    return _mm_setr_epi32(x, y, z, 0);
}

/// \brief  Returns a 2 doubles vector
/// \param  x The first  double component
/// \param  y The second double component
/// \return A vector of 2 doubles
inline VectorRegister128Double MakeVectorRegister128Double(
    const double x,
    const double y) ORDINAL_NOEXCEPT
{
    return _mm_set_pd(y, x);
}

/// \brief  Returns a 2 doubles vector
///         Initializes w to 0
/// \param  x The first  double component
/// \return A vector of 2 doubles
inline VectorRegister128Double MakeVectorRegister128Double(
    const double x) ORDINAL_NOEXCEPT
{
    return _mm_set_pd(0.0, x);
}

/// \brief  Loads 4 floats from unaligned memory
/// \param  vector Unaligned memory pointer to 4 floats
/// \return VectorRegister128(vector[0], vector[1], vector[2], vector[3])
inline  VectorRegister128 MakeVectorRegister128FromUnaligned4Floats(
    const float* vector) ORDINAL_NOEXCEPT
{
    return _mm_loadu_ps(vector);
}

/// \brief  Loads 4 ints from unaligned memory
/// \param  vector Unaligned memory pointer to 4 ints
/// \return VectorRegister128Int(vector[0], vector[1], vector[2], vector[3])
inline VectorRegister128Int MakeVectorRegister128IntFromUnaligned4Ints(
    const Int32* vector) ORDINAL_NOEXCEPT
{
    return MakeVectorRegister128Int(vector[0], vector[1], vector[2], vector[3]);
}

/// \brief  Loads 3 floats from unaligned memory
///         Sets the last float to 0.0f
/// \param  vector Unaligned memory pointer to 3 floats
/// \return VectorRegister128(vector[0], vector[1], vector[2], 0.0f)
inline VectorRegister128 MakeVectorRegister128FromUnaligned3Floats(
    const float* vector) ORDINAL_NOEXCEPT
{
    return MakeVectorRegister128(vector[0], vector[1], vector[2], 0.0f);
}

/// \brief  Loads 3 ints from unaligned memory
/// \param  vector Unaligned memory pointer to 3 ints
/// \return VectorRegister128Int(vector[0], vector[1], vector[2], 0.0)
inline VectorRegister128Int MakeVectorRegister128IntFromUnaligned3Ints(
    const Int32* vector) ORDINAL_NOEXCEPT
{
    return MakeVectorRegister128Int(vector[0], vector[1], vector[2], 0);
}

/// \brief  Loads 2 doubles from unaligned memory
/// \param  vector Unaligned memory pointer to 2 doubles
/// \return VectorRegister128Double(vector[0], vector[1])
inline VectorRegister128Double MakeVectorRegister128DoubleFromUnaligned2Doubles(
    const double* vector) ORDINAL_NOEXCEPT
{
    return _mm_loadu_pd(vector);
}

/// \brief  Returns the component at the given index
/// \param  vector The vector register
/// \param  ComponentIndex	Which component to get, X=0, Y=1, Z=2, W=3
/// \return The wanted component as a float
inline float GetVectorRegister128Component(
    const VectorRegister128 vector,
    const UInt32 index) ORDINAL_NOEXCEPT
{
    return ((float*)(&vector))[index];
}

/// \brief  Returns the component at the given index
/// \param  vector The vector register
/// \param  ComponentIndex	Which component to get, X=0, Y=1, Z=2, W=3
/// \return The wanted component as an int
inline Int32 GetVectorRegister128IntComponent(
    const VectorRegister128Int vector,
    const UInt32 index) ORDINAL_NOEXCEPT
{
    return ((Int32*)(&vector))[index];
}

/// \brief  Returns the component at the given index
/// \param  vector The vector register
/// \param  ComponentIndex	Which component to get, X=0, Y=1
/// \return The wanted component as a double
inline double GetVectorRegister128DoubleComponent(
    const VectorRegister128Double vector,
    const UInt32 index) ORDINAL_NOEXCEPT
{
    return ((double*)(&vector))[index];
}

/// \brief  Replicates the element at the given index
/// \param  vector The vector
/// \tparam Index The index (0-3)
/// \return VectorRegister(vector[index], vector[index], vector[index], vector[index])
template<UInt8 Index>
inline VectorRegister128 ReplicateVectorRegister128Component(
    const VectorRegister128 vector) ORDINAL_NOEXCEPT
{
    return _mm_shuffle_ps(vector, vector, _MM_SHUFFLE(
            Index, Index, Index, Index));
}

/// \brief  Replicates the element at the given index
/// \param  vector The vector
/// \tparam Index The index (0-3)
/// \return VectorRegister128Int(vector[index], vector[index], vector[index], vector[index])
template<UInt8 Index>
inline VectorRegister128Int ReplicateVector128IntComponent(
    const VectorRegister128Int vector) ORDINAL_NOEXCEPT
{
    return _mm_shuffle_epi32(vector, _MM_SHUFFLE(
            Index, Index, Index, Index));
}

/// \brief  Replicates the element at the given index
/// \param  vector The vector
/// \tparam Index The index (0-1)
/// \return VectorRegister128Double(vector[index], vector[index], vector[index], vector[index])
template<UInt8 Index>
inline VectorRegister128Double ReplicateVector128DoubleComponent(
    const VectorRegister128Double vector) ORDINAL_NOEXCEPT
{
    return _mm_shuffle_pd(vector, vector, _MM_SHUFFLE2(Index, Index));
}

/// \brief  Adds two vectors
/// \param  V1 The first  vector
/// \param  V2 The second vector
/// \return VectorRegister(V1.x + V2.x, V1.y + V2.y, V1.z + V2.z, V1.w + V2.w)
inline VectorRegister128 AddVectorRegister128(
    const VectorRegister128 a,
    const VectorRegister128 b) ORDINAL_NOEXCEPT
{
    return _mm_add_ps(a, b);
}

/// \brief  Adds two vectors
/// \param  V1 The first  vector
/// \param  V2 The second vector
/// \return VectorRegister(V1.x + V2.x, V1.y + V2.y, V1.z + V2.z, V1.w + V2.w)
inline VectorRegister128Int AddVectorRegister128Int(
    const VectorRegister128Int a,
    const VectorRegister128Int b) ORDINAL_NOEXCEPT
{
    return _mm_add_epi32(a, b);
}

/// \brief  Adds two vectors
/// \param  V1 The first  vector
/// \param  V2 The second vector
/// \return VectorRegister(V1.x + V2.x, V1.y + V2.y)
inline VectorRegister128Double AddVectorRegister128Double(
    const VectorRegister128Double a,
    const VectorRegister128Double b) ORDINAL_NOEXCEPT
{
    return _mm_add_pd(a, b);
}

/// \brief  Subtracts two vectors
/// \param  V1 The first  vector
/// \param  V2 The second vector
/// \return VectorRegister(V1.x - V2.x, V1.y - V2.y, V1.z - V2.z, V1.w - V2.w)
inline VectorRegister128 SubtractVectorRegister128(
    const VectorRegister128 a,
    const VectorRegister128 b) ORDINAL_NOEXCEPT
{
    return _mm_sub_ps(a, b);
}

/// \brief  Subtracts two vectors
/// \param  V1 The first  vector
/// \param  V2 The second vector
/// \return VectorRegister(V1.x - V2.x, V1.y - V2.y, V1.z - V2.z, V1.w - V2.w)
inline VectorRegister128Int SubtractVectorRegister128Int(
    const VectorRegister128Int a,
    const VectorRegister128Int b) ORDINAL_NOEXCEPT
{
    return _mm_sub_epi32(a, b);
}

/// \brief  Subtracts two vectors
/// \param  V1 The first  vector
/// \param  V2 The second vector
/// \return VectorRegister(V1.x - V2.x, V1.y - V2.y)
inline VectorRegister128Double SubtractVectorRegister128Double(
    const VectorRegister128Double a,
    const VectorRegister128Double b) ORDINAL_NOEXCEPT
{
    return _mm_sub_pd(a, b);
}

/// \brief  Multiplies two vectors
/// \param  V1 The first  vector
/// \param  V2 The second vector
/// \return VectorRegister(V1.x * V2.x, V1.y * V2.y, V1.z * V2.z, V1.w * V2.w)
inline VectorRegister128 MultiplyVectorRegister128(
    const VectorRegister128 a,
    const VectorRegister128 b) ORDINAL_NOEXCEPT
{
    return _mm_mul_ps(a, b);
}

/// \brief  Multiplies two vectors
/// \param  V1 The first  vector
/// \param  V2 The second vector
/// \return VectorRegister(V1.x * V2.x, V1.y * V2.y, V1.z * V2.z, V1.w * V2.w)
inline VectorRegister128Int MultiplyVectorRegister128Int(
    const VectorRegister128Int a,
    const VectorRegister128Int b) ORDINAL_NOEXCEPT
{
    __m128i tmp1 = _mm_mul_epu32(a, b);
    __m128i tmp2 = _mm_mul_epu32(_mm_srli_si128(a,4), _mm_srli_si128(b,4));
    return _mm_unpacklo_epi32(_mm_shuffle_epi32(tmp1, _MM_SHUFFLE(0, 0, 2, 0)),
                              _mm_shuffle_epi32(tmp2, _MM_SHUFFLE(0, 0, 2, 0)));
}

/// \brief  Multiplies two vectors
/// \param  V1 The first  vector
/// \param  V2 The second vector
/// \return VectorRegister(V1.x * V2.x, V1.y * V2.y)
inline VectorRegister128Double MultiplyVectorRegister128Double(
    const VectorRegister128Double a,
    const VectorRegister128Double b) ORDINAL_NOEXCEPT
{
    return _mm_mul_pd(a, b);
}

/// \brief  Stores a vector into an array of floats
/// \param  p_data The output
/// \param  vector The input
inline void StoreVectorRegister128Unaligned(float* p_data,
    const VectorRegister128 vector) ORDINAL_NOEXCEPT
{
    _mm_storeu_ps(p_data, vector);
}

/// \brief  Stores a vector into an array of ints
/// \param  p_data The output
/// \param  vector The input
inline void StoreVectorRegister128IntUnaligned(Int32* p_data,
    const VectorRegister128Int vector) ORDINAL_NOEXCEPT
{
    _mm_storeu_si128((__m128i_u*)p_data, vector);
}

/// \brief  Stores a vector into an array of floats
/// \param  p_data The output
/// \param  vector The input
inline void StoreVectorRegister128DoubleUnaligned(double* p_data,
    const VectorRegister128Double vector) ORDINAL_NOEXCEPT
{
    _mm_storeu_pd(p_data, vector);
}

} // !namespace

} // !namespace

#endif // !ORDINAL_ENGINE_VECTOR_SSE_2_HPP__