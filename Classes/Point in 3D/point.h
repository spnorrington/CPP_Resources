#ifndef POINT_H
#define POINT_H

class Point {
private:
  double x;
  double y;
  double z;

public:
  Point();
  Point(double newX, double newY, double newZ);
  void setCoordinates(double x, double y, double z);
  void move(double offsetX, double offsetY, double offsetZ);
  void move(Point* offset);
  double getX() const;
  double getY() const;
  double getZ() const;
};

#endif
