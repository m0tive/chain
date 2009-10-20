/// \file Container.cpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief 
/// \note 
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _Chain_Container_h_
#define _Chain_Container_h_

#include "DisplayObject.hpp"

namespace Chain
{
   /// \brief ...
   /// \details ...
   class Container : public DisplayObject
   {
      protected:
         //---------------------------------------
         /// \details Default Constructor
         Container();
         
      public:
         //---------------------------------------
         /// \details Destructor
         virtual ~Container();
         
         void AddChild (DisplayObject const& child);
   };
}

#endif
