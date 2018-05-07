/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Car Instrument
 * Created on May 6, 2018
 */

#include <iostream>
#include "FuelGauge.h"
#include "Odometer.h"
using namespace std;

int main() {
    // Create a FuelGuage object.
    FuelGauge fuel;

    // Create an Odometer object to work with the FuelGauge object.
    Odometer odometer(0, & fuel);

    // Fill the car up with gas.
    for (int i = 0; i < 15; i++)
        fuel.incrementGallons();

    // Drive the car until it runs out of gas.
    while (fuel.getGallons() > 0) {
        // Drive a mile.
        odometer.incrementMiles();

        // Display the mileage.
        cout << "Mileage: " << odometer.getMileage() << endl;

        // Display the amount of fuel.
        cout << "Fuel level: " << fuel.getGallons() << " gallons\n";
        cout << "------------------------------\n";
    }

    return 0;
}