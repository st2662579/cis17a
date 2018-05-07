/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Numbers Class
 * Created on May 6, 2018
 */

#include <iostream>
#include <string>
#include "Month.h"
using namespace std;

Month::Month(string mName, int nDays) {
    monthName = mName;
    numDays = nDays;
}

void Month::display() {
    cout << "The month is " << monthName << endl;
    cout << "The number of days in the month is " << numDays << endl;
}