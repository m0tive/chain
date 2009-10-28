/// \file Logger.hpp
/// \date 2009/10/20
/// \version 0.01
/// \author Peter Dodds
/// \brief
/// \note
//------------------------------------------------------------------------------

#ifdef _MSC_VER
   #pragma once
#endif

#ifndef _chain_Logger_h_
#define _chain_Logger_h_

#include "EventDispatcher.hpp"
#include <iostream>

namespace chain
{
   #ifdef _DEBUG
      #ifndef DOUT
         #define DOUT std::cout << ">> " << __FILE__ << " (" << __LINE__ << "): "
      #endif

      #ifndef DERR
         #define DERR std::cerr << "!! " << __FILE__ << " (" << __LINE__ << "): "
      #endif
   #else
      #define DOUT
      #define DERR
   #endif

   class Logger;

   /// \brief ...
   /// \details ...
   class Log : public EventDispatcher {
     DECLARE_CHAIN_CLASS(COb::Log,EventDispatcher,"log")
      friend class Logger;
      private:
         //---------------------------------------
         /// \details Default Constructor
         Log() {}
         //---------------------------------------
         /// \details Destructor
         virtual ~Log() {}

      public:
         //Log * Instance () {return th}
   };

   /// \brief Interface to chain::Log
   /// \details ...
   class Logger
   {
      public:
         //---------------------------------------
         /// \details Default Constructor
         Logger() {}
         //---------------------------------------
         /// \details Destructor
         virtual ~Logger() {}

      protected:
         Log * m_log;
   };

   extern Logger log;
   extern Logger lwar;
   extern Logger lerr;
}

#endif
