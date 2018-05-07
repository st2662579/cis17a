/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Car Instrument
 * Created on May 6, 2018
 */

#ifndef ODOMETER_H
#define ODOMETER_H

class Odometer {
    // Member variables
    private:
        // The current mileage
        int mileage;

    // Mileage set-point to remember when the
    // FuelGuage gallons were decremented.
    int setPoint;

    // Pointer to a FuelGauge object
    FuelGauge * fuelGauge;

    public:
        Odometer(int m, FuelGauge * fp) {
            mileage = m;
            setPoint = m;
            fuelGauge = fp;
        }
        int getMileage() {
            return mileage;
        }
        void incrementMiles() {
            if (mileage < 999999)
                mileage++;
            else
                mileage = 0;

            if (setPoint > mileage) {
                // Add 1 million to get the actual mileage.
                int falseMileage = mileage + 1000000;

                if ((falseMileage - setPoint) >= 24) {
                    fuelGauge->decrementGallons();
                    setPoint = mileage;
                }
            } else {
                if ((mileage - setPoint) >= 24) {
                    fuelGauge->decrementGallons();
                    setPoint = mileage;
                }
            }
        }
};

#endif /* ODOMETER_H */

