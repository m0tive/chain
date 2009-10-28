/// \file Script.cpp
/// \date 2009/10/28
/// \author Peter Dodds
/// \brief 
/// \note 
//------------------------------------------------------------------------------

#include "Script.hpp"
#include <lua/lua.hpp>
#include <fstream>

namespace chain
{
	//------------------------------------------------ Script::run
  bool Script::run()
  {
    //luaL_dostring(m_luaState, this->c_str());
    return false;
  }

  //------------------------------------------------ Script::load
  bool Script::load( const char* filename )
  {
    std::ifstream file;
    file.open(filename, std::ios::in);
    if (!file.is_open())
      return false;
    
    while(!file.eof())
      this->push_back(static_cast<char >(file.get()));

    return true;
  }

  //------------------------------------------------ Script::save
  bool Script::save( const char* filename )
  {
    std::ofstream file (filename,std::ios::out);
    if (!file.is_open())
      return false;
    
    std::string::iterator i = this->begin();
    for (;i!=this->end();++i)
      file.put(*i);

    file.close();

    return true;
  }
}