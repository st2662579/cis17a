/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Determine placings of runners
 * Created on March 14, 2018, 9:00 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main() {
    int runner[3];

    // Output
    cout << "Calculate placings of top 3 runners\n";

    for (int i = 0; i < 3; i++) {
        // Ask for runner's time and input it into the array
        cout << endl << "What was runner #" << (i + 1) << "'s time? ";
        cin >> runner[i];
        if (runner[i] < 0) {
            i = i - 1;
            cout << endl << "Please enter a positive number.";
        }
    }
    
    cout << endl << endl;
    
    if (runner[0] < runner[1] && runner[0] < runner[2]) {
        cout << "Runner #1 came in first with a time of " << runner[0] << endl;
        if (runner[1] < runner[2]) {
            cout << "Runner #2 came in second with a time of " << runner[1] << endl;
            cout << "Runner #3 came in third with a time of " << runner[2] << endl;
        } else {
            cout << "Runner #3 came in second with a time of " << runner[2] << endl;
            cout << "Runner #2 came in third with a time of " << runner[1] << endl;
        }
    } else if (runner[1] < runner[0] && runner[1] < runner[2]) {
        cout << "Runner #2 came in first with a time of " << runner[1] << endl;
        if (runner[0] < runner[2]) {
            cout << "Runner #1 came in second with a time of " << runner[0] << endl;
            cout << "Runner #3 came in third with a time of " << runner[2] << endl;
        } else {
            cout << "Runner #3 came in second with a time of " << runner[2] << endl;
            cout << "Runner #1 came in third with a time of " << runner[0] << endl;
        }
    } else if (runner[2] < runner[0] && runner[2] < runner[1]) {
        cout << "Runner #3 came in first with a time of " << runner[2] << endl;
        if (runner[0] < runner[1]) {
            cout << "Runner #1 came in second with a time of " << runner[0] << endl;
            cout << "Runner #2 came in third with a time of " << runner[1] << endl;
        } else {
            cout << "Runner #2 came in second with a time of " << runner[1] << endl;
            cout << "Runner #1 came in third with a time of " << runner[0] << endl;
        }
    }
    
    return 0;
}