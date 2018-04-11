/*
 * File:   RowAray.h
 * Author: Javier Ventura 
 * Purpose: RowAray Class Implementation
 * Created on March 5, 2018, 3:49 PM
 */

#include "RowAray.h"
#include <cstdlib>

RowAray::RowAray(unsigned int size)
{
    this->size = size;
    rowData = new int[this->size];
    for(int i=0;i< this->size;i++)
    {
        rowData[i] = rand()%90+10;//Fill data with 2 digit numbers
    }
}

RowAray::~RowAray()
{
    delete[]rowData;
}

void RowAray::setData(int col, int data)
{
    rowData[col] = data;
}