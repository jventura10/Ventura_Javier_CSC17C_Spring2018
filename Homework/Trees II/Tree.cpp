/*
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: Trees I Tree Class Implementation
 * Created on May 22, 2018, 9:57 AM
 */

#include "Tree.h"

//Constructor
Tree::Tree(){
    root=NULL; 
    size=0;
}

//Destructor
Tree::~Tree(){
    clean(root);
}

//Delete a node and its children
void Tree::clean(Node *node){
    if(node!=NULL){
        clean(node->left);
        clean(node->right);
        delete node;
    }
}

//Insert a number to a tree
void Tree::insert(int n){
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

//Insert
void Tree::insert(Node *&node, Node *&newNode){
    if(node==NULL)  {
        node=newNode;
    } 
    else if(newNode->value <= node->value){
        insert(node->left,newNode);
    } 
    else {
        insert(node->right,newNode);
    }
    //renew the height the node
    node->height=max(getHeight(node->left),getHeight(node->right))+1;
    int b=getBalance(node); //get the balance of the node
    
    //Right case
    if(b<-1){
        if(newNode->value >= node->right->value){
            rotateRR(node);
        } 
        else{
            rotateRL(node);
        }
    }
    if(b>1){
        if(newNode->value <= node->left->value){
            rotateLL(node);
        } 
        else{
            rotateLR(node);
        }
    }
}

//Get the balance of the node
int Tree::getBalance(Node *node){
    if(node==NULL){
        return 0;
    }
    return getHeight(node->left)-getHeight(node->right);
}

//Rotate for Left Left case
void Tree::rotateLL(Node *&z) {
    //Copy
    Node *y=z->left;
    Node *t3=y->right;
    
    //Perform rotation
    y->right=z;
    z->left=t3;
    
    //Renew the height
    z->height=max(getHeight(z->left),getHeight(z->right))+1;
    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    z=y;
}



//Rotate for Left Right case
void Tree::rotateLR(Node *&z) {
    //Change to LL case
    rotateRR(z->left);
    rotateLL(z);
}

//Rotate for Right Right case 
void Tree::rotateRR(Node *&z) {
    //Copy
    Node *y=z->right;
    Node *t2=y->left;
    
    //Perform rotation
    y->left=z;
    z->right=t2;
    
    //Renew the height
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

//Delete a tree
void Tree::dele(int n) {
    dele(root,n);
}

void Tree::dele(Node *&node,int n) {
    if(node==NULL) return;
    if(n<node->value) {
        //The node to be deleted on the left side
        dele(node->left,n);
    } 
    else if( n > node->value) {
        //The node to be deleted on the right side
        dele(node->right,n);
    } 
    else {
        //This is the node to be deleted
        //This node has one child or no child case
        if((node->left==NULL) || (node->right==NULL)){
            if((node->left==NULL) && (node->right==NULL)) {
                Node *temp=node;
                node=NULL;
                delete temp;
            } 
            else{
                //Assign the child to temp
                Node *temp= node->left ? node->left : node->right;
                Node *temp2=node;
                node=temp;
                delete temp2;
            }
        } 
        else{ //the node to be deleted has two children
            
            //Get the node contains max value from the left node
            Node *temp=node->left;
            if(temp!=NULL){
                while(temp->right!=NULL) {
                    temp=temp->right;
                }
            }
            node->value=temp->value;
            dele(node->left,node->value);
        }
        
        size--;     //Tree Node Size -1
    }
    if(node==NULL){
        return;
    }
    node->height=max(getHeight(node->left),getHeight(node->right))+1;
    int b=getBalance(node);     //Balance
    
    //Right case
    if(b<-1){
        
        if(getBalance(node->right)<=0){
            rotateRR(node);
        } 
        else{
            rotateRL(node);
        }
    }
    //left case
    if(b>1){
        if(getBalance(node->left)>=0){
            rotateLL(node);
        } 
        else{
            rotateLR(node);
        }
    }
}

void Tree::printNode(Node *node){
    cout<<node->value<<" ";
}

void Tree::preOrder(Node *node){
    if(node!=NULL) {
        printNode(node);
        preOrder(node->left);
        preOrder(node->right);
    }
} 

void Tree::inOrder(Node *node){
    if(node!=NULL){
        inOrder(node->left);
        printNode(node);
        inOrder(node->right);
    }
}

void Tree::postOrder(Node *node){
    if(node!=NULL){
        postOrder(node->left);
        postOrder(node->right);
        printNode(node);
    }
}

void Tree::prePnt(){
    cout<<"Pre-order:  ";
    preOrder(root);      //pre-order output
    cout<<endl;
}

void Tree::inPnt(){
    cout<<"In-order:   ";
    inOrder(root);       //in-order output
    cout<<endl;
}

void Tree::postPnt(){
    cout<<"Post-order: ";
    postOrder(root);    //post-order output
    cout<<endl;
}

int Tree::getHeight(Node* n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}

int Tree::max(int a, int b){
    return a>=b? a:b;
}