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
 * File:   csvproc.cpp
 * Author: dales
 *
 * Created on 14 de marzo de 2014, 17:38
 */
#include "csvproc.hpp"

using namespace std;

csvproc::csvproc()
{
  linea = 0;
  csvpos =0;
}

csvproc::csvproc(const csvproc& orig)
{
    
}

bool csvproc::abre(std::string arch)
{
  entrada.open(arch.c_str(), std::ifstream::in);
  if (!entrada.is_open()) {
       std::cerr << "Error leyendo archivo" << endl;  
       return false;
       }
  return true;  
}

void csvproc::cierra()
{
  if (entrada.is_open())      
        entrada.close();    
}

void csvproc::lee()
{
  logcsv log;
  bool comillas;
  comillas = false;  
  char c;
  long bytes;
  msgproc msgproc;
  
  while (entrada.good())         
  {
    c = entrada.get();      
    bytes = entrada.tellg();
  /*  if (bytes == 60)
        break;*/
    if (c == '"')
    {  
      if (comillas) 
        comillas = false;
      else         
        comillas = true;       
      c = 0x20;
       //continue; //adelanta un caracter para saltear las "
    }  
    if ((c == ',') && (!comillas)) //coma es la separacion entre campos
    {
        if (!comillas)
        {   
          csvpos++;    
        //  c = entrada.get(); //adetanta un caracter para saltear la coma
         continue; //adelanta un caracter para saltear la ,
        }
    }
    if ((csvpos >= 22) && (c ==  '\n'))
       {
        if (csvpos < 22) 
             cerr << "Error en csv csvpos=" << csvpos << endl;
        linea++;
        csvpos = 0;
        //cout << log.log_time << "-" << log.user_name << "-" << log.database_name;
        cout << linea << " -- " << bytes << endl;
        //msgproc->proc(log.message);
        msgproc.proc(log.message);
        //*********************************************************************
        // Limpia los campos, hace mas lento el proceso pero no deja sin memoria
        // a la maquina cuando el archivo de log es muy grande
        log.log_time.clear();
        log.user_name.clear();
        log.database_name.clear();
        log.process_id.clear();
        log.connection_from.clear();
        log.session_id.clear();
        log.session_line_num.clear();
        log.command_tag.clear();
        log.session_start_time.clear();
        log.virtual_transaction_id.clear();
        log.transaction_id.clear();
        log.error_severity.clear();
        log.sql_state_code.clear();
        log.message.clear();
        log.detail.clear();
        log.hint.clear();
        log.internal_query.clear();
        log.internal_query_pos.clear();
        log.contex.clear();
        log.query.clear();
        log.query_pos.clear();
        log.location.clear();
        log.application_name.clear();        
        //*********************************************************************
        continue; //vuelve limpiando cacater de fin de linea
       }    
    switch(csvpos)
    { //case para acomodar las variables del csv
        case 0:
            log.log_time += c;
            break;
        case 1:
            log.user_name += c;
            break;
        case 2:
            log.database_name += c;
            break;
        case 3:
            log.process_id += c;
            break;
        case 4:
            log.connection_from += c;
            break;
        case 5:
            log.session_id += c;
            break;
        case 6:
            log.session_line_num += c;
            break;            
        case 7:
            log.command_tag += c;
            break;
        case 8:
            log.session_start_time += c;
            break;
        case 9:
            log.virtual_transaction_id += c;
            break;
        case 10:
            log.transaction_id += c;
            break;           
        case 11:
            log.error_severity += c;
            break;           
        case 12:
            log.sql_state_code += c;
            break;
        case 13:
            log.message += c;
            break;
        case 14:
            log.detail += c;
            break;
        case 15:
            log.hint += c;
            break;
        case 16:
            log.internal_query += c;
            break;
        case 17:
            log.internal_query_pos += c;
            break;
        case 18:
            log.contex += c;
            break;
        case 19:
            log.query += c;
            break;
        case 20:
            log.query_pos += c;
            break;
        case 21:
            log.location += c;
            break;
        case 22:
            log.application_name += c;
            break;            
        default:
            cerr << "Error en csv csvpos=" << csvpos << endl;
    }       
  }     
}

void csvproc::procesacsv(std::string arch)
{
 if (!abre(arch))
    std::cerr << "Error leyendo archivo" << endl;
  //Falta la salida con error
 lee();
 cierra();
}


csvproc::~csvproc()
{
    
}       