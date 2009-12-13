/// \file Utl.hpp
/// \date 2007/11/19
/// \author Peter Dodds
/// \brief chain::Utl function declarations
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#ifdef _MSC_VER
#pragma once
#endif

#ifndef _chain_Utl_h_
#define _chain_Utl_h_

#include "Def.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Quaternion.hpp"

namespace chain
{
  /// \brief Class holding static maths utility functions
  class Utl
  {
  private:
    /// \details locked constructor
    Utl () {}
    /// \details locked destructor
    ~Utl () {}

  public:
    // -----------------------------------
    /// \brief Test if a point is within a 2D square.
    /// \details The point \a subject is tested against a axis aligned square defined by
    /// the upper right point \a upper, and the lower left point \a lower
    /// \param subject - The test point
    /// \param upper - The squares upper right corner
    /// \param lower - The squares lower left corner
    /// \param sorted - If the upper and lower limits have been correctly sorted. (ie all values in upper > lower)
    /// \returns bool - true if inside the square
    static bool PointWithin(const Vector2& subject, Vector2 upper, Vector2 lower, bool sorted = true );
    // -----------------------------------
    /// \brief Test if a point is within a 3D cube.
    /// \details The point \a subject is tested against a axis aligned cube defined by
    /// the far upper right point \a upper, and the near lower left point \a lower
    /// \param subject - The test point
    /// \param upper - The squares far upper right corner
    /// \param lower - The squares near lower left corner
    /// \param sorted - If the upper and lower limits have been correctly sorted. (ie all values in upper > lower)
    /// \returns bool - true if inside the square
    static bool PointWithin(const Vector3& subject, Vector3 upper, Vector3 lower, bool sorted = true );

    // -----------------------------------
    /// \brief Calculate the shortest distance between a point and a line
    /// \details The line is defined by two points on it, \a lineA and \a lineB. This performs two
    /// calls to Vector3::Magnitude(), which each call CH_SQRT().
    /// \param point - point to test against line
    /// \param lineA - first point on line
    /// \param lineB - second point on line
    /// \returns chain::Real - shortest distance
    /// \see DistanceToLineSquared()
    static Real DistanceToLine (const Vector3& point, const Vector3& lineA, const Vector3& lineB);

    // -----------------------------------
    /// \brief Calculate the shortest distance squared between a point and a line
    /// \details The line is defined by two points on it, \a lineA and \a lineB. This performs two
    /// calls to Vector3::MagnitudeSquared(), which do not call CH_SQRT().
    /// \param point - point to test against line
    /// \param lineA - first point on line
    /// \param lineB - second point on line
    /// \returns chain::Real - shortest distance squared
    /// \see DistanceToLine()
    /// \bug If \a point is \b not equal to (0,0,0) then incorrect answer is returned
    static Real DistanceToLineSquared (const Vector3& point, const Vector3& lineA, const Vector3& lineB);

    // -----------------------------------
    /// \brief Calculate the shortest distance between a point and a line segment
    /// \details The line is defined by two points on it, \a lineA and \a lineB. This performs two
    /// calls to Vector3::MagnitudeSquared(), which do not call CH_SQRT(). If the closest point to the
    /// line is outside the limits of \a lineA and \a lineB.
    /// \param point - point to test against line
    /// \param lineA - first point on line
    /// \param lineB - second point on line
    /// \param[out] distance - shortest distance
    /// \returns bool - if the \c point is within the limits
    static bool DistanceToLineSegment (const Vector3& point, const Vector3& lineA, const Vector3& lineB, Real& distance);

    // -----------------------------------
    /// \brief Calculate the shortest distance squared between a point and a line segment
    /// \details The line is defined by two points on it, \a lineA and \a lineB. This performs two
    /// calls to Vector3::MagnitudeSquared(), which do not call CH_SQRT(). If the closest point to the
    /// line is outside the limits of \a lineA and \a lineB.
    /// \param point - point to test against line
    /// \param lineA - first point on line
    /// \param lineB - second point on line
    /// \param[out] distance_squared - shortest distance squared
    /// \returns bool - if the \c point is within the limits
    static bool DistanceToLineSegmentSquared (const Vector3& point, const Vector3& lineA, const Vector3& lineB, Real& distance_squared);

    // -----------------------------------
    /// \brief Calculate the points of intersection between a line and a sphere
    /// \details The line is defined by two points on it, \a lineA and \a lineB, and the
    /// sphere is defined by its centre and radius, \a sC and \a sR. If there were
    /// line-sphere intersections they will be returned in \a iA and \a iB.
    /// \param lineA - first point on line
    /// \param lineB - second point on line
    /// \param sC - Centre of sphere
    /// \param sR - Radius of sphere
    /// \param[out] iA - first point of intersection
    /// \param[out] iB - second point of intersection
    /// \returns bool - true if intersections occurred
    /// \note points of intersection may be equal in the case of glancing intersections.
    static bool LineSphereIntersection (const Vector3& lineA, const Vector3& lineB, const Vector3& sC, const Real& sR, Vector3* iA, Vector3* iB);


    // -----------------------------------
    /// \brief Get difference in rotation between two chain::Quaternions
    /// \details The returns the value of w for the rotation between \c A and \c B.
    /// \param A - first chain::Quaternion
    /// \param B - second chain::Quaternion
    /// \returns chain::Real - w value of chain::Quaternion between \c A and \c B
    static Real EstimateRotationBetween (const Quaternion& A, const Quaternion& B);

    // -----------------------------------
    /// \brief Get angle between two chain::Quaternions
    /// \details The returns the angle of the rotation between \c A and \c B.
    /// \param A - first chain::Quaternion
    /// \param B - second chain::Quaternion
    /// \returns chain::Real - angle between \c A and \c B
    static Real RotationBetween (const Quaternion& A, const Quaternion& B);

    // -----------------------------------
    /// \brief Convert the length of a chord to the length of it's associated arc
    /// \param chord - length of the chord
    /// \param radius - radius of segment
    /// \returns chain::Real - length of the arc
    static Real ChordToArc( const Real& chord, const Real& radius );
    // -----------------------------------
    /// \brief Convert the length of an arc to the length of it's associated chord
    /// \param arc - length of the arc
    /// \param radius - radius of segment
    /// \returns chain::Real - length of the chord
    static Real ArcToChord( const Real& arc, const Real& radius );
    // -----------------------------------
    /// \brief Convert the angle traveled by a chord.
    /// \param chord - length of the chord
    /// \param radius - radius of segment
    /// \returns chain::Real - angle traveled
    static Real ChordToAngle( const Real& chord, const Real& radius );
    // -----------------------------------
    /// \brief Convert the angle traveled by an arc.
    /// \param arc - length of the arc
    /// \param radius - radius of segment
    /// \returns chain::Real - angle traveled
    static Real ArcToAngle( const Real& arc, const Real& radius );
  };
}

#endif
