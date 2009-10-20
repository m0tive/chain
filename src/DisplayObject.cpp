/// \file DisplayObject.cpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief 
/// \note 
//------------------------------------------------------------------------------

#include "DisplayObject.hpp"
#include "Container.hpp"
#include "Root.hpp"

namespace Chain 
{
   //------------------------------------------------ DisplayObject::DisplayObject
   DisplayObject::DisplayObject() //: m_root(0), m_parent(0)
   {
      
   }
   //------------------------------------------------ DisplayObject::~DisplayObject
   DisplayObject::~DisplayObject()
   {
      
   }
   //------------------------------------------------ DisplayObject::IsRoot
   bool DisplayObject::IsRoot() const
   {
      return false;
   }
   //------------------------------------------------ DisplayObject::Root
   Root* DisplayObject::Root () const
   {
      return 0;//m_root;
   }
   //------------------------------------------------ DisplayObject::Parent
   Container* DisplayObject::Parent () const
   {
      return 0;//m_parent;
   }
}
