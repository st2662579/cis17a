/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: TimeOff Class
 * Created on May 6, 2018
 */

#ifndef TIMEOFF_H
#define TIMEOFF_H

#include <iostream>
using namespace std;

class TimeOff {
    private:
        NumDays maxSickDays, sickTaken, maxVacation, vacTaken, maxUnpaid, unpaidTaken;
        char name[100];
        int id;
    public:
        TimeOff(char inname[100], int inid, float inMaxSickDays, float inSickTaken,
            float inMaxVacation,
            float inVacTaken, float inMaxUnpaid, float inUnpaidTaken) {
            strcpy(name, inname);
            if (inid > 0) {
                id = inid;
            };
            maxSickDays.setDays(inMaxSickDays);
            sickTaken.setDays(inSickTaken);

            if (inMaxVacation > 240) {
                cout << "Vacation maxed at 240 hours." << endl;
                maxVacation.setDays(240);
            } else {
                maxVacation.setDays(inMaxVacation);
            }

            vacTaken.setDays(inVacTaken);
            maxUnpaid.setDays(inMaxUnpaid);
            unpaidTaken.setDays(inUnpaidTaken);
        };
        TimeOff() {
            name[0] = '\0';
            id = 0;
        };

        int getEmpNum() {
            return (id);
        };
        char * getName() {
            return (name);
        };
        float getMaxSick() {
            return (maxSickDays.getDays());
        };
        float getMaxVacation() {
            return (maxVacation.getDays());
        };
        float getMaxUnpaid() {
            return (maxUnpaid.getDays());
        };
        float getSickTaken() {
            return (sickTaken.getDays());
        };
        float getVacationTaken() {
            return (vacTaken.getDays());
        };
        float getUnpaidTaken() {
            return (unpaidTaken.getDays());
        };
        void setUnpaidTaken(int indays) {
            unpaidTaken.addDays(indays);
            maxUnpaid.subDays(indays);
        };
        void setVacTaken(int indays) {
            vacTaken.addDays(indays);
            maxVacation.subDays(indays);
        };
        void setSickTaken(int indays) {
            sickTaken.addDays(indays);
            maxSickDays.subDays(indays);
        };
};

#endif /* TIMEOFF_H */

