/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Determine number of points earned based on books purchased
 * Created on March 14, 2018, 8:39 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main() {
    int books, points;

    // Output
    cout << "Calculate book club points\n";
    cout << "How many books have you purchased this month? ";
    
    // Ask for how many books
    cin >> books;
    
    // Calculate the points
    switch (books) {
        case 0:
            points = 0;
            break;
        case 1:
            points = 5;
            break;
        case 2:
            points = 15;
            break;
        case 3:
            points = 30;
            break;
        default:
            points = 60;
            break;
    }
    
    // Display points earned
    cout << endl << "You have earned " << points << " points this month.\n";

    return 0;
}