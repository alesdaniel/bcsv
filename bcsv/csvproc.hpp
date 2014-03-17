/*
 *  This file is part of bcsv.
 * 
 *  Foobar is free software: you can redistribute it and/or modify
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
 *  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
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

class csvproc {
public:
    csvproc();
    csvproc(const csvproc& orig);
    bool abre(std::string arch);
    virtual ~csvproc();
private:
    
protected:    
    int linea;
    int sql;
    int sql_insert;
    int sql_select;
    int sql_update;
};

#endif	/* CSVPROC_HPP */

