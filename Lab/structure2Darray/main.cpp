/*
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: Develop a 2D Array Structure
 *  with potential future for different # cols per row
 * Created on February 14, 2018, 7:42 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

#include "Struct2D.h"

using namespace std;

//Function Prototypes
Array2D *filStrc(int,int);
void prtStrc(Array2D *);
void destroy(Array2D *);
void mrkSort(Array2D *,int col);

int main(int argc, char** argv) {
    //Set Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and Initialize the 2D Structure 
    Array2D *x=filStrc(10,15);
    
    //Display the contents of the 2D Structure 
    prtStrc(x);
    
    //Sort a column of the Array
    mrkSort(x,0);
    
    //Display Sorted Contents of the 2D Structure
    prtStrc(x);
    
    //Destroy 
    destroy(x);
    
    return 0;
}

Array2D *filStrc(int row,int col){
    //Declare Variables
    Array2D *array=new Array2D;
    
    //Fill 2D Array Structure 
    array->rows=row;
    array->cols=col;
    
    //Allocate Memory for the 2D Array Structure 
    array->data=new int *[array->rows];
    for(int i=0;i<array->rows;i++){
        array->data[i]=new int[col];
    }
    
    //Fill the Memory Array 
    for(int i=0;i<array->rows;i++){
        for(int j=0;j<array->cols;j++){
            array->data[i][j]=rand()%90+10;
        }
    }
    return array;
}

void prtStrc(Array2D *a){
    //Display the Structure 
    cout<<"Structure Data Array Size => Rows = "<<a->rows<<" Cols = "<<a->cols<<endl;
    cout<<endl;
    for(int i=0;i<a->rows;i++){
        for(int j=0;j<a->cols;j++){
            cout<<a->data[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

void destroy(Array2D *array){
    //Deallocate Memory for the 2D Array Structure
    for(int i=0;i<array->rows;i++){
        delete []array->data[i];
    }
    delete []array->data;
    delete array;
}

void mrkSort(Array2D *a,int col){
    for(int i=0;i<a->rows-1;i++){
        for(int j=i+1;j<a->rows;j++){
            if(a->data[i][col]>a->data[j][col]){
                for(int k=0;k<a->cols;k++){
                    int temp=a->data[i][k];
                    a->data[i][k]=a->data[j][k];
                    a->data[j][k]=temp;
                }
            }
        }
    }
}