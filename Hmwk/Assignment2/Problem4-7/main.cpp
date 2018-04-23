/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Time Calculator
 * Created on March 14, 2018, 9:26 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main() {
    int seconds;
    int minutes;
    int hours;
    int days;
    
    cout << "Enter a number of seconds: ";
    cin >> seconds;
    
    minutes = (seconds / 60);
    hours = (minutes / 60);
    days = (hours / 24);
    
    if (days != 0) {
        cout << days << " day(s), ";
        seconds = (seconds - (days * 86400));
        minutes = (seconds / 60);
        hours = (minutes / 60);
    }
    if (hours != 0) {
        cout << hours << " hour(s), ";
        seconds = (seconds - (hours * 3600));
        minutes = (seconds / 60);
    }
    if (minutes != 0) {
        cout << minutes << " minute(s), " << (seconds % 60) << " second(s).";
    } else {
        cout << seconds << " second(s).";
    }

    return 0;
}