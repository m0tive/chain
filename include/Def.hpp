/// \file Def.hpp
/// \date 2008/04/19
/// \author Peter Dodds
/// \brief Definitions of basic data types, associated function and constants
/// \note
//------------------------------------------------------------------------------

#ifdef _MSC_VER
#pragma once
#endif

#ifndef _chain_Def_h_
#define _chain_Def_h_

#include <math.h>

namespace chain
{
  /// \todo make 64bit compatible
  /// \brief Unsigned data 8 bytes in length
  typedef unsigned char Uint8;
  /// \brief Unsigned data 32 bytes in length
  typedef unsigned Uint32;
  /// \brief Unsigned data 64 bytes in length
  typedef unsigned long Uint64;

  /// \brief A real number
  /// \details A float or double depending on if CH_DOUBLE_ACCURACY
  /// has been defined
#ifdef CH_DOUBLE_ACCURACY
  typedef double Real;
  #define CH_COS(X) cos(X)
  #define CH_SIN(X) sin(X)
  #define CH_TAN(X) tan(X)
  #define CH_ACOS(X) acos(X)
  #define CH_ASIN(X) asin(X)
  #define CH_ATAN(X) atan(X)
  #define CH_ATAN2(X,Y) atan2(X,Y)

  #define CH_POW(X,Y) pow(X,Y)
  #define CH_SQRT(X) sqrt(X)
#else
  typedef float Real;
  #define CH_COS(X) cosf(X)
  #define CH_SIN(X) sinf(X)
  #define CH_TAN(X) tanf(X)
  #define CH_ACOS(X) acosf(X)
  #define CH_ASIN(X) asinf(X)
  #define CH_ATAN(X) atanf(X)
  #define CH_ATAN2(X,Y) atan2f(X,Y)

  #define CH_POW(X,Y) powf(X,Y)
  #define CH_SQRT(X) (float)(sqrt(X))
#endif

  ///	\details This is the epsilon value used in FCOMPARE()
  const Real g_vecEpsilon = 0.001f;

  ///	PI / 180 constant
  /// \see DEG2RAD()
  const Real PI_OVER_180 = 0.017453292519943295769236907684886f;

  ///	180 / PI constant
  /// \see RAD2DEG()
  const Real _180_OVER_PI = 57.295779513082320876798154814105f;

  ///	PI constant
  const Real PI          = 3.1415926535897932384626433832795f;

  ///	2*PI constant
  const Real _2_PI       = 6.283185307179586476925286766558f;

  ///	PI/2 constant
  const Real PI_OVER_2   = 1.5707963267948966192313216916395f;
}
#ifdef FCOMPARE
  #undef FCOMPARE
#endif

#ifdef DEG2RAD
  #undef DEG2RAD
#endif

#ifdef RAD2DEG
  #undef RAD2DEG
#endif

/// \brief Safe comparison of two Real values.
/// \details Compare \a X and \a Y between +/- chain::g_vecEpsilon
#define FCOMPARE(X,Y) (((X)>((Y) - chain::g_vecEpsilon)) && ( (X) < ((Y)+ chain::g_vecEpsilon)))
/// \brief Convert degrees to radians
/// \details Using chain::PI_OVER_180
#define DEG2RAD(X) (chain::PI_OVER_180 * (X))
/// \brief Convert radians to degrees
/// \details Using chain::_180_OVER_PI
#define RAD2DEG(X) (chain::_180_OVER_PI * (X))

// Doxygen notation
//----------------------------------------------------------------------
/// \def CH_COS(X)
/// \brief Maths function interface
/// \par See
/// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/cos.html">
/// cos()</A>

//----------------------------------------------------------------------
/// \def CH_SIN(X)
/// \brief Maths function interface
/// \par See
/// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/sin.html">
/// sin()</A>

//----------------------------------------------------------------------
/// \def CH_TAN(X)
/// \brief Maths function interface
/// \par See
/// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/tan.html">
/// tan()</A>

//----------------------------------------------------------------------
/// \def CH_ACOS(X)
/// \brief Maths function interface
/// \par See
/// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/acos.html">
/// acos()</A>

//----------------------------------------------------------------------
/// \def CH_ASIN(X)
/// \brief Maths function interface
/// \par See
/// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/asin.html">
/// asin()</A>

//----------------------------------------------------------------------
/// \def CH_ATAN(X)
/// \brief Maths function interface
/// \par See
/// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/atan.html">
/// atan()</A>

//----------------------------------------------------------------------
/// \def CH_ATAN2(X,Y)
/// \brief Maths function interface
/// \par See
/// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/atan2.html">
/// atan2()</A>

//----------------------------------------------------------------------
/// \def CH_POW(X,Y)
/// \brief Maths function interface
/// \par See
/// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/pow.html">
/// pow()</A>

//----------------------------------------------------------------------
/// \def CH_SQRT(X)
/// \brief Maths function interface
/// \par See
/// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/clibrary/cmath/sqrt.html">
/// sqrt()</A>



#endif
