/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Display starting populating and projected population at the end of the year
 *
 * Created on February 28, 2018, 10:57 PM
 */

// System libraries

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getData(int&, float&, float&, int&);
int projYr(int, float, float);

int main() {
    
    // Declare variables
    int startPop,
            numOfYrs,
            projPop;

    float birthRate,	// The annual birth rate
            deathRate; 	// The annual death rate

    // Display introduction
    cout << "\nThis program projects and displays the "
             << "population at the end of each year.\n";

    // Call function getData
    getData(startPop, birthRate, deathRate, numOfYrs);

    cout << "\n           Population projection Table\n"
             << "  Year   Starting Population   Projected Population\n"
             << "-----------------------------------------------------\n";

    for (int yr = 1; yr <= numOfYrs; yr++) {
        projPop = projYr(startPop, birthRate, deathRate);

        cout << setw(4) << yr << "      " << setw(10) << startPop;
        cout << "             " << setw(10) << projPop << endl;

        startPop = projPop;
    }

    return 0;
}

int projYr(int startPop, float birthRate, float deathRate){
    return startPop * (1 + birthRate) * (1 - deathRate);
}

void getData(int& startPop, float& birthRate, float& deathRate, int& numOfYrs) {
    do {
        cout << "What is the starting size of the population? ";
        cin  >> startPop;

    } while (startPop < 2);

    do {
        cout << endl << "What is the annual birth rate? ";
        cin  >> birthRate;
    } while (birthRate < 0);

    do {
        cout << endl << "What is the annual death rate? ";
        cin  >> deathRate;

    } while (deathRate < 0);

    do {
        cout << endl << "How many years to display? ";
        cin  >> numOfYrs;
    } while (numOfYrs < 1);
}