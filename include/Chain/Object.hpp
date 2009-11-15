/// \file Object.hpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief Top level application class.
/// A singleton that acts as the root object for the application
/// \note
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _chain_Object_h_
#define _chain_Object_h_

#define __Chain

#include <string>
#include "Def.hpp"

namespace chain
{
  #define DECLARE_CHAIN_CLASS(OBJTYPE,PARENT,TYPENAME)    \
    public:                                               \
    static COb::eType GetType () {                        \
      return OBJTYPE;                                     \
    };                                                    \
    static std::string GetTypeName () {                   \
      return TYPENAME;                                    \
    };                                                    \
    static bool IsType (const COb::eType& _type) {        \
      if(_type != OBJTYPE) return PARENT::IsType(_type);  \
      else return true;                                   \
    };


   struct COb {
      enum eType {
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
        /// \brief Get the chain::COb type of the object
        /// \returns COb::eType - The object's type
        static COb::eType GetType () {
          return COb::Object;
        };
        // -----------------------------------
        /// \brief Get the chain::COb type as a string
        /// \returns std::string - The object's type
        static std::string GetTypeName () {
          return "object";
        };
        // -----------------------------------
        /// \brief Test if a class is of a certain type, or derived from that type.
        /// \details This function looks down the class hierarchy for the class type.
        /// \param _type - chain::COb type being checked against
        /// \returns bool - True if part of type
        static bool IsType(const COb::eType& _type) {
          return (_type == COb::Object);
        }


      protected:
         //---------------------------------------
         /// \details Default Constructor
         Object();

      public:
         //---------------------------------------
         /// \details Destructor
         virtual ~Object();

         //---------------------------------------
         /// \details Get the object's unique id
         Uint64 GetId() const;

      private:
         Uint64 m_id;
         static Uint64 m_id_incrementer;
   };
}

#endif