/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Card class
 * Created on May 28, 2018
 */

#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card {
    protected:
        int suit; // 1 = Hearts, 2 = Clubs, 3 = Spades, 4 = Diamonds
        int value;
        int type; // 0 = Normal, 1 = Jack, 2 = Queen, 3 = King, 4 = Ace
    public:
        string getReadable();
        virtual int getValue() { return value; };
        int getType() { return type; };
        int operator+(Card&);
        int operator- (Card&);
};

#endif /* CARD_H */

