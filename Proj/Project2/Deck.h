/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Deck class
 * Created on May 28, 2018
 */

#include "Card.h"
#include <string>
using namespace std;

#ifndef DECK_H
#define DECK_H

class Deck {
    public:
        static int numCards;
        int size;
        Card *cards;
        Deck(int);
        ~Deck();
        void deal(Deck&);
        void fill();
        void show();
        void shuffle();
        int bestSum();
        void showSum();
        void addCard(Deck&);
        int operator+(Deck&);
};

#endif /* DECK_H */

