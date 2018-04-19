/*
 * File:   enemy.h
 * Author: Javier Ventura 
 * Puprose: Enemy Class Specification for Opponents
 * Created on April 18, 2018, 8:45 PM
 */

#ifndef ENEMY_H
#define ENEMY_H

#include <map>
#include <string>

using namespace std;

class Enemy{
    private:
        map<int,string> cards;
        int hand[5];
        int pts;
    public:
        Enemy();
        void buildDeck();
        void setPts();
        int getPts();
};


#endif /* ENEMY_H */