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
        Node *root;   //Root node of the tree
       int size;      // Actual Size of the array
       void insert(Node *&,Node *&); //insert
       void dele(Node *&,int);
       int getBalance(Node *);//balance the tree       
       //function for printing
       void preOrder(Node *); 
       void inOrder(Node *);
       void postOrder(Node *);
       void printNode(Node *);
       
       void clean(Node *);//delete a node and its children
       int getHeight(Node *);//get the height of a particular node
       int max(int,int);//max of two integer
       //rotate functions
       void rotateLL(Node *&);
       void rotateLR(Node *&);
       void rotateRR(Node *&);
       void rotateRL(Node *&);
    public:      
       Tree();   //Default constructor  
       ~Tree();  // Destructor declaration
       void insert(int); //insert a number to a tree
       void dele(int);//delete
       void prePnt(); //print out tree with pre-order
       void inPnt(); //print out tree with in-order
       void postPnt(); //print out tree with post-order
       int getSize() const {return size;} //return size
};

#endif /* TREE_H */

