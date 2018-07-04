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

/// \file       TVec1.hpp
/// \date       04/07/2018
/// \project    Ordinal Engine
/// \package    Runtime/Core/Maths/Vector
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_T_VEC_1_HPP__
#define ORDINAL_ENGINE_T_VEC_1_HPP__

#include "Runtime/Core/Maths/Vector/TVec.hpp"

/// \namespace Ord
namespace Ord
{

/// \namespace Core
namespace Core
{

/// \brief  1D vector partial specialization
/// \class  TVec
/// \tparam N The number of component 1
/// \tparam Tp The type of the components
template<typename Tp>
class TVec<1, Tp>
{
public:

    using value_type      = Tp;
    using pointer         = Tp*;
    using reference       = Tp&;
    using const_pointer   = const Tp*;
    using const_reference = const Tp&;

public:

    /// \brief  Default constructor
    ORDINAL_CONSTEXPR inline ORDINAL_EXPLICIT TVec() ORDINAL_NOEXCEPT;

    /// \brief  Constructs a vector with only 1 component
    /// \param  X The x component
    ORDINAL_CONSTEXPR inline ORDINAL_EXPLICIT TVec(const value_type X) ORDINAL_NOEXCEPT;

    /// \brief  Constructs a vector from another of the same type
    /// \param  vector The vector to copy
    ORDINAL_CONSTEXPR inline TVec(const TVec<1, Tp>& vector) ORDINAL_NOEXCEPT;

    /// \brief  Constructs a 1D vector from another one of different type
    /// \param  vector The vector to copy
    template <typename U>
    ORDINAL_CONSTEXPR inline ORDINAL_EXPLICIT TVec(const TVec<1, U>& vector) ORDINAL_NOEXCEPT;

    /// \brief  Constructs a 1D vector from another one of different type
    /// \param  vector The vector to copy
    template <typename U>
    ORDINAL_CONSTEXPR inline ORDINAL_EXPLICIT TVec(const TVec<2, U>& vector) ORDINAL_NOEXCEPT;

    /// \brief  Constructs a 1D vector from another one of different type
    /// \param  vector The vector to copy
    template <typename U>
    ORDINAL_CONSTEXPR inline ORDINAL_EXPLICIT TVec(const TVec<3, U>& vector) ORDINAL_NOEXCEPT;

    /// \brief  Constructs a 1D vector from another one of different type
    /// \param  vector The vector to copy
    template <typename U>
    ORDINAL_CONSTEXPR inline ORDINAL_EXPLICIT TVec(const TVec<4, U>& vector) ORDINAL_NOEXCEPT;

    /// \brief  Default Destructor
    inline ~TVec() ORDINAL_NOEXCEPT ORDINAL_DEFAULT;

    /// \brief  Unary operator =
    /// \param  vector The vector to assign
    /// \return The updated vector
    ORDINAL_CXX14_CONSTEXPR inline TVec& operator=(const TVec<1, Tp>& vector) ORDINAL_NOEXCEPT ORDINAL_DEFAULT;

    /// \brief  Unary operator =
    /// \param  vector The vector to assign
    /// \return The updated vector
    template<typename U>
    ORDINAL_CXX14_CONSTEXPR inline TVec& operator=(const TVec<1, U>& vector) ORDINAL_NOEXCEPT;

    /// \brief  Unary operator +=
    /// \param  scalar The scalar to add
    /// \return The updated vector
    template<typename U>
    inline TVec& operator+=(const U scalar) ORDINAL_NOEXCEPT;

    /// \brief  Unary operator +=
    /// \param  vector The vector to add
    /// \return The updated vector
    template<typename U>
    inline TVec& operator+=(const TVec<1, U>& vector) ORDINAL_NOEXCEPT;

    /// \brief  Unary operator -=
    /// \param  scalar The scalar to subtract
    /// \return The updated vector
    template<typename U>
    inline TVec& operator-=(const U scalar) ORDINAL_NOEXCEPT;

    /// \brief  Unary operator -=
    /// \param  vector The vector to subtract
    /// \return The updated vector
    template<typename U>
    inline TVec& operator-=(const TVec<1, U>& vector) ORDINAL_NOEXCEPT;

    /// \brief  Unary operator *=
    /// \param  scalar The scalar to multiply with
    /// \return The updated vector
    template<typename U>
    inline TVec& operator*=(const U scalar) ORDINAL_NOEXCEPT;

    /// \brief  Unary operator *=
    /// \param  vector The vector to multiply with
    /// \return The updated vector
    template<typename U>
    inline TVec& operator*=(const TVec<1, U>& vector) ORDINAL_NOEXCEPT;

    /// \brief  Unary operator /=
    /// \param  scalar The scalar to divide with
    /// \return The updated vector
    template<typename U>
    inline TVec& operator/=(const U scalar) ORDINAL_NOEXCEPT;

    /// \brief  Unary operator *=
    /// \param  vector The vector to multiply with
    /// \return The updated vector
    template<typename U>
    inline TVec& operator/=(const TVec<1, U>& vector) ORDINAL_NOEXCEPT;

    /// \brief Increment operator++
    /// \return The updated vector
    inline TVec& operator++() ORDINAL_NOEXCEPT;

    /// \brief Increment operator--
    /// \return The updated vector
    inline TVec& operator--() ORDINAL_NOEXCEPT;

    /// \brief Increment operator++
    /// \return The updated vector
    inline TVec operator++(int) ORDINAL_NOEXCEPT;

    /// \brief Increment operator--
    /// \return The updated vector
    inline TVec operator--(int) ORDINAL_NOEXCEPT;

public:

    union
    {
        struct { value_type x; }; ///< The x component
        struct { value_type r; }; ///< The r component

        value_type v[1];     ///< The vector as an array
    };
};

/// \brief  Unary operator +
/// \param  vector The vector to transform
/// \return +vector
template<typename Tp>
inline TVec<1, Tp> operator+(const TVec<1, Tp>& vector) ORDINAL_NOEXCEPT;

/// \brief  Unary operator -
/// \param  vector The vector to negate
/// \return -vector
template<typename Tp>
inline TVec<1, Tp> operator-(const TVec<1, Tp>& vector) ORDINAL_NOEXCEPT;

/// \brief  Binary operator +
/// \param  vector The left hand side vector
/// \param  scalar The scalar to add
/// \return A new vector
template<typename Tp>
inline TVec<1, Tp> operator+(const TVec<1, Tp>& vector, const Tp scalar) ORDINAL_NOEXCEPT;

/// \brief  Binary operator +
/// \param  scalar The scalar to add
/// \param  vector The left hand side vector
/// \return A new vector (scalar + vector.x)
template<typename Tp>
inline TVec<1, Tp> operator+(const Tp scalar, const TVec<1, Tp>& vector) ORDINAL_NOEXCEPT;

/// \brief  Binary operator +
/// \param  lhs The left hand side vector
/// \param  rhs The right hand side vector
/// \return A new vector (lhs + rhs)
template<typename Tp>
inline TVec<1, Tp> operator+(const TVec<1, Tp>& lhs, const TVec<1, Tp>& rhs) ORDINAL_NOEXCEPT;

/// \brief  Binary operator -
/// \param  vector The left hand side vector
/// \param  scalar The scalar to subtract
/// \return A new vector (vector.x - scalar)
template<typename Tp>
inline TVec<1, Tp> operator-(const TVec<1, Tp>& vector, const Tp scalar) ORDINAL_NOEXCEPT;

/// \brief  Binary operator -
/// \param  scalar The scalar to subtract
/// \param  vector The left hand side vector
/// \return A new vector (scalar - vector.x)
template<typename Tp>
inline TVec<1, Tp> operator-(const Tp scalar, const TVec<1, Tp>& vector) ORDINAL_NOEXCEPT;

/// \brief  Binary operator -
/// \param  lhs The left hand side vector
/// \param  rhs The right hand side vector
/// \return A new vector (lhs.x - rhs.x)
template<typename Tp>
inline TVec<1, Tp> operator-(const TVec<1, Tp>& lhs, const TVec<1, Tp>& rhs) ORDINAL_NOEXCEPT;

/// \brief  Binary operator *
/// \param  vector The left hand side vector
/// \param  scalar The scalar to multiply with
/// \return A new vector (vector.x * scalar)
template<typename Tp>
inline TVec<1, Tp> operator*(const TVec<1, Tp>& vector, const Tp scalar) ORDINAL_NOEXCEPT;

/// \brief  Binary operator *
/// \param  scalar The scalar to multiply with
/// \param  vector The left hand side vector
/// \return A new vector (scalar * vector.x)
template<typename Tp>
inline TVec<1, Tp> operator*(const Tp scalar, const TVec<1, Tp>& vector) ORDINAL_NOEXCEPT;

/// \brief  Binary operator *
/// \param  lhs The left hand side vector
/// \param  rhs The right hand side vector
/// \return A new vector (lhs.x * rhs.x)
template<typename Tp>
inline TVec<1, Tp> operator*(const TVec<1, Tp>& lhs, const TVec<1, Tp>& rhs) ORDINAL_NOEXCEPT;

/// \brief  Binary operator /
/// \param  vector The left hand side vector
/// \param  scalar The scalar to divide with
/// \return A new vector (vector.x / scalar)
template<typename Tp>
inline TVec<1, Tp> operator/(const TVec<1, Tp>& vector, const Tp scalar) ORDINAL_NOEXCEPT;

/// \brief  Binary operator /
/// \param  scalar The scalar to divide with
/// \param  vector The left hand side vector
/// \return A new vector (scalar / vector.x)
template<typename Tp>
inline TVec<1, Tp> operator/(const Tp scalar, const TVec<1, Tp>& vector) ORDINAL_NOEXCEPT;

/// \brief  Binary operator /
/// \param  lhs The left hand side vector
/// \param  rhs The right hand side vector
/// \return A new vector (lhs.x / rhs.x)
template<typename Tp>
inline TVec<1, Tp> operator/(const TVec<1, Tp>& lhs, const TVec<1, Tp>& rhs) ORDINAL_NOEXCEPT;

/// \brief Tells if lhs and rhs are equal
/// \param lhs The left hand side member
/// \param rhs The right hand side member
/// \return True if lhs and rhs are equal, else false
template<typename Tp>
inline bool operator==(const TVec<1, Tp>& lhs, const TVec<1, Tp>& rhs) ORDINAL_NOEXCEPT;

/// \brief Tells if lhs and rhs are different
/// \param lhs The left hand side member
/// \param rhs The right hand side member
/// \return True if lhs and rhs are different, else false
template<typename Tp>
inline bool operator!=(const TVec<1, Tp>& lhs, const TVec<1, Tp>& rhs) ORDINAL_NOEXCEPT;

} // !namespace

} // !namespace

#include "Runtime/Core/Maths/Vector/Impl/TVec1_FPU.inl"

#endif // !ORDINAL_ENGINE_T_VEC_1_HPP__