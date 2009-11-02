/// \file Quaternion.hpp
/// \date 2007/12/07
/// \author Peter Dodds
/// \brief chain::Quaternion structure declaration
/// \note
//------------------------------------------------------------------------------

#ifdef _MSC_VER
#pragma once
#endif

#ifndef _chain_Quaternion_h_
#define _chain_Quaternion_h_

#include <iostream>
#include "Def.hpp"

namespace chain
{
  struct Matrix;
  struct EulerAngle;

#pragma pack(push,1)

  /// \brief Structure to hold a quaternion
  /// \details A normalised quaternion to represent a rotation in 3D about an arbitrary axis
  struct Quaternion
  {
  public:
    // -----------------------------------
    /// \details Default constructor taking initial values for \a x, \a y, \a z and \a w
    /// \param _x - initial value of Quaternion::x
    /// \param _y - initial value of Quaternion::y
    /// \param _z - initial value of Quaternion::z
    /// \param _w - initial value of Quaternion::w
    /// \note To be a valid quaternion rotation the magnitude of 1
    Quaternion(const Real& _x = 0, const Real& _y = 0, const Real& _z = 0, const Real& _w = 1);
    // -----------------------------------
    /// \details Constructor using a Quaternion
    /// \param q - quaternion
    Quaternion (const Quaternion& q);
    // -----------------------------------
    /// \details Constructor using a Matrix
    /// \param m - matrix
    /// \see Matrix::ToQuat()
    Quaternion (Matrix& m);

    // -----------------------------------
    /// \brief Set the values of \a x, \a y, \a z and \a w
    /// \param _x - new value of Quaternion::x
    /// \param _y - new value of Quaternion::y
    /// \param _z - new value of Quaternion::z
    /// \param _w - new value of Quaternion::w
    /// \returns const Quaternion& - this quaternion
    /// \note To be a valid quaternion rotation the magnitude of 1
    const Quaternion& Set (const Real& _x = 0, const Real& _y = 0, const Real& _z = 0, const Real& _w = 1);
    // -----------------------------------
    /// \brief Set the value of the rotation using an axis angle
    /// \details Axis angle is defined by a axis to rotate about (\a _x, \a _y, \a _z), and the angle to rotate by
    /// \param angle - angle to be rotated (in \b radians)
    /// \param _x - x component of axis
    /// \param _y - y component of axis
    /// \param _z - z component of axis
    /// \returns const Quaternion& - this quaternion
    /// \see ToAxisAngles()
    const Quaternion& SetAxisAngle (const Real& angle, const Real& _x, const Real& _y, const Real& _z );

    // -----------------------------------
    /// \brief Convert quaternion to a rotation matrix
    /// \returns Matrix - result matrix
    Matrix ToMatrix () const;
    // -----------------------------------
    /// \brief Convert quaternion to a axis angle
    /// \details Axis angle is defined by a axis to rotate about (\a _x, \a _y, \a _z), and the angle to rotate by
    /// \param[out] angle - angle rotated by (in \b radians)
    /// \param[out] _x - x component of axis
    /// \param[out] _y - y component of axis
    /// \param[out] _z - z component of axis
    /// \see SetAxisAngle()
    void ToAxisAngles (Real& angle, Real& _x, Real& _y, Real& _z) const;
    // -----------------------------------
    /// \brief Convert quaternion to euler angles
    /// \returns EulerAngle - result euler angle
    /// \warning Euler angle rotation is not equivalent to quaternion rotation.
    /// \see EulerAngle EulerAngle::FromQuat()
    EulerAngle ToEulerAngles () const;

    // -----------------------------------
    /// \brief Get the angle of rotation
    /// \returns chain::Real - angle of rotation in radians
    Real GetAngle ();

    // -----------------------------------
    /// \brief Split quaternion rotation into component rotations
    /// \details Split into roll, pitch, yaw (rotations about x, y, and z axis respectively).
    /// \par
    /// recombined in this order:\n<tt>R = _z * _y * _x</tt>
    /// \param[out] _x - x-axis rotation
    /// \param[out] _y - y-axis rotation
    /// \param[out] _z - z-axis rotation
    void Split (Quaternion& _x, Quaternion& _y, Quaternion& _z) const;
    //Quaternion GetRoll () const;
    //Quaternion GetPitch () const;
    //Quaternion GetYaw () const;
    //Real GetRollAngle () const;
    //Real GetPitchAngle () const;
    //Real GetYawAngle () const;

    // -----------------------------------
    /// \brief Normalise this quaternion
    /// \returns const Quaternion& - this quaternion
    const Quaternion& Normalise ();
    // -----------------------------------
    /// \brief Calculate the normalised quaternion
    /// \returns const Quaternion& - normalised quaternion
    Quaternion Normalised() const;

    // -----------------------------------
    /// \brief ScaleTo this quaternion to a new angle
    /// \param s - new angle to scale to
    /// \returns const Quaternion& - the quaternion
    const Quaternion& ScaleTo (Real s);

    // -----------------------------------
    /// \brief Calculate quaternion's magnitude squared
    /// \details similar to Magnitude(), but avoiding CH_SQRT()
    /// \returns Real - the magnitude squared
    Real MagnitudeSquared () const;
    // -----------------------------------
    /// \brief Calculate quaternion's magnitude
    /// \details similar to Magnitude(), but using CH_SQRT()
    /// \returns Real - the magnitude
    Real Magnitude () const;

    // -----------------------------------
    /// \brief Calculate the conjugate of this quaternion
    /// \details This is equvilent to the inverse of a normalised
    /// quaternion and therefore opposite rotation to that
    /// defined by this quaternion
    /// \returns chain::Quaternion - conjugate of this quaternion
    Quaternion Conjugate () const;

    // -----------------------------------
    /// \brief Get the inverse of this quaternion
    /// \details This uses Conjugate()
    /// \returns chain::Quaternion -
    /// \warning The quaternion is assumed to be normalised.
    Quaternion operator- () const;

    // -----------------------------------
    /// \details Multiply two quaternions. With normalised rotation quaternions, this can be
    /// seen to be similar to vector addition. Multiplication by the inverse
    /// quaternion would then be equivalent to vector subtraction
    Quaternion operator* (const Quaternion& q) const;
    // -----------------------------------
    /// \details Multiply a quaternion. This uses SLERP()
    Quaternion operator* (const Real& r) const;
    // -----------------------------------
    /// \details Divide a quaternion. This uses SLERP()
    Quaternion operator/ (const Real& r) const;

    // -----------------------------------
    /// \details Assignment operation using a quaternion
    const Quaternion& operator= (const Quaternion& q);
    // -----------------------------------
    /// \details Assignment operation using a rotation matrix
    /// \see ToMatrix()
    const Quaternion& operator= (const Matrix& m);

    // -----------------------------------
    /// \details Equal comparison operation, using FCOMPARE()
    bool operator== (const Quaternion& q) const;
    // -----------------------------------
    /// \details Not-equal comparison operation, using FCOMPARE()
    bool operator!= (const Quaternion& q) const;

    // -----------------------------------
    /// \brief Out stream operator
    /// \details In format:
    /// \par
    /// <tt>x y z w</tt>
    /// \par See
    /// <A TARGET="_parent" HREF="http://www.cplusplus.com/reference/iostream/ostream/">std::ostream</A>
    friend std::ostream& operator << (std::ostream& os,const Quaternion &q);

    // -----------------------------------
    /// \brief Spherical Linear Interpolation.
    /// \details Interpolate between two normalised quaternion rotations
    /// \param q1 - Start rotation
    /// \param q2 - End rotation
    /// \param t - Interpolation factor
    /// \returns Quaternion - result quaternion
    friend Quaternion SLERP (const Quaternion& q1, const Quaternion& q2, const Real& t);
    // -----------------------------------
    /// \brief Get the difference between two quaternions
    /// \details Calculate the rotation between two normalised quaternion rotations. This is the same as <tt>q1 * (-q2)</tt>
    /// \param orig - First rotation
    /// \param dest - Second rotation
    /// \returns Quaternion - result quaternion
    /// \see Quaternion::operator*()
    friend Quaternion DIFF (const Quaternion& orig, const Quaternion& dest);

    union
    {
      struct
      {
        Real x, y, z, w;
      };
      Real m_data[4];
    };

    /// \var Real Quaternion::x
    /// \details First value, x axis component

    /// \var Real Quaternion::y
    /// \details Second value, y axis component

    /// \var Real Quaternion::z
    /// \details Third value, z axis component

    /// \var Real Quaternion::w
    /// \details Fourth value, the scalar rotation element

    /// \var Real Quaternion::m_data[4]
    /// \brief Array data interface
    /// \details Array to access all four values
  };
#pragma pack(pop)
}

#endif
