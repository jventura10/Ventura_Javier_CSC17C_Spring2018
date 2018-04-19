/*
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: CSC 17C Project 1 Poker Game Version 3 is Starting to use Object 
 *          Concepts from STL 
 * Created on April 11, 2018, 3:24 PM
 */

//Libraries
#include <cstdlib>      //C Standard Library
#include <iostream>     //Input & Output Library
#include <ctime>        //C Time Library
#include <map>
#include <set>
#include <fstream>      //File Stream Library 
#include <string>

//User Libraries
#include "enemy.h"
#include "player.h"       //String Library

using namespace std;

int main(int argc, char** argv) {
    //Set Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int choice;         //Choice from the Menu 
    bool quit=false;    //Boolean to keep Menu Running
    int import;         //Import Option to Read in General Poker Rules
    char opt;           //Option to Fold,Match, or Raise
    Player user;        //User Object for PLayer
    Enemy opp1;         //Opponent 1 in the table
    Enemy opp2;         //Opponent 2 in the table
    
    do{
        cout<<"5 Card Draw Poker!"<<endl;
        cout<<"------------------"<<endl;
        cout<<"(1) Play Game"<<endl;
        cout<<"(2) Basic Rules"<<endl;
        cout<<"(3) Beginner's Guide To Poker"<<endl;
        cout<<"(4) Poker Hands Ranking"<<endl;
        cout<<"(5) Add Bitcoin to your Betting Pot"<<endl;
        cout<<"(6) Change Username"<<endl;
        cout<<"(7) Quit Game"<<endl;
        
        cout<<endl;
        cout<<"Enter Option: ";
        cin>>choice;
        
        while(choice<1 || choice>7){
            cout<<endl;
            cout<<"Enter Valid Option: ";
            cin>>choice;
        }
        
        switch(choice){
            case 1:{
                cout<<endl;
                
                user.showCards();
                user.setbet1();
                
                if(user.getbet1()<=0){
                    break;
                }
                
                user.swap();
                
                user.showCards();
                user.setbet2();
                
                if(user.getbet2()<=0){
                    break;
                }
                
                user.setPts();
                opp1.setPts();
                opp2.setPts();
                
                if(user.getPts()>opp1.getPts() && user.getPts()>opp2.getPts()){
                    cout<<endl;
                    cout<<"You Won!"<<endl;
                    user.win();
                    cout<<endl;
                }
                else{
                    cout<<endl;
                    cout<<"You Lost!"<<endl;
                    user.lose();
                    cout<<endl;
                }
                
                cout<<endl;
                break;
            }
            case 2:{
                cout<<endl;
                cout<<"Rules of the Game (5 Card Draw Poker):"<<endl;
                cout<<"Each player will receive 5 (hole) cards"<<endl;
                cout << "T =Ten Q=Queen J=Jack K=King A=Ace S=Spades C=Clubs D=Diamonds H=Hearts";
                cout<<"Each player may fold, raise the bet or match the bet"<<endl;
                cout<<"Each player may ask for up to three changes in cards"<<endl;
                cout<<"Another betting round will occur"<<endl;
                cout<<"There is no limit to betting, as long as you have the bet in your pot"<<endl;
                cout<<"New Players are given 2 Bitcoin to start off"<<endl;
                cout<<"Winner is based on Poker Hands (See Option 4)"<<endl;
                cout<<"***Complete Poker Guide See option 3***"<<endl;
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
                
                user.addCoin();
                
                cout<<endl;
                break;
            }
            case 6:{
                user.setName();
            }
            case 7:{
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
