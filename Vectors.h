// Vectors.h
#include <cmath>
#include <iostream>
#include <sstream>

#pragma once

using namespace std;

class Vector
{
private:
	double X;
	double Y;
	double Z;
	double W;

public:
	Vector(double pX, double pY, double pZ);

	__declspec(property(get = GetX)) double x;
	__declspec(property(get = GetY)) double y;
	__declspec(property(get = GetZ)) double z;
	__declspec(property(get = GetW)) double w;

	double GetX();
	double GetY();
	double GetZ();
	double GetW();

	double Multiply(Vector pV);
	Vector Copy();
	Vector Add(Vector pV);
	Vector Subtract(Vector pV);
	Vector Multiply(double pScalar);
	Vector Divide(double pScalar);
	double Magnitude();
	Vector Normalise();
	double DotProduct(Vector pV);
	Vector RotateX(double Radians);
	Vector RotateY(double Radians);
	Vector RotateZ(double Radians);
	Vector LimitTo(double pMax);
	Vector Interpolate(Vector pMyVector, double pInterpolation);
	double AngleBetween(Vector pMyVector);
	Vector CrossProduct(Vector pMyVector);
	string ToString();
	double GetElement(int x);
};

