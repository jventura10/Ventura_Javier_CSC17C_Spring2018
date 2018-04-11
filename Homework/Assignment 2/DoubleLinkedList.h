/*
 * File:   DoubleLinkedList.h
 * Author: Javier Ventura 
 * Purpose: 
 * Created on March 29, 2018, 12:06 PM
 */

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>
#include <iomanip>
#include "DoubleLink.h"

using namespace std;

template <class T>
class DoubleLL{
    private:
        DoubleLink<T> *front;
    public:
        DoubleLL();
        DoubleLL(const DoubleLL &orig);
        virtual ~DoubleLL();
        void fillLst(int);
        void prntLst(int);
        DoubleLink<T> *endLst(DoubleLink<T>*);
        void addEnd(T);
        void addBeg(T);
        void addBefore(int, T);
        void addAfter(int, T);
        void delEnd();
        void delBeg();
        void delBefore(int);
        void delAfter(int);
        T searchLL(int x);
};

template <class T>
DoubleLL<T>::DoubleLL(){
     front = new DoubleLink<T>;
}

template <class T>
DoubleLL<T>::DoubleLL(const DoubleLL& orig){
    DoubleLink<T> *origLnk = orig.front;
    front = new DoubleLink<T>;
    front->data = origLnk->data;
    front->head = NULL;
    front->tail = NULL;
    origLnk = origLnk->head;
    while(origLnk != NULL){
        this->addEnd(origLnk->data);
        origLnk = origLnk->head;
    }
}

template <class T>
DoubleLL<T>::~DoubleLL(){
    while(front != NULL){
        DoubleLink<T> *temp = front->head;
        delete front;
        front = temp;
    }
}

template <class T>
void DoubleLL<T>::fillLst(int n){
    DoubleLink<T> *lnk = front;
    lnk->data = n--;
    lnk->head = NULL;
    lnk->tail = NULL;
    do{
        DoubleLink<T> *temp=new DoubleLink<T>;//Create a new link
        temp->data=n--;     //Fill with data
        temp->head=NULL; //Point to no where
        temp->tail=lnk;
        lnk->head=temp;
        lnk = temp;
    }while(n>0);           //Repeat until filled
}

template <class T>
void DoubleLL<T>::prntLst(int perLine){
    int colCnt=0;                //Column counter
    DoubleLink<T> *next=front;            //Start at the front of the list
    cout<<endl;                  //Put the beginning on a new line
    
    do{
        cout<<setw(4)<<next->data<<" ";  //Print the link
        if(colCnt++%perLine==(perLine-1)){
            cout<<endl;
        }
        next=next->head;      //Go to the next link
    }while(next!=NULL);          //Stop when your at the end
    
    cout<<endl;
}

template <class T>
DoubleLink<T>* DoubleLL<T>::endLst(DoubleLink<T> *front){
    DoubleLink<T> *lnk=front,*end;//Start the link at the front to find the end
    do{
        end=lnk;         //Are we at the end yet?
        lnk=lnk->head;//Traverse to the next link
    }while(lnk!=NULL);   //Finally found the end when NULL
    
    return end;
}

template <class T>
void DoubleLL<T>::addEnd(T val){
    DoubleLink<T> *nx2last=endLst(front);//Find the last link in the list
    DoubleLink<T> *last=new DoubleLink<T>;        //Create a new last link
    last->data=val;             //Fill with the value desire
    last->head=NULL;         //Point the added link to no where
    last->tail=nx2last;
    nx2last->head=last;      //Put the last link on the end 
}

template <class T>
void DoubleLL<T>::addBeg(T val){
    DoubleLink<T> *temp = new DoubleLink<T>;
    temp->data = val;
    temp->head = front;
    front->tail = temp;
    front = temp;
}

template <class T>
void DoubleLL<T>::addBefore(int loc, T val){
    DoubleLink<T> *lnk = front;
    while(lnk->data!=loc){
        lnk = lnk->head;
    }
    
    DoubleLink<T> *temp = new DoubleLink<T>;
    temp->data = val;
    temp->head = lnk;
    temp->tail = lnk->tail;
    lnk->tail->head = temp;
    lnk->tail = temp;
}

template <class T>
void DoubleLL<T>::addAfter(int loc, T val){
    DoubleLink<T> *lnk = front;
    while(lnk->data!=loc){
        lnk = lnk->head;
    }
    
    DoubleLink<T> *temp = new DoubleLink<T>;
    temp->data = val;
    temp->head = lnk->head;
    temp->tail = lnk;
    lnk->head->tail = temp;
    lnk->head = temp;
}

template <class T>
void DoubleLL<T>::delEnd(){
    DoubleLink<T> *lnk = front;
    while(lnk->head!=NULL){
        lnk = lnk->head;
    }
    
    lnk->tail->head = NULL;
    delete lnk;
}

template <class T>
void DoubleLL<T>::delBeg(){
    DoubleLink<T> *lnk = front->head;
    lnk->tail = NULL;
    delete front;
    front = lnk;
    
}

template <class T>
void DoubleLL<T>::delBefore(int loc){
    DoubleLink<T> *lnk = front;
    while(lnk->head->data!=loc)
    {
        lnk = lnk->head;
    }
    lnk->tail->head = lnk->head;
    lnk->head->tail = lnk->tail;
    
    delete lnk;
}

template <class T>
void DoubleLL<T>::delAfter(int loc){
    DoubleLink<T> *lnk = front;
    while(lnk->data!=loc)
    {
        lnk = lnk->head;
    }
    lnk = lnk->head;
    
    lnk->tail->head = lnk->head;
    lnk->head->tail = lnk->tail;
    
    delete lnk;
}

template <class T>
T DoubleLL<T>::searchLL(int x){
    DoubleLink<T> *lnk = front;
    int j=0;
    bool found=false;
    
    for(int i = 0; i<12; i++){
        lnk=lnk->head;
        if(j==x){
            found=true;
            return x;
        }
        j++;
    }
    
    if(found==false){
        return 0;
    }
}


#endif /* DOUBLELINKEDLIST_H */

