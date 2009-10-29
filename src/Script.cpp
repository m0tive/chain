/// \file Script.cpp
/// \date 2009/10/28
/// \author Peter Dodds
/// \brief
/// \note
//------------------------------------------------------------------------------

#include "Script.hpp"
#include <lua/lua.hpp>
#include <fstream>

#include "ScriptManager.hpp"


namespace chain
{
	//------------------------------------------------ Script::run
  bool Script::Run()
  {
    return m_manager->Run(text.c_str());
  }

  //------------------------------------------------ Script::load
  bool Script::Load( const char* filename )
  {
    std::ifstream file;
    file.open(filename, std::ios::in);
    if (!file.is_open())
      return false;

    while(!file.eof())
      text.push_back(static_cast<char >(file.get()));

    return true;
  }

  //------------------------------------------------ Script::save
  bool Script::Save( const char* filename )
  {
    std::ofstream file (filename,std::ios::out);
    if (!file.is_open())
      return false;

    std::string::iterator i = text.begin();
    for (;i!=text.end();++i)
      file.put(*i);

    file.close();

    return true;
  }
}
