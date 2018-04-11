/*
 * File:   LinkedList.h
 * Author: Javier Ventura 
 * Purpose: Linked List Class that is replacing Dynamic Vector
 * Created on March 19, 2018, 4:20 PM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<class T>
class LinkedList{
    private:
        struct Link{
            T data;         
            Link *linkPtr;  
        };
        Link *front,*next,*temp,*end,*found;    //Permanent and Temp pointers
        void endLst();                                  //Find the end of the list
        void *fndLst(const T&);                     //Determine address of link that contains the data
        void *fndBef(const T &);
    public:
        LinkedList(const T&);
        ~LinkedList();
        void prntLst();                        //Print each data element in the list
        void  addLst(const T&);          //Add data at the end of the list
        void  del(const T&);                 // Delete the item from the list
        int  findLst(const T&);             //Determine what link contains the data
        int   cntLst();                         //How many elements are in the list
        T&    getObj(int);                  //Return the object
};

#endif	/* LINKEDLIST_H */

//Function Create a linked list and fill with data
//Input  -> n      The number of elements in the list to create
//Output -> front  The address to the front of the allocated list.
template<class T>
LinkedList<T>::LinkedList(const T &data){
    //Think of this part as the constructor
    front=new Link;      //Allocate a link at the front of the list
    front->data=data;    //Initialize with data
    front->linkPtr=NULL; //At the moment not pointing it to anything
}

//Function Print the entire contents of the linked list
//Input -> front  The address to the front of the allocated list.
//Output-> Display the entire linked list.
template<class T>
void LinkedList<T>::prntLst(){
    next=front;           //Create a pointer to the list
    cout<<endl<<"The Beginning of the List"<<endl;
    do{
        cout<<next->data<<endl; //Print the contents of the link
        next=next->linkPtr;     //Go to the next link in the list
    }while(next!=NULL);         //Loop until reaching the end
    cout<<"The End of the List"<<endl<<endl;
}

//Function Deallocate the entire list from the front to the end.
//Input -> front  The address to the front of the allocated list.
//Output-> Deallocate and return a NULL for the linked list pointer.
template<class T>
LinkedList<T>::~LinkedList(){
    do{
       temp=front->linkPtr;   //Point to the next link in the list
       delete front;          //Delete the front of the list
       front=temp;            //Swap the front
    }while(front!=NULL);
}

//Function Find the address of the last link in the list
//Input -> front  The address to the front of the allocated list.
//Output-> The address of the last link in the list
template<class T>
void LinkedList<T>::endLst(){
    temp=front; //Declare pointers used to step through the list
    do{
        end=temp;          //Point to the current link with a swap
        temp=temp->linkPtr; //Point to the next link
    }while(temp!=NULL);     //Your done when you hit the end
}

//Function Add a link and data to the end of the list
//Input -> front  The address to the front of the allocated list.
//         data   Data to embed at the last link in the list
template<class T>
void LinkedList<T>::addLst(const T &data){
    endLst();  //Find the last link
    Link *add=new Link;        //Create the new link
    add->data=data;            //Add the data
    add->linkPtr=NULL;         //Set the pointer to NULL
    end->linkPtr=add;         //Point to the new end of the list
}

//Function Find the number of the link that matches the data
//Input -> front  The address to the front of the allocated list.
//Output-> The Link<Object> number from the front where the data is found
template<class T>
int LinkedList<T>::findLst(const T &value){
    int n=0;                //Initialize the counter
    temp=front;             //Prepare to traverse the Link<Object>ed list
    do{
        n++;                //Increment the counter
        if(temp->data==value)return n;//Return where the data is found
        temp=temp->linkPtr; //Move to the next link
    }while(temp!=NULL);     //End when reaching the end of the linked list
    return 0;               //Not found then return a 0;
}

//Function Find the address of the link that matches the data
//Input -> front  The address to the front of the allocated list.
//Output-> The Link<Object> address from the front where the data is found
template<class T>
void *LinkedList<T>::fndLst(const T &value){
    found=front;       //Set the cursor to move through the list
    do{
        if(found->data==value)return found;  //Address of data match
        found=found->linkPtr;                //Next link in the list
    }while(found!=NULL);                    //End of the list
    
    found=NULL;                           //Not found
}

//Function Find the number of links in the list
//Input -> front  The address to the front of the allocated list.
//Output-> The number of links in the list
template<class T>
int LinkedList<T>::cntLst(){
    int n=0;            //Initialize the counter
    temp=front;   //Set the cursor to the front
    do{
        n++;            //Increment the counter
        temp=temp->linkPtr;//Move to the next link
    }while(temp!=NULL); //Loop until the end is reached
    return n;           //Return the counter value
}

//Function Find the number of links in the list
//Input -> front  The address to the front of the allocated list.
//Output-> The number of links in the list
template<class T>
T &LinkedList<T>::getObj(int indx){
    int n=0;                      //Initialize the counter
    temp=front;                   //Set the cursor to the front
    do{
        if(n==indx)return temp->data;
        n++;                      //Increment the counter
        temp=temp->linkPtr;       //Move to the next link
    }while(temp!=NULL);           //Loop until the end is reached
    return front->data;           //Return the counter value
}



template<class T>
void *LinkedList<T>::fndBef(const T &val){
    Link* next = front; //Set the cursor to move through the list
    Link* last = NULL;  //Link before next
    do{
        if(next->data==val) return last;
        last = next;
        next = next->linkPtr;   //Next link in the list
    }while(next != NULL);       //End of the list
    
    return NULL;
}



// Delete Last one in the list
template<class T>
void LinkedList<T>::del(const T &val){
    Link *bef = (Link *)fndBef(val);    // Link before val
    Link *aft = bef->linkPtr->linkPtr;  // Link after val
    
    bef->linkPtr = aft; // patch bef and aft together
}

