/*
 * File:   RowAray.h
 * Author: Javier Ventura 
 * Purpose: RowAray Class 
 * Created on March 13, 2018, 11:01 AM
 */

#ifndef ROWARAY_H
#define ROWARAY_H

#include "AbsRow.h"

#include <cstdlib>

template <class T>
class RowAray:public AbsRow<T>{
    public:
        RowAray(int);
        virtual ~RowAray();
        int getSize()const{return this->size;}
        T getData(int i)const{
            if(i>=0&&i<this->size){
                return this->rowData[i];
            }
            else{
                return 0;
            }
        }
        void setData(int,T);
};

//Constructor
template <class T>
RowAray<T>::RowAray(int size){
    this->size = size;
    this->rowData = new T [this->size];
    for(int i=0;i< this->size;i++){
        this->rowData[i] = rand()%90+10;
    }
}


//Destructor
template <class T>
RowAray<T>::~RowAray(){
    delete this->rowData;
}

template <class T>
void RowAray<T>::setData(int col, T data){
    this->rowData[col] = data;
}


#endif /* ROWARAY_H */

