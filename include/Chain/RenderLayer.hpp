/// \file RenderLayer.cpp
/// \date 2009/10/22
/// \version 0.01
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _Chain_RenderLayer_h_
#define _Chain_RenderLayer_h_

#include "EventDispatcher.hpp"

namespace chain
{
   /// \brief ...
   /// \details ...
   class RenderLayer : public EventDispatcher
   {
     DECLARE_CHAIN_CLASS(OType::RenderLayer,EventDispatcher,"renderLayer")
      friend class RenderManager;
      protected:
         //---------------------------------------
         /// \details Default Constructor
         RenderLayer();
         //---------------------------------------
         /// \details Destructor
         virtual ~RenderLayer();
   };
}

#endif
