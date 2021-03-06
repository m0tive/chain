/// \file EventManager.cpp
/// \date 2009/11/05
/// \version 0.01
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _Chain_EventManager_h_
#define _Chain_EventManager_h_

#include "Manager.hpp"

#include <vector>

namespace chain
{
  struct EType {
    enum T {
      Dummy=0,

      Force_Quit,

      Last,
      Max=0xFFFF
    };
  };

  class Event;
  class EventDispatcher;

  /// \brief ...
  /// \details ...
  class EventManager : public Manager
  {
    DECLARE_CHAIN_CLASS(OType::EventManager,Manager,"eventManager")
    CH_SINGLETON(EventDispatcher)

    friend class EventDispatcher;

    protected:
      //---------------------------------------
      /// \details Default Constructor
      EventManager() {}
      //---------------------------------------
      /// \details Destructor
      virtual ~EventManager();

    private:
      void AddEvent (const Event* event) {}
      bool DeleteEvent (const Event* event) {return false;}

      std::vector<Event* > m_events;
  };
}

#endif
