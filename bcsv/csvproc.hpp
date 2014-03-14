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

