/*
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: Hash Function with Chaining
 * Created on May 20, 2018, 12:00 PM
 */

#include <iostream>
#include "Hash.h"
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    int a[]={15,11,27,8,16,24,7,12,13,55,67,68,90,134,38,28};
    int n=sizeof(a)/sizeof(a[0]);
    
    //Insert 7 possible chains or columns
    Hash h(7);
    
    for(int i=0;i<n;i++){
        h.insert(a[i]);
    }
    
    h.dsply();
    
    return 0;
}

