// Implementation of the CheckNumbers class

#include "CheckNumbers.h"
#include <iostream>
using namespace std;


// Set of Static Strings that are the building blocks for numbers
const string CheckNumbers::lessThan20[20] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                                                 "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
const string CheckNumbers::hundred = "hundred";
const string CheckNumbers::thousand = "thousand";


// Constructor that accepts a non-negative integer to define value
CheckNumbers::CheckNumbers(int value)
{
    if (value < 0)
    {
        cerr << "Error: Value must be non-negative." << endl;
        exit(1);
    }

    number = value;
}

void CheckNumbers::print()
{
    if (number == 0)
    {
        cout << lessThan20[0] << endl;
        return;
    }

    string words;

    if (number >= 1000)
    {
        int thousands = number / 1000;
        int rest = number % 1000;

        if (thousands >= 20)
        {
            words += lessThan20[thousands / 100] + " " + hundred;
            if (thousands % 100 != 0)
            {
                words += " " + lessThan20[(thousands % 100) / 10 * 10];
                if (thousands % 10 != 0)
                    words += " " + lessThan20[thousands % 10];
            }
        }
        else
        {
            words += lessThan20[thousands];
        }

        words += " " + thousand;
        if (rest != 0)
        {
            words += " " + lessThan20[rest / 100] + " " + hundred;
            if (rest % 100 != 0)
            {
                words += " " + lessThan20[(rest % 100) / 10 * 10];
                if (rest % 10 != 0)
                    words += " " + lessThan20[rest % 10];
            }
        }
    }
    else
    {
        if (number >= 20)
        {
            words += lessThan20[number / 100] + " " + hundred;
            if (number % 100 != 0)
            {
                words += " " + lessThan20[(number % 100) / 10 * 10];
                if (number % 10 != 0)
                    words += " " + lessThan20[number % 10];
            }
        }
        else
        {
            words += lessThan20[number];
        }
    }

    cout << words << endl;
}
