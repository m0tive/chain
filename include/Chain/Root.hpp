/// \file Root.hpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _chain_Root_h_
#define _chain_Root_h_

#include "Container.hpp"
//#include "SceneManager.hpp"

namespace chain
{
   class SceneManager;

   /// \brief The root object of a scene
   /// \details These are created and managed in chain::SceneManager
   class Root : public Container
   {
     DECLARE_CHAIN_CLASS(OType::Root,Container,"root")
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
