/// \file Vector3.h
/// \date 2007/11/13
/// \author Peter Dodds
/// \brief chain::Vector3 structure declaration
/// \note
//------------------------------------------------------------------------------

#ifdef _MSC_VER
#pragma once
#endif

#ifndef _chain_Vector3_h_
#define _chain_Vector3_h_

#include "Def.hpp"
#include <ostream>

namespace chain
{
  struct Vector2;
  struct Vector4;

#pragma pack(push,1)
  /// \brief Structure to hold a vector contain three values.
  /// \details Used to define interaction in 3D, and used to represent
  /// a colour with no alpha (\a r,\a g,\a b)
  /// \todo add GetColour to read colour in 0-255 form
  struct Vector3
  {
    // -----------------------------------
    /// \details Default constructor taking initial values for \a x, \a y and \a z
    /// \param _x - initial value of Vector3::x
    /// \param _y - initial value of Vector3::y
    /// \param _z - initial value of Vector3::z
    Vector3(const Real& _x = 0, const Real& _y = 0, const Real& _z = 0);
    // -----------------------------------
    /// \details Constructor using a Vector2
    /// \param v - vector
    /// \note Vector3::z set to 0
    Vector3(const Vector2& v);
    // -----------------------------------
    /// \details Constructor using a Vector3
    /// \param v - vector
    Vector3(const Vector3& v);
    // -----------------------------------
    /// \details Constructor using a Vector4
    /// \param v - vector
    /// \warning \a v.w will be lost
    Vector3(const Vector4& v);
    // -----------------------------------
    /// \details Destructor
    ~Vector3();

    // -----------------------------------
    /// \brief Set the values of \a x, \a y and \a z
    /// \param _x - new value of Vector3::x
    /// \param _y - new value of Vector3::y
    /// \param _z - new value of Vector3::z
    /// \returns const Vector3& - this vector
    const Vector3& Set (const Real& _x = 0, const Real& _y = 0, const Real& _z = 0);

    // -----------------------------------
    /// \brief Set the values of \a r, \a g and \a b between the range 0-255
    /// \param _r - new value of Vector3::r
    /// \param _g - new value of Vector3::g
    /// \param _b - new value of Vector3::b
    /// \returns const Vector3& - this vector
    const Vector3& SetColour (const Real& _r, const Real& _g, const Real& _b);

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
    /// \returns const Vector3& - the new vector
    /// \see MagnitudeSquared(), Magnitude(), Scale(), Truncate()
    const Vector3& Normalise ();
    // -----------------------------------
    /// \brief Scale this vector to a new length
    /// \details scales the vector to a length of \a s
    /// \param s - new length
    /// \returns const Vector3& - the new vector
    /// \see MagnitudeSquared(), Magnitude(), Normalise(), Truncate()
    const Vector3& Scale( const Real s );
    // -----------------------------------
    /// \brief Truncate this vector
    /// \details similar to Scale(), but only scales vector to \a s
    /// if it's length is greater than \a s
    /// \param s - limiting length
    /// \returns const Vector3& - the new vector
    /// \see MagnitudeSquared(), Magnitude(), Normalise(), Scale()
    const Vector3& Truncate (Real s);

    // -----------------------------------
    /// \details Negative operator, get the inverse of this vector
    /// \returns Vector3 - negative vector
    Vector3 operator - () const;

    // -----------------------------------
    /// \details Add two vectors
    /// \param v - rhs of operation
    /// \returns Vector3 - result vector
    Vector3 operator + (const Vector3& v) const;
    // -----------------------------------
    /// \details Subtract two vectors
    /// \param v - rhs of operation
    /// \returns Vector3 - result vector
    Vector3 operator - (const Vector3& v) const;
    // -----------------------------------
    /// \brief Scalar/Dot product
    /// \details Multiply two vectors together to get a Real
    /// \param v - rhs of operation
    /// \returns Real - result value
    Real operator * (const Vector3& v) const;
    // -----------------------------------
    /// \brief Vector/Cross product
    /// \details Multiply two vectors together to get a vector.
    /// \param v - rhs of operation
    /// \returns Vector3 - result vector
    Vector3 operator ^ (const Vector3& v) const;
    // -----------------------------------
    /// \details Multiply this vector
    /// \param f - rhs of operation
    /// \returns Vector3 - result vector
    Vector3 operator * (Real f) const;
    // -----------------------------------
    /// \details Divide this vector
    /// \param f - rhs of operation
    /// \returns Vector3 - result vector
    Vector3 operator / (Real f) const;

    // -----------------------------------
    /// \details Assignment operator using Vector2
    /// \param v - rhs of operation
    /// \returns const Vector3& - this vector
    /// \warning Vector3::z set to 0
    const Vector3& operator = (const Vector2& v);
    // -----------------------------------
    /// \details Assignment operator using Vector3
    /// \param v - rhs of operation
    /// \returns const Vector3& - this vector
    const Vector3& operator = (const Vector3& v);
    // -----------------------------------
    /// \details Assignment operator using Vector4
    /// \param v - rhs of operation
    /// \returns const Vector3& - this vector
    /// \warning \a v.w will be lost
    const Vector3& operator = (const Vector4& v);

    // -----------------------------------
    /// \details Addition compound assignment see operator+()
    /// \param v - rhs of operation
    /// \returns const Vector3& - this vector
    const Vector3& operator += (const Vector3& v);
    // -----------------------------------
    /// \details Subtraction compound assignment see operator-()
    /// \param v - rhs of operation
    /// \returns const Vector3& - this vector
    const Vector3& operator -= (const Vector3& v);
    // -----------------------------------
    /// \details Multiplication compound assignment see operator*()
    /// \param f - rhs of operation
    /// \returns const Vector3& - this vector
    const Vector3& operator *= (const Real f);
    // -----------------------------------
    /// \details Division compound assignment see operator/()
    /// \param f - rhs of operation
    /// \returns const Vector3& - this vector
    const Vector3& operator /= (const Real f);

    // -----------------------------------
    /// \details Equal comparison operation, using FCOMPARE()
    /// \param v - rhs of operation
    /// \returns bool
    bool operator == (const Vector3& v) const;
    // -----------------------------------
    /// \details Not-equal comparison operation, using FCOMPARE()
    /// \param v - rhs of operation
    /// \returns bool
    bool operator != (const Vector3& v) const;

    // -----------------------------------
    /// \brief Out stream operator
    /// \details In format:
    /// \par
    /// <tt>x y z</tt>
    /// \par See
    /// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/iostream/ostream/">std::ostream</A>
    friend std::ostream& operator << (std::ostream &s, const Vector3& v);

    union
    {
      struct
      {
        Real x, y, z;
      };
      struct
      {
        Real r, g, b;
      };
      Real m_data[3];
    };

    /// \var Real Vector3::x
    /// \details First value of vector

    /// \var Real Vector3::y
    /// \details Second value of vector

    /// \var Real Vector3::z
    /// \details Third value of vector

    /// \var Real Vector3::r
    /// \brief Colour data interface
    /// \details Red value of vector, equal to Vector3::x

    /// \var Real Vector3::g
    /// \brief Colour data interface
    /// \details Green value of vector, equal to Vector3::y

    /// \var Real Vector3::b
    /// \brief Colour data interface
    /// \details Blue value of vector, equal to Vector3::z

    /// \var Real Vector3::m_data[3]
    /// \brief Array data interface
    /// \details Array to access all three values

  };
#pragma pack(pop)

  /// \brief A colour contain three values, red, green and blue.
  /// \relates Vector3
  /// \details Used to define a colour with no alpha (\a r,\a g,\a b).
  typedef Vector3 Colour3;
}

#endif
