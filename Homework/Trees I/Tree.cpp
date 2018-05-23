/*
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: Trees I Tree Class Implementation
 * Created on May 22, 2018, 9:57 AM
 */

#include "Tree.h"

//Constructor
Tree::Tree() {
    root=NULL; 
    size=0;
}

//Destructor
Tree::~Tree() {
    clean(root);
}

//delete a node and its children
void Tree::clean(Node *node) {
    if(node!=NULL) {
        clean(node->left);
        clean(node->right);
        delete node;
    }
}

//insert a number to a tree
void Tree::insert(int n) {
    //create a node to store the integer
    Node *newNode=new Node;
    newNode->value=n;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->height=1;
    //insert with recursion
    insert(root,newNode);
    size++;
}

//insert
void Tree::insert(Node *&node, Node *&newNode) {
    if(node==NULL)  {
        node=newNode;
    } else if(newNode->value <= node->value) {
        insert(node->left,newNode);
    } else {
        insert(node->right,newNode);
    }
    //renew the height the node
    node->height=max(getHeight(node->left),getHeight(node->right))+1;
    int b=getBalance(node); //get the balance of the node
    
    //Right case
    if(b<-1) {
        if(newNode->value >= node->right->value){
            rotateRR(node);
        } 
        else{
            rotateRL(node);
        }
    }
    if(b>1) {
        if(newNode->value <= node->left->value){
            rotateLL(node);
        } 
        else{
            rotateLR(node);
        }
    }
}

//Get the balance of the node
int Tree::getBalance(Node *node) {
    if(node==NULL) return 0;
    return getHeight(node->left)-getHeight(node->right);
}

//Rotate for Left Left case
void Tree::rotateLL(Node *&z) {
    //copy
    Node *y=z->left;
    Node *t3=y->right;
    
    //Perform rotation
    y->right=z;
    z->left=t3;
    
    //renew the height
    z->height=max(getHeight(z->left),getHeight(z->right))+1;
    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    z=y;
}



//Rotate for Left Right case
void Tree::rotateLR(Node *&z) {
    //change to LL case
    rotateRR(z->left);
    rotateLL(z);
}

//Rotate for Right Right case 
void Tree::rotateRR(Node *&z) {
    //copy
    Node *y=z->right;
    Node *t2=y->left;
    //Perform rotation
    y->left=z;
    z->right=t2;
    //renew the height
    z->height=max(getHeight(z->left),getHeight(z->right))+1;
    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    
    z=y;
}

//Rotate for Right Left case
void Tree::rotateRL(Node *&z) {
    //Change to RR case first
    rotateLL(z->right);
    rotateRR(z);
}



void Tree::printNode(Node *node) {
    cout<<node->value<<" ";
}

void Tree::preOrder(Node *node) {
    if(node!=NULL) {
        printNode(node);
        preOrder(node->left);
        preOrder(node->right);
    }
} 

void Tree::inOrder(Node *node) {
    if(node!=NULL) {
        inOrder(node->left);
        printNode(node);
        inOrder(node->right);
    }
}

void Tree::postOrder(Node *node) {
    if(node!=NULL) {
        postOrder(node->left);
        postOrder(node->right);
        printNode(node);
    }
}

void Tree::prePnt() {
    cout<<"Print with pre-order:  ";
    preOrder(root);      //pre-order output
    cout<<endl;
}

void Tree::inPnt() {
    cout<<"Print with in-order:   ";
    inOrder(root);       //in-order output
    cout<<endl;
}

void Tree::postPnt() {
    cout<<"Print with post-order: ";
    postOrder(root);    //post-order output
    cout<<endl;
}

int Tree::getHeight(Node* n) {
    if(n==NULL){
        return 0;
    }
    return n->height;
}

int Tree::max(int a, int b) {
    return a>=b? a:b;
}