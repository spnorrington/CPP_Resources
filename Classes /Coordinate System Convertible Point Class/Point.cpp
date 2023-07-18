//This code is apart of the Assignment 3: Problem 1 Project
//Please see assignment3.cpp in this folder for additional information.
//
//-------------Implementation File-----------------//


#include <iostream>
#include <cmath> // for calc used to compute spherical coordinates
#include "Point.h"

using namespace std;


void Point::setCoordinates(double newX, double newY, double newZ)
{
	x = newX;
	y = newY;
	z = newZ;

}

void Point::move(double offsetX, double offsetY, double offsetZ)
{
	x += x + offsetX;
	y += y + offsetY;
	z += z + offsetZ;

}

void Point::move(Point offset)
{
	x += x + offset.getX();
	y += y + offset.getY();
	z += z + offset.getZ();
}

double Point::getX() const
{
	return x;
}

double Point::getY() const
{
	return y;
}

double Point::getZ() const
{
	return z;
}

// The following functions are for the spherical coordinate system. 
// 
//Changed starter functions given in the assignment instructions to compute Spherical coordinates -> Added Point:: before function names for proper syntax and to state that these functions belong to the Point class from the orginal

double Point::radius(double x, double y, double z)
{
    double rSquare = x * x + y * y + z * z;
    return sqrt(rSquare);
}

double Point::theta(double x, double y)
{
    if (x == 0)
    {
        cerr << "Only Chuck Norris can divide by zero" << endl;
        return -1;
    }
    else
    {
        return atan(y / x);
    }
}

double Point::rho(double x, double y, double z)
{
    double rSquare = x * x + y * y + z * z;
    return acos(z / sqrt(rSquare));
}
