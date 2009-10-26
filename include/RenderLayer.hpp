/// \file RenderLayer.cpp
/// \date 2009/10/22
/// \version 0.01
/// \author Peter Dodds
/// \brief 
/// \note 
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _Chain_RenderLayer_h_
#define _Chain_RenderLayer_h_

#include "EventDispatcher.hpp"

namespace Chain
{
   /// \brief ...
   /// \details ...
   class RenderLayer : public EventDispatcher
   {
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
