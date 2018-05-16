/* 
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: Hashing Investigations with General Hash Functions
 * Created on May 15, 2018, 10:06 AM
 */

/*
 **************************************************************************
 *                                                                        *
 *           General Purpose Hash Function Algorithms Test                *
 *                                                                        *
 * Author: Arash Partow - 2002                                            *
 * URL: http://www.partow.net                                             *
 * URL: http://www.partow.net/programming/hashfunctions/index.html        *
 *                                                                        *
 * Copyright notice:                                                      *
 * Free use of the General Purpose Hash Function Algorithms Library is    *
 * permitted under the guidelines and in accordance with the most current *
 * version of the Common Public License.                                  *
 * http://www.opensource.org/licenses/cpl1.0.php                          *
 *                                                                        *
 **************************************************************************
*/

//Libraries 

#include <cstdlib>
#include <math.h>
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

//User Libraries
#include "GeneralHashFunctions.h"

using namespace std;

static const char randstring[] =            //List of all the characters
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

int size =sizeof(randstring)-1;             //Size of string

char GetChar(){                             // Get random character
    return randstring[rand() % size];
}

string hashrand(int a,int N);               // Function for the random string

int main(int argc, char** argv) {
      
    srand(static_cast<unsigned int>(time(0)));  // Set up random 

    int Count[11]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //Counters
    int N;                                          //Power of N
    int max[11]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // Max tracker
    
    for(int x=10;x<=25;x++){                        //Loop to increase N power 2^x
        cout<<"2^N N="<<x<<endl;
        N=pow(2,x);
        int *Pointer= new int[N];    
        

        for(int i=0;i<N;i++){                       //Loop to make N random Numbers
            
            Pointer[i]=rand()%N+1;                  //Store in pointer
            string a = hashrand(Pointer[i],N);      //Get the random string
            
            
            
            int b =    RSHash(a)/100000;            //Use hashes from file            
            int c =    JSHash(a)/10000;            
            int d =    PJWHash(a)/10000;
            int e =    ELFHash(a)/10000;
            int f =    BKDRHash(a)/10000;
            int g =    SDBMHash(a)/10000;
            int h =    DJBHash(a)/10000;
            int z =    DEKHash(a)/10000;
            int j =    FNVHash(a)/10000;
            int k =    BPHash(a)/10000;
            int l =    APHash(a)/10000;
               
            if(b==Pointer[i]){                      //check for collisions
                Count[0]=Count[0]+1;
                cout<<"Collision For RSHash"<<endl;
            }
                        
            if(c==Pointer[i]){
                Count[1]=Count[1]+1;
                cout<<"Collision For JSHash"<<endl;
            }
                        
            if(d==Pointer[i]){
                Count[2]=Count[2]+1;
                cout<<"Collision For PJWHash"<<endl;
            }
                        
            if(e==Pointer[i]){
                Count[3]=Count[3]+1;
                cout<<"Collision For ELFHash"<<endl;
            }
                       
            if(f==Pointer[i]){
                Count[4]=Count[4]+1;
                cout<<"Collision For BKDRHash"<<endl;
            }
            
            if(g==Pointer[i]){
                Count[5]=Count[5]+1;
                cout<<"Collision For SDBMHash"<<endl;
            }   
            if(h==Pointer[i]){
                Count[6]=Count[6]+1;
                cout<<"Collision For DJBHash"<<endl;
            }
            if(z==Pointer[i]){
                Count[7]=Count[7]+1;
                cout<<"Collision For DEKHash"<<endl;
            }
            if(j==Pointer[i]){
                Count[8]=Count[8]+1;
                cout<<"Collision For FNVHash"<<endl;
            }   
            if(k==Pointer[i]){
                Count[9]=Count[9]+1;
                cout<<"Collision For BPHash"<<endl;
            }
            if(l==Pointer[i]){
                Count[10]=Count[10]+1;
                cout<<"Collision For APHash"<<endl;
            }
        }
        
        
        for(int i=0;i<11;i++){
            if(Count[i]>max[i]){
                
                
                max[i]=Count[i];
            }
        }
     
        
        delete []Pointer;
        Pointer=NULL;
    }
    
    cout<<"Max Collision to happen at given N is "<<endl;
    
    cout<<"Max Collision For RSHash   "<<max[0]<<endl;

    cout<<"Max Collision For JSHash   "<<max[1]<<endl;

    cout<<"Max Collision For PJWHash  "<<max[2]<<endl;

    cout<<"Max Collision For ELFHash  "<<max[3]<<endl;

    cout<<"Max Collision For BKDRHash  "<<max[4]<<endl;

    cout<<"Max Collision For SDBMHash  "<<max[5]<<endl;

    cout<<"Max Collision For DJBHash  "<<max[6]<<endl;

    cout<<"Max Collision For DEKHash  "<<max[7]<<endl;

    cout<<"Max Collision For FNVHash  "<<max[8]<<endl;

    cout<<"Max Collision For BPHash  "<<max[9]<<endl;

    cout<<"Max Collision For APHash  "<<max[10]<<endl;
   
    
    
    return 0;
}

//13mil 13 collision mac][x]

string hashrand(int a,int N) {   //Get a random string with 5 char
    string key;
    
    for(int i=0; i<5;i++){
        key+= GetChar();
    }
    
    return key;
}

