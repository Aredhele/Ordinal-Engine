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

/// \brief Platform settings
#if defined(_WIN32) || defined(_WIN64)
#   define ORDINAL_PLATFORM_WINDOWS
#   define ORDINAL_API
#   define ORDINAL_EXPORT __declspec(dllexport)
#   define ORDINAL_IMPORT __declspec(dllimport)

#elif defined(__linux__) || defined(__unix__)
#   define ORDINAL_PLATFORM_LINUX
#   define ORDINAL_API
#   define ORDINAL_EXPORT
#   define ORDINAL_IMPORT

#elif defined(__APPLE__) && defined(__MACH__)
#   define ORDINAL_PLATFORM_APPLE
#   define ORDINAL_API
#   define ORDINAL_EXPORT
#   define ORDINAL_IMPORT

#else
#   error "Platform not supported."

#endif

/// \brief Detecting the architecture
#if (defined(_WIN64)      || defined(__amd64__)   || defined(__x86_64__) || \
     defined(__ia64__)    || defined(__ia64)      || defined(_M_IA64)    || \
     defined(__itanium__) || defined(__MINGW64__) || defined(_M_AMD64)   || \
     defined (_M_X64))
#   define ORDINAL_PLATFORM_X64

#else
#   define ORDINAL_PLATFORM_X86

#endif

/// \brief Detecting compiler
#if defined(__BORLANDC__)
#   define ORDINAL_COMPILER_BORLAND

#elif defined(__clang__)
#   define ORDINAL_COMPILER_CLANG

#elif defined(__GNUC__) || defined(__GNUG__) || defined(__MINGW32__)
#   define ORDINAL_COMPILER_GCC

#elif defined(_MSC_VER)
#   define ORDINAL_COMPILER_MSC

#elif defined(__INTEL_COMPILER) || defined(__ICL)
#   define ORDINAL_COMPILER_ICL

#else
#   error "Compiler not supported."

#endif

/// \brief Cross-compiler settings
#if defined(ORDINAL_COMPILER_BORLAND)
#   warning "Not all BORDINALland intrisics are available."
#   define ORDINAL_RESTRICT
#   define ORDINAL_NO_INLINE
#   define ORDINAL_ALIGNMENT(ALIGNMENT)
#   define ORDINAL_FORCE_INLINE
#   define ORDINAL_DEBUG_BREAK()

#elif defined(ORDINAL_COMPILER_CLANG)
#   define ORDINAL_RESTRICT             __restrict
#   define ORDINAL_NO_INLINE            __attribute__((noinline))
#   define ORDINAL_ALIGNMENT(ALIGNMENT) __attribute__((alloc_align(ALIGNMENT)))
#   define ORDINAL_FORCE_INLINE         __attribute__((always_inline))
#   define ORDINAL_DEBUG_BREAK()        __builtin_debugtrap()

#elif defined(ORDINAL_COMPILER_GCC)
#   define ORDINAL_RESTRICT             __restrict__
#   define ORDINAL_NO_INLINE            __attribute__ ((noinline))
#   define ORDINAL_ALIGNMENT(ALIGNMENT) __attribute__ ((aligned (ALIGNMENT)))
#   define ORDINAL_FORCE_INLINE         __attribute__ ((always_inline))
#   define ORDINAL_DEBUG_BREAK()        __asm__       ("int $03;")

#elif defined(ORDINAL_COMPILER_MSC)
#   define ORDINAL_RESTRICT             __restrict
#   define ORDINAL_NO_INLINE            __declspec    (noinline)
#   define ORDINAL_ALIGNMENT(ALIGNMENT) __declspec    (align (ALIGNMENT))
#   define ORDINAL_FORCE_INLINE         __forceinline
#   define ORDINAL_DEBUG_BREAK()        __debugbreak()

#elif defined(ORDINAL_COMPILER_ICL)
#   warning "Not all ICL intrisics are available."
#   define ORDINAL_RESTRICT
#   define ORDINAL_NO_INLINE
#   define ORDINAL_ALIGNMENT(ALIGNMENT) __attribute__ ((aligned(ALIGNMENT)))
#   define ORDINAL_FORCE_INLINE
#   define ORDINAL_DEBUG_BREAK()

#endif

/// \brief
#if defined(__SSE__)
#   define ORDINAL_SSE
#endif

#if defined(__SSE2__)
#   define ORDINAL_SSE2
#endif

#if defined(__SSE3__)
#   define ORDINAL_SSE3
#endif

#if defined(__AVX__)
#   define ORDINAL_AVX
#endif

#if defined(__AVX2__)
#   define ORDINAL_AVX2
#endif

/// \brief C++ standard backward compatibility
#if defined(__cplusplus)
#   if    __cplusplus == 201103L
#       define ORDINAL_CXX11
#       define ORDINAL_CXX11_CONSTEXPR constexpr
#   else
#        define ORDINAL_CXX11_CONSTEXPR
#   endif

#   if  __cplusplus == 201402L
#       define ORDINAL_CXX14
#       define ORDINAL_CXX14_CONSTEXPR constexpr
#   else
#       define ORDINAL_CXX14_CONSTEXPR
#   endif

#   if  __cplusplus == 201703L
#       define ORDINAL_CXX17
#       define ORDINAL_CXX17_CONSTEXPR constexpr
#   else
#       define ORDINAL_CXX17_CONSTEXPR
#   endif

#   if __cplusplus >= 201103L
#       define ORDINAL_FINAL     final
#       define ORDINAL_NULLPTR   nullptr
#       define ORDINAL_OVERRIDE  override
#       define ORDINAL_NOEXCEPT  noexcept
#       define ORDINAL_CONSTEXPR constexpr
#   else
#       warning "Please update your C++ standard."
#       define ORDINAL_CXX99
#       define ORDINAL_FINAL
#       define ORDINAL_NULLPTR NULL
#       define ORDINAL_OVERRIDE
#       define ORDINAL_NOEXCEPT throw();
#       define ORDINAL_CONSTEXPR
#   endif

#   if __cplusplus >= 201103L
#       define ORDINAL_STATIC_ASSERT(X) static_assert(X);
#   else
#       define ORDINAL_STATIC_ASSERT(X)
#   endif

#else
#       error "Please use the C++ language."
#endif

/// \brief  Alias the main function with a custom name
///         Not really useful, but kinda cool
#define Ordinal_EntryPoint main

#endif // !ORDINAL_ENGINE_COMPILER_HPP__