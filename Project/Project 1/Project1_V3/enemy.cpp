/*
 * File:   enemy.h
 * Author: Javier Ventura 
 * Puprose: Enemy Class Implementation for Opponents
 * Created on April 18, 2018, 8:45 PM
 */

#include <iostream>

#include "enemy.h"

using namespace std;

Enemy::Enemy(){
    pts=0;
    
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
    
    //Build Deck 
    buildDeck();
}

void Enemy::buildDeck(){
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

void Enemy::setPts(){
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

int Enemy::getPts(){
    return pts;
}