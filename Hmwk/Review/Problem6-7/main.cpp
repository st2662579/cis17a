/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Celsius Temperature Table
 *
 * Created on February 28, 2018, 9:18 PM
 */

// System libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
float celsius(int);

int main(int argc, char** argv) {

    float num;
    
    // Output table
    cout << "Table of Fahrenheit temperatures 0 - 20\n"
        << "and their Celsius equivalents.\n\n"
        << "------------------------------\n"
        << "  Fahrenheit       Celsius\n"
        << "------------------------------\n";

    for (int F = 0; F <= 20; F++)
    {
        cout << "      " << setw(2) << F;
        cout << "          "
                 << setw(3) << celsius(F) << endl;
    }
    cout << endl;
    return 0;
}

float celsius(int fahr) {
    return ((5.0 * (fahr - 32)) / 9);
}