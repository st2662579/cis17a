/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Deck structure
 * Created on April 22, 2018
 */

#ifndef DECK_H
#define DECK_H

#include <string>
#include "Card.h"
using namespace std;

struct Deck {
    int size = 52;
    Card* cards;
};

#endif /* DECK_H */

