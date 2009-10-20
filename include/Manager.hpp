/// \file Manager.cpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief 
/// \note 
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _Chain_Manager_h_
#define _Chain_Manager_h_

#include "EventDispatcher.hpp"

namespace Chain
{
   /// \brief ...
   /// \details ...
   class Manager : public EventDispatcher
   {
      protected:
         //---------------------------------------
         /// \details Default Constructor
         Manager();
         
      public:
         //---------------------------------------
         /// \details Destructor
         virtual ~Manager();
   }
}

#endif
