/// \file ScriptManager.cpp
/// \date 2009/10/22
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#include "ScriptManager.hpp"
#include "Log.hpp"

#include "LuaGL.h"

namespace chain
{
  std::string ScriptManager::path = "";

  #ifndef DOXYGEN_PROCESSING // Hide the lua functions
  int chain_lua_print (lua_State* L)
  {
    // basic lua code interpreted from http://csl.sublevel3.org/lua/
    int argc = lua_gettop(L);

    std::cout << "$$ ";

    for(int i=1;i<=argc;++i)
    {
      std::cout << lua_tostring(L, i);
    }
    std::cout << "\n";
    return 1;
  }

  int chain_lua_path (lua_State* L)
  {
    if(lua_gettop(L) > 0)
    {
      ScriptManager::path = lua_tostring(L, 1);
    }

    lua_pushstring(L,ScriptManager::path.c_str());

    return 1;
  }
  #endif

  //------------------------------------------------ ScriptManager::ScriptManager
  ScriptManager::ScriptManager() : m_scriptCounter(0)
  {
    // initialise the lua script interpreter
    DOUT << "initialising lua\n";
    m_luaState = lua_open();
    luaL_openlibs(m_luaState);
    luaopen_opengl(m_luaState);

#if 1
    // overload io.write
    AddFunction(chain_lua_print,"write","io"); /// \todo change this

    //lua_getglobal(m_luaState,"io");
    //lua_pushcfunction(m_luaState,chain_lua_print);
    //lua_setfield(m_luaState,-2,"write");

    // overload print
    AddFunction(chain_lua_print,"print");

    //lua_register(m_luaState,"print",chain_lua_print);


    luaL_Reg chainlib[] = {
      //{"print",chain_lua_print},
      {"path",chain_lua_path},
      {NULL,NULL}
    };


    luaL_register(m_luaState, "ch", chainlib);

    /*lua_pushnil(m_luaState);
    lua_setglobal(m_luaState,"ch");*/

    if(luaL_dostring(m_luaState, "\
       io.write(\"io.write\") \
       print \"print\""))
    {
      DOUT << "error setting ch.print";
    }
    /*lua_pushnil(m_luaState);
    lua_setfield(m_luaState,-2,"");
    lua_setfield(m_luaState,-2,"print2");

    if(luaL_dostring(m_luaState, "\
       io.write(\"io.write worked\")"))
    {
      DOUT << "failed to run io.write\n";
    }*/


#elif
    lua_register(m_luaState, "_chain_print", chain_lua_print);
    lua_register(m_luaState, "_chain_path", chain_lua_path);

    int TODO; /// \todo Improve chain lua table

    // hard code replacement for lua's default io.write function
    if(luaL_dostring(m_luaState, "\
       ch = {}; \
       ch.print = _chain_print; \
       ch.path = _chain_path; \
       \
       \
       io.write = ch.print; \
       print = ch.print; \
       print \"--\""))
    {
      DOUT << "error setting ch.print";
    }
#endif
  }

  //------------------------------------------------ ScriptManager::~ScriptManager
  ScriptManager::~ScriptManager()
  {
    DOUT << "closing lua\n";
    lua_close(m_luaState);
  }

  //------------------------------------------------ ScriptManager::LuaErrorCheck
  int ScriptManager::LuaErrorCheck()
  {
    //std::string str;
    while (!lua_isnil(m_luaState, -1))
    {
      /* uses 'key' (at index -2) and 'value' (at index -1) */
      std::cout << "$$ " << lua_tostring(m_luaState, -1) << "\n";
      /* removes 'value'; keeps 'key' for next iteration */
      lua_pop(m_luaState, 1);
    }

    //lua_pop(m_luaState, 1); // remove error message
    return 0;
  }
}
