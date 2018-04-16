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

Player::~Player(){
    
}