/// \file ScriptManager.cpp
/// \date 2009/10/22
/// \author Peter Dodds
/// \brief 
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#include "ScriptManager.hpp"
#include "Log.hpp"

int myFunt (lua_State *L){
   int argc = lua_gettop(L);
   
   std::cout << "$$ ";
   
   for(int i=1;i<=argc;++i){
      std::cout << lua_tostring(L, i);
   }
   std::cout << "\n";
   return 1;
}

void report_errors(lua_State *L, int status)
{
  if ( status!=0 ) {
    DOUT << "-- " << lua_tostring(L, -1) << "\n";
    lua_pop(L, 1); // remove error message
  }
}


namespace Chain
{
  //------------------------------------------------ ScriptManager::ScriptManager
  ScriptManager::ScriptManager()
  {
    // initilise the lua script interpreter
    DOUT << "initialising lua\n";
    m_luaState = lua_open();
    luaL_openlibs(m_luaState);
    
    lua_register(m_luaState, "ch_print", myFunt);
    
    // hardcode replacement for lua's default io.write function
    int s = luaL_dostring(m_luaState, "\
       io.write = ch_print \
       print = ch_print \
       print \"attempted to bind ch_print to io.write and print\"");
       
    //DOUT << "-- " << lua_tostring(m_luaState, -1) << "\n";
    
    //report_errors(m_luaState,s);
  }

  //------------------------------------------------ ScriptManager::~ScriptManager
  ScriptManager::~ScriptManager()
  {
    DOUT << "closing lua\n";
    lua_close(m_luaState);
  }
}