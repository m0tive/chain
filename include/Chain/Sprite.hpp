/// \file Sprite.hpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _chain_Sprite_h_
#define _chain_Sprite_h_

#include "Instance.hpp"

namespace chain
{
   /// \brief ...
   /// \details ...
   class Sprite : public Instance
   {
     DECLARE_CHAIN_CLASS(OType::Sprite,Instance,"sprite")
      public:
         //---------------------------------------
         /// \details Default Constructor
         Sprite();
         //---------------------------------------
         /// \details Destructor
         virtual ~Sprite();
   };
}

#endif
