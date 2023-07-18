//This code is apart of the Assignment 3: Problem 1 Project
//Please see assignment3.cpp in this folder for additional information.
// 
//-------------Header File-----------------//

#ifndef POINT_H
#define POINT_H

class Point
{
private:
	double x;
	double y;
	double z;

public:
	Point() : x(0), y(0), z(0) {}
	Point(double newX, double newY, double newZ) : x(newX), y(newY), z(newZ) {}

	void setCoordinates(double newX, double newY, double newZ);
	void move(double offsetX, double offsetY, double offsetZ);
	void move(Point offset);
	double getX() const;
	double getY() const;
	double getZ() const;

	// Declarations of Spherical Coordinate Functions
	double radius(double x, double y, double z);
	double theta(double x, double y);
	double rho(double x, double y, double z);
};

#endif