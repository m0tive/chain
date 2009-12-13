/// \file LuaUtl.hpp
/// \date 2009 Nov 25
/// \version
/// \author
/// \brief
/// \note Copyright (C) 2009 - All Rights Reserved
//-----------------------------------------------------------------------------

#ifdef _MSC_VER
  #pragma once
#endif

#ifndef _chain_LuaUtl_hpp_
#define _chain_LuaUtl_hpp_

#include <lua/lua.hpp>
//#include <typeinfo>

#include "Def.hpp"

// Code for lua class utilitys from code by Brian "rip-off" Barrett (http://ripoff.wordpress.com/)
// Sourced on 16/11/2009 from : http://www.gamedev.net/community/forums/topic.asp?topic_id=538631

namespace chain
{
  /// \brief
  template<int (*function)(lua_State* L)>
  int luaC_callProxy(lua_State* L)
  {
    try
    {
      return function(L);
    }
    catch(const std::exception& e)
    {
      luaL_error(L, "std::exception %s", e.what());
    }
    catch(...)
    {
      luaL_error(L, "unknown exception");
    }
    CH_ASSERT(false);
    return 0;
  }

  /// \todo replace typeid functions with a Chain type name
  class LuaUtl
  {
    protected:
      template<class T>
      void m_validate_type()
      {
        T *t = 0;
        Object *o = t;
        (void)o;
      }

      static void* m_create_object(lua_State* L, const char* key, int bytes)
      {
        void *ptr = lua_newuserdata(L,bytes);

        luaL_getmetatable(L, key);
        lua_setmetatable(L, -2);

        // check user data has been created (Is this correct?)
        if(luaL_checkudata(L, -1, key) == 0)
        {
          luaL_error(L,"\'%s\' expected",key);
        }

        return ptr;
      }

      void m_registerType(lua_State *L, const char *key, const luaL_Reg *functions)//, lua_CFunction garbageCollect)
      {
        luaL_newmetatable(L,key);

        lua_pushstring(L, "__index");
        lua_pushvalue(L, -2);  // pushes the metatable
        lua_settable(L, -3);  // metatable.__index = metatable

        // not doing garbage collection
        //lua_pushstring(L, "__gc");
        //lua_pushcfunction(L, garbageCollect);
        //lua_settable(L, -3);


        luaL_openlib(L, NULL, functions, 0);
        //lua_getglobal(L, "_G");
        //luaL_register(L, NULL, functions);
      }

    public:
      template<class T>
      static void* pushReference(lua_State* L, T* ref)
      {
        m_validate_type<T>();
        T** ptr = static_cast<T**>(m_create_object(L, T::GetTypeName(), sizeof(T*)));
        *ptr = ref;
        return ptr;
      }

      template<class T>
      void registerType(lua_State *L, const luaL_Reg *functions)
      {
        m_validate_type<T>();
        m_registerType(L, T::GetTypeName(), functions);//, &detail::garbageCollect<T>);
      }

    private:
      LuaUtl() {}
      ~LuaUtl() {}
  };
}

#define LUAC_ENTRY(x) {#x, &chain::luaC_callProxy<&x>}
#define LUAC_ENTRY2(x,y) {#x, &chain::luaC_callProxy<&y>}

#endif

