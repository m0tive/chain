/// \file Transform.cpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief 
/// \note 
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _Chain_Transform_h_
#define _Chain_Transform_h_

#include "EventDispatcher.hpp"

namespace Chain
{
   /// \brief ...
   /// \details ...
   class Transform : public EventDispatcher
   {
      protected:
         //---------------------------------------
         /// \details Default Constructor
         Transform();
         
      public:
         //---------------------------------------
         /// \details Destructor
         virtual ~Transform();
   };
}

#endif
