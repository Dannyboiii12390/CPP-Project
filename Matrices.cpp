//Matrices.h

#pragma once

#include "Vectors.h"
#include "Matrices.h"
#include <cmath>
#include <sstream>
#include <iostream>
#include <string>


namespace CPPCustomLibrary
{
    int Matrix::RowsToColumns(int pRow, int pColumn)
    {
        return pRow * 4 + pColumn;
    }
   
    Matrix::Matrix(
        double pRow0Column0, double pRow0Column1, double pRow0Column2, double pRow0Column3,
        double pRow1Column0, double pRow1Column1, double pRow1Column2, double pRow1Column3,
        double pRow2Column0, double pRow2Column1, double pRow2Column2, double pRow2Column3,
        double pRow3Column0, double pRow3Column1, double pRow3Column2, double pRow3Column3)

    {
        matrix[0] = pRow0Column0;
        matrix[1] = pRow0Column1;
        matrix[2] = pRow0Column2;
        matrix[3] = pRow0Column3;

        matrix[4] = pRow1Column0;
        matrix[5] = pRow1Column1;
        matrix[6] = pRow1Column2;
        matrix[7] = pRow1Column3;

        matrix[8] = pRow2Column0;
        matrix[9] = pRow2Column1;
        matrix[10] = pRow2Column2;
        matrix[11] = pRow2Column3;

        matrix[12] = pRow3Column0;
        matrix[13] = pRow3Column1;
        matrix[14] = pRow3Column2;
        matrix[15] = pRow3Column3;
    }

    double Matrix::GetElement(int pRow, int pColumn)
    {
        return matrix[RowsToColumns(pRow, pColumn)];
    }

    void Matrix::SetElement(int pRow, int pColumn, double pValue)
    {
        matrix[RowsToColumns(pRow, pColumn)] = pValue;
    }

    Vector Matrix::Multiply(Vector pVector)
    {

        double x = GetElement(0, 0) * pVector.x + GetElement(0, 1) * pVector.y + GetElement(0, 2) * pVector.z + GetElement(0, 3) * pVector.w;
        double y = GetElement(1, 0) * pVector.x + GetElement(1, 1) * pVector.y + GetElement(1, 2) * pVector.z + GetElement(1, 3) * pVector.w;
        double z = GetElement(2, 0) * pVector.x + GetElement(2, 1) * pVector.y + GetElement(2, 2) * pVector.z + GetElement(2, 3) * pVector.w;
        double w = GetElement(3, 0) * pVector.x + GetElement(3, 1) * pVector.y + GetElement(3, 2) * pVector.z + GetElement(3, 3) * pVector.w;
        Vector v = Vector(x, y, z);

        return v;
    }

    Matrix Matrix::Multiply(Matrix pMyMatrix)
    {

        Matrix result = CreateIdentity();

        for (int rowIndex = 0; rowIndex < 4; rowIndex++)
        {
            Vector row = GetRow(rowIndex);

            for (int colIndex = 0; colIndex < 4; colIndex++)
            {
                Vector col = pMyMatrix.GetColumn(colIndex);

                double value = row.Multiply(col);

                result.SetElement(rowIndex, colIndex, value);

            }

        }

        return result;
    }


    Vector Matrix::GetRow(int pRow)
    {
        double x = GetElement(pRow, 0);
        double y = GetElement(pRow, 1);
        double z = GetElement(pRow, 2);
        double w = GetElement(pRow, 3);



        return Vector(x, y, z);
    }
    Vector Matrix::GetColumn(int pColumn)
    {
        double x = GetElement(0, pColumn);
        double y = GetElement(1, pColumn);
        double z = GetElement(2, pColumn);
        double w = GetElement(3, pColumn);

        return Vector(x, y, z);
    }

    string Matrix::ToString()
    {
        stringstream ss;

        ss << GetElement(0, 0) << " " << GetElement(0, 1) << " " << GetElement(0, 2) << " " << GetElement(0, 3) << "\n" <<
            GetElement(1, 0) << " " << GetElement(1, 1) << " " << GetElement(1, 2) << " " << GetElement(1, 3) << "\n" <<
            GetElement(2, 0) << " " << GetElement(2, 1) << " " << GetElement(2, 2) << " " << GetElement(2, 3) << "\n" <<
            GetElement(3, 0) << " " << GetElement(3, 1) << " " << GetElement(3, 2) << " " << GetElement(3, 3) << "\n";
        return ss.str();
    }

};


