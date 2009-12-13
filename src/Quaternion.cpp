/// \file Quaternion.cpp
/// \date 2007/12/07
/// \author Peter Dodds
/// \brief chain::Quaternion function definitions
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#include "Quaternion.hpp"
#include "Matrix.hpp"
#include "EulerAngle.hpp"

namespace chain
{
	Quaternion::Quaternion( const Real& _x /*= 0*/, const Real& _y /*= 0*/, const Real& _z /*= 0*/, const Real& _w /*= 1*/ )
    : x(_x), y(_y), z(_z), w(_w)
  {

  }

  Quaternion::Quaternion( const Quaternion& quat )
    : x(quat.x), y(quat.y), z(quat.z), w(quat.w)
  {

  }

  Quaternion::Quaternion( Matrix& mat )
  {
    (*this) = mat.ToQuat();
  }

  //----------------------------------------------------------- Quaternion::Set
  const Quaternion& Quaternion::Set( const Real& _x /*= 0*/, const Real& _y /*= 0*/, const Real& _z /*= 0*/, const Real& _w /*= 1*/ )
  {
    x = _x; y = _y; z = _z; w = _w;
    return *this;
  }

  //------------------------------------------------ Quaternion::SetEuler
  const Quaternion& Quaternion::SetAxisAngle( const Real& angle, const Real& _x, const Real& _y, const Real& _z )
  {
    chain::Real _angle = angle * 0.5;
    chain::Real sin_a = CH_SIN(_angle);
    chain::Real cos_a = CH_COS(_angle);
    //sin_a = 1/sin_a;

    x = _x * sin_a;
    y = _y * sin_a;
    z = _z * sin_a;
    w = cos_a;

    return *this;
  }

  //------------------------------------------------ Quaternion::ToMatrix
  chain::Matrix Quaternion::ToMatrix() const
  {
    /// \bug This is in the incorrect format! Should be transposed

    Real xx = x * x;
    Real xy = x * y;
    Real xz = x * z;
    Real xw = x * w;
    Real yy = y * y;
    Real yz = y * z;
    Real yw = y * w;
    Real zz = z * z;
    Real zw = z * w;

#if 0
    return Matrix
      (1-2*(yy+zz),  2*(xy-zw),  2*(xz+yw), 0,
         2*(xy+zw),1-2*(xx+zz),  2*(yz-xw), 0,
         2*(xz-yw),  2*(yz+xw),1-2*(xx+yy), 0,
         0.0000000,  0.0000000,  0.0000000, 1);
#else
    return Matrix
      (1-2*(yy+zz),  2*(xy+zw),  2*(xz-yw), 0,
         2*(xy-zw),1-2*(xx+zz),  2*(yz+xw), 0,
         2*(xz+yw),  2*(yz-xw),1-2*(xx+yy), 0,
         0.0000000,  0.0000000,  0.0000000, 1);
#endif
  }

  //------------------------------------------------ Quaternion::ToAxisAngles
  void Quaternion::ToAxisAngles( Real& angle, Real& _x, Real& _y, Real& _z ) const
  {
    Quaternion quat (Normalised());
    angle = CH_ACOS(quat.w)*2;
    Real sina = CH_SQRT(1.0 - quat.w*quat.w);
    if (fabs(sina) < 0.0005)
    {
      // sina = 1;
      _x = quat.x;
      _y = quat.y;
      _z = quat.z;
    }
    else
    {
      sina = 1/sina;
      _x = quat.x * sina;
      _y = quat.y * sina;
      _z = quat.z * sina;
    }
  }

  //----------------------------------------------------------- Quaternion::ToEulerAngles
  chain::EulerAngle Quaternion::ToEulerAngles() const
  {
    return EulerAngle (*this);
#if 0
    _x = GetRollAngle();
    _y = CH_ASIN((2*(w*y - z*x)));
    _z = GetYawAngle();
#endif // 0
  }

  //------------------------------------------------ Quaternion::GetAngle
  chain::Real Quaternion::GetAngle()
  {
    return CH_ACOS(w)*2;
  }

  //----------------------------------------------------------- Quaternion::Split
  void Quaternion::Split (Quaternion& _x, Quaternion& _y, Quaternion& _z) const
  {
    EulerAngle ea (*this);

    if(ea.x!=0)
      _x.SetAxisAngle(ea.x,1,0,0);
    else
      _x.Set();

    if(ea.y!=0)
      _y.SetAxisAngle(ea.y,0,1,0);
    else
      _y.Set();

    if(ea.z!=0)
      _z.SetAxisAngle(ea.z,0,0,1);
    else
      _z.Set();

#if 0
    chain::Real ex,ey,ez;
    ToEulerAngles(ex,ey,ez);

    if(ex!=0)
      _x.SetAxisAngle(ex,1,0,0);
    else
      _x.Set();

    if(ey!=0)
      _y.SetAxisAngle(ey,0,1,0);
    else
      _y.Set();

    if(ez!=0)
      _z.SetAxisAngle(ez,0,0,1);
    else
      _z.Set();
#endif // 0
  }

#if 0

  //----------------------------------------------------------- Quaternion::GetRoll
  Quaternion Quaternion::GetRoll () const
  {
    return Quaternion ().SetAxisAngle(GetRollAngle(), 1,0,0);
  }

  //----------------------------------------------------------- Quaternion::GetPitch
  Quaternion Quaternion::GetPitch () const
  {
    return Quaternion ().SetAxisAngle(GetPitchAngle(), 0,1,0);
  }

  //----------------------------------------------------------- Quaternion::GetYaw
  Quaternion Quaternion::GetYaw () const
  {
    return Quaternion ().SetAxisAngle(GetYawAngle(), 0,0,1);
  }

  //----------------------------------------------------------- Quaternion::GetRollAngle
  Real Quaternion::GetRollAngle () const
  {
    // atan2 expands atan from range -pi/2 < x < pi/2, to the full -pi < x < pi
    // atan2 uses sign of A and B of atan(A/B) to determin the correct
    Real a;
    Real test = w*y - z*x;
    if (test > 0.4999)
      a = 2 * CH_ATAN2(x,w);
    else if (test < -0.4999)
      a = -2 * CH_ATAN2(x,w);
    else
      a = CH_ATAN2((2*(w*x + y*z)) , (1 - 2*(x*x + y*y)));
    //Real a = CH_ATAN2(2*(q1.x*q1.w-y*z) , 1 - 2*sqx - 2*sqz);
    return a;
  }

  //----------------------------------------------------------- Quaternion::GetPitchAngle
  Real Quaternion::GetPitchAngle () const
  {
    Real a;
    Real test = w*y - z*x;
    if (test > 0.4999)
      a = PI*0.5;
    else if (test < -0.4999)
      a = -PI*0.5;
    else
      a = CH_ASIN(2*test);

    return a;
  }

  //----------------------------------------------------------- Quaternion::GetYawAngle
  Real Quaternion::GetYawAngle () const
  {
    // atan2 expands atan from range -pi/2 < x < pi/2, to the full -pi < x < pi
    // atan2 uses sign of A and B of atan(A/B) to determin the correct

    Real a;
    Real test = w*y - z*x;
    if (test > 0.4999 || test < -0.4999)
      a = 0;
    else
      a = CH_ATAN2((2*(w*z + x*y)) , (1 - 2*(y*y + z*z)));
    //Real a = CH_ATAN2(2*(y*w - x*z) , 1 - 2*(y*y - z*z));
    return a;
  }
#endif // 0

  //----------------------------------------------------------- Quaternion::Normalise
  const Quaternion& Quaternion::Normalise()
  {
    double tmp = x*x + y*y + z*z + w*w;
    if(tmp>0.0)
    {
      tmp = 1.0 / sqrt(tmp);
      x *= (Real)tmp;
      y *= (Real)tmp;
      z *= (Real)tmp;
      w *= (Real)tmp;
    }
    return *this;
  }

  //----------------------------------------------------------- Quaternion::Normalised
  chain::Quaternion Quaternion::Normalised() const
  {
    double tmp = x*x + y*y + z*z + w*w;
    if(tmp!=0.0)
      tmp = 1.0 / sqrt(tmp);
    return Quaternion (x*(Real)tmp,y*(Real)tmp,z*(Real)tmp,w*(Real)tmp);
  }

  //----------------------------------------------------------- Quaternion::ScaleTo
  const Quaternion& Quaternion::ScaleTo( Real s )
  {
    return (*this = SLERP( Quaternion(), *this, s/GetAngle() ));
  }

  //----------------------------------------------------------- Quaternion::MagSquared
  chain::Real Quaternion::MagnitudeSquared() const
  {
    return x*x+y*y+z*z+w*w;
  }

  //----------------------------------------------------------- Quaternion::Mag
  chain::Real Quaternion::Magnitude() const
  {
    return CH_SQRT(x*x+y*y+z*z+w*w);
  }

  //----------------------------------------------------------- Quaternion::Mag
  Quaternion Quaternion::Conjugate () const
  {
    return Quaternion (-x,-y,-z,w);
  }

  //----------------------------------------------------------- Quaternion::operator-
  chain::Quaternion Quaternion::operator-() const
  {
    return Quaternion (-x,-y,-z,w);
  }

  //----------------------------------------------------------- Quaternion::operator*
  chain::Quaternion Quaternion::operator*( const Quaternion& q ) const
  {
    return Quaternion( q.w*x + q.x*w + y*q.z - z*q.y,
      q.w*y + q.y*w + z*q.x - x*q.z,
      q.w*z + q.z*w + x*q.y - y*q.x,
      q.w*w - q.x*x - q.y*y - q.z*z );
  }

  chain::Quaternion Quaternion::operator* (const Real& r) const
  {
    return SLERP(Quaternion (),*this,r);
  }

  chain::Quaternion Quaternion::operator/ (const Real& r) const
  {
    return SLERP(Quaternion (),*this,1/r);
  }

  const Quaternion& Quaternion::operator = (const Quaternion& q)
  {
    x = q.x;
    y = q.y;
    z = q.z;
    w = q.w;

    return *this;
  }

  const Quaternion& Quaternion::operator = (const Matrix& mat)
  {
    return *this = mat.ToQuat();
  }

  // this seems not to work, and is probably a bad idea
  //(non commutative operation may be confused)
#if 0
  const Quaternion& Quaternion::operator *= (const Quaternion& q)
  {
    return (*this)*q;
  }
#endif

  //----------------------------------------------------------- Quaternion::operator==
  bool Quaternion::operator==( const Quaternion& q ) const
  {
    return FCOMPARE(x,q.x) && FCOMPARE(y,q.y) && FCOMPARE(z,q.z) && FCOMPARE(w,q.w);
  }

  //----------------------------------------------------------- Quaternion::operator!=
  bool Quaternion::operator!=( const Quaternion& q ) const
  {
    if( !FCOMPARE(x,q.x) || !FCOMPARE(y,q.y) || !FCOMPARE(z,q.z) || !FCOMPARE(w,q.w) )
      return true;
    return false;
  }

  Quaternion SLERP (const Quaternion& q1, const Quaternion& q2, const Real& t)
  {
    Quaternion Q2;
    Quaternion rtrn;

    if( FCOMPARE( q1.x, q2.x ) &&
        FCOMPARE( q1.y, q2.y ) &&
        FCOMPARE( q1.z, q2.z ) &&
        FCOMPARE( q1.w, q2.w ) )
      return q1;

    // dot product
    Real prod = q1.x*q2.x +
                q1.y*q2.y +
                q1.z*q2.z +
                q1.w*q2.w;

    if (prod < 0.001f)
    { // if greater than 90, q2 and prod are negative
      Q2.Set(-q2.x,-q2.y,-q2.z,-q2.w);
      prod = -prod;
    }
    else
      Q2 = q2;

    Real iterp = t;
    Real iterp_inv = 1.0f - t;

    // Clamp to the range of acos
    if (prod > 1)
      prod = 0.999999f;
    else if (prod < -1)
      prod = -0.999999f;

    Real theta = CH_ACOS(prod);
    Real sinTheta = CH_SIN(theta);

    if (sinTheta != 0.0f)
    {
      iterp_inv = CH_SIN(iterp_inv * theta) / sinTheta;
      iterp = CH_SIN(iterp * theta) / sinTheta;
    }

    rtrn.x = (iterp_inv * q1.x) + (iterp * Q2.x);
    rtrn.y = (iterp_inv * q1.y) + (iterp * Q2.y);
    rtrn.z = (iterp_inv * q1.z) + (iterp * Q2.z);
    rtrn.w = (iterp_inv * q1.w) + (iterp * Q2.w);

    return rtrn.Normalise();
  }

  //----------------------------------------------------------- DIFF
  Quaternion DIFF( const Quaternion& orig, const Quaternion& dest )
  {
    /// \todo expand this out
    Quaternion ret = dest * -orig;
    return ret;
  }

  //------------------------------------------------ std::operator<<
  std::ostream& operator << (std::ostream& os,const Quaternion &q )
  {
    return os << q.x << " " << q.y << " " << q.z << " " << q.w;
  }
}

