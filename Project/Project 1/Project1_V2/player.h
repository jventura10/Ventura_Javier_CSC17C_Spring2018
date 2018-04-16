/*
 * File:   player.h
 * Author: Javier Ventura 
 * Purpose: Player Class Specification
 * Created on April 12, 2018, 7:20 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player{
    private:
        float pot;     //Betting Pot for Game
        float bet1;
        float bet2;
        char card1;
        char card2;
        char card3;
        char card4;
        char card5;
        int swap1;
        int swap2;
        int swap3;
        int nSwaps;
        char opt;
    public:
        Player();
        ~Player();
        void setName();
        void showCards();
        char suit(char);        //Gives a Suit to the card 
        char face(char);        //Gives a Face to the card 
        void bet();
};

#endif /* PLAYER_H */

