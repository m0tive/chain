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
#include "EventManager.hpp"

namespace chain
{
  /// \brief ...
  /// \details ...
  class Event : public Object
  {
    friend class EventManager;

    DECLARE_CHAIN_CLASS(COb::Event,Object,"event")
    public:
      //---------------------------------------
      /// \details Default Constructor
      Event(const EType::T type, const bool propagate)
        : m_type(type), m_propagate(propagate)
      {}

      //---------------------------------------
      /// \details Destructor
      virtual ~Event() {}

      EType::T GetType() {return m_type;}
      bool DoesPropagate() {return m_propagate;}

    private:
      EType::T m_type;
      bool m_propagate;
  };
}

#endif
