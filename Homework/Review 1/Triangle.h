/*
 * File:   Triangle.h
 * Author: Javier Ventura 
 * Purpose: Triangle Class Specification 
 * Created on February 25, 2018 at 11:10 AM
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "RowAray.h"

class Triangle{
private:
    int szRow;
    RowAray **records;
    
public:
    Triangle(int);
    ~Triangle();
    int getSzRow(){return szRow;}
    int getData(int, int);
    
};


#endif /* TRIANGLE_H */

