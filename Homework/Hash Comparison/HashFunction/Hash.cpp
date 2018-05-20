/*
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: Hash Function with Chaining
 * Created on May 20, 2018, 12:00 PM
 */
#include <iostream>

#include "Hash.h"

Hash::Hash(int j){
    this->chains=j;
    table=new list<int>[chains];
}

void Hash::insert(int key){
    int index=hshFunc(key);
    table[index].push_back(key);
}

void Hash::dltItm(int key){
    int index=hshFunc(key);
    
    //find key in the list
    list<int> :: iterator i;
    for(i=table[index].begin();i!=table[index].end();i++){
        if(*i==key){
            break;
        }
    }
    
    //If it is found delete item
    if(i!=table[index].end()){
        table[index].erase(i);
    }
    
}

void Hash::dsply(){
    for(int i=0;i<chains;i++){
        cout<<i;
        for(auto x:table[i]){
            cout<<" --> "<<x;
        }
        cout<<endl;
    }
}