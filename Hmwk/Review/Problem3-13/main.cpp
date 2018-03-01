/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: What will the following program display?
 *
 * Created on February 28, 2018, 8:16 PM
 */

// System libraries
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    int integer1, integer2;
    double result;
    integer1 = 19;
    integer2 = 2;
    result = integer1 / integer2;
    cout << result << endl;
    result = static_cast<double>(integer1) / integer2;
    cout << result << endl;
    result = static_cast<double>(integer1 / integer2);
    cout << result << endl;
    
    // The program will display a 9, 9.5, and a 9.
    
    return 0;
}

