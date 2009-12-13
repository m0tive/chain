/// \file EventDispatcher.hpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _chain_EventDispatcher_h_
#define _chain_EventDispatcher_h_

#include "Object.hpp"
#include "Script.hpp"

#include <utility>
#include <vector>
#include <map>

namespace chain
{
  class Event;

  #if 0
  class EventDispatcher;

  struct EventListener
  {
      int eventType;
      Script* script;

    private:
    friend class EventDispatcher;
      EventListener(const int _eventType, Script* _script)
        : eventType(_eventType), _script(script);
      {}

      ~EventListener() {}
  }
  #endif

  /// \brief ...
  /// \details ...
  class EventDispatcher : public Object
  {
    DECLARE_CHAIN_CLASS(OType::EventDispatcher,Object,"eventDispatcher")

    protected:
      //---------------------------------------
      /// \details Default Constructor
      EventDispatcher() {}
      //---------------------------------------
      /// \details Destructor
      virtual ~EventDispatcher() {}

    public:
      void DispatchEvent (const Event& event);
      void AddEventListener (const int type, Script* script);
      const std::vector<Script* >& GetEventListeners (const int type);
      //bool HasEventListener (const int type)

    protected:
      std::vector<std::pair<int, Script* > > m_eventListeners;
  };
}

#endif
