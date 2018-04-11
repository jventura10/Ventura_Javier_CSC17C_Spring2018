/*
 * File:   AbsRow.h
 * Author: Javier Ventura 
 * Purpose: AbsRow Class
 * Created on March 13, 2018, 11:02 AM
 */

#ifndef ABSROW_H
#define ABSROW_H

#include "SimpleVector.h"

template <class T>
class AbsRow{
    protected:
        int size;
        T *rowData;
    public:
        virtual int getSize()const = 0;
        virtual T getData(int)const = 0;
};


#endif /* ABSROW_H */

