/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Car Instrument
 * Created on May 6, 2018
 */

#ifndef FUELGAUGE_H
#define FUELGAUGE_H

#include <iostream>
using namespace std;

class FuelGauge {
    // Member variables
    private:
        int gallons;

    // Member functions
    public:
        // Default constructor
        FuelGauge() {
            gallons = 0;
        }

    // Overloaded constructor that accepts
    // an argument for gallons. It can hold
    // no more than 15 gallons.
    FuelGauge(int g) {
        if (g <= 15)
            gallons = g;
        else
            gallons = 15;
    }

    int getGallons() {
        return gallons;
    }

    // The incrementGallons function increments
    // the value of the gallons member, if it
    // is less than 15. The car holds a maximum
    // of 15 gallons.
    void incrementGallons() {
        if (gallons < 15)
            gallons++;
        else
            cout << "FUEL OVERFLOWING!!!\n";
    }

    // The decrementGallons function decrements
    // the value of the gallons member, if it
    // is greater than 0.
    void decrementGallons() {
        if (gallons > 0)
            gallons--;
        else
            cout << "OUT OF GAS!!!\n";
    }
};

#endif /* FUELGAUGE_H */

