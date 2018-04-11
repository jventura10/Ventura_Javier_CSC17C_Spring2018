/*
 * File:   PlusTab.h
 * Author: Javier Ventura 
 * Purpose: PlusTab Class Implementation, Table Addition Operator
 * Created on March 5, 2018, 3:49 PM
 */

#include "PlusTab.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

PlusTab PlusTab::operator +(const PlusTab& orig)
{
    PlusTab temp(this->szRow, this->szCol);
    for(int i =0; i < temp.szRow; i++)
    {
        temp.columns[i] = new RowAray(temp.szCol);
        for(int j = 0; j < temp.szCol; j++)
        {
            temp.setData(i, j, this->getData(i, j) + orig.getData(i, j));
        }
    }
    
    return temp;
}