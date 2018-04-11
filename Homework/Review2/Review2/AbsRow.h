/*
 * File:   AbsRow.h
 * Author: Javier Ventura 
 * Purpose: AbsRow Class Specification , Abstract Row Array Class
 * Created on March 5, 2018, 3:50 PM
 */

#ifndef ABSROW_H
#define ABSROW_H


class AbsRow{
    protected:
        int size;
        int *rowData;
    public:
        virtual int getSize()const = 0;
        virtual int getData(int)const = 0;
};

#endif /* ABSROW_H */

