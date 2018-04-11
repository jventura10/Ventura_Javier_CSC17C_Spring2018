/*
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: Take simple vector and the linked list shown in class.  Substitute the linkedlist for the dynamic vector and fully test.
 * Created on March 19, 2018, 4:18 PM
 */

// System Libraries
#include <iostream>

using namespace std; 

// User Libraries
#include "SimpleVector.h"
#include "Object.h"

// Function prototypes
template <class T>
void prntVec(SimpleVector<T> &vect);

int main(int argc, char** argv) {
    // Create the vector
    SimpleVector<Object> vect;
    
    // Add two items
    vect.push_back(Object(5));
    vect.push_back(Object(4));
    vect.push_back(Object(3));
    
    // Print vector
    prntVec(vect);
    
    // Add a third item, expanding the vectors size
    vect.push_back(Object(2));
    
    // Print vector
    prntVec(vect);
    
    // Remove Last item
    cout<<"Removed "<<vect.pop_off()<<endl;
    
    // Print vector
    prntVec(vect);
    
    return 0;
}

template <class T>
void prntVec(SimpleVector<T> &vect){
    int sz = vect.size();
    cout <<"Size: "<<sz<<endl;
    
    for (int i = 0; i < sz; i++){
        cout<<vect[i] << " ";
    }
    
}