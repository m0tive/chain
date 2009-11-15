/// \file Mesh.cpp
/// \date 2009/10/22
/// \version 0.01
/// \author Peter Dodds
/// \brief
/// \note
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _Chain_Mesh_h_
#define _Chain_Mesh_h_

#include "Geometry.hpp"

namespace chain
{
   /// \brief ...
   /// \details ...
   class Mesh : public Geometry
   {
     DECLARE_CHAIN_CLASS(COb::Mesh,Geometry,"mesh")
      public:
         //---------------------------------------
         /// \details Default Constructor
         Mesh();
         //---------------------------------------
         /// \details Destructor
         virtual ~Mesh();
   };
}

#endif
