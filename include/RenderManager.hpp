/// \file RenderManager.cpp
/// \date 2009/10/22
/// \version 0.01
/// \author Peter Dodds
/// \brief 
/// \note 
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _Chain_RenderManager_h_
#define _Chain_RenderManager_h_

#include "Manager.hpp"

namespace Chain
{
   /// \brief ...
   /// \details ...
   class RenderManager : public Manager
   {
      protected:
         //---------------------------------------
         /// \details Default Constructor
         RenderManager();
      public:
         //---------------------------------------
         /// \details Destructor
         virtual ~RenderManager();
   };
}

#endif
