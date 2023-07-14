// Sophia Norris
// Comp SCI II
// Mod 3; Assignment 3; Problem 1;


//The purpose of this program is to create a class that models a point using 3-D coordinates (x, y, and z) to refer to a point using #-D or spherical coordinates, where the spherical point coordinate is represented by 3 values:
//radius: the distance from the origin to the point
//theta: the angle, measures in radians, from the x - axis to the point
//rho : the angle, measured in radians, from the z - axis to the point


//By not disclosing the internal implementation of the class, we can give the user an option of using either coordinate system. Now we can manipulate the implementation of the class.

//----------------- MAIN.CPP --------------- ///

#include <iostream>
#include <cmath> //added for calculations done in implementation file that also required cmath
#include "Point.h"


using namespace std;

int main()
{
	Point* point1 = new Point();
	Point* point2 = new Point(3.0, 3.0, 3.0);
	cout << point1->getX() << point1->getY() << point1->getZ() << endl;
	cout << point2->getX() << point2->getY() << point2->getZ() << endl;

	point1->setCoordinates(2.0, 1.0, 2.0);
	cout << point1->getX() << point1->getY() << point1->getZ() << endl;

	point1->move(*point2);
	cout << point1->getX() << point1->getY() << point1->getZ() << endl;

	point2->move(3.0, 3.0, 3.0);


	return 0;
}


