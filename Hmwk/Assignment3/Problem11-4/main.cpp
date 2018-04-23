/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Weather Statistics
 * Created on March 26, 2018, 10:05 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "Structures.h"

int main() {

    MonthWeather a[12];
    int i = 0;
    for (i = 0; i < 12; i++) {
        cout << "Enter month " << (i + 1) << " details" << endl;
        cout << "Enter month " << (i + 1) << " total rainfall" << endl;
        cin >> a[i].totalRainfall;
        cout << "Enter month " << (i + 1) << " high temperature" << endl;
        cin >> a[i].highTemperature;

        cout << "Enter month " << (i + 1) << " low temperature" << endl;
        cin >> a[i].lowTemperature;
        cout << "Enter month " << (i + 1) << " month average temperature" << endl;
        cin >> a[i].averageTemperature;
    }
    int highTemperature = a[0].highTemperature;
    int lowTemperature = a[0].lowTemperature;
    int total = 0;
    float average = 0;
    for (i = 0; i < 12; i++) {
        if (a[i].highTemperature > highTemperature)
            highTemperature = a[i].highTemperature;
        if (a[i].lowTemperature < lowTemperature)
            lowTemperature = a[i].lowTemperature;
        total += a[i].totalRainfall;
    }

    average = total / 12;

    cout << "Total rainfall is " << total << endl;
    cout << "Average rainfall is " << average << endl;
    cout << "Highest temperature is " << highTemperature << endl;
    cout << "Lowest temperature is " << lowTemperature << endl;
    return 0;
}