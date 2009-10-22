/// \file Sprite.hpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief 
/// \note 
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _Chain_Sprite_h_
#define _Chain_Sprite_h_

#include "Instance.hpp"

namespace Chain
{
   /// \brief ...
   /// \details ...
   class Sprite : public Instance
   {
     DECLARE_CHAIN_CLASS(COb::Instance,Instance,"sprite")
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
