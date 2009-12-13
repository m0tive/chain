/// \file Transform.hpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _Chain_Transform_h_
#define _Chain_Transform_h_

#include "EventDispatcher.hpp"

namespace chain
{
   /// \brief ...
   /// \details ...
   class Transform : public EventDispatcher
   {
     DECLARE_CHAIN_CLASS(OType::Transform,EventDispatcher,"transform")
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
