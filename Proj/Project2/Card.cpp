/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Card class
 * Created on May 28, 2018
 */

#include <string>
#include <sstream>
#include "Card.h"
using namespace std;

string Card::getReadable() {
    ostringstream readable;
    // Output a card into a readable format for the player
    switch (type) {
        case 0: readable << value << " OF ";
            break;
        case 1: readable << "JACK OF ";
            break;
        case 2: readable << "QUEEN OF ";
            break;
        case 3: readable << "KING OF ";
            break;
        case 4: readable << "ACE OF ";
            break;
        default: 
            readable << "INVALID TYPE | ";
            break;
    }
    
    switch (suit) {
        case 1: readable << "HEARTS";
            break;
        case 2: readable << "CLUBS";
            break;
        case 3: readable << "SPADES";
            break;
        case 4: readable << "DIAMONDS";
            break;
        default: 
            readable << "INVALID SUIT";
            break;
    }
    
    readable << " (VALUE: ";
    
    if (value < 11) {
        readable << value;
    } else {
        readable << "1 / 11";
    }
    
    readable << ")";
    
    return readable.str();
}

int Card::operator +(Card &right) {
    return (value + right.value);
}

int Card::operator -(Card &right) {
    return (value - right.value);
}
