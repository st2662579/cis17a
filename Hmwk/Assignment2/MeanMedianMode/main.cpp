/* 
 * File:   main.cpp
 * Author: Seth Tyler
 * Purpose: Mean, median, mode
 * Created on March 14, 2018, 9:39 PM
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>

struct Stats {
    float avg;      // Average value of an integer array
    float median;   // Median value of an integer array
    int   *mode;    // Array containing the modes
    int   nModes;   // Number of modes in the array
    int   maxFreq;  // Max frequency of modes
};

using namespace std;

Stats *avgMedMode(int *, int);
Stats *avgMedMode(int *a, int n) {
    float avg=0,sum=0;
    for (int i = 0; i < n; i++) {
        sum=sum+a[i];
    }
    avg=sum/n;
    sort(&a[0], &a[n]); // Sort elements
    float median=0;
    if (n % 2 == 0) {
        // If n is even, then median is the average of two middle values
        int mid = (n / 2);
        median = (a[mid] + a[mid-1]) / 2.0;
    } else {
        median = a[n / 2]; // Middle is n / 2
    }
    
    int b[n][2];
    int index=0;//index of b array
    int temp=a[0],count=1;

    for (int i = 1; i < n; i++) {
        if (temp == a[i]) {
            count++;
        } else {
            b[index][0] = temp;
            b[index][1] = count;
            index++;
            temp=a[i];
            count=1;
            // Store the count and element in b, change temp and reset the count
        }
        if (i == n-1) {
            b[index][0]=temp;
            b[index][1]=count;
            index++;
        }
    }
    int maxCount=0;
    for (int i = 0; i < index; i++) {
        if (maxCount < b[i][1]) {
            maxCount=b[i][1];
        }
    }
    int numberMaxCounts=0;
    for (int i = 0; i < index; i++) {
        if (b[i][1] == maxCount) {
            numberMaxCounts++;
        }
    }
    int *mode;
    if (numberMaxCounts == index || n == 0) {// If all elements have equal count, then there is no mode
        mode='\0';
        maxCount=0;
        numberMaxCounts=0;
        if(n==0) {
            avg=0;
            median=0;          
        }
    } else {
        int ind=0;
        mode=new int[numberMaxCounts];
        for (int i = 0; i < index; i++) {
            if (b[i][1] == maxCount) {
                mode[ind++]=b[i][0];
            }
        }                                                          
    }

    Stats *s=new Stats();
    s->avg=avg;
    s->median=median;
    s->maxFreq=maxCount;
    s->nModes=numberMaxCounts;
    s->mode=mode;
    return s;
}

void printStat(Stats s) {
    cout << endl << "Stats:\n";
    cout << "Average: " << s.avg << endl;
    cout << "Median: " << s.median << endl;
    cout << "Number of Modes: " << s.nModes << endl;
    cout << "Max Frequency of Mode: " << s.maxFreq<< endl;
    if (s.mode == '\0') {
        cout << "There is no mode!" << endl;
    } else {
        cout << "Mode : " << endl;
        for (int i = 0; i < s.nModes; i++) {
            cout << "\t\t" << s.mode[i] << endl;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int *a;
    a=new int[n];
    cout << endl << "Enter its elements: \n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Stats *s = avgMedMode(a,n);
    printStat(*s);
    delete [](s->mode);
    delete [](s);
}