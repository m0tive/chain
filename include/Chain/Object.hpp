/// \file Object.hpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief Top level application class.
/// A singleton that acts as the root object for the application
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _chain_Object_h_
#define _chain_Object_h_

#define __Chain

#include <string>
#include "Def.hpp"
//#include "LuaUtl.hpp"

struct lua_State;

namespace chain
{
  #define DECLARE_CHAIN_CLASS(OBJTYPE,PARENT,TYPENAME)    \
    public:                                               \
    static OType::_t GetType () {                         \
      return OBJTYPE;                                     \
    };                                                    \
    static std::string GetTypeName () {                   \
      return TYPENAME;                                    \
    };                                                    \
    static bool IsType (const OType::_t& t) {             \
      if(t != OBJTYPE) return PARENT::IsType(t);          \
      else return true;                                   \
    };

  struct OType {
    enum _t {
      Object=0,
        Event,
        EventDispatcher,
          Log,
          App,
          Manager,
            RenderManager,
            SceneManager,
            ScriptManager,
            InputManager,
          RenderLayer,
          Transform,
            DisplayObject,
              Camera,
              Container,
                Instance,
                  Sprite,
                Root,
              Geometry,
                Mesh,

      Last,
      Max=0xFFFF
    };
  };

  /// \brief ...
  /// \details ...
  class Object
  {
   // IMPORTANT: No call to DECLARE_CHAIN_CLASS. This is replaced with the following code
    public:
      // -----------------------------------
      /// \brief Get the chain::OType _t of the object
      /// \returns OType::_t - The object's _t
      static OType::_t GetType () {
        return OType::Object;
      };
      // -----------------------------------
      /// \brief Get the chain::OType _t as a string
      /// \returns std::string - The object's _t
      static std::string GetTypeName () {
        return "object";
      };
      // -----------------------------------
      /// \brief Test if a class is of a certain _t, or derived from that _t.
      /// \details This function looks down the class hierarchy for the class _t.
      /// \param _t - chain::OType _t being checked against
      /// \returns bool - True if part of _t
      static bool IsType(const OType::_t& t) {
        return (t == OType::Object);
      }

#if 0
      //void LoadIntoLua (lua_State *L) {}

      bool RegisterLua (lua_State *L)
      {
        if(!m_hasLua){
          m_hasLua = true;
          // do register
        }
        return !m_hasLua
      }

    protected:
      virtual luaL_Reg* LuaBindings () {

        // Object::LuaBindings()


      }

    private:
      bool m_hasLua;
      #endif

    protected:


       //---------------------------------------
       /// \details Default Constructor
       Object();
       //---------------------------------------
       /// \details Destructor
       virtual ~Object() {}

  #if 0
       //---------------------------------------
       /// \details Get the object's unique id
       Uint64 GetId() const;

    private:
       Uint64 m_id;
       static Uint64 m_id_incrementer;
  #endif
   };
}

#endif
