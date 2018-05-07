/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Numbers Class
 * Created on May 6, 2018
 */

#include <string>
using namespace std;

#ifndef MONTH_H
#define MONTH_H

class Month {
    private:
        string monthName;
        int numDays;
    public:
        Month();
        Month(string mName, int nDays);
        void display();
};

#endif /* MONTH_H */

