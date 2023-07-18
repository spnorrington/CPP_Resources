// This program converts a whole dollar amount into the English description of the number.


#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "CheckNumbers.h"

using namespace std;


int main()
{
    int amount; // To hold int input
    cout << "Enter a non-negative dollar amount: ";
    cin >> amount;

    CheckNumbers check(amount);
    cout << "English description of the amount: ";
    check.print();

    return 0;
}
