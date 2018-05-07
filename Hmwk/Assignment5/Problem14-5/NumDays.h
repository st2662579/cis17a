/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: NumDays Class
 * Created on May 6, 2018
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays {
    private: double hours_;
    double days_;
    public: NumDays(double hours) {
        hours_ = hours;
        days_ = hours / 8;
    }
    NumDays operator + (NumDays nd) {
        NumDays sumNumDays;
        sumNumDays.hours_ = this.getHours() + nd.getHours();
        sumNumDays.days_ = sumNumDays.hours_ / 8;
        return sumNumDays;
    }
    NumDays operator - (NumDays nd) {
        NumDays sumNumDays;
        sumNumDays.hours_ = this.getHours() - nd.getHours();
        sumNumDays.days_ = sumNumDays.hours_ / 8;
        return sumNumDays;
    }
    void operator++(NumDays nd) {
        this.hours_ += nd.getHours();
        this.days_ = this.hours_ / 8;
    }
    void operator--(NumDays nd) {
        this.hours_ -= nd.getHours();
        this.days_ = this.hours_ / 8;
    }
    double getHours() {
        return hours_;
    }
    double getDays() {
        return days_;
    }
};

#endif /* NUMDAYS_H */

