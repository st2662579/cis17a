/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Movie Data
 * Created on March 26, 2018, 10:05 PM
 */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "Structures.h";

void printMovie(MovieData movie);

int main() {
    MovieData a, b;

    cout << "First Movie" << endl;
    cout << "Enter title: ";
    cin >> a.title;
    cout << "Enter year: ";
    cin >> a.year;
    cout << "Enter Runing Time: ";
    cin >> a.RunningTime;

    cout << "Second Movie" << endl;
    cout << "Enter title: ";
    cin >> b.title;
    cout << "Enter year: ";
    cin >> b.year;
    cout << "Enter running Time: ";
    cin >> a.RunningTime;

    printMovie(a);
    printMovie(b);
}

void printMovie(MovieData movie) {
    cout << "Title: " << movie.title << endl;
    cout << "Year: " << movie.year << endl;
    cout << "Running Time: " << movie.RunningTime << endl;
}