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
      if(recursive)
         children = root->children;
      
      DeleteContainer(root,recursive);
      
      return children;
   }
   //------------------------------------------------ SceneManager::DeleteContainer
   std::vector<DisplayObject* > SceneManager::DeleteContainer (Container * cont, bool recursive)
   {
      std::vector<DisplayObject* > children;
      // TODO
      return children;
   }
}
