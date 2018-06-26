/// Copyright (C) 2018-2019, Ordinal Engine
/// Vincent STEHLY--CALISTO, vincentstehly@hotmail.fr
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

/// \file       StringHash.hpp
/// \date       21/06/2018
/// \project    Ordinal Engine
/// \package    Runtime/Core/StringHash
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_STRING_HASH_HPP__
#define ORDINAL_ENGINE_STRING_HASH_HPP__

#include <cstdint>

/// \namespace ord
namespace ord
{

/// \namespace  impl
namespace impl
{

constexpr const int8_t   STRING_END_BYTE = 0;
constexpr const uint32_t STRING_BIT_SHIT = 5;

/// \brief   Magic number from string hash (k = 33)
/// \warning Do not edit
constexpr const uint32_t STRING_HASH_KEY = 5381;

/// \brief  Computes a 32 bits hash from a c string
/// \param  pTail A pointer on the c string
/// \param  hash The result
/// \return A 32 bits hash
///
/// \note   This function is tail recursive
constexpr uint32_t __hash(const char * pTail, uint32_t hash = STRING_HASH_KEY)
{
    return (pTail[0] == STRING_END_BYTE) ?
           hash : __hash(pTail + 1,
                         ((hash << STRING_BIT_SHIT) + hash) + (int32_t)*pTail);
}

/// \brief  Binds the constexpr tail recursive function to a static member
///         to force the compiler to hash the string compile time
/// \return see __hash function
template <uint32_t hash>  inline constexpr uint32_t __compile_hash()
{
    return hash;
}

} // !namespace

} // !namespace

/// \example DSID
///
/// DSID is the dymanic or run-time version of SSID
/// It takes in parameter a const char *
/// Example : U32 goID_1 = DSID(go.c_str());
///           U32 goID_2 = DSID("BossDoor");
///           U32 goID_3 = DSID(szP)
#define DSID(string) ord::impl::__hash(string)

/// \example SSID
///
/// To pre-hash all strings and get back a 32 bits unsigned int
/// at compile time, you have to call the SSID Macro.
/// It takes in parameter a const expression or static const char *
/// Example : U32 goID = SSID("MyGameObject");
#define SSID(string) ord::impl::__compile_hash<impl::__hash(string)>()

#endif // !ORDINAL_ENGINE_STRING_HASH_HPP__


