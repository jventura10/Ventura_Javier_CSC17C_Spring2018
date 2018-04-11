/*
 * File:   AbsTabl.h
 * Author: Javier Ventura 
 * Purpose: AbsTabl Class
 * Created on March 13, 2018, 11:00 AM
 */

#ifndef ABSTABL_H
#define ABSTABL_H

#include "RowAray.h"

template <class T>
class AbsTabl{
    protected:
        int szRow;
        int szCol;
        RowAray<T> **columns;
    public:
        virtual int getSzRow()const = 0;
        virtual int getSzCol()const = 0;
        virtual T getData(int,int)const = 0;
};



#endif /* ABSTABL_H */

