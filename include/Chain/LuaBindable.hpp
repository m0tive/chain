/// \file LuaBindable.hpp
/// \date 2009 Dec 14
/// \version
/// \author
/// \brief
/// \note
//-----------------------------------------------------------------------------

#ifdef _MSC_VER
  #pragma once
#endif

#ifndef _LuaBindable_hpp_
#define _LuaBindable_hpp_

#include <lua/lua.hpp>

class LuaBindable
{
  public:
		//---------------------------------------
		/// \details Defualt Constructor
	  LuaBindable() {}
		//---------------------------------------
		/// \details Destructor
		~LuaBindable() {}

		bool RegisterLua () {}


};

#endif
