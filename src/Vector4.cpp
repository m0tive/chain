/// \file Vector4.cpp
/// \date 2007/11/18
/// \author Peter Dodds
/// \brief chain::Vector4 function definitions
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"

#define _1OVER255 0.003921568627450980392156862745098

namespace chain
{
  Vector4::Vector4( const Real _x /*= 0*/, const Real _y /*= 0*/, const Real _z /*= 0*/, const Real _w /*= 0*/ )
    : x (_x), y (_y), z (_z), w (_w)
  {

  }

  Vector4::Vector4( const Vector2& v )
    : x (v.x), y (v.y), z (0.0), w (1.0)
  {

  }

  Vector4::Vector4( const Vector3& v )
    : x (v.x), y (v.y), z (v.z), w (1.0)
  {

  }

  Vector4::Vector4( const Vector4& v )
    : x (v.x), y (v.y), z (v.z), w (v.w)
  {

  }

  //-----------------------------------------------------------

  Vector4::~Vector4()
  {
  }

  //-----------------------------------------------------------

  const Vector4& Vector4::Set( const Real& _x /*= 0*/, const Real& _y /*= 0*/, const Real& _z /*= 0*/, const Real& _w /*= 0*/ )
  {
    x=_x; y=_y; z=_z; w=_w;
    return *this;
  }

  //-----------------------------------------------------------

  const Vector4& Vector4::SetColour (const Real& _r, const Real& _g, const Real& _b, const Real& _a)
  {
    r=_r*_1OVER255;
    g=_g*_1OVER255;
    b=_b*_1OVER255;
    a=_a*_1OVER255;
    return *this;
  }

  //-----------------------------------------------------------

  Vector4 Vector4::operator - () const
  {
    return Vector4(-x, -y, -z, -w);
  }

  //-----------------------------------------------------------

  Vector4 Vector4::operator + (const Vector4& v) const
  {
    return Vector4 ( x+v.x, y+v.y, z+v.z, w+v.w );
  }

  Vector4 Vector4::operator - (const Vector4& v) const
  {
    return Vector4 ( x-v.x, y-v.y, z-v.z, w-v.w );
  }

  Real Vector4::operator * (const Vector4& v) const // DOT
  {
    return x*v.x + y*v.y + z*v.z + w*v.w;
  }

  //-----------------------------------------------------------

  Vector4 Vector4::operator * (Real f) const
  {
    return Vector4 ( x*f, y*f, z*f, w*f );
  }

  Vector4 Vector4::operator / (Real f) const
  {
    Real _1f = 1/f;
    return Vector4 ( x*_1f, y*_1f, z*_1f, w*_1f );
  }

  //-----------------------------------------------------------

  const Vector4& Vector4::operator = (const Vector2& v)
  {
    x = v.x; y = v.y; z = 0.0, w = 1.0;
    return *this;
  }

  const Vector4& Vector4::operator =( const Vector3& v )
  {
    x = v.x; y = v.y; z = v.z, w = 1.0;
    return *this;
  }

  const Vector4& Vector4::operator =( const Vector4& v )
  {
    x = v.x; y = v.y; z = v.z, w = v.w;
    return *this;
  }


  //-----------------------------------------------------------

  const Vector4& Vector4::operator += (const Vector4& v)
  {
    x += v.x; y += v.y; z += v.z; w += v.w;
    return *this;
  }

  const Vector4& Vector4::operator -= (const Vector4& v)
  {
    x -= v.x; y -= v.y; z -= v.z; w -= v.w;
    return *this;
  }

  const Vector4& Vector4::operator *= (const Real f)
  {
    x *= f; y *= f; z *= f; w *= f;
    return *this;
  }

  const Vector4& Vector4::operator /= (const Real f)
  {
    Real _1f = 1/f;
    x *= _1f; y *= _1f; z *= _1f; w *= _1f;
    return *this;
  }

  //-----------------------------------------------------------

  bool Vector4::operator == (const Vector4& v) const
  {
    return FCOMPARE(x,v.x) && FCOMPARE(y,v.y) && FCOMPARE(z,v.z) && FCOMPARE(w,v.w);
  }
  bool Vector4::operator != (const Vector4& v) const
  {
    if( !FCOMPARE(x,v.x) || !FCOMPARE(y,v.y) || !FCOMPARE(z,v.z) || !FCOMPARE(w,v.w) )
      return true;
    return false;
  }
  //-----------------------------------------------------------

  std::ostream& operator << (std::ostream &s, const Vector4& v)
  {
    s << v.x << " " << v.y << " " << v.z << " " << v.w;
    return s;
  }
}
