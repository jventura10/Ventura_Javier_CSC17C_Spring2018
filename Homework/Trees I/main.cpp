/*
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: Trees I 
 * Created on May 22, 2018, 9:57 AM
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

#include "Tree.h"

int main(int argc, char** argv) {
    //Set Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    vector<int> vec;
    Tree t;
    
    //Insert random number and store them into vector and tree
    for(int i=0;i<10;i++) {
        int temp=rand()%90+10;
        cout<<"Insert "<<temp<<" to tree"<<endl;
        t.insert(temp);
        vec.push_back(temp);
    }
    
    //Traversing the tree
    cout<<endl;
    cout<<"Traversing the tree: "<<endl;
    t.inPnt();
    t.prePnt();
    t.postPnt();
    cout<<endl;
    
    return 0;
}
