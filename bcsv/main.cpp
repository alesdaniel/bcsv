/*
 *  This file is part of bcsv.
 * 
 *  bcsv is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  bcsv is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with bcsv.  If not, see <http://www.gnu.org/licenses/>.
 */
/* 
 * File:   main.cpp
 * Author: dales
 *
 * Created on 13 de marzo de 2014, 18:52
 */
#define BOOST_FILESYSTEM_VERSION 3

#include <boost/config/warning_disable.hpp>
#include <boost/filesystem.hpp>
#include <boost/version.hpp>
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
  
  csvproc csvproc; 

  csvproc.procesacsv("d:\\postgresql-2014-03-14_000000.csv");

  
  return 0;
}
