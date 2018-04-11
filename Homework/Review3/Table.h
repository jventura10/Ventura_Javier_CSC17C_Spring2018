/*
 * File:   Table.h
 * Author: Javier Ventura 
 * Purpose: Table Class Specification and Implementation, Inherited from AbsTabl
 * Created on March 13, 2018, 10:56 AM
 */

#ifndef TABLE_H
#define TABLE_H

#include "AbsTabl.h"

template <class T>
class Table:public AbsTabl<T>{
    public:
        Table(unsigned int,unsigned int);
        Table(const Table &);
        virtual ~Table();
        Table operator+(const Table&);
        int getSzRow()const {return this->szRow;}
        int getSzCol()const {return this->szCol;}
        T getData(int,int)const;
        void setData(int,int,T);
};

//Constructor
template<class T>
Table<T>::Table(unsigned int row, unsigned int col){
    this->szRow = row;
    this->szCol = col;
    
    //Create the new array
    this->columns = new RowAray<T>*[col];
    
    //Fill the array
    for (int i=0;i<col;i++){
        this->columns[i] = new RowAray<T>(row);
    }
}

template<class T>
Table<T>::Table(const Table &first){
    this->szRow = first.getSzRow();
    this->szCol = first.getSzCol();
    
    //Create the new array
    this->columns = new RowAray<T>*[this->szCol];
    
    //Fill the array
    for(int i = 0; i < this->szCol; i++){
        this->columns[i] = new RowAray<T>(this->szRow);
        for (int j=0;j<this->szRow;j++){
            this->columns[i]->setData(j,first.getData(j,i));
        }
    }
}

template<class T>
Table<T>::~Table(){
    // Delete each element
    for(int i=0;i<this->szCol;i++){
        delete this->columns[i];
    }
    
    // Delete the array
    delete []this->columns;
}

template<class T>
T Table<T>::getData(int row, int col)const{
    return this->columns[row]->getData(col);
}

template<class T>
void Table<T>::setData(int row, int col, T data){
    this->columns[row]->setData(col,data);
}

template <class T>
Table<T> Table<T>::operator +(const Table& first){
    Table temp(this->szRow, this->szCol);
    for(int i =0;i<temp.szRow;i++){
        temp.columns[i] = new RowAray<T>(temp.szCol);
        for(int j= 0;j<temp.szCol;j++){
            temp.setData(i, j, this->getData(i, j)+first.getData(i,j));
        }
    }
    return temp;
}

#endif /* TABLE_H */
