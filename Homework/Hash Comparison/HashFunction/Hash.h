/*
 * File:   Hash.h
 * Author: Javier Ventura 
 * Purpose: Hash Class
 * Created on May 20, 2018, 12:25 PM
 */

#ifndef HASH_H
#define HASH_H

#include <list>

using namespace std;

class Hash{
private:
    int chains;
    list<int> *table;
public:
    Hash(int j);
    void insert(int key);
    void dltItm(int key);
    int hshFunc(int x){
        return (x%chains);
    }
    void dsply();
};

#endif /* HASH_H */

