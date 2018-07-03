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

/// \file       Compiler.hh
/// \date       08/02/2018
/// \project    Ordinal Engine
/// \package    Runtime/Platform/Configuration
/// \author     Vincent STEHLY--CALISTO

#ifndef ORDINAL_ENGINE_COMPILER_HPP__
#define ORDINAL_ENGINE_COMPILER_HPP__

/// \brief  Cross-compiler settings (GCC | MSVC)
#if   defined(ORDINAL_USE_GCC)
#   define RESTRICT             __restrict__
#   define NO_INLINE            __attribute__ ((noinline))
#   define ALIGNMENT(ALIGNMENT) __attribute__ ((aligned (ALIGNMENT)))
#   define FORCE_INLINE         __attribute__ ((always_inline))
#   define DEBUG_BREAK()        __asm__       ("int $03;")

#elif defined(ORDINAL_USE_MSVC)
#   define RESTRICT             __restrict
#   define NO_INLINE            __declspec    (noinline)
#   define ALIGNMENT(ALIGNMENT) __declspec    (align (ALIGNMENT))
#   define FORCE_INLINE         __forceinline
#   define DEBUG_BREAK()        __debugbreak()

#else
// None

#endif

/// \brief  Alias the main function with a custom name
///         Not really useful, but kinda cool
#define Ordinal_EntryPoint  main

#endif // !ORDINAL_ENGINE_COMPILER_HPP__