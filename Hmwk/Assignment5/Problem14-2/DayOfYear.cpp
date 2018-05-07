/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: DayOfYear Class
 * Created on May 6, 2018
 */

#include <iostream>
#include "DayOfYear.h"
using namespace std;

DayOfYear::DayOfYear(int num) {
    if (num > 0 && num <= 365) {
        number = num;
    } else {
        cout << "This number was not in the proper range.";
    }
}

void DayOfYear::print() {
    if (number <= 31) {
        month = "January";
    } else if (number <= 59) {
        month = "February";
        number = number - 31;
    } else if (number <= 90) {
        month = "March";
        number = number - 59;
    } else if (number <= 120) {
        month = "April";
        number = number - 90;
    } else if (number <= 151) {
        month = "May";
        number = number - 120;
    } else if (number <= 181) {
        month = "June";
        number = number - 151;
    } else if (number <= 212) {
        month = "July";
        number = number - 181;
    } else if (number <= 243) {
        month = "August";
        number = number - 212;
    } else if (number <= 273) {
        month = "September";
        number = number - 243;
    } else if (number <= 304) {
        month = "October";
        number = number - 273;
    } else if (number <= 334) {
        month = "November";
        number = number - 304;
    } else if (number <= 365) {
        month = "December";
        number = number - 334;
    }
    cout << month << " " << number;
}