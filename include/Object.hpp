/// \file Object.cpp
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

namespace Chain
{
   struct OType {
      enum Type {
         Object=0,
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
         virtual unsigned int GetType () const
         {
            return OType::App;
         }
         
         /*OType::Type */
      
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
