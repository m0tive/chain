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
   std::vector<Container* > SceneManager::DeleteScene (Root * root, bool recursive = false)
   {
      std::vector<Container* > children;
      if(recursive)
         children = root->children;
      
      DeleteContainer(root,recursive);
      
      return children;
   }
   //------------------------------------------------ SceneManager::DeleteContainer
   std::vector<Container* > SceneManager::DeleteContainer (Container * cont, bool recursive = false)
   {
      // TODO
      return std::vector<Container* >;
   }
}
