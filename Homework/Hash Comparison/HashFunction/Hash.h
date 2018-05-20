/*
 * File:   Hash.h
 * Author: Javier Ventura 
 * Purpose: Hash Class
 * Created on May 20, 2018, 12:25 PM
 */

#ifndef HASH_H
#define HASH_H

#include <list>
#include <string>
#include <iostream>
using namespace std;

class Hash{
private:
    int chains;
    list<string> *table;
public:
    Hash(int j);
    void insert(string word);
    void dltItm(string word);
    int hshFunc(string word);
    void dsply();
};

#endif /* HASH_H */

