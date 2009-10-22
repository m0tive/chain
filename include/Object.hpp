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

#ifndef _Chain_Object_h_
#define _Chain_Object_h_

#include <string>

namespace Chain
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
            EventDispatcher,
              App,
              Manager,
                 RenderManager,
                 SceneManager,
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
      public:
        // -----------------------------------
        /// \brief Get the Chain::COb type of the object
        /// \returns COb::eType - The object's type
        static COb::eType GetType () {
          return COb::Object;
        };
        // -----------------------------------
        /// \brief Get the Chain::COb type as a string
        /// \returns std::string - The object's type
        static std::string GetTypeName () {
          return "object";
        };
        // -----------------------------------
        /// \brief Test if a class is of a certain type, or derived from that type.
        /// \details This function looks down the class hierarchy for the class type.
        /// \param _type - Chain::COb type being checked against
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
         unsigned long GetId() const;
      
      private:
         unsigned long m_id;
         static unsigned long m_id_incrementer;
   };
}

#endif
