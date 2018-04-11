/*
 * File:   Link.h
 * Author: Javier Ventura 
 * Purpose: 
 * Created on March 29, 2018, 12:06 PM
 */

#ifndef LINK_H
#define LINK_H

template <class T>
class DoubleLink{
    public:
        T data;
        DoubleLink *head;
        DoubleLink *tail;
};


#endif /* LINK_H */

