/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Track a speakers' bureau
 * Created on March 26, 2018, 10:05 PM
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "Structures.h"

void getSpeaker(speakerBureau * );
void printSpeaker(speakerBureau * );
void editSpeaker(speakerBureau * );
void searchSpeakTopic(speakerBureau * );

int main() {
    int NUM_SPEAKERS = 10;
    int index;
    speakerBureau info[10];

    int menu;
    const int enter = 1,
        change = 2,
        print = 3,
        search = 4,
        leave = 5;

    do {
        cout << "Please select a choice from the menu.\n" << "1) Enter Speaker Information.\n" << "2) Change Speaker Information.\n" << "3) Print Speaker Information.\n" << "4) Search for Topic. \n" << "5) Leave this menu.\n" << "Select: ";
        cin >> menu;

        switch (menu) {
        case enter:
            {
                getSpeaker(info);
            }
            break;
        case change:
            {
                editSpeaker(info);
            }
            break;
        case print:
            {
                printSpeaker(info);
            }
            break;

        case search:
            {
                searchSpeakTopic(info);
            }
        }
    } while (menu != leave);
    return 0;
}
void getSpeaker(speakerBureau * p){
    int size = 10;
    for (int i = 0; i < size; i++) {
        cout << "\nPlease enter the following information of speaker " << i << ": \n";
        cout << "Speaker Name:";
        cin.ignore();
        getline(cin, p[i].name);
        cout << "\nSpeaker Telephone Number:";
        cin.ignore();
        getline(cin, p[i].TelephoneNumber);
        cout << "\nSpeaker Topic:";
        cin.ignore();
        getline(cin, p[i].SpeakTopic);
        cout << "\nFee Required:";
        cin >> p[i].fee;
    }
}

void printSpeaker(speakerBureau * p) {
    int size = 10;
    for (int i = 0; i < size; i++) {
        cout << "The information entered for each speaker is: \n";
        cout << "Speaker " << i << endl;
        cout << "Speaker Name: " << p[i].name << endl;
        cout << "Speaker Telephone Number: " << p[i].TelephoneNumber << endl;
        cout << "Speaker Topic: " << p[i].SpeakTopic << endl;
        cout << "Speaker Fee Required: " << p[i].fee << endl;
    }
}

void editSpeaker(speakerBureau * p) {
    int i;
    cout << "Please enter the number of the speaker you would like to edit." << endl;
    cin >> i;
    if (i <= 9) {
        cout << endl;
        cout << "Please enter the updated information of the speaker: \n";
        cout << "Speaker Name:";
        cin.ignore();
        getline(cin, p[i].name);
        cout << "\nSpeaker Telephone Number:";
        getline(cin, p[i].TelephoneNumber);
        cout << "\nSpeaker Topic:";
        getline(cin, p[i].SpeakTopic);
        cout << "\nFee Required:";
        cin >> p[i].fee;
    } else {
        cout << "Please pick a number between 0-9" << endl;
    }
}

void searchSpeakTopic(speakerBureau * p) {
    int topic;
    cout << " Please type a topic in the program" << endl;
    cin >> topic;
}