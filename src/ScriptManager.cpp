/// \file ScriptManager.cpp
/// \date 2009/10/22
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#include "ScriptManager.hpp"
#include "Log.hpp"

int _lua_print (lua_State* L)
{
  // basic lua code interpreted from http://csl.sublevel3.org/lua/
  int argc = lua_gettop(L);

  std::cout << "$$ ";

  for(int i=1;i<=argc;++i){
    std::cout << lua_tostring(L, i);
  }
  std::cout << "\n";
  return 1;
}

namespace chain
{
  //------------------------------------------------ ScriptManager::ScriptManager
  ScriptManager::ScriptManager()
  {
    // initialise the lua script interpreter
    DOUT << "initialising lua\n";
    m_luaState = lua_open();
    luaL_openlibs(m_luaState);

    lua_register(m_luaState, "ch_print", _lua_print);

    // hard code replacement for lua's default io.write function
    if(luaL_dostring(m_luaState, "\
       io.write = ch_print \
       print = ch_print \
       print \"attempted to bind ch_print to io.write and print\""))
    {
      DOUT << "error setting ch_print";
    }
  }

  //------------------------------------------------ ScriptManager::~ScriptManager
  ScriptManager::~ScriptManager()
  {
    DOUT << "closing lua\n";
    lua_close(m_luaState);
  }

  //------------------------------------------------ ScriptManager::executeFile
  bool ScriptManager::executeFile( const char* filename )
  {
    int TODO;///\todo 2009/10/28 21:50 : Load file
    return execute(std::string("print \"execute file '") + filename + "'\"");
  }

  //------------------------------------------------ ScriptManager::execute
  bool ScriptManager::execute( const char* script )
  {
    return false;
  }

  //------------------------------------------------ ScriptManager::execute
  bool ScriptManager::execute( const std::string& script )
  {
    return false;
  }

  //------------------------------------------------ ScriptManager::lua_print
  int ScriptManager::lua_print( lua_State *L )
  {
    // basic lua code interpreted from http://csl.sublevel3.org/lua/
    int argc = lua_gettop(L);

    std::cout << "$$ ";

    for(int i=1;i<=argc;++i){
      std::cout << lua_tostring(L, i);
    }
    std::cout << "\n";
    return 1;
  }

  //------------------------------------------------ ScriptManager::getErrors
  int ScriptManager::getErrors()
  {
    //DOUT << "-- " << lua_tostring(m_luaState, -1) << "\n";
    //lua_pop(m_luaState, 1); // remove error message
    return 0;
  }
}
