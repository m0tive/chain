/// \file SceneManager.cpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief 
/// \note 
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _Chain_SceneManager_h_
#define _Chain_SceneManager_h_

#include "Manager.hpp"
#include "DisplayObject.hpp"
#include "Root.hpp"

#include <vector>

namespace Chain
{
   class App;
   
   /// \brief ...
   /// \details ...
   class SceneManager : public Manager
   {
     DECLARE_CHAIN_CLASS(COb::SceneManager,Manager,"sceneManager")
      friend class App;
      protected:
         //---------------------------------------
         /// \details Default Constructor
         SceneManager();
      public:
         //---------------------------------------
         /// \details Destructor
         virtual ~SceneManager();
         //---------------------------------------
         /// \brief Create a new scene hierarchy
         /// \return Root* - Pointer to the scene's root
         virtual Root * NewScene ();
         //---------------------------------------
         /// \brief Delete a scene hierarchy
         /// \param root Pointer to the scene's root
         /// \param recursive true to also delete all the children of \c root
         /// \return std::vector<Container*> - Children of the root, empty if \c recursive is true
         std::vector<DisplayObject* > DeleteScene (Root * root, bool recursive = true);
         //---------------------------------------
         /// \brief Delete a Chain::Container safely
         /// \param cont Chain::DisplayObject to be deleted
         /// \param recursive true to also delete all the children of \c cont
         /// \return std::vector<Container*> - Children of the container, empty if \c recursive is true
         std::vector<DisplayObject* > DeleteDisplayObject (DisplayObject * obj, bool recursive = false);
         
      protected:
         /// \brief Pointer to scene roots
         std::vector<Root* > m_scenes;
   };
}

#endif
