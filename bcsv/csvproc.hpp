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
 * File:   csvproc.hpp
 * Author: dales
 *
 * Created on 14 de marzo de 2014, 17:38
 */

#ifndef CSVPROC_HPP
#define	CSVPROC_HPP

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <cstring>
#include "msgproc.hpp"
#include "debug.hpp"


class csvproc {
public:
    csvproc();
    csvproc(const csvproc& orig);
    void procesacsv(std::string arch);   
    virtual ~csvproc();
private:
    std::ifstream entrada;
    bool abre(std::string arch);
    void cierra();
    void lee();

//    friend log;
protected:    
    int linea;
    int csvpos;
/*CREATE TABLE postgres_log
(
  log_time timestamp(3) with time zone,
  user_name text,
  database_name text,
  process_id integer,
  connection_from text,
  session_id text,
  session_line_num bigint,
  command_tag text,
  session_start_time timestamp with time zone,
  virtual_transaction_id text,
  transaction_id bigint,
  error_severity text,
  sql_state_code text,
  message text,
  detail text,
  hint text,
  internal_query text,
  internal_query_pos integer,
  context text,
  query text,
  query_pos integer,
  location text,
  application_name text,
  PRIMARY KEY (session_id, session_line_num)
);*/    
  struct logcsv
  {
   std::string log_time;
   std::string user_name;
   std::string database_name;
   std::string process_id;
   std::string connection_from;
   std::string session_id;
   std::string session_line_num;
   std::string command_tag;
   std::string session_start_time;
   std::string virtual_transaction_id;
   std::string transaction_id;
   std::string error_severity;
   std::string sql_state_code;
   std::string message;
   std::string detail;
   std::string hint;
   std::string internal_query;
   std::string internal_query_pos;
   std::string contex;
   std::string query;
   std::string query_pos;
   std::string location;
   std::string application_name;
  };  
};
#endif	/* CSVPROC_HPP */

