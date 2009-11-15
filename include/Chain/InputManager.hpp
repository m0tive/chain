/// \file InputManager.cpp
/// \date 2009/11/05
/// \version 0.01
/// \author Peter Dodds
/// \brief
/// \note
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _Chain_InputManager_h_
#define _Chain_InputManager_h_

#include "Manager.hpp"

namespace chain
{
  class App;

  /// \brief ...
  /// \details ...
  class InputManager : public Manager
  {
    //DECLARE_CHAIN_CLASS(COb::InputManager,Manager,"inputManager")

      friend class App;
    protected:
      //---------------------------------------
      /// \details Default Constructor
      InputManager() {}
      //---------------------------------------
      /// \details Destructor
      virtual ~InputManager() {}

    public:
      void PollInput ();
  };
}

#endif
