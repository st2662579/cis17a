/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Keep track of weather conditions in a 3-month period
 *
 * Created on February 28, 2018, 9:25 PM
 */

// System libraries
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int mth = 3,
        day = 30;
    char weather[mth][day];

    int sun,
        rain,
        cloudy,
        totSun = 0,
        totRain = 0,
        totCloudy = 0,
        lrgstRain = 0;

    ifstream read;
    read.open("RainOrShine.txt");
    if (!read) {
            cout << "Error opening data file.";
    } else {	// Read weather data in from file
        for (int row = 0; row < mth; row++) {
            for (int col = 0; col < day; col++) {
                read >> weather[row][col];
            }
        }
    }
    read.close();					// Close file

    // Create and display report
    cout << "\n           Three-month weather report\n"
             << "--------------------------------------------------\n";
    
    for (int row = 0; row < mth; row++) {
        sun = rain = cloudy = 0;
        for (int col = 0; col < day; col++) {
            switch (weather[row][col])
            {
                case 'S' : sun++;
                    break;
                case 'R' : rain++;
                    break;
                case 'C' : cloudy++;
                    break;
            }
        }

        // Display monthly numbers
        cout << "\nFor the month of ";
        if (row == 0)
            cout << "June.\n";
        else if (row == 1)
            cout << "July.\n";
        else if (row == 2)
            cout << "August.\n";

        cout << "Rainy : " << rain << endl
                 << "Sunny : " << sun  << endl
                 << "Cloudy: " << cloudy << endl;

        // Calculate 3-month totals
        totSun += sun;
        totRain += rain;
        totCloudy += cloudy;

        // Calculate month with most rainy days
        if(lrgstRain > rain)
                lrgstRain = row;
    }

    // Display monthly totals
    cout << "\nFor the whole three-month period\n"
             << "Rainy : " << totRain << endl
             << "Sunny : " << totSun  << endl
             << "Cloudy: " << totCloudy << endl;

    // Display month with the largest number of rainy days
    cout << "\nMonth with the largest number of rainy days: ";
    
    
    if (lrgstRain == 0)
        cout << "June.\n\n";
    else if (lrgstRain == 1)
        cout << "July.\n\n";
    else if (lrgstRain == 2)
        cout << "August.\n\n";

    return 0;
}