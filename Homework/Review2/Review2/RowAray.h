/*
 * File:   RowAray.h
 * Author: Javier Ventura 
 * Purpose: RowAray Class Specification
 * Created on March 5, 2018, 3:49 PM
 */

#ifndef ROWARAY_H
#define ROWARAY_H

#include "AbsRow.h"

class RowAray:public AbsRow{
    public:
        RowAray(unsigned int);
        virtual ~RowAray();
        int getSize()const{return size;}
        int getData(int i)const{
            if(i>=0&&i<size)return rowData[i];
            else return 0;}
        void setData(int,int);
};


#endif /* ROWARAY_H */

