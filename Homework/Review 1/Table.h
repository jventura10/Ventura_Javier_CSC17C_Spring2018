/*
 * File:   Table.h
 * Author: Javier Ventura
 * Purpose: Table Class Specification
 * Created on February 28, 2018 at 11:08 PM
 */

#ifndef TABLE_H
#define TABLE_H

#include "RowAray.h"

class Table{
private:
    int szRow;
    int szCol;
    RowAray **records;
    
public:
    Table(int,int);
    ~Table();
    int getSzRow(){return szRow;}
    int getSzCol(){return szCol;}
    int getData(int,int); 
};

#endif /* TABLE_H */

