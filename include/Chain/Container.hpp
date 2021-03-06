/// \file Container.hpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _Chain_Container_h_
#define _Chain_Container_h_

#include "DisplayObject.hpp"

#include <vector>

namespace chain
{
   class SceneManager;

   /// \brief ...
   /// \details ...
   class Container : public DisplayObject
   {
     DECLARE_CHAIN_CLASS(OType::Container,DisplayObject,"container")
      friend class SceneManager;
      protected:
         //---------------------------------------
         /// \details Default Constructor
         Container();
         //---------------------------------------
         /// \details Destructor
         virtual ~Container();

      public:
         void AddChild (DisplayObject const& child);

         std::vector<DisplayObject* > children;
   };
}

#endif
