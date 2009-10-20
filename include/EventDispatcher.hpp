/// \file EventDispatcher.cpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief 
/// \note 
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _Chain_EventDispatcher_h_
#define _Chain_EventDispatcher_h_

#include "Object.hpp"

namespace Chain
{
   /// \brief ...
   /// \details ...
   class EventDispatcher : public Object
   {
      protected:
         //---------------------------------------
         /// \details Default Constructor
         EventDispatcher();
         
      public:
         //---------------------------------------
         /// \details Destructor
         virtual ~EventDispatcher();
   };
}

#endif
