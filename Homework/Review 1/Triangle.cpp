/*
 * File:   Triangle.cpp
 * Author: Javier Ventura
 * Purpose: Triangle Class Implementation 
 * Created on February 25, 2018 at 11:13 AM
 */

#include "Triangle.h"
#include "RowAray.h"

Triangle::Triangle(int rows){
    szRow=rows;     //set szRow to rows
    records =new RowAray*[szRow];   // Creates pointer of records
    for(int j = 0;j< szRow; ++j){
        records[j] = new RowAray(szRow,szRow);  //Creates space for record
    }
    
    for(int j=0;j<szRow;j++){
        for(int v=0;v<szRow;v++){
            records[j]->Fill(v);    // Fills in the record 
        }
    }
}

int Triangle::getData(int row, int col){
    return records[row]->getData(col);  // Gets the data in that space
}

Triangle::~Triangle(){
    for(int j = 0; j < szRow; ++j) {
        delete [] records[j];   // Deletes the records  
    }
    delete records;     // Deallocates the record 
}