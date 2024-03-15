//Matrices.h

#pragma once

#include "Vectors.h"
#include <cmath>
#include <sstream>
#include <string>
#include <iostream>

namespace CPPCustomLibrary
{
    class Matrix
    {
        //Variables
    private:
        double matrix[16] = { 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0 };

        //methods
    private:
        int RowsToColumns(int pRow, int pColumn);

    public:
        Matrix(
            double pRow0Column0, double pRow0Column1, double pRow0Column2, double pRow0Column3,
            double pRow1Column0, double pRow1Column1, double pRow1Column2, double pRow1Column3,
            double pRow2Column0, double pRow2Column1, double pRow2Column2, double pRow2Column3,
            double pRow3Column0, double pRow3Column1, double pRow3Column2, double pRow3Column3);

        double GetElement(int pRow, int pColumn);
        void SetElement(int pRow, int pColumn, double pValue);

        static Matrix CreateIdentity()
        {
            Matrix Mat = Matrix(
                1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1);

            return Mat;
        }
        static Matrix CreateTranslation(Vector pTranslation)
        {
            Matrix eye = CreateIdentity();
            eye.SetElement(0, 3, pTranslation.x);
            eye.SetElement(1, 3, pTranslation.y);
            eye.SetElement(2, 3, pTranslation.z);
            return eye;
        }
        static Matrix CreateScale(Vector pScale)
        {
            Matrix m1 = Matrix(
                pScale.x, 0, 0, 0,
                0, pScale.y, 0, 0,
                0, 0, pScale.z, 0,
                0, 0, 0, 1);

            return m1;
        }
        static Matrix CreateRotationX(double pAngle)
        {
            Matrix rotation = Matrix(
                1, 0, 0, 0,
                0, (double)cos(pAngle), (double)-sin(pAngle), 0,
                0, (double)sin(pAngle), (double)cos(pAngle), 0,
                0, 0, 0, 1

            );
            return rotation;
        }
        static Matrix CreateRotationY(double pAngle)
        {
            Matrix rotation = Matrix(
                (double)cos(pAngle), 0, (double)sin(pAngle), 0,
                0, 1, 0, 0,
                (double)-sin(pAngle), 0, (double)cos(pAngle), 0,
                0, 0, 0, 1);

            return rotation;
        }
        static Matrix CreateRotationZ(double pAngle)
        {
            Matrix rotation = Matrix(
                (double)cos(pAngle), (double)-sin(pAngle), 0, 0,
                (double)sin(pAngle), (double)cos(pAngle), 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1);

            return rotation;
        }

        Vector Multiply(Vector pVector);
        Matrix Multiply(Matrix pMyMatrix);
        Vector GetRow(int pRow);
        Vector GetColumn(int pColumn);
        string ToString();

    };
}

