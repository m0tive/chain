/// \file EventDispatcher.cpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief Parent class for all Chain classes.
/// \note
//------------------------------------------------------------------------------

#include "EventDispatcher.hpp"
#include "Event.hpp"
#include "Container.hpp"

namespace chain
{
  //------------------------------------------------ EventDispatcher::DispatchEvent
  void EventDispatcher::DispatchEvent (const Event& event)
  {
    // process event
    int eventID = event.GetType();

    std::vector<std::pair<int, Script* > >::iterator it = m_eventListeners.begin(),
      endit = m_eventListeners.end();
    for(;it!=endit;++it)
    {
      if(it->first == eventID)
      {
        /// \todo Push the event object (and all it's sub variables) to the lua stack
        it->second->Run();
      }
    }

    Container* con_this = dynamic_cast<Container* >(this);
    if(con_this != 0 && event.DoesPropagate())
    {
      con_this->DispatchEvent(event);
    }
  }

  //------------------------------------------------ EventDispatcher::AddEventListener
  void EventDispatcher::AddEventListener (const int type, Script* script)
  {
    // add the pair to the event listener
    m_eventListeners.push_back( std::make_pair(type,script) );
  }

  //------------------------------------------------ EventDispatcher::GetEventListeners
  const std::vector<Script* >& EventDispatcher::GetEventListeners (const int type)
  {
    std::vector<Script* > matches;

    std::vector<std::pair<int, Script* > >::iterator it = m_eventListeners.begin(),
      endit = m_eventListeners.end();
    for(;it!=endit;++it)
    {
      if(it->first == type)
      {
        matches.push_back(it->second);
      }
    }

    return matches;
  }
}
