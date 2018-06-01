/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: SpecialCard class
 * Created on May 28, 2018
 */

#include <string>
#include <sstream>
#include "SpecialCard.h"
using namespace std;

SpecialCard::SpecialCard(int setSuit, int setType) {
    type = setType;
    suit = setSuit;
    if (setType == 4) {
        value = 11;
    } else {
        value = 10;
    }
}

int SpecialCard::getValue() {
    if (type == 4) {
        value == 11;
    } else {
        value = 10;
    }
}