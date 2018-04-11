/*
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: Add Functions, Delete and FIll -> Replace Dynamic Vector with Linked List
 * Created on March 19, 2018, 4:18 PM
 */

// System Libraries
#include <iostream>

using namespace std;  // Name-space used in the System Library

// User Libraries
#include "SimpleVector.h"
#include "Object.h"

// Global Constants

// Function prototypes
template <class T>
void prntVec(SimpleVector<T> &vect);

// Execution Begins Here!
int main(int argc, char** argv) {
    // Create the vector
    SimpleVector<Object> vect;
    
    // Add items
    vect.push_back(Object(6));
    vect.push_back(Object(5));
    vect.push_back(Object(4));
    
    // Print vector
    prntVec(vect);
    
    // Delete Items
    cout<<"Removed " <<vect.pop_off()<<endl;
    cout<<"Removed " <<vect.pop_off()<<endl;
    
    
    // Print vector
    prntVec(vect);

    // Add items back
    cout<<"Adding Some Objects Back"<<endl;
    vect.push_back(Object(5));
    vect.push_back(Object(4));
    vect.push_back(Object(3));
    
    // Print vector
    prntVec(vect);
    
    return 0;
}

template <class T>
void prntVec(SimpleVector<T> &vect) {
    int sz = vect.size();
    cout << "Size: " << sz << endl;
    
    for (int i = 0; i < sz; i++) {
        cout << vect[i] << " ";
    }
}