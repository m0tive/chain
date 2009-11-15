/// \file EventDispatcher.cpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief Parent class for all Chain classes.
/// \note
//------------------------------------------------------------------------------

#include "EventDispatcher.hpp"
#include "Event.hpp"
#include "DisplayObject.hpp"
#include "Container.hpp"

#include "Log.hpp"

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

    // try to cast this to a DisplayObject, and then propergate the event
    DisplayObject* dis_this;
    if(event.DoesPropagate() && (dis_this = dynamic_cast<DisplayObject* >(this)) != 0 )
    {
      dis_this->Parent()->DispatchEvent(event);
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
    int TODO;///\todo 2009/11/14 21:07 : Test this. 
    /// the compiler thinks matches will go out of scope before returning properly

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
