/*
 * File:   Table.cpp
 * Author: Javier Ventura
 * Purpose: Table Class Implementation
 * Created on February 25, 2018 at 11:14 AM
 */

#include "RowAray.h"
#include "Table.h"

Table::Table(int rows, int cols){
    //Setting sizes for Table
    szRow=rows;//sets rows to szRow
    szCol=cols;//set cols to szCol
    records =new RowAray*[szRow];//creates a pointer for record
    //creates space for 2dArray
    for (int j=0; j<szRow;j++){
        records[j]=new RowAray(szRow,szCol);//pointer to pointer  
    }
    //fill the array
    for(int j=0;j<szRow;j++){
        for(int v=0;v<szCol;v++){
            records[j]->Fill(v);//fills my 2d array 
        }
    }         
}

int Table::getData(int row, int col){ 
    return records[row]->getData(col);//returns the data at location
}

Table::~Table(){
    for(int j = 0; j < szRow; ++j) {
        delete [] records[j]; //deallocate records 2 degree of pointer
    } 
    delete [] records;//deallocate records
}