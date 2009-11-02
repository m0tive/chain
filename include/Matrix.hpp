/// \file Matrix.hpp
/// \date 2007/11/13
/// \author Peter Dodds
/// \brief chain::Matrix structure declaration
/// \note
//------------------------------------------------------------------------------

#ifdef _MSC_VER
#pragma once
#endif

#ifndef _chain_Matrix_h_
#define _chain_Matrix_h_

#include "Def.hpp"
#include <iostream>

namespace chain
{
  struct Quaternion;
  struct Vector3;
  //struct Matrix3;

#pragma pack(push,1)

  /// \brief Structure to hold a 4x4 matrix, in openGL format
  /// \note Matrix::m_data in OpenGL format :
  /// \par
  /// <tt>|x0 y0 z0 0|</tt>\n
  /// <tt>|x1 y1 z1 0|</tt>\n
  /// <tt>|x2 y2 z2 0|</tt>\n
  /// <tt>|tx ty tz 1|</tt>\n
  struct Matrix
  {
    //---------------------------------------
    /// \details Default constructor taking initial values for individual matrix elements.\n
    /// In format :
    /// \par
    /// <tt>|x0 y0 z0 w0|</tt>\n
    /// <tt>|x1 y1 z1 w1|</tt>\n
    /// <tt>|x2 y2 z2 w2|</tt>\n
    /// <tt>|tx ty tz tw|</tt>\n
    /// \note default value is the identity matrix
    /// \see Identity()
    Matrix(Real x0 = 1, Real y0 = 0, Real z0 = 0, Real w0 = 0,
           Real x1 = 0, Real y1 = 1, Real z1 = 0, Real w1 = 0,
           Real x2 = 0, Real y2 = 0, Real z2 = 1, Real w2 = 0,
           Real tx = 0, Real ty = 0, Real tz = 0, Real tw = 1);
    //---------------------------------------
    /// \details Constructor using a Matrix
    Matrix(const Matrix& m);
    //---------------------------------------
    /// \details Constructor using a Vector3 to create a translation matrix
    /// \par
    /// <tt>|1 0 0 0|</tt>\n
    /// <tt>|0 1 0 0|</tt>\n
    /// <tt>|0 0 1 0|</tt>\n
    /// <tt>|x y z 1|</tt>\n
    /// \deprecated See Matrix::NewTranslation()
    Matrix(const Vector3& translation);
    //---------------------------------------
    /// \details Constructor taking a Quaternion to create a rotation matrix
    /// \par
    /// <tt>|R R R 0|</tt>\n
    /// <tt>|R R R 0|</tt>\n
    /// <tt>|R R R 0|</tt>\n
    /// <tt>|0 0 0 1|</tt>\n
    /// \see Quaternion::ToMatrix()
    /// \deprecated See Matrix::NewQuaternionRotation()
    Matrix(const Quaternion& rotation);
    //---------------------------------------
    /// \details Destructor
    ~Matrix();

    //---------------------------------------
    /// \brief Load the identity matrix
    /// \par
    /// <tt>|1 0 0 0|</tt>\n
    /// <tt>|0 1 0 0|</tt>\n
    /// <tt>|0 0 1 0|</tt>\n
    /// <tt>|0 0 0 1|</tt>\n
    const Matrix& Identity();

    //---------------------------------------
    /// \brief Transpose this matrix
    /// \details Reflect matrix by its main diagonal, top left to bottom right.
    /// \par
    /// <tt>|01 02 03 04| ---> |01 05 09 13|</tt>\n
    /// <tt>|05 06 07 08| ---> |02 06 10 14|</tt>\n
    /// <tt>|09 10 11 12| ---> |03 07 11 15|</tt>\n
    /// <tt>|13 14 15 16| ---> |04 08 12 16|</tt>\n
    /// \return const Matrix& - the transposed matrix
    const Matrix& Transpose();
    //---------------------------------------
    /// \brief Get the transpose of this matrix
    /// \return Matrix - the transposed matrix
    /// \see Transpose()
    Matrix GetTranspose() const;

    //---------------------------------------
    /// \brief Calculate the determinant of this matrix
    /// \return Real - the determinant
    Real Determinant() const;
    //---------------------------------------
    /// \brief Invert this matrix
    /// \return const Matrix& - the inverted matrix
    /// \note If there is no inverse to this matrix, it has a determinant of 0,
    /// the identity matrix will be returned
    const Matrix& Invert();
    //---------------------------------------
    /// \brief Get the inverse of this matrix
    /// \return Matrix - the inverted matrix
    /// \note If there is no inverse to this matrix, it has a determinant of 0,
    /// the identity matrix will be returned
    /// \see Invert()
    Matrix GetInverse() const;

    //Matrix3 GetSubMatrix (const unsigned i, const unsigned j) const;

    // -----------------------------------
    /// \brief Get the quaternion rotation of this matrix
    /// \details Convert the rotation components of this matrix
    /// into a quaternion rotation
    /// \returns Quaternion - the quaternion rotation
    Quaternion ToQuat () const;

    // -----------------------------------
    /// \details Multiply two matrices together to get a combined transform
    /// \param m - rhs of operation
    /// \returns Matrix - result matrix
    /// \note This operation is not commutative.
    Matrix operator * (const Matrix& m) const;
    // -----------------------------------
    /// \details Multiply a Vector3 by this matrix. This is the
    /// same as applying the matrix transform onto a 3D point
    /// \param v - rhs of operation
    /// \returns Vector3 - result vector
    Vector3 operator * (const Vector3& v) const;
    // -----------------------------------
    /// \details Matrix-Matrix multiplication compound assignment see operator*()
    /// \param m - rhs of operation
    /// \returns const Matrix& - this matrix
    const Matrix& operator *= (const Matrix& m);
#if 0
    // -----------------------------------
    /// \details Matrix-Vector multiplication compound assignment see operator*().\n
    /// This operation re-organises the arguments.\n
    /// \par
    /// <tt>v *= m</tt>, becomes, <tt>v = m * v</tt>
    /// \param v - lhs of operation
    /// \param m - rhs of operation
    /// \returns const Vector3& - the new value of \a v
    friend const Vector3& operator *= (Vector3 &v,const Matrix &m);
#endif // 0

    // -----------------------------------
    /// \details Multiply this matrix
    /// \param d - rhs of operation
    /// \returns Matrix - result matrix
    Matrix operator * (const Real& d) const;
    // -----------------------------------
    /// \details Divide this matrix
    /// \param d - rhs of operation
    /// \returns Matrix - result matrix
    Matrix operator / (const Real& d) const;
    // -----------------------------------
    /// \details Multiplication compound assignment see operator*()
    /// \param d - rhs of operation
    /// \returns const Matrix& - result matrix
    const Matrix& operator *= (const Real& d);
    // -----------------------------------
    /// \details Division compound assignment see operator/()
    /// \param d - rhs of operation
    /// \returns const Matrix& - result matrix
    const Matrix& operator /= (const Real& d);

    // -----------------------------------
    /// \details Assignment operator using a matrix
    /// \param m - rhs of operation
    /// \returns const Matrix& - this matrix
		const Matrix& operator = (const Matrix& m);
    // -----------------------------------
    /// \details Assignment operator using a Quaternion to
    /// create a rotation matrix
    /// \par
    /// <tt>|R R R 0|</tt>\n
    /// <tt>|R R R 0|</tt>\n
    /// <tt>|R R R 0|</tt>\n
    /// <tt>|0 0 0 1|</tt>\n
    /// \param q - rhs of operation
    /// \returns const Matrix& - this matrix
    /// \see Quaternion::ToMatrix()
    const Matrix& operator = (Quaternion& q);

    // -----------------------------------
    /// \details Equal comparison operation, using FCOMPARE()
    /// \param m - rhs of operation
    /// \returns bool
    bool operator == (const Matrix& m) const;
    // -----------------------------------
    /// \details Not-equal comparison operation, using FCOMPARE()
    /// \param m - rhs of operation
    /// \returns bool
		bool operator != (const Matrix& m) const;

    // -----------------------------------
    /// \brief Out stream operator
    /// \details In format:
    /// \par
    /// <tt>m00 m01 m02 m03\n
    /// m10 m11 m12 m13\n
    /// m20 m21 m22 m23\n
    /// m30 m31 m32 m33</tt>
    /// \par See
    /// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/iostream/ostream/">std::ostream</A>
    friend std::ostream& operator << (std::ostream &s, const Matrix& m);

    union
    {
      struct
      {
        Real m00, m01, m02, m03;
        Real m10, m11, m12, m13;
        Real m20, m21, m22, m23;
        Real m30, m31, m32, m33;
      };
      Real m_data[16];
    };

    /// \var Real Matrix::m00
    /// \details x0

    /// \var Real Matrix::m01
    /// \details y0

    /// \var Real Matrix::m02
    /// \details z0

    /// \var Real Matrix::m03
    /// \details w0


    /// \var Real Matrix::m10
    /// \details x1

    /// \var Real Matrix::m11
    /// \details y1

    /// \var Real Matrix::m12
    /// \details z1

    /// \var Real Matrix::m13
    /// \details w1


    /// \var Real Matrix::m20
    /// \details x2

    /// \var Real Matrix::m21
    /// \details y2

    /// \var Real Matrix::m22
    /// \details z2

    /// \var Real Matrix::m23
    /// \details w2


    /// \var Real Matrix::m30
    /// \details tz - X translation component

    /// \var Real Matrix::m31
    /// \details ty - Y translation component

    /// \var Real Matrix::m32
    /// \details tz - Z translation component

    /// \var Real Matrix::m33
    /// \details tw


    /// \var Real Matrix::m_data[16]
    /// \brief Array data interface
    /// \details Array to access matrix, compatible with OpenGL


    static Matrix NewXAxisRotation (const Real& a);
    static Matrix NewYAxisRotation (const Real& a);
    static Matrix NewZAxisRotation (const Real& a);
    static Matrix NewQuaternionRotation (const Quaternion& q);

    static Matrix NewTranslation (const Vector3& t);
  };
#pragma pack(pop)
}

#endif
