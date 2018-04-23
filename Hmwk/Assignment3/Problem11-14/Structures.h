/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Structures.h
 * Author: Seth
 *
 * Created on March 26, 2018, 10:15 PM
 */

#ifndef STRUCTURES_H
#define STRUCTURES_H

struct HourlyPaid {
    float HoursWorked;
    float HourlyRate;
};

struct Salaried {
    float Salary;
    float Bonus;
};

union Worker {
    HourlyPaid hourlyPaid;
    Salaried salaried;
};

#endif /* STRUCTURES_H */

