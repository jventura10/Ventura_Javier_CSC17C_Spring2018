/*
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: Hash Function with Chaining
 * Created on May 20, 2018, 12:00 PM
 */

#include <iostream>
#include <string>

#include "Hash.h"

Hash::Hash(int j){
    this->chains=j;
    table=new list<string>[chains];
}

void Hash::insert(string word){
    int index=hshFunc(word);
    table[index].push_back(word);
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

int Hash::hshFunc(string word){
    int sum=0;
    for(int j=0;j<word.length();j++){
        sum=sum+int(word[j]);
    }
    
    return (sum%chains);
}