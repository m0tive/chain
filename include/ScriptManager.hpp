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

#include "lua/lua.hpp"

namespace Chain
{
  class App;

	/// \brief
  class ScriptManager : public Manager
	{
    friend class App;
  protected:
		//---------------------------------------
		/// \details Default Constructor
		ScriptManager();
		//---------------------------------------
		/// \details Destructor
		~ScriptManager();
		
  protected:
    lua_State* m_luaState;
	};
}

#endif