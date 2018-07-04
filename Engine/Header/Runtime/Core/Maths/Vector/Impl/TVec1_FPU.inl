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

/// \file       TVec1_FPU.inl
/// \date       04/07/2018
/// \project    Ordinal Engine
/// \package    Runtime/Core/Maths/Vector/Impl
/// \author     Vincent STEHLY--CALISTO

/// \namespace Ord
namespace Ord
{

/// \namespace Core
namespace Core
{

/// \brief  Default constructor
template<typename Tp>
ORDINAL_CONSTEXPR /* ORDINAL_EXPLICIT */ TVec<1, Tp>::TVec() ORDINAL_NOEXCEPT
: x(0)
{
    // None
}

/// \brief  Constructs a vector with only 1 component
/// \param  X The x component
template<typename Tp>
ORDINAL_CONSTEXPR /* ORDINAL_EXPLICIT */ TVec<1, Tp>::TVec(const value_type X) ORDINAL_NOEXCEPT
: x(X)
{
    // None
}

/// \brief  Constructs a vector from another of the same type
/// \param  vector The vector to copy
template<typename Tp>
ORDINAL_CONSTEXPR TVec<1, Tp>::TVec(const TVec<1, Tp>& vector) ORDINAL_NOEXCEPT
: x(vector.x)
{
    // None
}

/// \brief  Constructs a 1D vector from another one of different type
/// \param  vector The vector to copy
template<typename Tp>
template<typename U>
ORDINAL_CONSTEXPR /* ORDINAL_EXPLICIT */ TVec<1, Tp>::TVec(const TVec<2, U>& vector) ORDINAL_NOEXCEPT
: x(static_cast<Tp>(vector.x))
{
    // None
}

/// \brief  Constructs a 1D vector from another one of different type
/// \param  vector The vector to copy
template<typename Tp>
template<typename U>
ORDINAL_CONSTEXPR /* ORDINAL_EXPLICIT */ TVec<1, Tp>::TVec(const TVec<3, U>& vector) ORDINAL_NOEXCEPT
: x(static_cast<Tp>(vector.x))
{
    // None
}

/// \brief  Constructs a 1D vector from another one of different type
/// \param  vector The vector to copy
template<typename Tp>
template<typename U>
ORDINAL_CONSTEXPR /* ORDINAL_EXPLICIT */ TVec<1, Tp>::TVec(const TVec<4, U>& vector) ORDINAL_NOEXCEPT
: x(static_cast<Tp>(vector.x))
{
    // None
}

/// \brief  Unary operator +=
/// \param  scalar The scalar to add
/// \return The updated vector
template<typename Tp>
template<typename U>
/* inline */ TVec<1, Tp>& TVec<1, Tp>::operator+=(const U scalar) ORDINAL_NOEXCEPT
{
    x += static_cast<Tp>(scalar);
    return *this;
}

/// \brief  Unary operator +=
/// \param  vector The vector to add
/// \return The updated vector
template<typename Tp>
template<typename U>
/* inline */ TVec<1, Tp>& TVec<1, Tp>::operator+=(const TVec<1, U>& vector) ORDINAL_NOEXCEPT
{
    x += static_cast<Tp>(vector.x);
    return *this;
}

/// \brief  Unary operator -=
/// \param  scalar The scalar to subtract
/// \return The updated vector
template<typename Tp>
template<typename U>
/* inline */ TVec<1, Tp>& TVec<1, Tp>::operator-=(const U scalar) ORDINAL_NOEXCEPT
{
    x -= static_cast<Tp>(scalar);
    return *this;
}

/// \brief  Unary operator -=
/// \param  vector The vector to subtract
/// \return The updated vector
template<typename Tp>
template<typename U>
/* inline */ TVec<1, Tp>& TVec<1, Tp>::operator-=(const TVec<1, U>& vector) ORDINAL_NOEXCEPT
{
    x -= static_cast<Tp>(vector.x);
    return *this;
}

/// \brief  Unary operator *=
/// \param  scalar The scalar to multiply with
/// \return The updated vector
template<typename Tp>
template<typename U>
/* inline */ TVec<1, Tp>& TVec<1, Tp>::operator*=(const U scalar) ORDINAL_NOEXCEPT
{
    x *= static_cast<Tp>(scalar);
    return *this;
}

/// \brief  Unary operator *=
/// \param  vector The vector to multiply with
/// \return The updated vector
template<typename Tp>
template<typename U>
/* inline */ TVec<1, Tp>& TVec<1, Tp>::operator*=(const TVec<1, U>& vector) ORDINAL_NOEXCEPT
{
    x *= static_cast<Tp>(vector.x);
    return *this;
}

/// \brief  Unary operator /=
/// \param  scalar The scalar to divide with
/// \return The updated vector
template<typename Tp>
template<typename U>
/* inline */ TVec<1, Tp> &TVec<1, Tp>::operator/=(const U scalar) ORDINAL_NOEXCEPT
{
    // Pre-conditions
    ORD_ASSERT_NE_MSG(scalar, 0, "Division by 0.");

    x /= static_cast<Tp>(scalar);
    return *this;
}

/// \brief  Unary operator *=
/// \param  vector The vector to multiply with
/// \return The updated vector
template<typename Tp>
template<typename U>
/* inline */ TVec<1, Tp>& TVec<1, Tp>::operator/=(const TVec<1, U>& vector) ORDINAL_NOEXCEPT
{
    // Pre-conditions
    ORD_ASSERT_NE_MSG(vector.x, 0, "Division by 0.");

    x /= static_cast<Tp>(vector.x);
    return *this;
}

/// \brief Increment operator++
/// \return The updated vector
template<typename Tp>
/* inline */ TVec<1, Tp>& TVec<1, Tp>::operator++() ORDINAL_NOEXCEPT
{
    ++x;
    return *this;
}

/// \brief Increment operator--
/// \return The updated vector
template<typename Tp>
/* inline */ TVec<1, Tp>& TVec<1, Tp>::operator--() ORDINAL_NOEXCEPT
{
    --x;
    return *this;
}

/// \brief Increment operator++
/// \return The updated vector
template<typename Tp>
/* inline */ TVec<1, Tp> TVec<1, Tp>::operator++(int) ORDINAL_NOEXCEPT
{
    TVec<1, Tp> result(*this);
    ++*this;
    return result;
}

/// \brief Increment operator--
/// \return The updated vector
template<typename Tp>
/* inline */ TVec<1, Tp> TVec<1, Tp>::operator--(int) ORDINAL_NOEXCEPT
{
    TVec<1, Tp> result(*this);
    --*this;
    return result;
}

/// \brief  Unary operator +
/// \param  vector The vector to transform
/// \return +vector
template<typename Tp>
/* inline */ TVec<1, Tp> operator+(const TVec<1, Tp>& vector) ORDINAL_NOEXCEPT
{
    return vector;
}

/// \brief  Unary operator -
/// \param  vector The vector to negate
/// \return -vector
template<typename Tp>
/* inline */ TVec<1, Tp> operator-(const TVec<1, Tp>& vector) ORDINAL_NOEXCEPT
{
    return TVec<1, Tp>(-vector.x);
}

/// \brief  Binary operator +
/// \param  vector The left hand side vector
/// \param  scalar The scalar to add
/// \return A new vector
template<typename Tp>
/* inline */ TVec<1, Tp> operator+(const TVec<1, Tp>& vector, const Tp scalar) ORDINAL_NOEXCEPT
{
    return TVec<1, Tp>(vector.x + scalar);
}

/// \brief  Binary operator +
/// \param  scalar The scalar to add
/// \param  vector The left hand side vector
/// \return A new vector (scalar + vector.x)
template<typename Tp>
/* inline */ TVec<1, Tp> operator+(const Tp scalar, const TVec<1, Tp> &vector) ORDINAL_NOEXCEPT
{
    return TVec<1, Tp>(scalar + vector.x);
}

/// \brief  Binary operator +
/// \param  lhs The left hand side vector
/// \param  rhs The right hand side vector
/// \return A new vector (lhs + rhs)
template<typename Tp>
/* inline */ TVec<1, Tp> operator+(const TVec<1, Tp>& lhs, const TVec<1, Tp>& rhs) ORDINAL_NOEXCEPT
{
    return TVec<1, Tp>(lhs.x + rhs.x);
}

/// \brief  Binary operator -
/// \param  vector The left hand side vector
/// \param  scalar The scalar to subtract
/// \return A new vector (vector.x - scalar)
template<typename Tp>
/* inline */ TVec<1, Tp> operator-(const TVec<1, Tp>& vector, const Tp scalar) ORDINAL_NOEXCEPT
{
    return TVec<1, Tp>(vector.x - scalar);
}

/// \brief  Binary operator -
/// \param  scalar The scalar to subtract
/// \param  vector The left hand side vector
/// \return A new vector (scalar - vector.x)
template<typename Tp>
/* inline */ TVec<1, Tp> operator-(const Tp scalar, const TVec<1, Tp> &vector) ORDINAL_NOEXCEPT
{
    return TVec<1, Tp>(scalar - vector.x);
}

/// \brief  Binary operator -
/// \param  lhs The left hand side vector
/// \param  rhs The right hand side vector
/// \return A new vector (lhs.x - rhs.x)
template<typename Tp>
/* inline */ TVec<1, Tp> operator-(const TVec<1, Tp>& lhs, const TVec<1, Tp>& rhs) ORDINAL_NOEXCEPT
{
    return TVec<1, Tp>(lhs.x - rhs.x);
}

/// \brief  Binary operator *
/// \param  vector The left hand side vector
/// \param  scalar The scalar to multiply with
/// \return A new vector (vector.x * scalar)
template<typename Tp>
/* inline */ TVec<1, Tp> operator*(const TVec<1, Tp>& vector, const Tp scalar) ORDINAL_NOEXCEPT
{
    return TVec<1, Tp>(vector.x * scalar);
}

/// \brief  Binary operator *
/// \param  scalar The scalar to multiply with
/// \param  vector The left hand side vector
/// \return A new vector (scalar * vector.x)
template<typename Tp>
/* inline */ TVec<1, Tp> operator*(const Tp scalar, const TVec<1, Tp>& vector) ORDINAL_NOEXCEPT
{
    return TVec<1, Tp>(scalar * vector.x);
}

/// \brief  Binary operator *
/// \param  lhs The left hand side vector
/// \param  rhs The right hand side vector
/// \return A new vector (lhs.x * rhs.x)
template<typename Tp>
/* inline */ TVec<1, Tp> operator*(const TVec<1, Tp>& lhs, const TVec<1, Tp>& rhs) ORDINAL_NOEXCEPT
{
    return TVec<1, Tp>(lhs.x * rhs.x);
}

/// \brief  Binary operator /
/// \param  vector The left hand side vector
/// \param  scalar The scalar to divide with
/// \return A new vector (vector.x / scalar)
template<typename Tp>
/* inline */ TVec<1, Tp> operator/(const TVec<1, Tp>& vector, const Tp scalar) ORDINAL_NOEXCEPT
{
    // Pre-conditions
    ORD_ASSERT_NE_MSG(scalar, 0, "Division by 0.");

    return TVec<1, Tp>(vector.x / scalar);
}

/// \brief  Binary operator /
/// \param  scalar The scalar to divide with
/// \param  vector The left hand side vector
/// \return A new vector (scalar / vector.x)
template<typename Tp>
/* inline */ TVec<1, Tp> operator/(const Tp scalar, const TVec<1, Tp>& vector) ORDINAL_NOEXCEPT
{
    // Pre-conditions
    ORD_ASSERT_NE_MSG(vector.x, 0, "Division by 0.");

    return TVec<1, Tp>(scalar / vector.x);
}

/// \brief  Binary operator /
/// \param  lhs The left hand side vector
/// \param  rhs The right hand side vector
/// \return A new vector (lhs.x / rhs.x)
template<typename Tp>
/* inline */ TVec<1, Tp> operator/(const TVec<1, Tp>& lhs, const TVec<1, Tp>& rhs) ORDINAL_NOEXCEPT
{
    // Pre-conditions
    ORD_ASSERT_NE_MSG(rhs.x, 0, "Division by 0.");

    return TVec<1, Tp>(lhs.x / rhs.x);
}

/// \brief Tells if lhs and rhs are equal
/// \param lhs The left hand side member
/// \param rhs The right hand side member
/// \return True if lhs and rhs are equal, else false
template<typename Tp>
/* inline */ bool operator==(const TVec<1, Tp>& lhs, const TVec<1, Tp>& rhs) ORDINAL_NOEXCEPT
{
    return (lhs.x == rhs.x);
}

/// \brief Tells if lhs and rhs are different
/// \param lhs The left hand side member
/// \param rhs The right hand side member
/// \return True if lhs and rhs are different, else false
template<typename Tp>
/* inline */ bool operator!=(const TVec<1, Tp> &lhs, const TVec<1, Tp> &rhs) ORDINAL_NOEXCEPT
{
    return !(lhs == rhs); // NOLINT
}

} // !namespace

} // !namespace