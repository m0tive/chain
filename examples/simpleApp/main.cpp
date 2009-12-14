// windows includes
#ifdef WIN32
  #define WIN32_LEAN_AND_MEAN
  #include <Windows.h>
  #ifdef _DEBUG
    // visual leak detector - catch memory leaks
    #include <vld.h>
  #endif
#endif

// #include <iostream>
#include <stdlib.h>
//
// #include <boost/filesystem/operations.hpp>
// #include <boost/filesystem/path.hpp>
//
#include "Chain/App.hpp"
#include "Chain/Event.hpp"

#include "Chain/Def.hpp"

//
// namespace fs = boost::filesystem;

int main(int argc, char *argv[])
{
  chain::App& app = chain::App::Instance();
/*

  // get the path to try and find the script files
  fs::path full_path( fs::current_path<fs::path>() );
  std::string pathStr;
  if(!is_directory(full_path))
  {
    pathStr = full_path.parent_path().string();
  }
  else
  {
    pathStr = full_path.file_string();
  }

#ifdef WIN32
  size_t pos; // swap '/' for '\'
  while((pos = pathStr.find('\\')) != -1)
    pathStr.replace(pos,1,1,'/');
  pathStr += "/../scripts/";
#else
  pathStr += "/scripts/";
#endif

  // build the init script
  pathStr.insert(0,"path(\"");
  pathStr.append("\"); dofile(path() .. \"init.lua\");");


  //app.AddEventListener(chain::EType::Application_Start,
  //  app.scriptManager.NewScript(pathStr + "io.write(\"Application start script\")"));
*/
  app.AddEventListener(chain::EType::Application_Stop,
    app.scriptManager.NewScript("io.write(\"Application stop script\")"));

  //CH_ASSERT(0);

  app.AddEventListener(chain::EType::Application_Render,
    app.scriptManager.NewScript("io.write(\"Render!\")"));

  app.AddEventListener(chain::EType::Application_Render,
    app.scriptManager.NewScript("io.write(\"rrrrrender\")"));

  app.Run();

  //app.renderManager.Init(200,200);


#ifdef _MSC_VER
  system("pause");
#endif
  return EXIT_SUCCESS;
}

