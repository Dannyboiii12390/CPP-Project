// Vectors.h
#include <cmath>
#include <iostream>
#include <sstream>
#include "Vectors.h"

#pragma once

using namespace std;

Vector::Vector(double pX, double pY, double pZ)
{
	X = pX;
	Y = pY;
	Z = pZ;
	W = 0;
}	

double Vector::GetX()
{
	return X;
}
double Vector::GetY()
{
	return Y;
}
double Vector::GetZ()
{
	return Z;
}
double Vector::GetW()
{
	return W;
}

double Vector::Multiply(Vector pV)
{
	double x = X * pV.X;
	double y = Y * pV.Y;
	double z = Z * pV.Z;

	return x + y + z;
}
Vector Vector::Copy()
{
	return Vector(X, Y, Z);
}
Vector Vector::Add(Vector pV)
{
	return Vector(X + pV.X, Y + pV.Y, Z + pV.Z);
}
Vector Vector::Subtract(Vector pV)
{
	return Vector(X - pV.X, Y - pV.Y, Z - pV.Z);
}
Vector Vector::Multiply(double pScalar)
{
	return Vector(X * pScalar, Y * pScalar, Z * pScalar);
}
Vector Vector::Divide(double pScalar)
{
	//divide by zero error
	if (abs(pScalar - 0.0) < DBL_EPSILON)
	{
		return Copy();
	}
	return Multiply(1 / pScalar);
}
double Vector::Magnitude()
{
	double Xsqu = X * X;
	double Ysqu = Y * Y;
	double Zsqu = Z * Z;
	double tot = Xsqu + Ysqu + Zsqu;

	return (double)sqrt(tot);
}
Vector Vector::Normalise()
{
	double Mag = Magnitude();
	double Xunit = X / Mag;
	double Yunit = Y / Mag;
	double Zunit = Z / Mag;

	return Vector(Xunit, Yunit, Zunit);
}
double Vector::DotProduct(Vector pV)
{
	double XDot = X * pV.X;
	double YDot = Y * pV.Y;
	double ZDot = Z * pV.Z;

	double DotTot = XDot + YDot + ZDot;

	return DotTot;
}
Vector Vector::RotateX(double Radians)
{
	double pRadians = (double)Radians;
	double yDash = (double)(-sin(pRadians) * Z + cos(pRadians) * Y);
	double zDash = (double)(sin(pRadians) * Y + cos(pRadians) * Z);

	return Vector(X, yDash, zDash);
}
Vector Vector::RotateY(double Radians)
{
	double pRadians = (double)Radians;
	double xDash = (double)cos(pRadians) * X + (double)sin(pRadians) * Z;
	double zDash = (double)-sin(pRadians) * X + (double)cos(pRadians) * Z;

	return Vector(xDash, Y, zDash);
}
Vector Vector::RotateZ(double Radians)
{
	double pRadians = (double)Radians;
	double xDash = (double)(cos(pRadians) * X + (double)-sin(pRadians) * Y);
	double yDash = (double)(sin(pRadians) * X + (double)cos(pRadians) * Y);

	return Vector(xDash, yDash, Z);
}
Vector Vector::LimitTo(double pMax)
{
	Vector v = Vector(0, 0, 0);
	if (Magnitude() >= pMax)
	{
		Vector vUnit = Normalise();

		v = vUnit.Copy();
		v = v.Multiply(pMax);
	}
	else
	{
		v = Copy();
	}

	return v;
}
Vector Vector::Interpolate(Vector pMyVector, double pInterpolation)
{
	double interpolatedX = X + (pMyVector.X - X) * pInterpolation;
	double interpolatedY = Y + (pMyVector.Y - Y) * pInterpolation;
	double interpolatedZ = Z + (pMyVector.Z - Z) * pInterpolation;

	// Create a new MyVector object with the interpolated values
	Vector interpolatedMyVector = Vector(interpolatedX, interpolatedY, interpolatedZ);

	return interpolatedMyVector;

}
double Vector::AngleBetween(Vector pMyVector)
{
	double dot = DotProduct(pMyVector);
	double Amag = Magnitude();
	double Bmag = pMyVector.Magnitude();

	double theta = (double)acos(dot / (Amag * Bmag));

	return theta;
}
Vector Vector::CrossProduct(Vector pMyVector)
{

	double resultX = (Y * pMyVector.Z) - (Z * pMyVector.Y);
	double resultY = (Z * pMyVector.X) - (X * pMyVector.Z);
	double resultZ = (X * pMyVector.Y) - (Y * pMyVector.X);

	// Create a new MyVector3D object with the cross product result
	Vector crossProduct = Vector(resultX, resultY, resultZ);

	return crossProduct;

}
string Vector::ToString()
{
	stringstream ss;
	ss << "X: " << X << " " << "Y: " << Y << " " << "Z: " << Z;
	return ss.str();
}
double Vector::GetElement(int x)
{
	switch (x)
	{
	case 0:
		return X;
	case 1:
		return Y;
	case 2:
		return Z;
	default:
		throw overflow_error("Index Out of Range Error");
	}
}


