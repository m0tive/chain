/// \file Object.cpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief Parent class for all Chain classes.
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#include "Object.hpp"

namespace chain
{

   //------------------------------------------------ Object::Object
   Object::Object()
   {

   }

#if 0
   Uint64 Object::m_id_incrementer = 0;

   //------------------------------------------------ Object::Object
   Object::Object()
   {
      m_id = ++m_id_incrementer;
   }
   //------------------------------------------------ Object::~Object
   Object::~Object()
   {

   }

   //------------------------------------------------ Object::GetId
   Uint64 Object::GetId() const
   {
      return m_id;
   }
#endif
}
