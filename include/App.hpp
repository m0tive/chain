/// \file App.cpp
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

#ifndef _Chain_App_h_
#define _Chain_App_h_

#define __Chain

#include "EventDispatcher.hpp"

namespace Chain
{
   /// \brief Class to define the main game application.
   /// \details To start the client, create a new application,
   /// and call App::Run()
   class App : public EventDispatcher
   {
      public:
         // -----------------------------------
         /// \details Get an instance of this singleton.
         /// The first call to this will create the singleton.
         /// \returns Application& - the application
         static App& Instance ()
         {
            static App singleton;
            return singleton;
         }
         
         //---------------------------------------
         /// \details Main application function. 
         /// Calls App::Init(), starts main loop updating App::dt
         void Run ();
      
      private:
         //---------------------------------------
         /// \details Default Constructor
         App();
         
         //---------------------------------------
         /// \details Destructor
         virtual ~App();
   };
}

#endif
