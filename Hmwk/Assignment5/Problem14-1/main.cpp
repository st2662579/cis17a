/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Numbers Class
 * Created on May 6, 2018
 */

#include <iostream>
#include "Numbers.h"

using namespace std;

int main(int argc, char** argv) {
    int input;
    cout << "Enter a number between 0 and 9999: ";
    cin >> input;
    Numbers newNum(input);
    newNum.print();
    return 0;
}

