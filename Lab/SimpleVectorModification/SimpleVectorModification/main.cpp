/* 
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: Create Simple Vector , modify to expand size 
 * Created on March 7, 2018, 7:48 PM
 */

#include <cstdlib>
#include <iostream>

#include "SimpleVector.h"

using namespace std;

int main(int argc, char** argv) {
    //Set Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables 
    const int size=10;  
    SimpleVector<int> vec(size);
    
    for(int i=0;i<vec.size();i++){
        vec[i]=rand()%90+10;
    }
    
    
    cout << "Original Size: " << vec.size() << endl;;
    vec.print();
    cout<<endl;
    
    // push/pop some elemtents
    vec.Push(rand()%90+10);
    vec.Push(rand()%90+10);
    vec.Push(rand()%90+10);
    vec.Push(rand()%90+10);
    vec.Push(rand()%90+10);
    vec.Push(rand()%90+10);
    vec.Push(rand()%90+10);
    vec.Push(rand()%90+10);
    vec.Push(rand()%90+10);
    vec.Push(rand()%90+10);
    
    
    cout << "New Size after pushing: " << vec.size() << endl;
    vec.print();
    cout << endl;


    return 0;
}

