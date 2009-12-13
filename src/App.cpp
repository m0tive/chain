/// \file App.cpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief Top level application class.
/// A singleton that acts as the root object for the application
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#include "App.hpp"
#include "Event.hpp"

namespace chain
{
  //------------------------------------------------ App::Run
  bool App::Run(const char* script/* = 0*/)
  {
    //bool s = scriptManager.Run(script);

    DispatchEvent(Event(EType::Application_Start));

    m_isRunning = true;
    while(!m_shutdown)
    {
      //draw
      DispatchEvent(Event(EType::Application_Render));
      //events
      DispatchEvent(Event(EType::Application_PollInputs));

      Shutdown();
    }
    m_isRunning = false;
    // while loop

    DispatchEvent(Event(EType::Application_Stop));

    return true;
  }
}
