/*
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: Douibly Linked List with Sorting 
 * Created on March 29, 2018, 11:38 AM
 */

//Libraries
#include <cstdlib>
#include <iostream>

//User Libraries
#include "DoubleLinkedList.h"

using namespace std;

//Function Prototypes
void doublyLL();

int main(int argc, char** argv) {
    //Declare Variables
    bool menu=true;
    int choice;
    
    doublyLL();
    
    return 0;
}

void doublyLL(){
    //Declare Variables
    DoubleLL<int> newDLL;
    int x;
    
    cout<<"Sorted Doubly Linked List"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<endl;
    
    cout <<"Fill List";
    newDLL.fillLst(12);
    newDLL.prntLst(4);

    cout <<"Add 13 to the beginning, add 0 to the end";
    newDLL.addBeg(13);
    newDLL.addEnd(0);
    newDLL.prntLst(4);
    cout<<endl;

    cout<<"Delete beginning, delete end";
    newDLL.delBeg();
    newDLL.delEnd();
    newDLL.prntLst(4);
    cout<<endl;

    cout<<"Add 13 before 5, add 0 after 5";
    newDLL.addBefore(5, 13);
    newDLL.addAfter(5, 0);
    newDLL.prntLst(4);

    cout<<endl<<"Delete before 5, delete before 5";
    newDLL.delBefore(5);
    newDLL.delAfter(5);
    newDLL.prntLst(4);
    cout<<endl;
    
    cout<<"Search for a Number to Add to Priority: ";
    cin>>x;
    
    newDLL.addBeg(newDLL.searchLL(x));
    newDLL.prntLst(4);
    
    
}