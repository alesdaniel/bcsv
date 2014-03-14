/* 
 * File:   main.cpp
 * Author: dales
 *
 * Created on 13 de marzo de 2014, 18:52
 */
#define BOOST_FILESYSTEM_VERSION 3

#include <boost/config/warning_disable.hpp>
#include <boost/filesystem.hpp>

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <cstring>

#include "csvproc.hpp"

#ifdef BOOST_WINDOWS_API
# include <windows.h>
#endif


static bool echo = false;
static bool create_dirs = false;
static bool boost_build_v2 = true;


using namespace std;
namespace fs = boost::filesystem;     
/*
 * 
 */
int main(int argc, char** argv) 
{
   std::ios::sync_with_stdio(false);
   fs::initial_path();
  
   std::ifstream arch("c:\\postgresql-2014-01-08_000000.log");

   if (!arch.is_open()) {
       std::cerr << "Error leyendo archivo";  
       return 1;
       }
   
   while (arch.good())          // loop while extraction from file is possible
  {
    char c = arch.get();       // get character from file
    if (arch.good())
      std::cout << c;
  }

    arch.close();
    return 0;
}
