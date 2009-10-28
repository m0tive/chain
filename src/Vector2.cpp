/// \file Vector2.cpp
/// \date 2007/11/13
/// \author Peter Dodds
/// \brief chain::Vector2 function definitions
/// \note
//------------------------------------------------------------------------------

#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"

#include <math.h>

namespace chain
{
  Vector2::Vector2( const Real _x /*= 0*/, const Real _y /*= 0*/)
    : x (_x), y (_y)
  {

  }

  Vector2::Vector2( const Vector2& v )
    : x (v.x), y (v.y)
  {

  }

  Vector2::Vector2( const Vector3& v )
    : x (v.x), y (v.y) // dump the z value
  {

  }

  Vector2::Vector2( const Vector4& v )
    : x (v.x), y (v.y) // dump the z and w value
  {

  }

  Vector2::~Vector2()
  {

  }

  //-----------------------------------------------------------

  const Vector2& Vector2::Set( const Real& _x /*= 0*/, const Real& _y /*= 0*/ )
  {
    x = _x; y = _y;
    return *this;
  }

  chain::Real Vector2::MagnitudeSquared() const
  {
    return x*x+y*y;
  }

  chain::Real Vector2::Magnitude() const
  {
    return CH_SQRT(MagnitudeSquared());
  }

  const Vector2& Vector2::Normalise()
  {
    double tmp = x*x + y*y;
    if(tmp>0.0)
    {
      tmp = 1.0 / sqrt(tmp);
      x *= (Real)tmp;
      y *= (Real)tmp;
    }
    return *this;
  }

  const Vector2& Vector2::Scale( const Real s )
  {
    double tmp = x*x + y*y;
    if(tmp>0.0)
    {
      tmp = s / sqrt(tmp);
      x *= (Real)tmp;
      y *= (Real)tmp;
    }
    return *this;
  }

  const Vector2& Vector2::Truncate( const Real s )
  {
    double tmp = x*x + y*y;
    if(tmp > s*s)
    {
      tmp = s / sqrt(tmp);
      x *= (Real)tmp;
      y *= (Real)tmp;
    }
    return *this;
  }

  //-----------------------------------------------------------

  Vector2 Vector2::operator - () const
  {
    return Vector2(-x, -y);
  }

  //-----------------------------------------------------------

  Vector2 Vector2::operator + (const Vector2& v) const
  {
    return Vector2 ( x+v.x, y+v.y );
  }

  Vector2 Vector2::operator - (const Vector2& v) const
  {
    return Vector2 ( x-v.x, y-v.y );
  }

  Real Vector2::operator * (const Vector2& v) const // DOT
  {
    return x*v.x + y*v.y;
  }

  //-----------------------------------------------------------

  Vector2 Vector2::operator * (const Real f) const
  {
    return Vector2 ( x*f, y*f );
  }

  Vector2 Vector2::operator / (const Real f) const
  {
    Real _1f = 1/f;
    return Vector2 ( x*_1f, y*_1f );
  }

  //-----------------------------------------------------------

  const Vector2& Vector2::operator = (const Vector2& v)
  {
    x = v.x; y = v.y;
    return *this;
  }

  const Vector2& Vector2::operator =( const Vector3& v )
  {
    x = v.x; y = v.y;
    return *this;
  }

  const Vector2& Vector2::operator=( const Vector4& v )
  {
    x = v.x; y = v.y;
    return *this;
  }

  //-----------------------------------------------------------

  const Vector2& Vector2::operator += (const Vector2& v)
  {
    x += v.x; y += v.y;
    return *this;
  }

  const Vector2& Vector2::operator -= (const Vector2& v)
  {
    x -= v.x; y -= v.y;;
    return *this;
  }

  const Vector2& Vector2::operator *= (const Real f)
  {
    x *= f; y *= f;
    return *this;
  }

  const Vector2& Vector2::operator /= (const Real f)
  {
    Real _1f = 1/f;
    x *= _1f; y *= _1f;
    return *this;
  }

  //-----------------------------------------------------------

  bool Vector2::operator == (const Vector2& v) const
  {
    return FCOMPARE(x,v.x) && FCOMPARE(y,v.y);
  }

  bool Vector2::operator != (const Vector2& v) const
  {
    if( !FCOMPARE(x,v.x) || !FCOMPARE(y,v.y) )
      return true;
    return false;
  }

  //-----------------------------------------------------------

  std::ostream& operator << (std::ostream &s, const Vector2& v)
  {
    s << v.x << " " << v.y;
    return s;
  }
}
