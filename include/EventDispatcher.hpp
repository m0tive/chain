/// \file EventDispatcher.hpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief
/// \note
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _chain_EventDispatcher_h_
#define _chain_EventDispatcher_h_

#include "Object.hpp"

namespace chain
{
   /// \brief ...
   /// \details ...
   class EventDispatcher : public Object
   {
     DECLARE_chain_CLASS(COb::EventDispatcher,Object,"eventDispatcher")
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
