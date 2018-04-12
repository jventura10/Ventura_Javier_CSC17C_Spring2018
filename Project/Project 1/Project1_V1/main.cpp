/*
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: CSC 17C Project 1 
 * Created on April 11, 2018, 3:24 PM
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>

//User Libraries

using namespace std;

//Function Prototypes

int main(int argc, char** argv) {
    //Set Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int choice;
    bool quit=false;
    
    do{
        cout<<"Poker!"<<endl;
        cout<<"------"<<endl;
        cout<<"(1) Play Game"<<endl;
        cout<<"(2) Basic Rules"<<endl;
        cout<<"(3) Beginner's Guide"<<endl;
        cout<<"(4) Poker Hands Ranking"<<endl;
        cout<<"(5) Quit Game"<<endl;
        cout<<endl;
        cout<<"Enter Option: ";
        cin>>choice;
        
        while(choice<1 || choice>3){
            cout<<endl;
            cout<<"Enter Valid Option: ";
            cin>>choice;
        }
        
        switch(choice){
            case 1:{
                cout<<endl;
                
            }
            case 2:{
                cout<<endl;
                cout<<"Rules for Texas Hold'em Poker:"<<endl;
                cout<<"Each player will receive two cards (hole)"<<endl;
                cout<<"There will be 2 initial community cards"<<endl;
                cout<<"Player will be asked to raise,match, or fold"<<endl;
                cout<<"To raise you must enter more than current expected bet"<<endl;
                cout<<"Matching means entering with minimum amount for bet"<<endl;
                cout<<"Folding means you will not bet and not receive another card"<<endl;
                cout<<"After each opportunity to bet there will be another community card added"<<endl;
                cout<<"Final Round will be when there are five community cards"<<endl;
                cout<<"Betting is No-Limit Hold'em"<<endl;
                cout<<"Winner is based on Poker Hands (See Option 4)"<<endl;
                cout<<"***Complete Guide See option 3***"<<endl;
            }
            case 3:{
                cout<<endl;
                
            }
            case 4:{
                cout<<endl;
                cout<<"Poker Hands Ranking: "<<endl;
                cout<<"H-Hearts S-Spades C-Clubs D-Diamonds"<<endl;
                cout<<"Royal Flush: 10-H J-H Q-H K-H A-H"<<endl;
                cout<<"Straight Flush: 3-S 4-S 5-S 6-S 7-S"<<endl;
                cout<<"Four of a Kind: 10-S 10-C 10-D 10-H 5-D"<<endl;
                cout<<"Full House: J-H J-C 7-D 7-H 7-C"<<endl;
                cout<<"Flush: 2-H 6-H 9-H J-H K-H"<<endl;
                cout<<"Straight: 3-H 4-C 5-D 6-C 7-S"<<endl;
                cout<<"Three of a Kind: "<<endl;
                cout<<"Two Pairs: "<<endl;
                cout<<"A Pair: "<<endl;
                cout<<"No Pair/High Card: "<<endl;
                
            }
            case 5:{
                cout<<endl;
                cout<<"Quitting Game... :("<<endl;
                return 0;
            }
            default:{
                cout<<endl;
                cout<<"Enter Valid Option!"<<endl;
                cout<<endl;
            }
        }
        
    }while(quit==false);
    
    //Exit
    return 0;
}

