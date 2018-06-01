/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: NormalCard class
 * Created on May 28, 2018
 */

#include <string>
#include <sstream>
#include "NormalCard.h"
using namespace std;

NormalCard::NormalCard(int setSuit, int setVal) {
    type = 0;
    suit = setSuit;
    value = setVal;
}