/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Structures.h
 * Author: Seth
 *
 * Created on March 26, 2018, 10:39 PM
 */

#ifndef STRUCTURES_H
#define STRUCTURES_H

struct CorpData {
    string DivName; // Division name
    double FstQtr, // First quarter sales
    SecQtr, // second quarter sales
    TrdQtr, // Third quarter sales
    FthQtr, // Fourth quarter sales
    TotAnn, // Total annual sales
    AvgQtrly; // Average quarterly sales

    CorpData(string D, double f, double s, double t, double fr) {
        DivName = D;
        FstQtr = f;
        SecQtr = s;
        TrdQtr = t;
        FthQtr = fr;
    }
};

#endif /* STRUCTURES_H */

