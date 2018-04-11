/*
 * File:   Table.h
 * Author: Javier Ventura 
 * Purpose: Table Class Specification
 * Created on March 5, 2018, 3:48 PM
 */

#ifndef TABLE_H
#define TABLE_H

#include "AbsTabl.h"

class Table:public AbsTabl{
    public:
        Table(unsigned int,unsigned int);
        Table(const Table &);
        virtual ~Table();
        int getSzRow()const {return szRow;}
        int getSzCol()const {return szCol;}
        int getData(int,int)const;
        void setData(int,int,int);
};


#endif /* TABLE_H */

