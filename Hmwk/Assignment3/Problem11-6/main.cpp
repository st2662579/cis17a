/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Soccer player data
 * Created on March 26, 2018, 10:05 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "Structures.h"

const int numPlayers = 12;

// Function prototypes
void getPlayerInfo(Player & );
void showInfo(Player);
int getTotalPoints(Player[], int);
void showHighest(Player[], int);

int main() {
    Player team[numPlayers];
    int index;

    for (index = 0; index < 12; index++) {
        cout << "\nPLAYER #" << (index + 1) << "\n";
        cout << "---------\n";
        getPlayerInfo(team[index]);
        cin.get();
    }

    cout.width(20);
    cout.setf(ios::left);
    cout << "\nNAME";
    cout.width(10);
    cout << "NUMBER";
    cout.width(10);
    cout << "POINTS SCORED\n";
    for (index = 0; index < 12; index++)
        showInfo(team[index]);
    cout << "TOTAL POINTS: " << getTotalPoints(team, numPlayers) << endl;
    showHighest(team, numPlayers);
}

void getPlayerInfo(Player & p) {
    cout << "Player name: ";
    cin.getline(p.name, 45);
    cout << "Player's number: ";
    cin >> p.number;
    cout << "Points scored: ";
    cin >> p.points;
}

void showInfo(Player p) {
    cout << setw(20) << p.name;
    cout << setw(10) << p.number;
    cout << setw(10) << p.points << endl;
}

int getTotalPoints(Player p[], int size) {
    int total = 0;
    for (int index = 0; index < size; index++)
        total += p[index].points;
    return total;
}

void showHighest(Player p[], int size) {
    int highest = 0, highPoints = p[0].points;

    for (int index = 1; index < size; index++) {
        if (p[index].points > highPoints) {
            highest = index;
            highPoints = p[index].points;
        }
    }
    cout << "The player who scored the most points is: ";
    cout << p[highest].name << endl;
}