/// \file Camera.hpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief
/// \note
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _Chain_Camera_h_
#define _Chain_Camera_h_

#include "DisplayObject.hpp"

namespace chain
{
   /// \brief ...
   /// \details ...
   class Camera : public DisplayObject
   {
     DECLARE_chain_CLASS(COb::Camera,DisplayObject,"camera")
      public:
         //---------------------------------------
         /// \details Default Constructor
         Camera();
         //---------------------------------------
         /// \details Destructor
         virtual ~Camera();
   };
}

#endif
