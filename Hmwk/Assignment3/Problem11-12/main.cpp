/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Monthly Budget
 * Created on March 26, 2018, 10:05 PM
 */

#include <iostream>
#include <iomanip>
#include "Structures.h";

using namespace std;

// Function Prototypes
void getSpent(MonthlyBudget &);
void displayReport(MonthlyBudget A, MonthlyBudget B);
void displayReportHelper(float B, float S);
float total(MonthlyBudget);

int main() {
    MonthlyBudget Budget = {
        500.00,
        150.00,
        65.00,
        50.00,
        250.00,
        30.00,
        100.00,
        150.00,
        75.00,
        50.00
    };
    MonthlyBudget Spent;

    getSpent(Spent);

    displayReport(Budget, Spent);

    return 0;
}

void getSpent(MonthlyBudget &B) {
    cout << "During the past month:\n";
    cout << "How much was spent on housing? ";
    cin >> B.Housing;
    cout << endl << "How much was spent on utilities? ";
    cin >> B.Utilities;
    cout << endl << "How much was spent on household expenses? ";
    cin >> B.HouseholdExpense;
    cout << endl << "How much was spent on transportation? ";
    cin >> B.Transportation;
    cout << endl << "How much was spent on food? ";
    cin >> B.Food;
    cout << endl << "How much was spent on medical? ";
    cin >> B.Medical;
    cout << endl << "How much was spent on insurance? ";
    cin >> B.Insurance;
    cout << endl << "How much was spent on entertainment? ";
    cin >> B.Entertainment;
    cout << endl << "How much was spent on clothing? ";
    cin >> B.Clothing;
    cout << endl << "How much was spent on miscellaneous? ";
    cin >> B.Miscellaneous;
}

void displayReport(MonthlyBudget B, MonthlyBudget S) {
    float TotalBudget, TotalSpent;

    cout << endl << "\n         Monthly budget report\n";
    cout << "------------------------------------------\n";

    cout << "Housing:            $";
    displayReportHelper(B.Housing, S.Housing);

    cout << "Utilities:          $";
    displayReportHelper(B.Utilities, S.Utilities);

    cout << "Household expenses: $";
    displayReportHelper(B.HouseholdExpense, S.HouseholdExpense);

    cout << "Transportation:     $";
    displayReportHelper(B.Transportation, S.Transportation);

    cout << "Food:               $";
    displayReportHelper(B.Food, S.Food);

    cout << "Medical:            $";
    displayReportHelper(B.Medical, S.Medical);

    cout << "Insurance:          $";
    displayReportHelper(B.Insurance, S.Insurance);

    cout << "Entertainment:      $";
    displayReportHelper(B.Entertainment, S.Entertainment);

    cout << "Clothing:           $";
    displayReportHelper(B.Clothing, S.Clothing);

    cout << "Miscellaneous:      $";
    displayReportHelper(B.Miscellaneous, S.Miscellaneous);

    TotalBudget = total(B);

    TotalSpent = total(S);

    cout << "Entire budget:      $";
    displayReportHelper(TotalBudget, TotalSpent);
}

void displayReportHelper(float B, float S) {
    cout << fixed << showpoint << setprecision(2);
    if (B > S) {
        cout << setw(7) << B - S;
        cout << " under\n";
    } else {
        cout << setw(7) << S - B;
        cout << " over\n";
    }
}

float total(MonthlyBudget B) {
    return B.Housing + B.Utilities + B.HouseholdExpense + B.Transportation + B.Food + B.Medical + B.Insurance + B.Entertainment +
        B.Clothing + B.Miscellaneous;
}