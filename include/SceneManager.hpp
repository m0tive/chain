/// \file SceneManager.cpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief 
/// \note 
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _Chain_SceneManager_h_
#define _Chain_SceneManager_h_

#include "Manager.hpp"
#include "App.hpp"

namespace Chain
{
   /// \brief ...
   /// \details ...
   class SceneManager : public Manager
   {
      friend class App;
      protected:
         //---------------------------------------
         /// \details Default Constructor
         SceneManager();
      public:
         //---------------------------------------
         /// \details Destructor
         virtual ~SceneManager();
   }
}

#endif
