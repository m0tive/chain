/// \file App.hpp
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

#include "EventDispatcher.hpp"

// Manager classes
#include "SceneManager.hpp"
#include "ScriptManager.hpp"
#include "RenderManager.hpp"
#include "Log.hpp"

namespace chain
{
  /// \brief Class to define the main game application.
  /// \details To start the client, create a new application,
  /// and call App::Run()
  /// \todo Change name: App -> Application
  class App : public EventDispatcher
  {
    DECLARE_CHAIN_CLASS(COb::App,EventDispatcher,"app")
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

      // Main application function.
      virtual bool Run (const char* script = 0);

    private:
      //---------------------------------------
      /// \details Default Constructor
      App() {}
      //---------------------------------------
      /// \details Destructor
      virtual ~App() {}

    public:
      RenderManager renderManager;
      SceneManager sceneManager;
      ScriptManager scriptManager;
      Log * log;
  };
}

#endif
