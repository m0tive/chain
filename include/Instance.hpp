/// \file Instance.hpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief 
/// \note 
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _Chain_Instance_h_
#define _Chain_Instance_h_

#include "Container.hpp"

namespace Chain
{
   /// \brief ...
   /// \details ...
   class Instance : public Container
   {
     DECLARE_CHAIN_CLASS(COb::Instance,Container,"instance")
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
