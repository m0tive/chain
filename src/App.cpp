/// \file App.cpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief Top level application class.
/// A singleton that acts as the root object for the application
/// \note
//------------------------------------------------------------------------------

#include "App.hpp"

namespace chain
{
  //------------------------------------------------ App::App
  App::App()
  {
    DOUT << "libChain App created\n";
  }
  //------------------------------------------------ App::~App
  App::~App()
  {

  }

  //------------------------------------------------ App::Run
  bool App::Run(const char* script)
  {
    bool s = scriptManager.Run(script);
    return s;
  }
}
