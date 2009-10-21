/// \file Root.cpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief 
/// \note 
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _Chain_Root_h_
#define _Chain_Root_h_

#include "Container.hpp"
//#include "SceneManager.hpp"

namespace Chain
{
   class SceneManager;
   
   /// \brief The root object of a scene
   /// \details These are created and managed in Chain::SceneManager
   class Root : public Container
   {
      friend class SceneManager;
      protected:
         //---------------------------------------
         /// \details Default Constructor
         Root();
      public:
         //---------------------------------------
         /// \details Destructor
         virtual ~Root();
         
         // bool IsRoot() const;
   };
}

#endif
