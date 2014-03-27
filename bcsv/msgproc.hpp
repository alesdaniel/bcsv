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
 * File:   msgproc.hpp
 * Author: dales
 *
 * Created on 20 de marzo de 2014, 17:35
 */

#ifndef MSGPROC_HPP
#define	MSGPROC_HPP

#include <string>
#include <cstring>
#include <iostream>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;

class msgproc {
public:
    msgproc();
    msgproc(const msgproc& orig);
    virtual ~msgproc();
    void proc(string msg);
private:
    int tokmsg(string msg);
    int maxstr;
    string strarray[400];    
protected:
    int sql;
    int sql_insert;
    int sql_select;
    int sql_update;
    int sql_otro;
    int no_sql;

};

#endif	/* MSGPROC_HPP */

