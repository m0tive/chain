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
#include "Root.hpp"
#include "Container.hpp"

#include <vector>

namespace Chain
{
   class App;
   
   /// \brief ...
   /// \details ...
   class SceneManager : public Manager
   {
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
         /// \brief Create a new scene hierarchy
         /// \param root Pointer to the scene's root
         /// \return std::vector<Container*> - Children of the root, empty if \c recursive is true
         std::vector<Container* > DeleteScene (Root * root, bool recursive = false);
         //---------------------------------------
         /// \brief Delete a Chain::Container safely
         /// \param cont Chain::Container to be deleted
         /// \return std::vector<Container*> - Children of the container, empty if \c recursive is true
         std::vector<Container* > DeleteContainer (Container * cont, bool recursive = false);
         
      protected:
         /// \brief Pointer to scene roots
         std::vector<Root* > m_scenes;
   };
}

#endif
