/// \file Script.h
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
#include "ScriptManager.hpp"

namespace chain
{
	/// \brief
  class Script : public std::string
	{
	public:
		//---------------------------------------
		/// \details Default Constructor
		Script() {}
		//---------------------------------------
		/// \details Destructor
		~Script() {}
		
    bool run ();
    bool load (const char* filename);
    bool save (const char* filename);
	};
}

#endif