/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Corporate Sales Data
 * Created on March 26, 2018, 10:05 PM
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "Structures.h"

// Function Prototypes
void calcSales(CorpData & );
void displayDivInfo(CorpData);

int main() {

    CorpData East("East", 1000, 1500, 1250, 1750);
    CorpData West("West", 2500, 2000, 2750, 2250);
    CorpData North("North", 3750, 3500, 3250, 3000);
    CorpData South("South", 4250, 4750, 4000, 4500);

    calcSales(East);
    calcSales(West);
    calcSales(North);
    calcSales(South);

    displayDivInfo(East);
    displayDivInfo(West);
    displayDivInfo(North);
    displayDivInfo(South);
    return 0;
}

void calcSales(CorpData & D) {
    D.TotAnn = D.FstQtr + D.SecQtr + D.TrdQtr + D.FthQtr;
    D.AvgQtrly = D.TotAnn / 4;
}

void displayDivInfo(CorpData D) {
    cout << "\n           Sales Data\n" << "---------------------------------------\n";
    cout << fixed << showpoint << setprecision(2);
    cout << "Division :          " << D.DivName << endl;
    cout << "Total Sales :       $" << D.TotAnn << endl;
    cout << "Quarterly average : $" << D.AvgQtrly << endl;
}