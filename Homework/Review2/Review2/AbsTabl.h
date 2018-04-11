/*
 * File:   AbsTabl.h
 * Author: Javier Ventura 
 * Purpose: AbsTabl Class Specification, Abstract Table Class
 * Created on March 5, 2018, 3:50 PM
 */

#ifndef ABSTABL_H
#define ABSTABL_H

#include "RowAray.h"

class AbsTabl{
    protected:
        int szRow;
        int szCol;
        RowAray **columns;
    public:
        virtual int getSzRow()const = 0;
        virtual int getSzCol()const = 0;
        virtual int getData(int,int)const = 0;
};


#endif /* ABSTABL_H */

