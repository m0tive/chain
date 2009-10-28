/// \file Vector2.h
/// \date 2007/11/13
/// \author Peter Dodds
/// \brief chain::Vector2 structure declaration
/// \note
//------------------------------------------------------------------------------

#ifdef _MSC_VER
#pragma once
#endif

#ifndef _chain_Vector2_h_
#define _chain_Vector2_h_

#include "Def.hpp"
#include <ostream>

namespace chain
{
  struct Vector3;
  struct Vector4;

#pragma pack(push,1)
  /// \brief Structure to hold a vector contain two values.
  /// \details Used to define interaction in 2D
	struct Vector2
	{
    // -----------------------------------
    /// \details Default Constructor taking initial values for \a x and \a y
    /// \param _x - initial value of \a x
    /// \param _y - initial value of \a y
    Vector2(const Real _x = 0, const Real _y = 0);
    // -----------------------------------
    /// \brief Constructor using a Vector2
    /// \param v - vector
    Vector2(const Vector2& v);
    // -----------------------------------
    /// \brief Constructor using a Vector3
    /// \param v - vector
    /// \warning \a v.z will be lost
    Vector2(const Vector3& v);
    // -----------------------------------
    /// \brief Constructor using a Vector4
    /// \param v - vector
    /// \warning \a v.z and \a v.w will be lost
    Vector2(const Vector4& v);
    // -----------------------------------
    /// \details Destructor
    ~Vector2();

    // -----------------------------------
    /// \brief Set the values of \a x and \a y
    /// \param _x - new value of \a x
    /// \param _y - new value of \a y
    /// \returns const Vector2& - this vector
    const Vector2& Set (const Real& _x = 0, const Real& _y = 0);

    // -----------------------------------
    /// \brief Calculate vector's length squared
    /// \details similar to Magnitude(), but avoiding CH_SQRT()
    /// \returns Real - the length squared
    /// \see Magnitude(), Normalise(), Scale(), Truncate()
    Real MagnitudeSquared () const;
    // -----------------------------------
    /// \brief Calculate vector's length
    /// \details similar to MagnitudeSquared(), but using CH_SQRT()
    /// \returns Real - the length
    /// \see MagnitudeSquared(), Normalise(), Scale(), Truncate()
    Real Magnitude () const;
    // -----------------------------------
    /// \brief Normalise this vector
    /// \details similar to Scale(), scales the vector to a length of 1
    /// \returns const Vector2& - the new vector
    /// \see MagnitudeSquared(), Magnitude(), Scale(), Truncate()
    const Vector2& Normalise ();
    // -----------------------------------
    /// \brief Scale this vector to a new length
    /// \details scales the vector to a length of \a s
    /// \param s - new length
    /// \returns const Vector2& - the new vector
    /// \see MagnitudeSquared(), Magnitude(), Normalise(), Truncate()
    const Vector2& Scale( const Real s );
    // -----------------------------------
    /// \brief Truncate this vector
    /// \details similar to Scale(), but only scales vector to \a s
    /// if it's length is greater than \a s
    /// \param s - limiting length
    /// \returns const Vector2& - the new vector
    /// \see MagnitudeSquared(), Magnitude(), Normalise(), Scale()
    const Vector2& Truncate ( const Real s );

    // -----------------------------------
    /// \details Negative operator, get the inverse of this vector
    /// \returns Vector2 - negative vector
    Vector2 operator - () const;

    // -----------------------------------
    /// \details Add two vectors
    /// \param v - rhs of operation
    /// \returns Vector2 - result vector
    Vector2 operator + (const Vector2& v) const;
    // -----------------------------------
    /// \details Subtract two vectors
    /// \param v - rhs of operation
    /// \returns Vector2 - result vector
    Vector2 operator - (const Vector2& v) const;
    // -----------------------------------
    /// \brief Scalar/Dot product
    /// \details multiply two vectors together to get a Real
    /// \param v - rhs of operation
    /// \returns Real - result value
    Real operator * (const Vector2& v) const;
    // -----------------------------------
    /// \details Multiply this vector
    /// \param f - rhs of operation
    /// \returns Vector2 - result vector
    Vector2 operator * (const Real f) const;
    // -----------------------------------
    /// \details Divide this vector
    /// \param f - rhs of operation
    /// \returns Vector2 - result vector
    Vector2 operator / (const Real f) const;

    // -----------------------------------
    /// \details Assignment operator using Vector2
    /// \param v - rhs of operation
    /// \returns const Vector2& - this vector
    const Vector2& operator = (const Vector2& v);
    // -----------------------------------
    /// \details Assignment operator using Vector3
    /// \param v - rhs of operation
    /// \returns const Vector2& - this vector
    /// \warning \a v.z will be lost
    const Vector2& operator = (const Vector3& v);
    // -----------------------------------
    /// \details Assignment operator using Vector4
    /// \param v - rhs of operation
    /// \returns const Vector2& - this vector
    /// \warning \a v.z and \a v.w will be lost
    const Vector2& operator = (const Vector4& v);

    // -----------------------------------
    /// \details Addition compound assignment see operator+()
    /// \param v - rhs of operation
    /// \returns const Vector2& - this vector
    const Vector2& operator += (const Vector2& v);
    // -----------------------------------
    /// \details Subtraction compound assignment see operator-()
    /// \param v - rhs of operation
    /// \returns const Vector2& - this vector
    const Vector2& operator -= (const Vector2& v);
    // -----------------------------------
    /// \details Multiplication compound assignment see operator*()
    /// \param f - rhs of operation
    /// \returns const Vector2& - this vector
    const Vector2& operator *= (const Real f);
    // -----------------------------------
    /// \details Division compound assignment see operator/()
    /// \param f - rhs of operation
    /// \returns const Vector2& - this vector
    const Vector2& operator /= (const Real f);

    // -----------------------------------
    /// \details Equal comparison operation, using FCOMPARE()
    /// \param v - rhs of operation
    /// \returns bool
    bool operator == (const Vector2& v) const;
    // -----------------------------------
    /// \details Not-equal comparison operation, using FCOMPARE()
    /// \param v - rhs of operation
    /// \returns bool
    bool operator != (const Vector2& v) const;

    // -----------------------------------
    /// \brief Out stream operator
    /// \details In format:
    /// \par
    /// <tt>x y</tt>
    /// \par See
    /// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/iostream/ostream/">std::ostream</A>
    friend std::ostream& operator << (std::ostream &s, const Vector2& v);

    union
    {
      struct
      {
        Real x, y;
      };
      Real m_data[2];
    };

    /// \var Real Vector2::x
    /// \details First value of vector

    /// \var Real Vector2::y
    /// \details Second value of vector

    /// \var Real Vector2::m_data[2]
    /// \brief Array data interface
    /// \details Array to access the two values
	};
#pragma pack(pop)
}

#endif
