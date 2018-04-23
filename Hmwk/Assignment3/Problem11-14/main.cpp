/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Calculate pay
 * Created on March 26, 2018, 10:05 PM
 */

// System libraries
#include <iostream>
#include <string>
#include "Structures.h"

using namespace std;

int main() {
    Worker worker;
    int option;
    float totalSalary;
    while (true) {
        cout << "Please select your option \n";
        cout << "1. Hourly Paid \n";
        cout << "2. Salary \n";
        cout << "3. Exit \n";
        cin >> option;
        switch (option) {
        case 1:
            HourlyPaid hourlyPaid;
            cout << "Enter Number of Hours Worked: ";
            cin >> hourlyPaid.HoursWorked;
            cout << endl << "Enter Hourly Rate: ";
            cin >> hourlyPaid.HourlyRate;
            worker.hourlyPaid = hourlyPaid;
            
            totalSalary = worker.hourlyPaid.HoursWorked * worker.hourlyPaid.HourlyRate;
            cout << endl << "Total Salary is: " << totalSalary << endl;
            break;
        case 2:
            Salaried salaried;
            cout << "Enter Salary: ";
            cin >> salaried.Salary;
            cout << endl << "Enter Bonus: ";
            cin >> salaried.Bonus;
            worker.salaried = salaried;

            totalSalary = worker.salaried.Salary + worker.salaried.Bonus;
            cout << endl << "Total Salary is: " << totalSalary << endl;
            break;
        case 3:
            break;
        default:
            cout << endl << "Invalid Option\n";
        }
        if (option == 3)
            break;
    }
    cout << "Thank you\n";
    return 0;
}