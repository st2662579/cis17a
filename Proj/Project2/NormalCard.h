/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: NormalCard class
 * Created on May 28, 2018
 */

/* 
 * File:   NormalCard.h
 * Author: Seth
 *
 * Created on May 31, 2018, 7:44 PM
 */

#ifndef NORMALCARD_H
#define NORMALCARD_H

#include "Card.h"

class NormalCard : public Card {
    public:
        NormalCard(int, int); // Suit, Value
};

#endif /* NORMALCARD_H */

