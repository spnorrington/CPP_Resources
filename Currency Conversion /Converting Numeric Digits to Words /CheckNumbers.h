// Specification File for CheckNumbers class

#ifndef CHECKNUMBERS_H
#define CHECKNUMBERS_H

#include <iostream>
#include <string>
using namespace std;


class CheckNumbers
{
public:
    // Constructor that accepts a non-negative integer to define value
    CheckNumbers(int value);

    // Public method to print the English description of the amount
    void print();

private:
    int number; // Property to store the number

    // Static strings to be used as building blocks for numbers
    static const string lessThan20[20];
    static const string hundred;
    static const string thousand;


};

#endif
