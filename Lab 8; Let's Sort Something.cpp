//Sophia Norris
//Comp Sci II SUM
//06/20/2023
//Module 4
//Lab 8


//***** Important Note *****//
// Need to stop using namespace std in codes
// As well as namespace directives into header files
// to prevent naming conflicts and type errors
// **** end note **********//


//This program takes a data set stored in table format in a atext file and displays:
//- A list of the products in the order of their sales dollars
//(**NOT** units sold) from highest to lowest.
//- The total number of all units dols.
//- The total sales for the six - month period
// 
// data format --->>
//productNumber	An integer that is the product number
//units	Number of units sold
//price	Price of product per unit, stored as double
//need to calculate sales amount

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct ProductSales
{
    int productNumber;
    int units;
    double price;
    double sales;
};

//Global Variables
int sumOfSales = 0;
int sumOfUnits = 0;

//Function Prototypes
void readDataFromFile(vector<ProductSales>& salesData);
void sortTheData(vector<ProductSales>& salesData);
void displaySales(vector<ProductSales>& salesData);
void showTotals(vector<ProductSales>& salesData);

int main() 
{
    vector<ProductSales> mySalesData;
    readDataFromFile(mySalesData);
    sortTheData(mySalesData);
    displaySales(mySalesData);
    showTotals(mySalesData);
    return 0;
}

void readDataFromFile(vector<ProductSales>& salesData) 
{
    const string DATAFILE = "datafile.txt";
    ifstream dfile;
    ProductSales oneRowOfSales;

    dfile.open(DATAFILE);
    if (dfile.is_open())
    {
        dfile >> oneRowOfSales.productNumber
            >> oneRowOfSales.units
            >> oneRowOfSales.price;
        while (!dfile.eof())
        {
            oneRowOfSales.sales = oneRowOfSales.units * oneRowOfSales.price;
            salesData.push_back(oneRowOfSales);
            sumOfSales += oneRowOfSales.sales;
            sumOfUnits += oneRowOfSales.units;
            dfile >> oneRowOfSales.productNumber
                >> oneRowOfSales.units
                >> oneRowOfSales.price;
        }
        dfile.close();
    }
    else
    {
        cerr << "Error: Unable to open data file" << endl;
        exit(1);
    }
}

void sortTheData(vector<ProductSales>& salesData) 
{
    int startScan, maxIndex, size;
    double maxValue;
    ProductSales tempRow;
    size = salesData.size();
    for (startScan = 0; startScan < (size - 1); startScan++) {
        maxIndex = startScan;
        maxValue = salesData[startScan].sales;
        for (int index = startScan + 1; index < size; index++) {
            if (salesData[index].sales > maxValue) {
                maxValue = salesData[index].sales;
                maxIndex = index;
            }
        }
        // Now swap the max value with value where you started
        tempRow = salesData[maxIndex];
        salesData[maxIndex] = salesData[startScan];
        salesData[startScan] = tempRow;

        swap(salesData[maxIndex], salesData[startScan]);
    }
}

void displaySales(vector<ProductSales>& salesData) 
{

    cout << "Product Number\tSales\n";
    cout << "----------------------------------\n";
    for (int index = 0; index < salesData.size(); index++) {
        cout << salesData[index].productNumber << "\t\t$";
        cout << setw(8) << salesData[index].sales << endl;
    }
    cout << endl;
}

void showTotals(vector<ProductSales>& salesData) 
{
    int sumOfUnits = 0;
    double sumOfSales = 0.0;

    for (const auto& product : salesData) 
    {
        sumOfUnits += product.units;
        sumOfSales += product.sales;
    }
    cout << "Total Units Sold: " << sumOfUnits << endl;
    cout << "Total Sales:     $" << sumOfSales << endl;
}

