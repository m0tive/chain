/// \file SceneManager.cpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief 
/// \note 
//------------------------------------------------------------------------------

#include "SceneManager.hpp"

namespace Chain 
{
   //------------------------------------------------ SceneManager::SceneManager
   SceneManager::SceneManager()
   {
      
   }
   //------------------------------------------------ SceneManager::~SceneManager
   SceneManager::~SceneManager()
   {
      
   }
   //------------------------------------------------ SceneManager::NewScene
   Root * SceneManager::NewScene ()
   {
      m_scenes.push_back(new Root());
      // TODO some setup
      return m_scenes.back();
   }
   //------------------------------------------------ SceneManager::DeleteScene
   std::vector<DisplayObject* > SceneManager::DeleteScene (Root * root, bool recursive)
   {
      std::vector<DisplayObject* > children;
      if(!recursive)
         children = root->children;
      
      DeleteDisplayObject(static_cast<DisplayObject* >(root),recursive);
      
      return children;
   }
   //------------------------------------------------ SceneManager::DeleteDisplayObject
   std::vector<DisplayObject* > SceneManager::DeleteDisplayObject (DisplayObject * obj, bool recursive)
   {
      std::vector<DisplayObject* > children;
      Container* cont;
      // If not recursive
      if(0){ /* check obj is a container */
         cont = static_cast<Container* >(obj);
         children = cont->children;
         if(recursive){
            
         }
      }
      
      // TODO Delete the object
      
      return children;
   }
}
