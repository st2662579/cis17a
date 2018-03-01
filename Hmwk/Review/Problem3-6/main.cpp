/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Display a user's weight in kolograms
 *
 * Created on February 28, 2018, 9:00 PM
 */

// System libraries
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    // Declare variables
    double pounds, kilograms;
    
    // Ask the user for their weight in pounds
    cout << "Enter your weight in pounds: ";
    cin >> pounds;
    
    // Convert the user's weight in pounds to kilograms
    kilograms = pounds / 2.2;
    
    cout << endl << "Your weight in kilograms is " << kilograms << " kilogram(s).";

    return 0;
}

