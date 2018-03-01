/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Predict the size of a population of organisms
 *
 * Created on February 28, 2018, 9:13 PM
 */

// System libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {

    // Declare variables
    float days, sizeOfPop;
    float dailyInc;
    
    // Output and receive user input
    cout << "What is the starting number of organisms? ";
    cin >> sizeOfPop;
    cout << endl << "What is the average daily population increase? (percent of current population): ";
    cin >> dailyInc;
    cout << endl << "Enter the number of days of growth: ";
    cin >> days;
    
    cout << endl;
    
    
    // Input validation
    while (sizeOfPop < 2 || dailyInc < 0 || days < 1) {
        if (sizeOfPop < 2) {
            cout << "Starting size of population must be greater than 2.\n";
            cout << "Enter a new starting number of organisms: ";
            cin >> sizeOfPop;
        } else if (dailyInc < 0) {
            cout << "Average daily population increase must be greater than 0.\n";
            cout << "Enter a new average daily population increase.\n";
            cin >> dailyInc;
        } else if (days < 1) {
            cout << "Number of days must be greater than 0.\n";
            cout << "Enter a new number of days.\n";
            cin >> days; 
        }
    }
    
    // Calculate and display daily increase;
    cout << "Table displaying population increase over " << days << " days.\n"
             << "      Day              Size of population\n"
             <<"--------------------------------------------------\n";


    cout.precision(0);
    for (int x = 1; x <= days; x++) {
            cout << "      " << fixed << x << "                      "
                     << sizeOfPop << endl; 
            sizeOfPop *= (1 + (dailyInc / 100));
    }
    return 0;
}

