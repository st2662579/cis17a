/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: DayOfYear Class
 * Created on May 6, 2018
 */

#include <iostream>
#include "DayOfYear.h"

using namespace std;

int main(int argc, char** argv) {
    int input;
    cout << "Enter an integer from 1 to 365 that represents a day of the year: ";
    cin >> input;
    DayOfYear day(input);
    day.print();
    return 0;
}

