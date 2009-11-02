/// \file Vector4.hpp
/// \date 2007/11/18
/// \author Peter Dodds
/// \brief chain::Vector4 structure declaration
/// \note
//------------------------------------------------------------------------------

#ifdef _MSC_VER
#pragma once
#endif

#ifndef _chain_Vector4_h_
#define _chain_Vector4_h_

#include "Def.hpp"
#include <ostream>

namespace chain
{
  struct Vector2;
  struct Vector3;

#pragma pack(push,1)
  /// \brief Structure to hold a vector contain four values.
  /// \details Used to define interaction in 4D, and used to represent
  /// a colour with a alpha (\a r,\a g,\a b,\a a)
	struct Vector4
  {
    // -----------------------------------
    /// \details Default constructor taking initial values for \a x, \a y, \a z and \a w
    /// \param _x - initial value of Vector4::x
    /// \param _y - initial value of Vector4::y
    /// \param _z - initial value of Vector4::z
    /// \param _w - initial value of Vector4::w
    Vector4(const Real _x = 0, const Real _y = 0, const Real _z = 0, const Real _w = 0);
    // -----------------------------------
    /// \details Constructor using a Vector2
    /// \param v - vector
    /// \note Vector4::z and Vector4::w set to 0
    Vector4(const Vector2& v);
    // -----------------------------------
    /// \details Constructor using a Vector3
    /// \note Vector3::w set to 0
    Vector4(const Vector3& v);
    // -----------------------------------
    /// \details Constructor using a Vector4
    Vector4(const Vector4& v);
    // -----------------------------------
    /// \details Destructor
    ~Vector4();

    // -----------------------------------
    /// \brief Set the values of \a x, \a y and \a z
    /// \param _x - new value of Vector4::x
    /// \param _y - new value of Vector4::y
    /// \param _z - new value of Vector4::z
    /// \param _w - new value of Vector4::w
    /// \returns const Vector4& - this vector
    const Vector4& Set (const Real& _x = 0, const Real& _y = 0, const Real& _z = 0, const Real& _w = 0);

    // -----------------------------------
    /// \brief Set the values of \a r, \a g, \a b and \a a between the range 0-255
    /// \param _r - new value of Vector4::r
    /// \param _g - new value of Vector4::g
    /// \param _b - new value of Vector4::b
    /// \param _a - new value of Vector4::a
    /// \returns const Vector4& - this vector
    const Vector4& SetColour (const Real& _r, const Real& _g, const Real& _b, const Real& _a);

    // -----------------------------------
    /// \details Negative operator, get the inverse of this vector
    /// \returns Vector4 - negative vector
    Vector4 operator - () const;

    // -----------------------------------
    /// \details Add two vectors
    /// \param v - rhs of operation
    /// \returns Vector4 - result vector
    Vector4 operator + (const Vector4& v) const;
    // -----------------------------------
    /// \details Subtract two vectors
    /// \param v - rhs of operation
    /// \returns Vector4 - result vector
    Vector4 operator - (const Vector4& v) const;
    // -----------------------------------
    /// \brief Scalar/Dot product
    /// \details Multiply two vectors together to get a Real
    /// \param v - rhs of operation
    /// \returns Real - result value
    Real operator * (const Vector4& v) const;
    // -----------------------------------
    /// \details Multiply this vector
    /// \param f - rhs of operation
    /// \returns Vector4 - result vector
    Vector4 operator * (Real f) const;
    // -----------------------------------
    /// \details Divide this vector
    /// \param f - rhs of operation
    /// \returns Vector4 - result vector
    Vector4 operator / (Real f) const;

    // -----------------------------------
    /// \details Assignment operator using Vector2
    /// \param v - rhs of operation
    /// \returns const Vector4& - this vector
    /// \warning Vector4::z and Vector4::w set to 0
    const Vector4& operator = (const Vector2& v);
    // -----------------------------------
    /// \details Assignment operator using Vector3
    /// \param v - rhs of operation
    /// \returns const Vector4& - this vector
    /// \warning Vector4::w set to 0
    const Vector4& operator = (const Vector3& v);
    // -----------------------------------
    /// \details Assignment operator using Vector4
    /// \param v - rhs of operation
    /// \returns const Vector4& - this vector
    const Vector4& operator = (const Vector4& v);

    // -----------------------------------
    /// \details Addition compound assignment see operator+()
    /// \param v - rhs of operation
    /// \returns const Vector4& - this vector
    const Vector4& operator += (const Vector4& v);
    // -----------------------------------
    /// \details Subtraction compound assignment see operator-()
    /// \param v - rhs of operation
    /// \returns const Vector4& - this vector
    const Vector4& operator -= (const Vector4& v);
    // -----------------------------------
    /// \details Multiplication compound assignment see operator*()
    /// \param f - rhs of operation
    /// \returns const Vector4& - this vector
    const Vector4& operator *= (const Real f);
    // -----------------------------------
    /// \details Division compound assignment see operator/()
    /// \param f - rhs of operation
    /// \returns const Vector4& - this vector
    const Vector4& operator /= (const Real f);

    // -----------------------------------
    /// \details Equal comparison operation, using FCOMPARE()
    /// \param v - rhs of operation
    /// \returns bool
    bool operator == (const Vector4& v) const;
    // -----------------------------------
    /// \details Not-equal comparison operation, using FCOMPARE()
    /// \param v - rhs of operation
    /// \returns bool
    bool operator != (const Vector4& v) const;

    // -----------------------------------
    /// \brief Out stream operator
    /// \details In format:
    /// \par
    /// <tt>x y z w</tt>
    /// \par See
    /// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/iostream/ostream/">std::ostream</A>
    friend std::ostream& operator << (std::ostream &s, const Vector4& v);

    union
    {
      struct
      {
        Real x, y, z, w;
      };
      struct
      {
        Real r, g, b, a;
      };
      Real m_data[4];
    };

    /// \var Real Vector4::x
    /// \details First value of vector

    /// \var Real Vector4::y
    /// \details Second value of vector

    /// \var Real Vector4::z
    /// \details Third value of vector

    /// \var Real Vector4::w
    /// \details Fourth value of vector

    /// \var Real Vector4::r
    /// \brief Colour data interface
    /// \details Red value of vector, equal to Vector4::x

    /// \var Real Vector4::g
    /// \brief Colour data interface
    /// \details Green value of vector, equal to Vector4::y

    /// \var Real Vector4::b
    /// \brief Colour data interface
    /// \details Blue value of vector, equal to Vector4::z

    /// \var Real Vector4::a
    /// \brief Colour data interface
    /// \details Alpha value of vector, equal to Vector4::w

    /// \var Real Vector4::m_data[4]
    /// \brief Array data interface
    /// \details Array to access all four values
  };
#pragma pack(pop)

  /// \brief A colour contain four values, red, green, blue and alpha.
  /// \relates Vector4
  /// \details Used to define a colour with a alpha (\a r,\a g,\a b,\a a).
  typedef Vector4 Colour4;
}

#endif
