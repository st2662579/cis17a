/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Multiply two numbers and display the result
 *
 * Created on February 28, 2018, 9:06 PM
 */

// System libraries
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    // Declare variables
    float first, second, product;
    
    // Output/input
    cout << "This program will display the product of two numbers. Enter two numbers to be multipled: ";
    cin >> first >> second;
    
    // Multiply the two numbers
    product = first * second;
    
    // Display the product
    cout << endl << "The product is " << product;
    
    return 0;
}

