/// \file ScriptManager.cpp
/// \date 2009/10/22
/// \author Peter Dodds
/// \brief 
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#include "ScriptManager.hpp"

namespace Chain
{
  //------------------------------------------------ ScriptManager::ScriptManager
  ScriptManager::ScriptManager()
  {
    luaState = lua_open();
    lua_close(luaState);
  }

  //------------------------------------------------ ScriptManager::~ScriptManager
  ScriptManager::~ScriptManager()
  {

  }
}