/*
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: Trees I Tree Specification
 * Created on May 22, 2018, 9:57 AM
 */

#ifndef TREE_H
#define TREE_H

#include <iostream>

using namespace std;

class Tree {
    private:
       struct Node {
            int value;         //value
            struct Node *left; //left child
            struct Node *right;//right child
            int height;        //height of the node
        };
       Node *root;                      //Root node of the tree
       int size;                        //Actual Size of the array
       void insert(Node *&,Node *&);    //Insert
       void dele(Node *&,int);
       int getBalance(Node *);          //Balance the tree       
       //Functions for Printing
       void preOrder(Node *); 
       void inOrder(Node *);
       void postOrder(Node *);
       void printNode(Node *);
       
       void clean(Node *);      //Delete a node and its children
       int getHeight(Node *);   //Get the height of a particular node
       int max(int,int);        //Max of two integer
       //rotate functions
       void rotateLL(Node *&);
       void rotateLR(Node *&);
       void rotateRR(Node *&);
       void rotateRL(Node *&);
    public:      
       Tree();              //Default constructor  
       ~Tree();             //Destructor declaration
       void insert(int);    //Insert a number to a tree
       void dele(int);      //Delete
       void prePnt();       //Print out tree with pre-order
       void inPnt();        //Print out tree with in-order
       void postPnt();      //Print out tree with post-order
       int getSize()const{return size;}     //Return size
};

#endif /* TREE_H */

