#include "Shape.h"

const double PI = 3.14;

Shape::	Shape(int Id, int X, int Y, int Radius)
{
	this->Id = Id; 
	this->X = X;
	this->Y = Y;
	this->Radius = Radius;
	this->Area = Radius*Radius*PI;
}