/// \file Script.hpp
/// \date 2009/10/28
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#ifdef _MSC_VER
#pragma once
#endif

#ifndef _chain_Script_h_
#define _chain_Script_h_

#include <string>
//#include "ScriptManager.hpp"

namespace chain
{
    class ScriptManager;

	/// \brief
  class Script
	{
  friend class ScriptManager;
  protected:
    //---------------------------------------
    /// \details Default Constructor
    Script() {}
    //---------------------------------------
    /// \details Destructor
    ~Script() {}

  public:
    bool Run ();
    bool Load (const char* filename);
    bool Save (const char* filename);

    std::string text;

  protected:
    ScriptManager* m_manager;

  private:
    unsigned int m_id;
    std::string m_name;
	};
}

#endif
