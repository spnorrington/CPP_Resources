#include "Point.h"

void Point::setCoordinates(double newX, double newY, double newZ)
{
  x = newX;
  y = newY;
  z = newZ;
}

void Point::move(double offsetX, double offsetY, double offsetZ)
{
  x += offsetX;
  y += offsetY;
  z += offsetZ;
}

void Point::move(Point* offset)
{
  x += offset->x;
  y += offset->y;
  z += offset->z;
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
