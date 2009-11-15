/// \file ScriptManager.hpp
/// \date 2009/10/22
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#ifdef _MSC_VER
#pragma once
#endif

#ifndef _Chain_ScriptManager_h_
#define _Chain_ScriptManager_h_

#include "Manager.hpp"

#include <lua/lua.hpp>
#include <map>
#include "Script.hpp"

//#ifndef

namespace chain
{
  typedef int (*ScriptFunction) (lua_State *L);
  typedef luaL_Reg ScriptFunctionTable;

  class App;

	/// \brief
  class ScriptManager : public Manager
	{
    // DECLARE_CHAIN_CLASS(COb::ScriptManager,Manager,"scriptManager")
    friend class App;
  protected:
		//---------------------------------------
		/// \details Default Constructor
		ScriptManager();
		//---------------------------------------
		/// \details Destructor
		~ScriptManager();

  public:
    Script* NewScript (const char* str = "", const char* name = 0);
    Script* NewScript (const std::string& str, const char* name = 0);
    Script* NewScript (const Script* s, const char* name = 0);

    Script* GetScript (const char* name);
    Script* GetScript (const unsigned int id);

    bool DeleteScript (Script* s);

    bool Run (const char* str);

    void RunFile (const char* filename) {}

    void AddFunction (ScriptFunction funct, const char* name, const char* table = 0)
    {
      /// \todo Make some lua functions protected

      if(table == 0) // The function is global
      {
        lua_register(m_L,name,funct);
      }
      else
      {
        lua_getglobal(m_L,table); /// \todo Catch errors if table isn't global
        lua_pushcfunction(m_L,funct);
        lua_setfield(m_L,-2,name);
      }
    }

    void AddTable (const char* name, const ScriptFunctionTable* t = 0)
    {
    }

    //lua_State* GetLuaState () {return m_L;}

  private:
    int LuaErrorCheck();

    unsigned int m_scriptCounter;

  public:
    static std::string path;

  protected:

    lua_State* m_L;
    std::map<unsigned int,Script* > m_scripts;
	};
}

#endif
