// Sophia Norris
// Lab 10
// 
// A payroll system stores information about an employee in a data record with the following fields:

//empId: A integer employee number
//hours : Number of hours worked by employee each week
//payRate : Payrate in units of dollars per hour
//wages : Employee’s gross wages earned in current year
//You are asked to write a program that generates test data for the payroll system.The program needs to ask the user to enter an non - predetermined number of these data records and outputs them to a data file sorted by the employee number.

// Make certain the break points remain set in your IDE. Build and run your program and, at each break point, compare the difference between how this worked with the list, the stack, and the queue data types.



#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

struct Employee 
{
    int empId;
    int hours;
    int rate;
    int pay;
};

queue<Employee*> employeeQueue;

void getEmployee(Employee*);
void displayAndDump();

int main() 
{
    int numEmps = 0;
    Employee* empPtr = nullptr;
    cout << "How many employees? ";
    cin >> numEmps;
    for (int count = 0; count < numEmps; ++count) 
    {
        empPtr = new Employee();
        getEmployee(empPtr);
        employeeQueue.push(empPtr);
    }
    displayAndDump();
    return 0;
}

void getEmployee(Employee* emp) 
{
    cout << "Enter employee number: ";
    cin >> emp->empId;
    cout << "How many hours did they work? ";
    cin >> emp->hours;
    cout << "What is their hourly rate? ";
    cin >> emp->rate;
    emp->pay = emp->hours * emp->rate;
}

void displayAndDump() 
{
    fstream dStream("empdata.csv", ios::out);
    if (dStream.is_open()) 
    {
        while (!employeeQueue.empty()) 
        {
            Employee* empPtr = employeeQueue.front();
            dStream << empPtr->empId << ",";
            dStream << empPtr->hours << ",";
            dStream << empPtr->rate << ",";
            dStream << empPtr->pay << endl;
            cout << empPtr->empId << ",";
            cout << empPtr->hours << ",";
            cout << empPtr->rate << ",";
            cout << empPtr->pay << endl;
            employeeQueue.pop();
            delete empPtr;
        }
        dStream.close();
    }
}