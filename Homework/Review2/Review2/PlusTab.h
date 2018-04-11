/*
 * File:   PlusTab.h
 * Author: Javier Ventura 
 * Purpose: PlusTab Class Specification, Table Addition Operator
 * Created on March 5, 2018, 3:49 PM
 */

#ifndef PLUSTAB_H
#define PLUSTAB_H

#include "Table.h"

class PlusTab:public Table{
    public:
        PlusTab(unsigned int r,unsigned int c):Table(r,c){};
        PlusTab operator+(const PlusTab &);
};

#endif /* PLUSTAB_H */

