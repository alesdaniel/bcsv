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
 * File:   msgproc.cpp
 * Author: dales
 * 
 * Created on 20 de marzo de 2014, 17:35
 */
/* Deberia analizar el campo msg del log y ver si que funcion es para descartarla
 * o reenviarla a el servidor
 */
#include "msgproc.hpp"



msgproc::msgproc() {
    sql = 0; 
    no_sql = 0; 
    sql_insert = 0;
    sql_select = 0;
    sql_update = 0;
    sql_delete = 0;
    sql_otro = 0;
}

msgproc::msgproc(const msgproc& orig) {
}

int msgproc::tokmsg(string msg) {
  
  int cont;
  cont  =-1;
  typedef boost::tokenizer<boost::char_separator<char> > 
    tokenizer;
  boost::char_separator<char> sep(": ");
  tokenizer tokens(msg, sep);
  for (tokenizer::iterator tok_iter = tokens.begin();
       tok_iter != tokens.end(); ++tok_iter)
      strarray[++cont]=*tok_iter;
    /*std::cout << "<" << *tok_iter << "> ";
  std::cout << "\n";   */
  if (strarray[0] == "statement")
      return 1; 
  return 0;
}

void msgproc::proc(string msg) {
//  strarray->clear();   falta funcion para limpiar variable
  limpia_strarray();  
  switch(tokmsg(msg)) 
  {
      case 1:
          proc_statement(msg);
          break;  //analiza que funcion sql es para replicarla o no
      default: break; //el resto de las funciones se vera caso por caso
  }       
}

void msgproc::limpia_strarray() {
  for (int i = 0;i<3000;i++)
     strarray[i].clear();
}


void msgproc::proc_statement(string msg) {
  int cont = 0;
  bool var = false;
  string str;
  while ((!var) || (cont > 3000))
  {
   cont++;
   str.clear();   
   str = boost::to_upper_copy(strarray[cont]);
   
  }   
}


msgproc::~msgproc() {
}

