/// \file Geometry.cpp
/// \date 2009/10/22
/// \version 0.01
/// \author Peter Dodds
/// \brief 
/// \note 
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _Chain_Geometry_h_
#define _Chain_Geometry_h_

#include "DisplayObject.hpp"

namespace Chain
{
   /// \brief ...
   /// \details ...
   class Geometry : public DisplayObject
   {
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
