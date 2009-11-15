/// \file Event.cpp
/// \date 2009/11/09
/// \version 0.01
/// \author Peter Dodds
/// \brief Parent class for all Chain classes.
/// \note
//------------------------------------------------------------------------------

#include "Event.hpp"

#include "Log.hpp"

#include <assert.h>

namespace chain
{
  //------------------------------------------------ Event::Event
  Event::Event(int type, bool propagate/* = false*/)
    : m_type(type), m_propagate(propagate)
  {
    assert(type <= EType::Max);
  }
}
