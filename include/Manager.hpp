/// \file Manager.hpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief
/// \note
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _chain_Manager_h_
#define _chain_Manager_h_

#include "EventDispatcher.hpp"

namespace chain
{
   /// \brief ...
   /// \details ...
   class Manager : public EventDispatcher
   {
     DECLARE_chain_CLASS(COb::Manager,EventDispatcher,"manager")
      protected:
         //---------------------------------------
         /// \details Default Constructor
         Manager();

      public:
         //---------------------------------------
         /// \details Destructor
         virtual ~Manager();
   };
}

#endif
