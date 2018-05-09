/*
 * File:   main.cpp
 * Author: Javier Ventura
 * Purpose: Hashing Lab
 * Created on May 2, 2018, 7:49 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

//Function Prototypes
int power(int);
int hashing(int);

int main(int argc, char** argv) {
    //Set Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int *a;
    int y=25;
    int v=power(y);
    a=new int[v];
    int count=0;
    
    for(int i=0;i<v;i++){
        a[i]=i;
    }
    
    //Output Size
    cout<<"2^N N="<<y<<endl;
    
    for(int i=0;i<v;i++){
        if(a[hashing(v)]==i){
            cout<<"Collision! At Index = "<<hashing(v)<<endl;
            if(count==0){
                cout<<"First Collision!"<<endl;
            }
            count++;
        }
    }
    
    
    if(count>0){
        cout<<"Max Collisions: "<<count<<endl;
    }
    else{
        cout<<"No Collisions! :O "<<endl;
    }
    
    delete a;

    return 0;
}

//Function 2^y recursive, returns 2^y
int power(int y){
    if(y==0){
        return 1;
    }
    else{
        return power(y-1)+power(y-1);
    }
}

//Hash Function take mods random number by size v passed in, returns hash value
// for index for array in main 
int hashing(int v){
    int temp;
    
    temp=rand()%v;
    
    return temp;
}
