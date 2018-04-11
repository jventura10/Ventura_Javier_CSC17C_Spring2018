/*
 * File:   main.cpp
 * Author: Javier Ventura
 * Purpose: Using Pointer to Array to fill table and triangle
 * Created on February 25, 2018 at 11:05 AM
 */

//Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>

//User Libraries
#include "Table.h"
#include "Triangle.h"

using namespace std;

//Function Prototypes Here
void prntRow(RowAray *, int );
void prntTab(Table * );
void prntTri(Triangle * );

int main(int argc, char** argv) {
    //Set Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables 
    int rows=6,cols=8,perLine=cols/2;
    
    //Test out the RowAray
    RowAray row(cols);
    
    //Print the RowAray
    cout<<"The Row Array size = "<<row.getSize()<<" printed "<<perLine<<" per Line "<<endl;
    
    //Print Row
    prntRow(&row,perLine);
    
    //Test out the Table
    Table tab(rows,cols);
    
    //Print the Table 
    cout<<"The Table size is [row,col] = ["<<rows<<" , "<<cols<<"]";
    prntTab(&tab);
    
    //Test out the Triangular Table
    Triangle tri(rows);
    
    //Print the Triangular Table
    cout<<"The Triangular Table size is [row,row] = ["<<rows<<" , "<<rows<<"]";
    prntTri(&tri);
    
    //Exit Stage
    return 0;
}

void prntRow(RowAray *a, int perLine){
    cout<<endl;
    for(int i=0;i<a->getSize();i++){
        cout<<a->getData(i)<<" ";
        if(i%perLine==(perLine-1)){
            cout<<endl;
        }
    }
    cout<<endl;
}

void prntTab(Table *a ){
    cout<<endl;
    for(int row=0;row<a->getSzRow();row++){
        for(int col=0;col<a->getSzCol();col++){
            cout<<a->getData(row,col)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void prntTri(Triangle * a){
    cout<<endl;
    for(int row=0;row<a->getSzRow();row++){
        for(int col=0;col<=row;col++){
            cout<<a->getData(row,col)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}