/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Numbers Class
 * Created on May 6, 2018
 */

#ifndef NUMBERS_H
#define NUMBERS_H

#include <string>
using namespace std;

class Numbers {
    private:
        int number;
        string lsThn20[20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
        string mrThn20[8] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
        string hundred = "hundred";
        string thousand = "thousand";
    public:
        Numbers(int num);
        void print();
};

#endif /* NUMBERS_H */

