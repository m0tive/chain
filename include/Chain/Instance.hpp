/// \file Instance.hpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _chain_Instance_h_
#define _chain_Instance_h_

#include "Container.hpp"

namespace chain
{
   /// \brief ...
   /// \details ...
   class Instance : public Container
   {
     DECLARE_CHAIN_CLASS(OType::Instance,Container,"instance")
      public:
         //---------------------------------------
         /// \details Default Constructor
         Instance();
         //---------------------------------------
         /// \details Destructor
         virtual ~Instance();
   };
}

#endif
