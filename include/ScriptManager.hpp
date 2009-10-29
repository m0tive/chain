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

namespace chain
{
  class App;

	/// \brief
  class ScriptManager : public Manager
	{
     DECLARE_CHAIN_CLASS(COb::ScriptManager,Manager,"scriptManager")
    friend class App;
  protected:
		//---------------------------------------
		/// \details Default Constructor
		ScriptManager();
		//---------------------------------------
		/// \details Destructor
		~ScriptManager();

  public:
    Script* NewScript (const char* str = "", const char* name = 0)
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
    Script* NewScript (const std::string& str, const char* name = 0)
    {
      return NewScript(str.c_str(),name);
    }
    Script* NewScript (const Script* s, const char* name = 0)
    {
      return NewScript(s->text.c_str(),name);
    }

    Script* GetScript (const char* name)
    {
      std::map<unsigned int,Script* >::iterator it = m_scripts.begin();
      for(;it!=m_scripts.end();++it)
      {
        if(it->second->m_name == name)
          return it->second;
      }
      return 0;
    }
    Script* GetScript (const unsigned int id)
    {
      std::map<unsigned int,Script* >::iterator it = m_scripts.find(id);
      if(it != m_scripts.end())
        return it->second;
      return 0;
    }

    bool DeleteScript (Script* s)
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

    bool Run (const char* str)
    {
      luaL_dostring(m_luaState, str);
      return LuaErrorCheck();
    }

    bool RunFile (const char* filename) {return false;}

    //lua_State* GetLuaState () {return m_luaState;}

  private:
    int lua_print(lua_State *L);
    int LuaErrorCheck();

    unsigned int m_scriptCounter;

  protected:
    lua_State* m_luaState;
    std::map<unsigned int,Script* > m_scripts;
	};
}

#endif
