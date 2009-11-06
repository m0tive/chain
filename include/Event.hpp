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
      Dummy=0,

      Force_Quit,

      Last,
      Max=0xFFFF
    };
  };

  /// \brief ...
  /// \details ...
  class Event : public Object
  {
    friend class EventManager;

    DECLARE_CHAIN_CLASS(COb::Event,Object,"event")
    public:
      //---------------------------------------
      /// \details Default Constructor
      Event(int type, const bool propagate)
        : m_type(type), m_propagate(propagate)
      {
        assert(type <= EType::Max);
      }

      //---------------------------------------
      /// \details Destructor
      virtual ~Event() {}

      const int GetEventType() const {return m_type;}
      const bool DoesPropagate() const {return m_propagate;}

    private:
      int m_type;
      bool m_propagate;
  };
}

#endif
