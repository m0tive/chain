/// \file Event.hpp
/// \date 2009/11/05
/// \version 0.01
/// \author Peter Dodds
/// \brief
/// \note
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _chain_Event_h_
#define _chain_Event_h_

#include "Object.hpp"
//#include "EventManager.hpp"

#include <assert.h>

namespace chain
{
  struct EType {
    enum T {
      Null=0,

      Application_Start, /// Before the application while loop starts
      Application_Stop, /// After the application while loop finishes
      Application_Render,
      Application_PollInputs,

      Input_Quit,
      Input_ForceQuit,

      Last,
      Max=0xFFFF
    };
  };

  /// \brief ...
  /// \details ...
  class Event// : public Object
  {
    friend class EventManager;

    //DECLARE_CHAIN_CLASS(COb::Event,Object,"event")
    public:
      //---------------------------------------
      /// \details Default Constructor
      Event(int type, bool propagate = false);

      //---------------------------------------
      /// \details Destructor
      virtual ~Event() {}

      const int GetType() const {return m_type;}
      const bool DoesPropagate() const {return m_propagate;}

    private:
      int m_type;
      bool m_propagate;
  };
}

#endif
