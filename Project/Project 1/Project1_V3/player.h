/*
 * File:   player.h
 * Author: Javier Ventura 
 * Purpose: Player Class Specification
 * Created on April 12, 2018, 7:20 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <map>
#include <iostream>

using namespace std;

class Player{
    private:
        map<int,string> cards;
        float pot;     //Betting Pot for Game
        float bet1;
        float bet2;
        int hand[5];
        int swap1;
        int swap2;
        int swap3;
        int nSwaps;
        char opt;
        string name;
        int pts;
        struct Wins{
            bool win;
            Wins *linkWins;
        };
    public:
        Player();
        ~Player();
        void setName();
        void showCards();       //Outputs Hand
        char suit(char);        //Gives a Suit to the card 
        char face(char);        //Gives a Face to the card 
        void buildDeck();
        void setbet1();
        float getbet1();
        void setbet2();
        float getbet2();
        void swap();
        void setPts();
        int getPts();
        void win();
        void lose();
        void addCoin();
};

#endif /* PLAYER_H */

