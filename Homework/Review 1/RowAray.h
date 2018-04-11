/*
 * File:   RowAray.h
 * Author: Javier Ventura 
 * Purpose: RowAray Class Specification
 * Created on February 28, 2018 at 11:07 PM
 */

#ifndef ROWARAY_H
#define ROWARAY_H

class RowAray{
private:
    int size;
    int *rowData;
    
public:
    RowAray(int);
    RowAray(int,int);
    void Fill(int);
    ~RowAray();
    int getSize(){return size;}
    int getData(int i ){return rowData[i];}    
};


#endif /* ROWARAY_H */

