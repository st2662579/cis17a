/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Display a character's ASCII code
 *
 * Created on February 28, 2018, 8:00 PM
 */

// System libraries
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    char letter;
    
    // Ask the user to enter a character
    cout << "Enter a character: ";
    cin >> letter;
    
    // Output the character's ASCII code
    cout << endl << "ASCII code: " << static_cast<int>(letter);
    
    return 0;
}

