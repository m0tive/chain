/// \file EulerAngle.cpp
/// \date 2008/04/16
/// \author Peter Dodds
/// \brief chain::EulerAngle function definitions
/// \note
//------------------------------------------------------------------------------

#include "EulerAngle.hpp"
#include "Quaternion.hpp"
#include "Matrix.hpp"

namespace chain
{
  //------------------------------------------------ EulerAngle::EulerAngle
  EulerAngle::EulerAngle( const Real& _x /*= 0*/, const Real& _y /*= 0*/, const Real& _z /*= 0*/ ) : x (_x), y (_y), z (_z)
  {

  }

  //------------------------------------------------ EulerAngle::EulerAngle
  EulerAngle::EulerAngle( const EulerAngle& ea ) : x (ea.x), y (ea.y), z (ea.z)
  {

  }

  //------------------------------------------------ EulerAngle::EulerAngle
  EulerAngle::EulerAngle( const Matrix& m )
  {
    FromMatrix(m);
  }

  //------------------------------------------------ EulerAngle::EulerAngle
  EulerAngle::EulerAngle( const Quaternion& q )
  {
    FromMatrix(q.ToMatrix());
  }

  //------------------------------------------------ EulerAngle::operator=
  const EulerAngle& EulerAngle::operator=( const EulerAngle& ea )
  {
    x = ea.x; y = ea.y; z = ea.z;
    return *this;
  }

  //------------------------------------------------ EulerAngle::FromMatrix
  const EulerAngle& EulerAngle::FromMatrix( const Matrix& m )
  {
    // http://vered.rose.utoronto.ca/people/david_dir/GEMS/GEMS.html
    // assuming that angle is in static XYZ order
    chain::Real cy = CH_SQRT(m.m00*m.m00 + m.m10*m.m10);
    if (cy > 16*0.00001) {
      x = CH_ATAN2(m.m21, m.m22);
      y = CH_ATAN2(-m.m20, cy);
      z = CH_ATAN2(m.m10, m.m00);
    } else {
      x = CH_ATAN2(-m.m12, m.m11);
      y = CH_ATAN2(-m.m20, cy);
      z = 0;
    }
    return *this;
  }

  //------------------------------------------------ EulerAngle::FromQuat
  const EulerAngle& EulerAngle::FromQuat( const Quaternion& q )
  {
    return FromMatrix(q.ToMatrix());
  }

  //------------------------------------------------ EulerAngle::ToQuat
  chain::Quaternion EulerAngle::ToQuat()
  {
    // http://vered.rose.utoronto.ca/people/david_dir/GEMS/GEMS.html
    // assuming that angle is in static XYZ order
    Quaternion q;
    Real ti, tj, th, ci, cj, ch, si, sj, sh, cc, cs, sc, ss;

    ti = x*0.5; tj = y*0.5; th = z*0.5;

    ci = CH_COS(ti);  cj = CH_COS(tj);  ch = CH_COS(th);
    si = CH_SIN(ti);  sj = CH_SIN(tj);  sh = CH_SIN(th);

    cc = ci*ch; cs = ci*sh; sc = si*ch; ss = si*sh;

    q.x = cj*sc - sj*cs;
    q.y = cj*ss + sj*cc;
    q.z = cj*cs - sj*sc;
    q.w = cj*cc + sj*ss;

    return q;
  }
}
