/*
 * File:   player.h
 * Author: Javier Ventura 
 * Purpose: Player Class Implementation
 * Created on April 12, 2018, 7:20 PM
 */

//Libraries
#include <iostream>

//User Libraries
#include "player.h"

using namespace std;

Player::Player(){
    pot=2.0f;
    card1=rand()%52+1;
    
    while(card1==card2 || card1==card3 || card1==card4 || card1==card5){
        card1=rand()%52+1;
    }
    
    card2=rand()%52+1;
    
    while(card2==card3 || card2==card4 || card2==card5){
        card2=rand()%52+1;
    }
    
    card3=rand()%52+1;
    
    while(card3==card4 || card3==card5){
        card3=rand()%52+1;
    }
    
    card4=rand()%52+1;
    
    while(card4==card5){
        card4=rand()%52+1;
    }
    
    card5=rand()%52+1;
    
}

void Player::showCards(){
    cout<<endl;
    cout<<face(card1)<<suit(card1)<<" "<<face(card2)<<suit(card2)
        <<" "<<face(card3)<<suit(card3)<<" "<<face(card4)<<suit(card4)
        <<" "<<face(card5)<<suit(card5)<<endl;
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
            card1=rand()%52+1;

            while(card1==card2 || card1==card3 || card1==card4 || card1==card5){
                card1=rand()%52+1;
            }

        }
        else if(swap1==2){
            card2=rand()%52+1;

            while(card2==card1 || card2==card3 || card2==card4 || card2==card5){
                card1=rand()%52+1;
            }
        }
        else if(swap1==3){
            card3=rand()%52+1;

            while(card3==card1 || card3==card2 || card3==card4 || card3==card5){
                card3=rand()%52+1;
            }
        }
        else if(swap1==4){
            card4=rand()%52+1;

            while(card4==card1 || card4==card3 || card4==card2 || card2==card5){
                card1=rand()%52+1;
            }
        }
        else if(swap1==5){
            card5=rand()%52+1;

            while(card5==card1 || card5==card3 || card5==card2 || card5==card4){
                card5=rand()%52+1;
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
            card1=rand()%52+1;

            while(card1==card2 || card1==card3 || card1==card4 || card1==card5){
                card1=rand()%52+1;
            }
        }
        if(swap1==2 || swap2==2){
            card2=rand()%52+1;

            while(card2==card1 || card2==card3 || card2==card4 || card2==card5){
                card1=rand()%52+1;
            }
        }
        if(swap1==3 ||swap2==3){
            card3=rand()%52+1;

            while(card3==card1 || card3==card2 || card3==card4 || card3==card5){
                card3=rand()%52+1;
            }
        }
        if(swap1==4 || swap2==4){
            card4=rand()%52+1;

            while(card4==card1 || card4==card3 || card4==card2 || card2==card5){
                card1=rand()%52+1;
            }
        }
        if(swap1==5 || swap2==5){
            card5=rand()%52+1;

            while(card5==card1 || card5==card3 || card5==card2 || card5==card4){
                card5=rand()%52+1;
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
            card1=rand()%52+1;

            while(card1==card2 || card1==card3 || card1==card4 || card1==card5){
                card1=rand()%52+1;
            }
        }
        if(swap1==2 || swap2==2 || swap3==2){
            card2=rand()%52+1;

            while(card2==card1 || card2==card3 || card2==card4 || card2==card5){
                card1=rand()%52+1;
            }
        }
        if(swap1==3 ||swap2==3 || swap3==3){
            card3=rand()%52+1;

            while(card3==card1 || card3==card2 || card3==card4 || card3==card5){
                card3=rand()%52+1;
            }
        }
        if(swap1==4 || swap2==4 || swap3==4){
            card4=rand()%52+1;

            while(card4==card1 || card4==card3 || card4==card2 || card2==card5){
                card1=rand()%52+1;
            }
        }
        if(swap1==5 || swap2==5 || swap3==5){
            card5=rand()%52+1;

            while(card5==card1 || card5==card3 || card5==card2 || card5==card4){
                card5=rand()%52+1;
            }
        }
    }
}

void Player::rank(){
    int win=rand()%100+1;
                
    if(win>=0 && win<=40){
        cout<<endl;
        cout<<"You Won!"<<endl;
        pot=pot+(3*bet1)+(3*bet2);
    }
    else{
        cout<<endl;
        cout<<"You Lost!"<<endl;
        pot=(pot-bet1)-bet2;
    }
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

Player::~Player(){
    
}