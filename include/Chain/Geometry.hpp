/// \file Geometry.cpp
/// \date 2009/10/22
/// \version 0.01
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _Chain_Geometry_h_
#define _Chain_Geometry_h_

#include "DisplayObject.hpp"

namespace chain
{
   /// \brief ...
   /// \details ...
   class Geometry : public DisplayObject
   {
     DECLARE_CHAIN_CLASS(OType::Geometry,DisplayObject,"geometry")
      protected:
         //---------------------------------------
         /// \details Default Constructor
         Geometry();
      public:
         //---------------------------------------
         /// \details Destructor
         virtual ~Geometry();
   };
}

#endif
