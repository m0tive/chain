/// \file RenderManager.cpp
/// \date 2009/10/22
/// \version 0.01
/// \author Peter Dodds
/// \brief
/// \note
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _Chain_RenderManager_h_
#define _Chain_RenderManager_h_

#include "Manager.hpp"

#ifdef DARWIN
  #include <OpenGL/gl.h>
#else
  #include <GL/glew.h>
  #include <GL/gl.h>
#endif

#include <SDL/SDL.h>

namespace chain
{
  class App;

  /// \brief ...
  /// \details ...
  class RenderManager : public Manager
  {
    friend class App;

    //DECLARE_CHAIN_CLASS(COb::RenderManager,Manager,"renderManager")
    protected:
      //---------------------------------------
      /// \details Default Constructor
      RenderManager() {}
      //---------------------------------------
      /// \details Destructor
      virtual ~RenderManager();

    public:
      void Init(const int width, const int height, const int sdlFlags = SDL_INIT_VIDEO, const int glFlags = SDL_OPENGL | SDL_HWSURFACE);

    protected:
      SDL_Surface* m_sdlSurface;
  };
}

#endif
