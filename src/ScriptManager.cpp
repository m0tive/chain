/// \file ScriptManager.cpp
/// \date 2009/10/22
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#include "ScriptManager.hpp"
#include "Log.hpp"

#ifndef DOXYGEN_PROCESSING
#include "LuaGL.h"
#endif

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
    m_L = lua_open();
    luaL_openlibs(m_L);
    luaopen_opengl(m_L);

    // overload io.write
    lua_getglobal(m_L,"io");
    lua_pushcfunction(m_L,chain_lua_print);
    lua_setfield(m_L,-2,"write");

    // overload print
    lua_register(m_L,"print",chain_lua_print);

    // add path
    lua_register(m_L,"path",chain_lua_path);


    /* luaL_Reg chainlib[] = {
      //{"print",chain_lua_print},
      //{"path",chain_lua_path},
      {NULL,NULL}
    };
    luaL_register(m_L, "ch", chainlib); */

#if 0
    if(luaL_dostring(m_luaState, "\
       io.write(\"io.write\") \
       print \"print\""))
    {
      DOUT << "error setting ch.print";
    }
#endif
  }

  //------------------------------------------------ ScriptManager::~ScriptManager
  ScriptManager::~ScriptManager()
  {
    DOUT << "closing lua\n";
    lua_close(m_L);
  }

  //------------------------------------------------ ScriptManager::LuaErrorCheck
  int ScriptManager::LuaErrorCheck()
  {
    //std::string str;
    while (!lua_isnil(m_L, -1))
    {
      /* uses 'key' (at index -2) and 'value' (at index -1) */
      std::cout << "$$ " << lua_tostring(m_L, -1) << "\n";
      /* removes 'value'; keeps 'key' for next iteration */
      lua_pop(m_L, 1);
    }

    //lua_pop(m_L, 1); // remove error message
    return 0;
  }

  //------------------------------------------------ ScriptManager::NewScript
  Script* ScriptManager::NewScript( const char* str /*= ""*/, const char* name /*= 0*/ )
  {
    Script* s = new Script;
    s->text = str;
    s->m_manager = this;
    s->m_id = m_scriptCounter++;
    if(name != 0)
      s->m_name = name;
    else
      s->m_name = s->m_id;
    int TODO; /// \todo Check the script name is unique
    m_scripts[s->m_id] = s;

    return s;
  }

  //------------------------------------------------ ScriptManager::NewScript
  Script* ScriptManager::NewScript( const std::string& str, const char* name /*= 0*/ )
  {
    return NewScript(str.c_str(),name);
  }

  //------------------------------------------------ ScriptManager::NewScript
  Script* ScriptManager::NewScript( const Script* s, const char* name /*= 0*/ )
  {
    return NewScript(s->text.c_str(),name);
  }

  //------------------------------------------------ ScriptManager::GetScript
  Script* ScriptManager::GetScript( const char* name )
  {
    std::map<unsigned int,Script* >::iterator it = m_scripts.begin();
    for(;it!=m_scripts.end();++it)
    {
      if(it->second->m_name == name)
        return it->second;
    }
    return 0;
  }

  //------------------------------------------------ ScriptManager::GetScript
  Script* ScriptManager::GetScript( const unsigned int id )
  {
    std::map<unsigned int,Script* >::iterator it = m_scripts.find(id);
    if(it != m_scripts.end())
      return it->second;
    return 0;
  }

  //------------------------------------------------ ScriptManager::DeleteScript
  bool ScriptManager::DeleteScript( Script* s )
  {
    std::map<unsigned int,Script* >::iterator it = m_scripts.find(s->m_id);
    if(it != m_scripts.end())
    {
      m_scripts.erase(it);
      delete s;
      return true;
    }
    return false;
  }

  //------------------------------------------------ ScriptManager::Run
  bool ScriptManager::Run( const char* str )
  {
    int s = luaL_dostring(m_L, str);
    if(s != 0)
      return LuaErrorCheck();
    return false;
  }
}
