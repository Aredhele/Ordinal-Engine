/// Copyright (C) 2018-2019 Ordinal Engine
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

/// \file       Compiler.pp
/// \date       08/02/2018
/// \project    Ordinal Engine
/// \package    Runtime/Platform/Configuration
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_COMPILER_HPP__
#define ORDINAL_ENGINE_COMPILER_HPP__

#if defined(__SSE__)
#   define ORD_SSE
#elif defined(__SSE2__)
#   define ORD_SSE2
#elif defined(__SSE3__)
#   define ORD_SSE3
#elif defined(__AVX__)
#   define ORD_AVX
#elif defined(__AVX2__)
#   define ORD_AVX2
#endif

// 32 / 64
// mvs / mingw

/// \brief Cross-compiler settings (GCC | MSVC)
#if   defined(ORDINAL_USE_GCC)
#   define ORD_RESTRICT             __restrict__
#   define ORD_NO_INLINE            __attribute__ ((noinline))
#   define ORD_ALIGNMENT(ALIGNMENT) __attribute__ ((aligned (ALIGNMENT)))
#   define ORD_FORCE_INLINE         __attribute__ ((always_inline))
#   define ORD_DEBUG_BREAK()        __asm__       ("int $03;")

#elif defined(ORDINAL_USE_MSVC)
#   define ORD_RESTRICT             __restrict
#   define ORD_NO_INLINE            __declspec    (noinline)
#   define ORD_ALIGNMENT(ALIGNMENT) __declspec    (align (ALIGNMENT))
#   define ORD_FORCE_INLINE         __forceinline
#   define ORD_DEBUG_BREAK()        __debugbreak()

#else
// None

#endif

/// \brief C++ standard backward compatibility
#if defined(__cplusplus)
#   if    __cplusplus == 201103L
#       define ORD_CXX11
#       define ORD_CXX11_CONSTEXPR constexpr
#   else
#        define ORD_CXX11_CONSTEXPR
#   endif

#   if  __cplusplus == 201402L
#       define ORD_CXX14
#       define ORD_CXX14_CONSTEXPR constexpr
#   else
#       define ORD_CXX14_CONSTEXPR
#   endif

#   if  __cplusplus == 201703L
#       define ORD_CXX17
#       define ORD_CXX17_CONSTEXPR constexpr
#   else
#       define ORD_CXX17_CONSTEXPR
#   endif

#   if __cplusplus >= 201103L
#       define ORD_FINAL     final
#       define ORD_NULLPTR   nullptr
#       define ORD_OVERRIDE  override
#       define ORD_NOEXCEPT  noexcept
#       define ORD_CONSTEXPR constexpr
#   else
#       warning "Please update your C++ standard."
#       define ORD_CXX99
#       define ORD_FINAL
#       define ORD_NULLPTR NULL
#       define ORD_OVERRIDE
#       define ORD_NOEXCEPT
#       define ORD_CONSTEXPR
#   endif

#   if __cplusplus >= 201103L
#       define ORD_STATIC_ASSERT(X) static_assert(X);
#   else
#       define ORD_STATIC_ASSERT(X)
#   endif

#else
#       error "Please use the C++ language."
#endif

/// \brief  Alias the main function with a custom name
///         Not really useful, but kinda cool
#define Ordinal_EntryPoint main

#endif // !ORDINAL_ENGINE_COMPILER_HPP__