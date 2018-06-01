/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: SpecialCard class
 * Created on May 28, 2018
 */

#include "Card.h"
using namespace std;

#ifndef SPECIALCARD_H
#define SPECIALCARD_H

class SpecialCard : public Card {
    public:
        SpecialCard(int, int); // Suit, Type
        int getValue();
};

#endif /* SPECIALCARD_H */

