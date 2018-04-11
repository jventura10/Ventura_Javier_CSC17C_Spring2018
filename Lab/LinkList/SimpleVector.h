/*
 * File:   SimpleVector.h
 * Author: Javier Ventura 
 * Purpose: Use LinkedList to replace dynamic vector 
 * Created on March 19, 2018, 4:19 PM
 */

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function

#include "LinkedList.h"

using namespace std;

template <class T>
class SimpleVector
{
private:
   LinkedList<T> *list;
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector() {list = NULL;};
   
   // Accessor to return the array size
   int size() const{ return this->list->cntLst(); }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
   
   // Add item to the end of the array
   void push_back(const T&);
   
   // Removes the item at the end of the array
   T &pop_off();
};

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError(){
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError(){
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub) {
    if (list == NULL){
        return NULL;
    }
    return list->getObj(sub);
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub) {
    if (list != NULL) {
        return list->getObj(sub);
    }
}

template <class T>
void SimpleVector<T>::push_back(const T &obj) {
    if (list == NULL) {
        list = new LinkedList<T>(obj);
    } 
    else{
        list->addLst(obj);
    }
}
   
template <class T>
T &SimpleVector<T>::pop_off() {
    if (list != NULL) {
        int c = list->cntLst() - 1;
        T &obj = list->getObj(c);
        list->del(obj);
        return obj;
    }
}

#endif /* SIMPLEVECTOR_H */

