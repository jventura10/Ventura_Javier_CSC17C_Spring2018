/* 
 * File:   main.cpp
 * Author: Javier Ventura
 * Purpose: Compare Permutation and Combination
 * Created on March 28, 2018, 2:37 PM
 */

//Libraries
#include <iostream> //Input Output Library
#include <math.h>   //Use for Exponent

using namespace std;

int factorial(int);     //Calculates factorial for a number
void loop();

int main(int argc, char** argv) {
    //Call Function that loops through N's and M's
    loop();
    
    return 0;
}

int factorial(int n){
    int f=1;
    for(int i = 1; i <=n; i++){
        f *= i;
    }
    
    return f;
}

void loop(){
    //Declare Variables
    int n=2;
    int m=1;
    
    for(int j=1;j<n;j++){
        for(int i=0;i<n;i++){
            int permR=pow(n,m);                 //Permutation Equation With Repetition Allowed
            int permNR=(factorial(n))/(factorial(n-m));           //Permutation Equation With No Repetition
            int combR=(factorial(n+m-1))/(factorial(n)*factorial(m-1))  ;   //Combination Equation With Repetition Allowed
            int combNR=(factorial(n))/(factorial(n-m)*factorial(m));         //Combination Equation With No Repetition
            
            cout<<"Using N= "<<n<<" M= "<<m<<":"<<endl;
            cout<<"Permutation Ordered Combination (Repetition Allowed): "<<permR<<endl;
            cout<<"Permutation Ordered Combination (No Repetition): "<<permNR<<endl;
            cout<<"Combination (Repetition Allowed): "<<combR<<endl;
            cout<<"Combination (No Repetition Allowed: "<<combNR<<endl;
            cout<<endl;
            m++;
        }
        m=1;
        if(n<5){
            n++;
        }
    }
    
}