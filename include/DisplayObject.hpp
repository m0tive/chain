/// \file DisplayObject.cpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief 
/// \note 
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _Chain_DisplayObject_h_
#define _Chain_DisplayObject_h_

#include "Transform.hpp"

namespace Chain
{
   class Root;
   class Container;
   
   /// \brief ...
   /// \details ...
   class DisplayObject : public Transform
   {
      // The Container needs access to m_root and m_parent, which are updated 
      // when added as a child
      friend class Container; 
      protected:
         //---------------------------------------
         /// \details Default Constructor
         DisplayObject();
         
      public:
         //---------------------------------------
         /// \details Destructor
         virtual ~DisplayObject();
         
         //---------------------------------------
         /// \brief Get a pointer to the root object of the Scene hierarchy
         /// \return Root* - pointer to the Chain::Root object, 
         virtual bool IsRoot() const;
         //---------------------------------------
         /// \brief Get a pointer to the root object of the scene hierarchy
         /// \return Root* - 0 if not part of scene hierarchy (or root)
         Root* Root () const;
         //---------------------------------------
         /// \brief Get a pointer to the parent Chain::Container
         /// \return Container* - 0 if not part of scene hierarchy (or root)
         Container* Parent () const;
         
      private:
         //Root* m_root;
         //Container* m_parent;
   };
}

#endif
