/// \file Matrix.cpp
/// \date 2007/12/07
/// \author Peter Dodds
/// \brief chain::Matrix function definitions
/// \note
//------------------------------------------------------------------------------

#include "Matrix.hpp"
#include "Quaternion.hpp"
#include "Vector3.hpp"
//#include "Matrix3.hpp"

#include <assert.h>
#include <string.h>

namespace chain
{
  //------------------------------------------------ Matrix::Matrix
  //Matrix::Matrix()
  //{
  //}

  Matrix::Matrix(Real x0, Real y0, Real z0, Real w0,
                 Real x1, Real y1, Real z1, Real w1,
                 Real x2, Real y2, Real z2, Real w2,
                 Real tx, Real ty, Real tz, Real tw)
    : m00 (x0), m01 (y0), m02 (z0), m03 (w0),
      m10 (x1), m11 (y1), m12 (z1), m13 (w1),
      m20 (x2), m21 (y2), m22 (z2), m23 (w2),
      m30 (tx), m31 (ty), m32 (tz), m33 (tw)
  {

  }

  Matrix::Matrix(const Matrix& m)
  {
#if 0
    m00 = m.m00; m01 = m.m01; m02 = m.m02; m03 = m.m03;
    m10 = m.m10; m11 = m.m11; m12 = m.m12; m13 = m.m13;
    m20 = m.m20; m21 = m.m21; m22 = m.m22; m23 = m.m23;
    m30 = m.m30; m31 = m.m31; m32 = m.m32; m33 = m.m33;
#endif // 0

    memcpy(m_data,m.m_data,16*sizeof(Real));
  }

  Matrix::Matrix(const Vector3& translation)
  {
    m00 = 1; m01 = 0; m02 = 0; m03 = 0;
    m10 = 0; m11 = 1; m12 = 0; m13 = 0;
    m20 = 0; m21 = 0; m22 = 1; m23 = 0;
    m30 = translation.x; m31 = translation.y; m32 = translation.z; m33 = 1;
  }

  Matrix::Matrix(const Quaternion& rotation)
  {
#if 0
    Real xx = rotation.x * rotation.x;
    Real xy = rotation.x * rotation.y;
    Real xz = rotation.x * rotation.z;
    Real xw = rotation.x * rotation.w;
    Real yy = rotation.y * rotation.y;
    Real yz = rotation.y * rotation.z;
    Real yw = rotation.y * rotation.w;
    Real zz = rotation.z * rotation.z;
    Real zw = rotation.z * rotation.w;

    m00 = 1-2*(yy+zz); m01 =   2*(xy-zw); m02 =   2*(xz+yw); m03 = 0;
    m10 =   2*(xy+zw); m11 = 1-2*(xx+zz); m12 =   2*(yz-xw); m13 = 0;
    m20 =   2*(xz-yw); m21 =   2*(yz+xw); m22 = 1-2*(xx+yy); m23 = 0;
    m30 = m31 = m32 = 0; m33 = 1;
#endif // 0
    /// \bug see Quaternion::ToMatrix()
    *this = rotation.ToMatrix();
  }

  //------------------------------------------------ Matrix::~Matrix
  Matrix::~Matrix()
  {
  }

  //------------------------------------------------ Matrix::Identity
  const Matrix& Matrix::Identity()
  {
    m01 =  m02 =  m03 =
    m10 =  m12 =  m13 =
    m20 =  m21 =  m23 =
    m30 =  m31 =  m32 = 0.0f;

    m00 = m11 = m22 = m33 = 1.0f;
    return *this;
  }

  //------------------------------------------------ Matrix::Transpose
  const Matrix& Matrix::Transpose()
  {
		Matrix m ( m00, m10, m20, m30,
               m01, m11, m21, m31,
               m02, m12, m22, m32,
               m03, m13, m23, m33 );

		memcpy(m_data,m.m_data,16*sizeof(Real));
    return *this;
  }

  //------------------------------------------------ Matrix::GetTranspose
  Matrix Matrix::GetTranspose() const
  {
    return Matrix ( m00, m10, m20, m30,
                    m01, m11, m21, m31,
                    m02, m12, m22, m32,
                    m03, m13, m23, m33 );
  }

  //------------------------------------------------ Matrix::Determinant
  Real Matrix::Determinant() const
  {
#if 1
    Real value =
      m03 * m12 * m21 * m30-m02 * m13 * m21 * m30-m03 * m11 * m22 * m30+m01 * m13    * m22 * m30+
      m02 * m11 * m23 * m30-m01 * m12 * m23 * m30-m03 * m12 * m20 * m31+m02 * m13    * m20 * m31+
      m03 * m10 * m22 * m31-m00 * m13 * m22 * m31-m02 * m10 * m23 * m31+m00 * m12    * m23 * m31+
      m03 * m11 * m20 * m32-m01 * m13 * m20 * m32-m03 * m10 * m21 * m32+m00 * m13    * m21 * m32+
      m01 * m10 * m23 * m32-m00 * m11 * m23 * m32-m02 * m11 * m20 * m33+m01 * m12    * m20 * m33+
      m02 * m10 * m21 * m33-m00 * m12 * m21 * m33-m01 * m10 * m22 * m33+m00 * m11    * m22 * m33;
    return value;

#else
    Real det, result = 0, i = 1;
    Matrix3 msub3;
    int     n;

    for ( n = 0; n < 4; n++, i *= -1 )
    {
      msub3 = GetSubMatrix( 0, n );

      det     = msub3.Determinant();
      result += m_data[n] * det * i;
    }

    return result;
#endif // 0
  }

  //------------------------------------------------ Matrix::Invert
  const Matrix& Matrix::Invert()
  {
    return *this = GetInverse();
  }

  //------------------------------------------------ Matrix::GetInverse
  Matrix Matrix::GetInverse() const
  {
#if 1
    Real det = Determinant();
    Matrix mat;
    if ( FCOMPARE(det,0.0f) )
      return mat;

    mat.m00 = m12*m23*m31 - m13*m22*m31 + m13*m21*m32 - m11*m23*m32 - m12*m21*m33 + m11*m22*m33;
    mat.m01 = m03*m22*m31 - m02*m23*m31 - m03*m21*m32 + m01*m23*m32 + m02*m21*m33 - m01*m22*m33;
    mat.m02 = m02*m13*m31 - m03*m12*m31 + m03*m11*m32 - m01*m13*m32 - m02*m11*m33 + m01*m12*m33;
    mat.m03 = m03*m12*m21 - m02*m13*m21 - m03*m11*m22 + m01*m13*m22 + m02*m11*m23 - m01*m12*m23;
    mat.m10 = m13*m22*m30 - m12*m23*m30 - m13*m20*m32 + m10*m23*m32 + m12*m20*m33 - m10*m22*m33;
    mat.m11 = m02*m23*m30 - m03*m22*m30 + m03*m20*m32 - m00*m23*m32 - m02*m20*m33 + m00*m22*m33;
    mat.m12 = m03*m12*m30 - m02*m13*m30 - m03*m10*m32 + m00*m13*m32 + m02*m10*m33 - m00*m12*m33;
    mat.m13 = m02*m13*m20 - m03*m12*m20 + m03*m10*m22 - m00*m13*m22 - m02*m10*m23 + m00*m12*m23;
    mat.m20 = m11*m23*m30 - m13*m21*m30 + m13*m20*m31 - m10*m23*m31 - m11*m20*m33 + m10*m21*m33;
    mat.m21 = m03*m21*m30 - m01*m23*m30 - m03*m20*m31 + m00*m23*m31 + m01*m20*m33 - m00*m21*m33;
    mat.m22 = m01*m13*m30 - m03*m11*m30 + m03*m10*m31 - m00*m13*m31 - m01*m10*m33 + m00*m11*m33;
    mat.m23 = m03*m11*m20 - m01*m13*m20 - m03*m10*m21 + m00*m13*m21 + m01*m10*m23 - m00*m11*m23;
    mat.m30 = m12*m21*m30 - m11*m22*m30 - m12*m20*m31 + m10*m22*m31 + m11*m20*m32 - m10*m21*m32;
    mat.m31 = m01*m22*m30 - m02*m21*m30 + m02*m20*m31 - m00*m22*m31 - m01*m20*m32 + m00*m21*m32;
    mat.m32 = m02*m11*m30 - m01*m12*m30 - m02*m10*m31 + m00*m12*m31 + m01*m10*m32 - m00*m11*m32;
    mat.m33 = m01*m12*m20 - m02*m11*m20 + m02*m10*m21 - m00*m12*m21 - m01*m10*m22 + m00*m11*m22;

    mat = mat/det;

    return mat;

#else
    Matrix3 mtemp;
    Matrix mat;
    int i, j, sign;

    if ( FCOMPARE(mdet,0.0f) )
      return mat;

    Real _1omdet = 1/mdet;
    for ( i = 0; i < 4; i++ )
      for ( j = 0; j < 4; j++ )
      {
        sign = 1 - ( (i +j) % 2 ) * 2;

        mtemp = GetSubMatrix(i,j);

        mat.m_data[i+j*4] = ( mtemp.Determinant() * sign ) * _1omdet;
      }
      return mat;
#endif

  }

//   //------------------------------------------------ Matrix::GetSubMatrix
//   chain::Matrix3 Matrix::GetSubMatrix( const unsigned i, const unsigned j ) const
//   {
//     int ti, tj, idst, jdst;
//     Matrix3 mat;
//
//     for ( ti = 0; ti < 4; ti++ )
//     {
//       if ( ti < i )
//         idst = ti;
//       else
//         if ( ti > i )
//           idst = ti-1;
//
//       for ( tj = 0; tj < 4; tj++ )
//       {
//         if ( tj < j )
//           jdst = tj;
//         else
//           if ( tj > j )
//             jdst = tj-1;
//
//         // if it isn't the column or row (i,j), then grab it
//         if ( ti != i && tj != j )
//           mat.m_data[idst*3 + jdst] = m_data[ti*4 + tj];
//       }
//     }
//
//     return mat;
//   }

  //------------------------------------------------ Matrix::ToQuat
  Quaternion Matrix::ToQuat() const
  {
    // note: the addition of 1 was missed out in example, some I'm following that
    // may turn out dodgy

    Matrix m = this->GetTranspose();

    Real T = m.m_data[0] + m.m_data[5] + m.m_data[10] /*+ 1*/;
    if (T>0.0000001)
    { // do 'instant' calculation
      Real S = sqrt (T+1);
      Real w = 0.5f*S;
      S = 0.5f/S;

      return Quaternion (
        (m.m_data[9] - m.m_data[6])*S,
        (m.m_data[2] - m.m_data[8])*S,
        (m.m_data[4] - m.m_data[1])*S, w );
    }

    // identify which major diagonal element has the greatest value
    Real greatest = m.m_data[0];
    unsigned char c = 0;
    if (m.m_data[5] > greatest)
    {
      c = 1;
      greatest = m.m_data[5];
    }
    if (m.m_data[10] > greatest)
    {
      c = 1;
      greatest = m.m_data[10];
    }

    switch(c)
    {
    case 0:
      {
        Real S = sqrt( 1.0f + m.m_data[0] - m.m_data[5] - m.m_data[10]);
        Real _s = S * 0.5f;
        if (S != 0.0f)
          S = 0.5f/S;

        return Quaternion (
          _s,
          (m.m_data[4] + m.m_data[1]) * S,
          (m.m_data[2] + m.m_data[8]) * S,
          (m.m_data[9] - m.m_data[6]) * S);
      }
    	break;
    case 1:
      {
        Real S = sqrt( 1.0f + m.m_data[5] - m.m_data[0] - m.m_data[10]);
        Real _s = S * 0.5f;
        if (S != 0.0f)
          S = 0.5f/S;

        return Quaternion (
          (m.m_data[4] + m.m_data[1]) * S,
          _s,
          (m.m_data[9] + m.m_data[6]) * S,
          (m.m_data[2] - m.m_data[8]) * S);
      }
    	break;
    case 2:
      {
        Real S = sqrt( 1.0f + m.m_data[10] - m.m_data[0] - m.m_data[5]);
        Real _s = S * 0.5f;
        if (S != 0.0f)
          S = 0.5f/S;

        return Quaternion (
          (m.m_data[2] + m.m_data[8]) * S,
          (m.m_data[9] + m.m_data[6]) * S,
          _s,
          (m.m_data[4] - m.m_data[1]) * S);
      }
      break;
    default:
      assert(0);
      break;
    }

    return Quaternion();
  }

  //------------------------------------------------ operator *  Matrix
  Matrix Matrix::operator * (const Matrix& m) const
  {
    Matrix Nm;

    // -------------------------------- row 0
    Nm.m00  =  m00 * m.m00;
    Nm.m01  =  m01 * m.m00;
    Nm.m02  =  m02 * m.m00;
    Nm.m03  =  m03 * m.m00;

    Nm.m00 +=  m10 * m.m01;
    Nm.m01 +=  m11 * m.m01;
    Nm.m02 +=  m12 * m.m01;
    Nm.m03 +=  m13 * m.m01;

    Nm.m00 +=  m20 * m.m02;
    Nm.m01 +=  m21 * m.m02;
    Nm.m02 +=  m22 * m.m02;
    Nm.m03 +=  m23 * m.m02;

    Nm.m00 +=  m30 * m.m03;
    Nm.m01 +=  m31 * m.m03;
    Nm.m02 +=  m32 * m.m03;
    Nm.m03 +=  m33 * m.m03;

    // -------------------------------- row 1
    Nm.m10  =  m00 * m.m10;
    Nm.m11  =  m01 * m.m10;
    Nm.m12  =  m02 * m.m10;
    Nm.m13  =  m03 * m.m10;

    Nm.m10 +=  m10 * m.m11;
    Nm.m11 +=  m11 * m.m11;
    Nm.m12 +=  m12 * m.m11;
    Nm.m13 +=  m13 * m.m11;

    Nm.m10 +=  m20 * m.m12;
    Nm.m11 +=  m21 * m.m12;
    Nm.m12 +=  m22 * m.m12;
    Nm.m13 +=  m23 * m.m12;

    Nm.m10 +=  m30 * m.m13;
    Nm.m11 +=  m31 * m.m13;
    Nm.m12 +=  m32 * m.m13;
    Nm.m13 +=  m33 * m.m13;

    // -------------------------------- row 2
    Nm.m20  =  m00 * m.m20;
    Nm.m21  =  m01 * m.m20;
    Nm.m22  =  m02 * m.m20;
    Nm.m23  =  m03 * m.m20;

    Nm.m20 +=  m10 * m.m21;
    Nm.m21 +=  m11 * m.m21;
    Nm.m22 +=  m12 * m.m21;
    Nm.m23 +=  m13 * m.m21;

    Nm.m20 +=  m20 * m.m22;
    Nm.m21 +=  m21 * m.m22;
    Nm.m22 +=  m22 * m.m22;
    Nm.m23 +=  m23 * m.m22;

    Nm.m20 +=  m30 * m.m23;
    Nm.m21 +=  m31 * m.m23;
    Nm.m22 +=  m32 * m.m23;
    Nm.m23 +=  m33 * m.m23;

    // -------------------------------- row 3
    Nm.m30  =  m00 * m.m30;
    Nm.m31  =  m01 * m.m30;
    Nm.m32  =  m02 * m.m30;
    Nm.m33  =  m03 * m.m30;

    Nm.m30 +=  m10 * m.m31;
    Nm.m31 +=  m11 * m.m31;
    Nm.m32 +=  m12 * m.m31;
    Nm.m33 +=  m13 * m.m31;

    Nm.m30 +=  m20 * m.m32;
    Nm.m31 +=  m21 * m.m32;
    Nm.m32 +=  m22 * m.m32;
    Nm.m33 +=  m23 * m.m32;

    Nm.m30 +=  m30 * m.m33;
    Nm.m31 +=  m31 * m.m33;
    Nm.m32 +=  m32 * m.m33;
    Nm.m33 +=  m33 * m.m33;

    return Nm;
  }

  //------------------------------------------------ operator *  Vector
  Vector3 Matrix::operator *  (const Vector3& v) const
  {
    Vector3 Nv;

    // working with vector3 not vector4 (so no w value)




#if 1
    Nv.x  = m00 * v.x;
    Nv.x += m10 * v.y;
    Nv.x += m20 * v.z;
    Nv.x += m30;// * v.w;

    Nv.y  = m01 * v.x;
    Nv.y += m11 * v.y;
    Nv.y += m21 * v.z;
    Nv.y += m31;// * v.w;

    Nv.z  = m02 * v.x;
    Nv.z += m12 * v.y;
    Nv.z += m22 * v.z;
    Nv.z += m32;// * v.w;

    //Nv.w  = m03 * v.x;
    //Nv.w += m13 * v.y;
    //Nv.w += m23 * v.z;
    //Nv.x += m33 * v.w;

#else

    Nv.x  = m00 * v.x;
    Nv.x += m01 * v.y;
    Nv.x += m02 * v.z;
    //Nv.x += m03 * v.w;
    Nv.x += m30;

    Nv.y  = m10 * v.x;
    Nv.y += m11 * v.y;
    Nv.y += m12 * v.z;
    //Nv.x += m13 * v.w;
    Nv.x += m31;

    Nv.z  = m20 * v.x;
    Nv.z += m21 * v.y;
    Nv.z += m22 * v.z;
    //Nv.x += m23 * v.w;
    Nv.x += m32;

    //Nv.w  = m30 * v.x;
    //Nv.w += m31 * v.y;
    //Nv.w += m32 * v.z;
    //Nv.x += m33 * v.w;
#endif


    return Nv;
  }

  //------------------------------------------------ operator *= Matrix
  const Matrix& Matrix::operator *= (const Matrix& m)
  {
    Matrix Nm (*this);

    // -------------------------------- row 0
    m00  =  Nm.m00 * m.m00;
    m01  =  Nm.m01 * m.m00;
    m02  =  Nm.m02 * m.m00;
    m03  =  Nm.m03 * m.m00;

    m00 +=  Nm.m10 * m.m01;
    m01 +=  Nm.m11 * m.m01;
    m02 +=  Nm.m12 * m.m01;
    m03 +=  Nm.m13 * m.m01;

    m00 +=  Nm.m20 * m.m02;
    m01 +=  Nm.m21 * m.m02;
    m02 +=  Nm.m22 * m.m02;
    m03 +=  Nm.m23 * m.m02;

    m00 +=  Nm.m30 * m.m03;
    m01 +=  Nm.m31 * m.m03;
    m02 +=  Nm.m32 * m.m03;
    m03 +=  Nm.m33 * m.m03;

    // -------------------------------- row 1
    m10  =  Nm.m00 * m.m10;
    m11  =  Nm.m01 * m.m10;
    m12  =  Nm.m02 * m.m10;
    m13  =  Nm.m03 * m.m10;

    m10 +=  Nm.m10 * m.m11;
    m11 +=  Nm.m11 * m.m11;
    m12 +=  Nm.m12 * m.m11;
    m13 +=  Nm.m13 * m.m11;

    m10 +=  Nm.m20 * m.m12;
    m11 +=  Nm.m21 * m.m12;
    m12 +=  Nm.m22 * m.m12;
    m13 +=  Nm.m23 * m.m12;

    m10 +=  Nm.m30 * m.m13;
    m11 +=  Nm.m31 * m.m13;
    m12 +=  Nm.m32 * m.m13;
    m13 +=  Nm.m33 * m.m13;

    // -------------------------------- row 2
    m20  =  Nm.m00 * m.m20;
    m21  =  Nm.m01 * m.m20;
    m22  =  Nm.m02 * m.m20;
    m23  =  Nm.m03 * m.m20;

    m20 +=  Nm.m10 * m.m21;
    m21 +=  Nm.m11 * m.m21;
    m22 +=  Nm.m12 * m.m21;
    m23 +=  Nm.m13 * m.m21;

    m20 +=  Nm.m20 * m.m22;
    m21 +=  Nm.m21 * m.m22;
    m22 +=  Nm.m22 * m.m22;
    m23 +=  Nm.m23 * m.m22;

    m20 +=  Nm.m30 * m.m23;
    m21 +=  Nm.m31 * m.m23;
    m22 +=  Nm.m32 * m.m23;
    m23 +=  Nm.m33 * m.m23;

    // -------------------------------- row 3
    m30  =  Nm.m00 * m.m30;
    m31  =  Nm.m01 * m.m30;
    m32  =  Nm.m02 * m.m30;
    m33  =  Nm.m03 * m.m30;

    m30 +=  Nm.m10 * m.m31;
    m31 +=  Nm.m11 * m.m31;
    m32 +=  Nm.m12 * m.m31;
    m33 +=  Nm.m13 * m.m31;

    m30 +=  Nm.m20 * m.m32;
    m31 +=  Nm.m21 * m.m32;
    m32 +=  Nm.m22 * m.m32;
    m33 +=  Nm.m23 * m.m32;

    m30 +=  Nm.m30 * m.m33;
    m31 +=  Nm.m31 * m.m33;
    m32 +=  Nm.m32 * m.m33;
    m33 +=  Nm.m33 * m.m33;

    return *this;
  }

  //------------------------------------------------ Matrix::NewXAxisRotation
  chain::Matrix Matrix::NewXAxisRotation( const Real& a )
  {
    // transposed from 'norm' due to translation being on the bottom
    return Matrix ( 1,     0     ,     0     , 0,
                    0, CH_COS(a), CH_SIN(a), 0,
                    0,-CH_SIN(a), CH_COS(a), 0,
                    0,     0     ,     0     , 1);
  }

  //------------------------------------------------ Matrix::NewYAxisRotation
  chain::Matrix Matrix::NewYAxisRotation( const Real& a )
  {
    // transposed from 'norm' due to translation being on the bottom
    return Matrix ( CH_COS(a), 0,-CH_SIN(a), 0,
                        0     , 1,     0     , 0,
                    CH_SIN(a), 0, CH_COS(a), 0,
                        0     , 0,     0     , 1);
  }

  //------------------------------------------------ Matrix::NewZAxisRotation
  chain::Matrix Matrix::NewZAxisRotation( const Real& a )
  {
    // transposed from 'norm' due to translation being on the bottom
    return Matrix ( CH_COS(a), CH_SIN(a), 0, 0,
                   -CH_SIN(a), CH_COS(a), 0, 0,
                        0     ,     0     , 0, 0,
                        0     ,     0     , 0, 0);
  }

  //------------------------------------------------ Matrix::NewQuaternionRotation
  chain::Matrix Matrix::NewQuaternionRotation( const Quaternion& q )
  {
    return q.ToMatrix();
  }

  //------------------------------------------------ Matrix::NewTranslation
  chain::Matrix Matrix::NewTranslation( const Vector3& t )
  {
    // transposed from 'norm' due to translation being on the bottom
    return Matrix ( 1 , 0 , 0 , 0,
                    0 , 1 , 0 , 0,
                    0 , 0 , 1 , 0,
                   t.x,t.y,t.z, 1);
  }

#if 0
  //-------------------------------------------------- Vector *= Matrix
  const Vector3& operator *= (Vector3 &v,const Matrix &m)
  {
    Vector3 Nv (v);
    v.x  = m.m00 * Nv.x;
    v.x += m.m01 * Nv.y;
    v.x += m.m02 * Nv.z;
    //v.x += m.m03 * Nv.w;
    v.x += m.m03;

    v.y  = m.m10 * Nv.x;
    v.y += m.m11 * Nv.y;
    v.y += m.m12 * Nv.z;
    //v.y += m.m13 * Nv.w;
    v.y += m.m13;

    v.z  = m.m20 * Nv.x;
    v.z += m.m21 * Nv.y;
    v.z += m.m22 * Nv.z;
    //v.z += m.m23 * Nv.w;
    v.z += m.m23;

    //v.w  = m.m30 * Nv.x;
    //v.w += m.m31 * Nv.y;
    //v.w += m.m32 * Nv.z;
    //v.w += m.m33 * Nv.w;

    return v;
  }
#endif // 0

  //------------------------------------------------ operator *  Real
  Matrix Matrix::operator * (const Real& d) const
  {
    Matrix m (*this);
    Real* endit = m.m_data + 16;
    for(Real* p=m.m_data;p!=endit;++p)
    {
      (*p) *= d;
    }
    return m;
  }

  //------------------------------------------------ operator /  Real
  Matrix Matrix::operator / (const Real& d) const
  {
    Matrix m (*this);
    Real _1ov_d = 1/d;
    Real* endit = m.m_data + 16;
    for(Real* p=m.m_data;p!=endit;++p)
    {
      (*p) *= _1ov_d;
    }
    return m;
  }

  //------------------------------------------------ operator *= Real
  const Matrix& Matrix::operator *= (const Real& d)
  {
    Real* endit = m_data + 16;
    for(Real* p=m_data;p!=endit;++p)
    {
      (*p) *= d;
    }
    return *this;
  }

  //------------------------------------------------ operator /= Real
  const Matrix& Matrix::operator /= (const Real& d)
  {
    Real _1ov_d = 1/d;
    Real* endit = m_data + 16;
    for(Real* p=m_data;p!=endit;++p)
    {
      (*p) *= _1ov_d;
    }
    return *this;
  }

  //------------------------------------------------ operator =  Matrix
	const Matrix& Matrix::operator = (const Matrix& m)
  {
    m00 = m.m00; m01 = m.m01; m02 = m.m02; m03 = m.m03;
    m10 = m.m10; m11 = m.m11; m12 = m.m12; m13 = m.m13;
    m20 = m.m20; m21 = m.m21; m22 = m.m22; m23 = m.m23;
    m30 = m.m30; m31 = m.m31; m32 = m.m32; m33 = m.m33;
    return *this;
  }

  const Matrix& Matrix::operator=( Quaternion& q )
  {
    return *this = q.ToMatrix();
  }

  //------------------------------------------------ operator == Matrix
	bool Matrix::operator == (const Matrix& m) const
  {
    return FCOMPARE( m00, m.m00 ) &&
           FCOMPARE( m01, m.m01 ) &&
           FCOMPARE( m02, m.m02 ) &&
           FCOMPARE( m03, m.m03 ) &&

           FCOMPARE( m10, m.m10 ) &&
           FCOMPARE( m11, m.m11 ) &&
           FCOMPARE( m12, m.m12 ) &&
           FCOMPARE( m13, m.m13 ) &&

           FCOMPARE( m20, m.m20 ) &&
           FCOMPARE( m21, m.m21 ) &&
           FCOMPARE( m22, m.m22 ) &&
           FCOMPARE( m23, m.m23 ) &&

           FCOMPARE( m30, m.m30 ) &&
           FCOMPARE( m31, m.m31 ) &&
           FCOMPARE( m32, m.m32 ) &&
           FCOMPARE( m33, m.m33 );
  }

  //------------------------------------------------ operator != Matrix
	bool Matrix::operator != (const Matrix& m) const
  {
    if( !FCOMPARE( m00, m.m00 ) ||
        !FCOMPARE( m01, m.m01 ) ||
        !FCOMPARE( m02, m.m02 ) ||
        !FCOMPARE( m03, m.m03 ) ||

        !FCOMPARE( m10, m.m10 ) ||
        !FCOMPARE( m11, m.m11 ) ||
        !FCOMPARE( m12, m.m12 ) ||
        !FCOMPARE( m13, m.m13 ) ||

        !FCOMPARE( m20, m.m20 ) ||
        !FCOMPARE( m21, m.m21 ) ||
        !FCOMPARE( m22, m.m22 ) ||
        !FCOMPARE( m23, m.m23 ) ||

        !FCOMPARE( m30, m.m30 ) ||
        !FCOMPARE( m31, m.m31 ) ||
        !FCOMPARE( m32, m.m32 ) ||
        !FCOMPARE( m33, m.m33 ) )
        return true;
    return false;
  }

  //------------------------------------------------- ostream << Matrix
  std::ostream& operator << (std::ostream &s, const Matrix& m)
  {
    s << m.m00 << " ";
	  s << m.m01 << " ";
	  s << m.m02 << " ";
	  s << m.m03 << "\n";

	  s << m.m10 << " ";
	  s << m.m11 << " ";
	  s << m.m12 << " ";
	  s << m.m13 << "\n";

	  s << m.m20 << " ";
	  s << m.m21 << " ";
	  s << m.m22 << " ";
	  s << m.m23 << "\n";

	  s << m.m30 << " ";
	  s << m.m31 << " ";
	  s << m.m32 << " ";
	  s << m.m33 << "\n";
	  return s;
  }
}
