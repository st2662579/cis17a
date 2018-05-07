/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: DayOfYear Class
 * Created on May 6, 2018
 */

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

#include <string>
using namespace std;

class DayOfYear {
    private:
        int number;
        string month;
    public:
        DayOfYear(int num);
        void print();
};

#endif /* DAYOFYEAR_H */

