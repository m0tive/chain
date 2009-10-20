/// \file Object.cpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief Parent class for all Chain classes.
/// \note 
//------------------------------------------------------------------------------

#include "Object.hpp"

namespace Chain 
{
   unsigned int Object::m_id_incrementer = 0;
   
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
   unsigned int Object::GetId() 
   {
      return m_id;
   }
}
