/// \file RenderManager.cpp
/// \date 2009/10/22
/// \version 0.01
/// \author Peter Dodds
/// \brief
/// \note Copyright (C) 2009 - All Rights Reserved
//------------------------------------------------------------------------------

#include "RenderManager.hpp"
#include "Log.hpp"

namespace chain
{
  //------------------------------------------------ RenderManager::~RenderManager
  RenderManager::~RenderManager()
  {
    DOUT << "quiting renderer\n";
    if(SDL_WasInit(SDL_INIT_VIDEO)){
      DOUT << "quiting sdl\n";
      SDL_Quit();
    }
  }
  //------------------------------------------------ RenderManager::Init
  void RenderManager::Init(const int width, const int height,
    const int sdlFlags/* = SDL_INIT_VIDEO*/, const int glFlags/* = SDL_OPENGL | SDL_HWSURFACE*/)
  {
    // SDL init originally referenced from NCCA Graphics Library

    int TODO; /// \todo Catch this error
    if(SDL_Init(sdlFlags 
#ifdef _DEBUG
      | SDL_INIT_NOPARACHUTE // Tell SDL not to catch fatal errors
#endif
        ) != 0)
    {
      DERR << "error init'ing SDL\n";
      exit(EXIT_FAILURE);
    }
    DOUT << "starting renderer\n";

    const SDL_VideoInfo* info=NULL;
    info = SDL_GetVideoInfo();
    int bpp = info->vfmt->BitsPerPixel;

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,24);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);


    m_sdlSurface = SDL_SetVideoMode(width,height,bpp, SDL_OPENGL | SDL_HWSURFACE | SDL_RESIZABLE );

    if(m_sdlSurface==0)
    {
      DERR << "Video Mode Failed\n" << SDL_GetError();
      exit(EXIT_FAILURE);
    }
    SDL_EnableKeyRepeat(100, 10);
  }
}
