/// \file EulerAngle.hpp
/// \date 2008/04/16
/// \author Peter Dodds
/// \brief chain::EulerAngle structure declaration
/// \note
//------------------------------------------------------------------------------

#ifdef _MSC_VER
#pragma once
#endif

#ifndef _chain_EulerAngle_h_
#define _chain_EulerAngle_h_

#include "Def.hpp"

namespace chain
{
  struct Matrix;
  struct Quaternion;

#pragma pack(push,1)
  /// \todo Expand to accommodate any set of euler angles (eg. XYX, ZXY, ...)
	/// \brief Structure to hold a set of euler angles in the format XYZ
  /// \details Euler angles represent series of rotations in 3D, applied in a defined order
  /// \warning Euler angles are prone to Gimbel Lock.
	struct EulerAngle
	{
		//---------------------------------------
		/// \details Default Constructor taking initial values for \a x, \a y and \a z
    /// \param _x - initial value of EulerAngle::x
    /// \param _y - initial value of EulerAngle::y
    /// \param _z - initial value of EulerAngle::z
    EulerAngle(const Real& _x = 0, const Real& _y = 0, const Real& _z = 0);
    //---------------------------------------
    /// \details Constructor using a EulerAngle
    /// \param ea - euler angle
    EulerAngle(const EulerAngle& ea);
    //---------------------------------------
    /// \details Constructor using a Matrix
    /// \param m - matrix
    /// \see FromMatrix()
    EulerAngle(const Matrix& m);
    //---------------------------------------
    /// \details Constructor using a Quaternion
    /// \param q - quaternion
    /// \see FromQuat()
    EulerAngle(const Quaternion& q);
    //---------------------------------------
    /// \details Destructor
    ~EulerAngle() {}

    // -----------------------------------
    /// \brief Set the value of this from a Matrix
    /// \details Assume that the euler angle is in the order XYZ
    /// \param m - matrix
    /// \returns const EulerAngle& - this euler angle
    const EulerAngle& FromMatrix (const Matrix& m);
    // -----------------------------------
    /// \brief Set the value of this from a Quaternion
    /// \details This converts the quaternion into a rotation matrix, then uses FromMatrix()
    /// \param q - quaternion
    /// \returns const EulerAngle& - this euler angle
    const EulerAngle& FromQuat (const Quaternion& q);

    // -----------------------------------
    /// \brief Convert this into a Quaternion
    /// \returns Quaternion - result quaternion
    Quaternion ToQuat ();

    // -----------------------------------
    /// \details Assignment operation using a euler angle
    const EulerAngle& operator = (const EulerAngle& ea);

    union
    {
      struct
      {
        Real x;
        Real y;
        Real z;
      };
      struct
      {
        Real roll;
        Real pitch;
        Real yaw;
      };
      Real m_data[3];
    };

    /// \var Real EulerAngle::x
    /// \details X-axis rotation

    /// \var Real EulerAngle::y
    /// \details Y-axis rotation

    /// \var Real EulerAngle::z
    /// \details Z-axis rotation

    /// \var Real EulerAngle::roll
    /// \details X-axis rotation

    /// \var Real EulerAngle::pitch
    /// \details Y-axis rotation

    /// \var Real EulerAngle::yaw
    /// \details Z-axis rotation

    /// \var Real EulerAngle::m_data[3]
    /// \brief Array data interface
    /// \details Array to access all three values
  };
#pragma pack(pop)
}

#endif
