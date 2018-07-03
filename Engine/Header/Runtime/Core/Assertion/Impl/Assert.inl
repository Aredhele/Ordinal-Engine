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

/// \file       Assert.inl
/// \date       10/02/2018
/// \project    Ordinal Engine
/// \package    Runtime/Core/Assertion/Impl
/// \author     Vincent STEHLY--CALISTO

///\namespace ord
namespace ord { namespace impl {

/// \brief  Displays the assertion message
inline void assert_print(const char *szName, const char *szExpr, const char *szMsg,
                  const char *szFile, const char *szFunc, int32_t line)
{
    fprintf(stderr, "FILE\t : %s\nLINE\t : %d\nFUNCTION : %s\n"
                    "Assertion failed %s(%s) with message : %s\n",
                     szFile, line, szFunc, szName, szExpr, szMsg);
}

/// \brief  Checks if the expression is true
inline void assert_true(bool bExpr, const char *szExpr, const char *szMsg,
                 const char *szFile, const char *szFunc, int32_t line)
{
    if (!bExpr)
    {
        assert_print("ASSERT_TRUE", szExpr, szMsg, szFile, szFunc, line);
        ORD_DEBUG_BREAK();
    }
}

/// \brief  Checks sif the expression is false
inline void assert_false(bool bExpr, const char *szExpr, const char *szMsg,
                  const char *szFile, const char *szFunc, int32_t line)
{
    if (bExpr)
    {
        assert_print("ASSERT_FALSE", szExpr, szMsg, szFile, szFunc, line);
        ORD_DEBUG_BREAK();
    }
}

/// \brief  Checks if rhs and lhs are equal
template<class T, class U>
inline void assert_equal(const T &lhs, const U &rhs,
                  const char * szLhs, const char * szRhs,
                  const char * szMsg, const char * szFile,
                  const char * szFunc, int32_t line)
{
    if (lhs != rhs)
    {
        std::string expr = std::string(szLhs) + " == " +
                           std::string(szRhs);

        assert_print("ASSERT_EQ", expr.c_str(), szMsg, szFile, szFunc, line);
        ORD_DEBUG_BREAK();
    }
}

/// \brief  Checks if rhs and lhs are different
template <class T, class U>
inline void assert_non_equal(const T &lhs, const U &rhs,
                      const char * szLhs, const char * szRhs,
                      const char * szMsg, const char * szFile,
                      const char * szFunc, int32_t line)
{
    if (lhs == rhs)
    {
        std::string expr = std::string(szLhs) + " != " +
                           std::string(szRhs);

        assert_print("ASSERT_NE", expr.c_str(), szMsg, szFile, szFunc, line);
        ORD_DEBUG_BREAK();
    }
}

/// \brief  Checks if ptr is null pointer
inline void assert_is_null(void *ptr, const char *szExpr, const char *szMsg,
                           const char *szFile, const char *szFunc, int32_t line)
{
    if (ptr != nullptr)
    {
        assert_print("ASSERT_NULL", szExpr, szMsg, szFile, szFunc, line);
        ORD_DEBUG_BREAK();
    }
}

/// \brief  Checks if ptr is not null pointer
inline void assert_is_not_null(void *ptr, const char *szExpr, const char *szMsg,
                               const char *szFile, const char *szFunc, int32_t line)
{
    if (ptr == nullptr)
    {
        assert_print("ASSERT_NOT_NULL", szExpr, szMsg, szFile, szFunc, line);
        ORD_DEBUG_BREAK();
    }
}

/// \brief  Checks if rhs is greater than lhs
template <class T, class U>
inline void assert_is_greater_than(const T & lhs, const U & rhs,
                            const char * szLhs, const char * szRhs,
                            const char * szMsg, const char * szFile,
                            const char * szFunc, int32_t line)
{
    if(lhs < rhs)
    {
        std::string expr = std::string(szLhs) + " > " +
                           std::string(szRhs);

        assert_print("ASSERT_GT", expr.c_str(), szMsg, szFile, szFunc, line);
        ORD_DEBUG_BREAK();
    }
}

/// \brief  Checks if rhs is lower than lhs
template <class T, class U>
inline void assert_is_lower_than(const T & lhs, const U & rhs,
                          const char * szLhs, const char * szRhs,
                          const char * szMsg, const char * szFile,
                          const char * szFunc, int32_t line)
{
    if(lhs > rhs)
    {
        std::string expr = std::string(szLhs) + " < " +
                           std::string(szRhs);

        assert_print("ASSERT_LT", expr.c_str(), szMsg, szFile, szFunc, line);
        ORD_DEBUG_BREAK();
    }
}

} } // impl - ord