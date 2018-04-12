/*
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: CSC 17C Project 1 Poker Game Version 1 is Procedural Programming Style
 *          to get the game running
 * Created on April 11, 2018, 3:24 PM
 */

//Libraries
#include <cstdlib>      //C Standard Library
#include <iostream>     //Input & Output Library
#include <ctime>        //C Time Library
#include <fstream>      //File Stream Library 
#include <string>       //String Library

//User Libraries

using namespace std;

//Function Prototypes
char suit(char);        //Gives a Suit to the card 
char face(char);        //Gives a Face to the card 

int main(int argc, char** argv) {
    //Set Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int choice;         //Choice from the Menu 
    bool quit=false;    //Boolean to keep Menu Running
    int import;         //Import Option to Read in General Poker Rules
    float pot=1.0f;     //Total Betting Pot in Bitcoin
    float bet=0.0f;     //Bet for a round, subtracted or added back to pot
    char opt;           //Option to Fold,Match, or Raise
    
    do{
        cout<<"5 Card Draw Poker!"<<endl;
        cout<<"------------------"<<endl;
        cout<<"(1) Play Game"<<endl;
        cout<<"(2) Basic Rules"<<endl;
        cout<<"(3) Beginner's Guide To Poker"<<endl;
        cout<<"(4) Poker Hands Ranking"<<endl;
        cout<<"(5) Add Bitcoin to you Betting Pot"<<endl;
        cout<<"(6) Quit Game"<<endl;
        cout<<endl;
        cout<<"Enter Option: ";
        cin>>choice;
        
        while(choice<1 || choice>6){
            cout<<endl;
            cout<<"Enter Valid Option: ";
            cin>>choice;
        }
        
        switch(choice){
            case 1:{
                cout<<endl;
                //Declare Local Variables 
                char card1=rand()%52+1;
                char card2=rand()%52+1;
                char card3=rand()%52+1;
                char card4=rand()%52+1;
                char card5=rand()%52+1;
                int swap1,swap2,swap3;
                
                while(card1==card2 || card1==card3 || card1==card4 || card1==card5){
                    card1=rand()%52+1;
                }
                while(card2==card3 || card2==card4 || card2==card5){
                    card2=rand()%52+1;
                }
                while(card3==card4 || card3==card5){
                    card3=rand()%52+1;
                }
                while(card4==card5){
                    card4=rand()%52+1;
                }
                
                cout<<face(card1)<<suit(card1)<<" "<<face(card2)<<suit(card2)
                    <<" "<<face(card3)<<suit(card3)<<" "<<face(card4)<<suit(card4)
                    <<" "<<face(card5)<<suit(card5)<<endl;
                
                cout<<endl;
                cout<<"Fold (F), Match(M) 0.5 Bitcoin, Raise(R): ";
                cin>>opt;
                
                //Possible Outcomes from Folding,Matching, and Betting
                if(opt=='F'){
                    cout<<endl;
                    cout<<"Folded..."<<endl;
                    break;
                }
                else if(opt=='M'){
                    cout<<endl;
                    cout<<"Matched 0.5 Bitcoin"<<endl;
                    bet=0.5f;
                }
                else{
                    cout<<endl;
                    cout<<"Raise bet: ";
                    cin>>bet;
                    
                    while(bet<=0.5){
                        cout<<"Raise must be higher than 0.5 minimum: ";
                        cin>>bet;
                    }
                }
                
                
                               
                cout<<endl;
                break;
            }
            case 2:{
                cout<<endl;
                cout<<"Rules of the Game (5 Card Draw Poker):"<<endl;
                cout<<"Each player will receive 5 (hole) cards"<<endl;
                cout<<"Each player may fold, raise the bet or match the bet"<<endl;
                cout<<"Each player may ask for up to three changes in cards"<<endl;
                cout<<"Another betting round will occur"<<endl;
                cout<<"There is no limit to betting, as long as you have the bet in your pot"<<endl;
                cout<<"New Players are given 1 Bitcoin to start off"<<endl;
                cout<<"Winner is based on Poker Hands (See Option 4)"<<endl;
                cout<<"***Complete Guide See option 3***"<<endl;
                cout<<endl;
                break;
            }
            case 3:{
                cout<<endl;
                cout<<"Beginner's Guide to Poker: "<<endl;
                cout<<"--References--"<<endl;
                cout<<"https://www.bicyclecards.com/how-to-play/basics-of-poker/"<<endl;
                cout<<"https://www.pokerlistings.com/poker-rules-5-card-draw0"<<endl;
                cout<<endl;
                cout<<"Enter 1 to import general rules or 2 to return to Menu: ";
                cin>>import;
                
                
                if(import==1){
                    cout<<endl;
                    ifstream file("guide.txt");
                    string line;
                    
                    while(getline(file,line)){
                        cout<<line<<endl;
                    }
                    
                    file.close();
                }
                else{
                    cout<<endl;
                    break;
                }
                
                cout<<endl;
                break;
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
                cout<<"1 Pair: "<<endl;
                cout<<"No Pair/High Card: "<<endl;
                cout<<endl;
                break;
            }
            case 5:{
                cout<<endl;
                //Declare Local Variables
                float temp;         //Temporary Variable to add to pot
                
                cout<<"Enter Bitcoin Amount to your Total Pot: "<<endl;
                cin>>temp;
                
                while(temp<0.00000001){
                    cout<<endl;
                    cout<<"Not a valid Amount, Enter Again: ";
                    cin>>temp;
                }
                
                pot=pot+temp;
                cout<<endl;
                break;
            }
            case 6:{
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

//******************************************************************************
//** Face Function gives Face to card passes in                               **
//******************************************************************************
char face(char card){
    switch(card%13){
        case 1:{
            return 'A';
        }
        case 2:{
            return '2';
        }
        case 3:{
            return '3';
        }
        case 4:{
            return '4';
        }
        case 5:{
            return '5';
        }
        case 6:{
            return '6';
        }
        case 7:{
            return '7';
        }
        case 8:{
            return '8';
        }
        case 9:{
            return '9';
        }
        case 10:{
            return 'T';
        }
        case 11:{
            return 'J';
        }
        case 12:{
            return 'Q';
        }
        default:{
            return 'K';
        }
    }
}

//******************************************************************************
//** Suit Function gives a Suit a card passed in                              **
//******************************************************************************
char suit(char card){
    if(card<=13){
        return 'S';
    }
    else if(card<=26){
        return 'C';
    }
    else if(card<=39){
        return 'H';
    }
    else{
        return 'D';
    }
    
}