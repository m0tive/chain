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
   /// \brief ...
   /// \details ...
   class Object 
   {
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
         unsigned int GetId() const;
      
      private:
         unsigned int m_id;
         static unsigned int m_id_incrementer;
   };
}

#endif
