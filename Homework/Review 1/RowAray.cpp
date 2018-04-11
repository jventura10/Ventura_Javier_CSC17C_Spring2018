/*
 * File:   RowAray.cpp
 * Author: Javier Ventura
 * Purpose: RowAray Class Implementation
 * Created on February 25, 2018 at 11:12 AM
 */


#include "RowAray.h"
#include <iostream>
RowAray::RowAray(int cols){
    size=cols;//set cols into size
    rowData=new int[size];//create pointer
    
    for(int j=0;j<size;j++){//fill in pointer
        rowData[j]=rand()%90+10;
    }
}

RowAray::RowAray(int row,int col){
    size=row*col;//multiply row and col and set to size
    rowData=new int[size];//create pointer with size
}

void RowAray::Fill(int j){
    rowData[j]=rand()%90+10;   //fill from 10-99
}

RowAray::~RowAray(){
    delete []rowData;//deallocates rowData
}