/*
 * File:   Table.h
 * Author: Javier Ventura 
 * Purpose: Table Class Implementation
 * Created on March 5, 2018, 3:48 PM
 */


#include "Table.h"

Table::Table(unsigned int row,unsigned int col)
{
    szRow = row;
    szCol = col;
    columns = new RowAray*[szRow];
    for(int i = 0; i < szRow; i++)
    {
        columns[i] = new RowAray(szCol);
    }
}

Table::Table(const Table& orig)
{
    this->szRow = orig.szRow;
    this->szCol = orig.szCol;
    this->columns = new RowAray*[szRow];
    for(int i = 0; i < this->szRow; i++)
    {
        this->columns[i] = orig.columns[i];
    }
}

Table::~Table()
{
    for(int i = 0; i < this->szRow;i++)
    {
        delete columns[i];
    }
    delete[]columns;
}

int Table::getData(int row, int col) const
{
    return columns[row]->getData(col);
}

void Table::setData(int row, int col, int data)
{
    columns[row]->setData(col, data);
}