/// \file Vector3.cpp
/// \date 2008/04/17
/// \author Peter Dodds
/// \brief chain::Vector3 function definitions
/// \note
//------------------------------------------------------------------------------

#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"

#define _1OVER255 0.003921568627450980392156862745098

#include <math.h>

namespace chain
{
  //-----------------------------------------------------------
  Vector3::Vector3(const Real& _x /*= 0*/, const Real& _y /*= 0*/, const Real& _z /*= 0*/)
    : x(_x), y(_y), z(_z)
  {
  }

  Vector3::Vector3( const Vector2& v )
    : z (0)
  {
    x = v.x;
    y = v.y;
  }

  Vector3::Vector3(const Vector3& v)
    : x(v.x), y(v.y), z(v.z)
  {
  }


  Vector3::Vector3( const Vector4& v )
    : x(v.x), y(v.y), z(v.z)
  {

  }
  //-----------------------------------------------------------

  Vector3::~Vector3()
  {
  }

  //-----------------------------------------------------------

  const Vector3& Vector3::Set( const Real& _x /*= 0*/, const Real& _y /*= 0*/, const Real& _z /*= 0*/ )
  {
    x=_x; y=_y; z=_z;
    return *this;
  }

  //-----------------------------------------------------------

  const Vector3& Vector3::SetColour (const Real& _r, const Real& _g, const Real& _b)
  {
    r=_r*_1OVER255;
    g=_g*_1OVER255;
    b=_b*_1OVER255;
    return *this;
  }

  //-----------------------------------------------------------

  chain::Real Vector3::MagnitudeSquared() const
  {
    return x*x+y*y+z*z;
  }

  chain::Real Vector3::Magnitude() const
  {
    return CH_SQRT(MagnitudeSquared());
  }

  const Vector3& Vector3::Normalise()
  {
    double tmp = x*x + y*y + z*z;
    if(tmp>0.0)
    {
      tmp = 1.0 / sqrt(tmp);
      x *= (Real)tmp;
      y *= (Real)tmp;
      z *= (Real)tmp;
    }
    return *this;
  }

  const Vector3& Vector3::Scale( Real s )
  {
    double tmp = x*x + y*y + z*z;
    if(tmp>0.0)
    {
      tmp = s / sqrt(tmp);
      x *= (Real)tmp;
      y *= (Real)tmp;
      z *= (Real)tmp;
    }
    return *this;
  }

  const Vector3& Vector3::Truncate( Real s )
  {
    double tmp = x*x + y*y + z*z;
    if(tmp>s*s)
    {
      tmp = s / sqrt(tmp);
      x *= (Real)tmp;
      y *= (Real)tmp;
      z *= (Real)tmp;
    }
    return *this;
  }

  //-----------------------------------------------------------

  Vector3 Vector3::operator - () const
  {
    return Vector3(-x, -y, -z);
  }

  //-----------------------------------------------------------

  Vector3 Vector3::operator + (const Vector3& v) const
  {
    return Vector3 ( x+v.x, y+v.y, z+v.z );
  }

  Vector3 Vector3::operator - (const Vector3& v) const
  {
    return Vector3 ( x-v.x, y-v.y, z-v.z );
  }

  Real Vector3::operator * (const Vector3& v) const // DOT
  {
    return x*v.x + y*v.y + z*v.z;
  }

  Vector3 Vector3::operator ^ (const Vector3& v) const // CROSS
  {
    return Vector3 ( y*v.z - z*v.y,
                    z*v.x - x*v.z,
                    x*v.y - y*v.x );
  }

  //-----------------------------------------------------------

  Vector3 Vector3::operator * (Real f) const
  {
    return Vector3 ( x*f, y*f, z*f );
  }

  Vector3 Vector3::operator / (Real f) const
  {
    Real _1f = 1/f;
    return Vector3 ( x*_1f, y*_1f, z*_1f );
  }

  //-----------------------------------------------------------

  const Vector3& Vector3::operator = (const Vector2& v)
  {
    x = v.x; y = v.y; z = 0.0;
    return *this;
  }

  const Vector3& Vector3::operator =( const Vector3& v )
  {
    x = v.x; y = v.y; z = v.z;
    return *this;
  }

  const Vector3& Vector3::operator=( const Vector4& v )
  {
    x = v.x; y = v.y; z = v.z;
    return *this;
  }

  //-----------------------------------------------------------

  const Vector3& Vector3::operator += (const Vector3& v)
  {
    x += v.x; y += v.y; z += v.z;
    return *this;
  }

  const Vector3& Vector3::operator -= (const Vector3& v)
  {
    x -= v.x; y -= v.y; z -= v.z;
    return *this;
  }

  const Vector3& Vector3::operator *= (const Real f)
  {
    x *= f; y *= f; z *= f;
    return *this;
  }

  const Vector3& Vector3::operator /= (const Real f)
  {
    Real _1f = 1/f;
    x *= _1f; y *= _1f; z *= _1f;
    return *this;
  }

  //-----------------------------------------------------------

  bool Vector3::operator == (const Vector3& v) const
  {
    return FCOMPARE(x,v.x) && FCOMPARE(y,v.y) && FCOMPARE(z,v.z);
  }
  bool Vector3::operator != (const Vector3& v) const
  {
    if( !FCOMPARE(x,v.x) || !FCOMPARE(y,v.y) || !FCOMPARE(z,v.z) )
      return true;
    return false;
  }
  //-----------------------------------------------------------

  std::ostream& operator << (std::ostream &s, const Vector3& v)
  {
    s << v.x << " " << v.y << " " << v.z;
    return s;
  }
}
