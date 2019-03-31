#ifndef _SHAPE_H_
#define _SHAPE_H_

#include<iostream>
#include<string>
using namespace std;

class Shape
{
private:
	int Id;
	int X;
	int Y;
	int Radius;
	double Area;

public:
	Shape() {}
	Shape(int ID, int X, int Y, int Radius);
	~Shape() {}

	int getId() {return Id;}
	int getX() { return X;}
	int getY() { return Y;}
	int getRadius() { return Radius;}
	double getArea() { return Area;}
};


#endif