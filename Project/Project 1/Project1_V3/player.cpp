/*
 * File:   player.h
 * Author: Javier Ventura 
 * Purpose: Player Class Implementation
 * Created on April 12, 2018, 7:20 PM
 */

//Libraries
#include <iostream>
#include <string>
#include <map>
#include <cstdlib>

//User Libraries
#include "player.h"

using namespace std;

Player::Player(){
    //Set Pot to Default 2.0 Bitcoin
    pot=2.0f;
    
    name="Username";
    
    //Fill Hand with 5 random keys to the deck integers from 1-52
    hand[0]=rand()%52+1;
    
    hand[1]=rand()%52+1;
    
    while(hand[1]==hand[0]){
        hand[1]=rand()%52+1;
    }
    
    hand[2]=rand()%52+1;
    
    while(hand[2]==hand[1] || hand[2]==hand[0]){
        hand[2]=rand()%52+1;
    }
    
    hand[3]=rand()%52+1;
    
    for(int i=0;i<3;i++){    
        if(hand[3]==hand[i]){
            hand[3]=rand()%52+1;
        }
    }
    
    hand[4]=rand()%52+1;
    for(int i=0;i<4;i++){
        if(hand[4]==hand[i]){
            hand[4]=rand()%52+1;
        }
    }
    
    buildDeck();
    
}

void Player::showCards(){
    cout<<endl;
    cout<<name<<"'s Cards: "<<endl;
    cout<<cards[hand[0]]<<" "<<cards[hand[1]]<<" "<<cards[hand[2]]<<" "<<cards[hand[3]]
        <<" "<<cards[hand[4]]<<endl;
}

char Player::face(char card){
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

void Player::buildDeck(){
    //Map to hold Deck of Cards
    
    //Spades
    cards[1]="AS";
    cards[2]="2S";
    cards[3]="3S";
    cards[4]="4S";
    cards[5]="5S";
    cards[6]="6S";
    cards[7]="7S";
    cards[8]="8S";
    cards[9]="9S";
    cards[10]="TS";
    cards[11]="JS";
    cards[12]="QS";
    cards[13]="KS";
    
    //Clubs
    cards[14]="AC";
    cards[15]="2C";
    cards[16]="3C";
    cards[17]="4C";
    cards[18]="5C";
    cards[19]="6C";
    cards[20]="7C";
    cards[21]="8C";
    cards[22]="9C";
    cards[23]="TC";
    cards[24]="JC";
    cards[25]="QC";
    cards[26]="KC";
    
    //Diamonds
    cards[27]="AD";
    cards[28]="2D";
    cards[29]="3D";
    cards[30]="4D";
    cards[31]="5D";
    cards[32]="6D";
    cards[33]="7D";
    cards[34]="8D";
    cards[35]="9D";
    cards[36]="TD";
    cards[37]="JD";
    cards[38]="QD";
    cards[39]="KD";
    
    //Hearts
    cards[40]="AH";
    cards[41]="2H";
    cards[42]="3H";
    cards[43]="4H";
    cards[44]="5H";
    cards[45]="6H";
    cards[46]="7H";
    cards[47]="8H";
    cards[48]="9H";
    cards[49]="TH";
    cards[50]="JH";
    cards[51]="QH";
    cards[52]="KH";
}

char Player::suit(char card){
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

void Player::setName(){
    cout<<endl;
    cout<<"Enter Username: ";
    cin>>name;
}

void Player::setbet1(){
    cout<<endl;
    cout<<"Fold (F), Match(M) 0.2 Bitcoin, Raise(R): ";
    cin>>opt;

    //Possible Outcomes from Folding,Matching, and Betting
    if(opt=='F'){
        cout<<endl;
        cout<<"Folded..."<<endl;
        cout<<endl;
        bet1=0.0f;
    }
    else if(opt=='M'){
        cout<<endl;
        cout<<"Matched 0.2 Bitcoin"<<endl;
        cout<<endl;
        bet1=0.2f;
    }
    else{
        cout<<endl;
        cout<<"Raise bet: ";
        cin>>bet1;

        while(bet1<=0.2){
            cout<<"Raise must be higher than 0.2 minimum: ";
            cin>>bet1;
        }
    }
}

float Player::getbet1(){
    return bet1;
}

void Player::setbet2(){
    cout<<endl;
    cout<<"Fold (F), Match(M) Last Bet, Raise(R): ";
    cin>>opt;

    //Possible Outcomes from Folding,Matching, and Betting
    if(opt=='F'){
        cout<<endl;
        cout<<"Folded..."<<endl;
        cout<<endl;
        bet2=0.0f;
    }
    else if(opt=='M'){
        cout<<endl;
        cout<<"Matched Last Bet"<<endl;
        bet2=bet1;
        cout<<endl;
    }
    else{
        cout<<endl;
        cout<<"Raise bet: ";
        cin>>bet2;

        while(bet2<=bet1){
            cout<<"Raise must be higher than last bet: ";
            cin>>bet2;
        }
        
    }
}

float Player::getbet2(){
    return bet2;
}

void Player::swap(){
    cout<<endl;
    cout<<"Enter the amount of cards you want to change(Up to 3):  ";
    cin>>nSwaps;

    while(nSwaps<0 || nSwaps>3){
        cout<<endl;
        cout<<"Only Allowed to Swap up to 3, Enter Again: ";
        cin>>nSwaps;
    }

    if(nSwaps==0){
        cout<<endl;
        cout<<"No Swaps!"<<endl;
    }
    else if(nSwaps==1){
        cout<<endl;
        cout<<"Enter what card do you want to Swap: ";
        cin>>swap1;

        while(swap1<1 || swap1>5){
            cout<<endl;
            cout<<"Must be card 1-5: ";
            cin>>swap1;
        }

        if(swap1==1){
            hand[0]=rand()%52+1;

            while(hand[0]==hand[1] || hand[0]==hand[2] || hand[0]==hand[3] || hand[0]==hand[4]){
                hand[0]=rand()%52+1;
            }

        }
        else if(swap1==2){
            hand[1]=rand()%52+1;

            while(hand[1]==hand[0] || hand[1]==hand[2] || hand[1]==hand[3] || hand[1]==hand[4]){
                hand[0]=rand()%52+1;
            }
        }
        else if(swap1==3){
            hand[2]=rand()%52+1;

            while(hand[2]==hand[0] || hand[2]==hand[1] || hand[2]==hand[3] || hand[2]==hand[4]){
                hand[2]=rand()%52+1;
            }
        }
        else if(swap1==4){
            hand[3]=rand()%52+1;

            while(hand[3]==hand[0] || hand[3]==hand[2] || hand[3]==hand[1] || hand[1]==hand[4]){
                hand[0]=rand()%52+1;
            }
        }
        else if(swap1==5){
            hand[4]=rand()%52+1;

            while(hand[4]==hand[0] || hand[4]==hand[2] || hand[4]==hand[1] || hand[4]==hand[3]){
                hand[4]=rand()%52+1;
            }
        }

    }
    else if(nSwaps==2){
        cout<<endl;
        cout<<"Enter what two cards do you want to Swap: ";
        cin>>swap1>>swap2;

        while(swap1<1 || swap1>5){
            cout<<endl;
            cout<<"Your first swap must be a card 1-5: ";
            cin>>swap1;
        }
        while(swap2<1 || swap2>5 || swap2==swap1){
            cout<<endl;
            cout<<"Your Second Swap must be a card 1-5: ";
            cin>>swap2;
        }

        if(swap1==1 || swap2==1){
            hand[0]=rand()%52+1;

            while(hand[0]==hand[1] || hand[0]==hand[2] || hand[0]==hand[3] || hand[0]==hand[4]){
                hand[0]=rand()%52+1;
            }
        }
        if(swap1==2 || swap2==2){
            hand[1]=rand()%52+1;

            while(hand[1]==hand[0] || hand[1]==hand[2] || hand[1]==hand[3] || hand[1]==hand[4]){
                hand[0]=rand()%52+1;
            }
        }
        if(swap1==3 ||swap2==3){
            hand[2]=rand()%52+1;

            while(hand[2]==hand[0] || hand[2]==hand[1] || hand[2]==hand[3] || hand[2]==hand[4]){
                hand[2]=rand()%52+1;
            }
        }
        if(swap1==4 || swap2==4){
            hand[3]=rand()%52+1;

            while(hand[3]==hand[0] || hand[3]==hand[2] || hand[3]==hand[1] || hand[1]==hand[4]){
                hand[0]=rand()%52+1;
            }
        }
        if(swap1==5 || swap2==5){
            hand[4]=rand()%52+1;

            while(hand[4]==hand[0] || hand[4]==hand[2] || hand[4]==hand[1] || hand[4]==hand[3]){
                hand[4]=rand()%52+1;
            }
        }
    }
    else if(nSwaps==3){
        cout<<endl;
        cout<<"Enter what two cards do you want to Swap: ";
        cin>>swap1>>swap2>>swap3;

        while(swap1<1 || swap1>5){
            cout<<endl;
            cout<<"Your first swap must be a card 1-5: ";
            cin>>swap1;
        }
        while(swap2<1 || swap2>5 || swap2==swap1){
            cout<<endl;
            cout<<"Your Second Swap must be a card 1-5 and Same Number Cannot be Swapped Twice: ";
            cin>>swap2;
        }
        while(swap3<1 || swap2>5 || swap3==swap1 || swap3==swap2){
            cout<<endl;
            cout<<"Your Third Swap must be a card 1-5 and Same Number Cannot be Swapped Twice: ";
            cin>>swap3;
        }

        if(swap1==1 || swap2==1 || swap3==1){
            hand[0]=rand()%52+1;

            while(hand[0]==hand[1] || hand[0]==hand[2] || hand[0]==hand[3] || hand[0]==hand[4]){
                hand[0]=rand()%52+1;
            }
        }
        if(swap1==2 || swap2==2 || swap3==2){
            hand[1]=rand()%52+1;

            while(hand[1]==hand[0] || hand[1]==hand[2] || hand[1]==hand[3] || hand[1]==hand[4]){
                hand[0]=rand()%52+1;
            }
        }
        if(swap1==3 ||swap2==3 || swap3==3){
            hand[2]=rand()%52+1;

            while(hand[2]==hand[0] || hand[2]==hand[1] || hand[2]==hand[3] || hand[2]==hand[4]){
                hand[2]=rand()%52+1;
            }
        }
        if(swap1==4 || swap2==4 || swap3==4){
            hand[3]=rand()%52+1;

            while(hand[3]==hand[0] || hand[3]==hand[2] || hand[3]==hand[1] || hand[1]==hand[4]){
                hand[0]=rand()%52+1;
            }
        }
        if(swap1==5 || swap2==5 || swap3==5){
            hand[4]=rand()%52+1;

            while(hand[4]==hand[0] || hand[4]==hand[2] || hand[4]==hand[1] || hand[4]==hand[3]){
                hand[4]=rand()%52+1;
            }
        }
    }
}

void Player::setPts(){
    //Give pts based on cards 
    int x1=hand[0]%13;
    int x2=hand[1]%13;
    int x3=hand[2]%13;
    int x4=hand[3]%13;
    int x5=hand[4]%13;
    
    //Pairs
    if(x1==x2){
        pts=pts+1;
    }
    if(x1==x3){
        pts=pts+1;
    }
    if(x1==x4){
        pts=pts+1;
    }
    if(x1==x5){
        pts=pts+1;
    }
    if(x2==x3){
        pts=pts+1;
    }
    if(x2==x4){
        pts=pts+1;
    }
    if(x2==x5){
        pts=pts+1;
    }
    if(x3==x4){
        pts=pts+1;
    }
    if(x3==x5){
        pts=pts+1;
    }
    if(x4==x5){
        pts=pts+1;
    }
    
}

int Player::getPts(){
    return pts;
}
void Player::addCoin(){
    //Declare Local Variables
    float temp;         //Temporary Variable to add to pot

    cout<<"Enter Bitcoin Amount to Add to your Total Pot: "<<endl;
    cin>>temp;

    while(temp<0.00000001){
        cout<<endl;
        cout<<"Not a valid Amount, Enter Again: ";
        cin>>temp;
    }

    pot=pot+temp;
}
void Player::win(){
    pot=pot+(2*bet1)+(2*bet2);
    cout<<endl;
    cout<<"Pot: "<<pot<<" Bitcoin";
}

void Player::lose(){
    cout<<endl;
    pot=pot-bet1-bet2;
    cout<<"Pot: "<<pot<<" Bitcoin";
}

Player::~Player(){
    
}