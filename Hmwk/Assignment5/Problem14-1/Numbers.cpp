/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Numbers Class
 * Created on May 6, 2018
 */

#include <iostream>
#include "Numbers.h"
using namespace std;

Numbers::Numbers(int num) {
    if (num >= 0 && num <= 9999) {
        number = num;
    } else {
        cout << "This number was not in the proper range.";
    }
}

void Numbers::print() {
    if (number < 20) {
        cout << lsThn20[number];
    } else if (number >= 20 && number < 100) {
        int frstDgt = (number / 10);
        int scndDgt = (number % 10);
        if (scndDgt != 0) {
            cout << mrThn20[frstDgt - 2] << "-" << lsThn20[scndDgt];
        } else {
            cout << mrThn20[frstDgt - 2];
        }
    } else if (number >= 100 && number < 1000) {
        int frstDgt = (number / 100);
        int lstDgts = (number % 100);
        int scndDgt = (lstDgts / 10);
        int thrdDgt = (lstDgts % 10);
        cout << lsThn20[frstDgt] << " hundred ";
        if (scndDgt > 0 && lstDgts < 20) {
            cout << lsThn20[lstDgts];
        } else if (lstDgts > 20) {
            if (thrdDgt > 0) {
                cout << mrThn20[scndDgt - 2] << "-" << lsThn20[thrdDgt];
            } else {
                cout << mrThn20[scndDgt - 2];
            }
        } else if (scndDgt == 0 && thrdDgt > 0) {
            cout << lsThn20[thrdDgt];
        } else if (lstDgts == 0) {
            cout << endl;
        }
    } else if (number > 1000 && number < 10000) {
        int frstDgt = (number / 1000);
        int last3 = (number % 1000);
        int scndDgt = (last3 / 100);
        int last2 = (last3 % 100);
        int thrdDgt = (last2 / 10);
        int frthDgt = (last2 % 10);
        cout << lsThn20[frstDgt] << " thousand ";
        if (scndDgt > 0) {
            cout << lsThn20[scndDgt] << " hundred ";
        }
        if (last2 < 20) {
            cout << lsThn20[last2];
        } else {
            cout << mrThn20[thrdDgt - 2];
            if (frthDgt > 0) {
                cout << " " << lsThn20[frthDgt];
            }
        }
    }
}