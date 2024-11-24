#include <iostream>
#include "lab2oop.h"
#include <vector>

MyMatrix operator+(const MyMatrix& array1, const MyMatrix& array2)
{
    if (array1.getHeight() != array2.getHeight() && array1.getWidth() != array2.getWidth())
    {
        throw std::invalid_argument("Matrices are not the same size");
    }
    std::vector<std::vector<double>> result(array1.getHeight(), std::vector<double>(array1.getWidth()));
    for (int i = 0; i < array1.getHeight(); ++i)
    {
        for (int j = 0; j < array1.getWidth(); ++j)
        {
            result[i][j] = array1[i][j] + array2[i][j];
        }
    }
    return MyMatrix(result);
}
MyMatrix operator*(const MyMatrix& array1, const MyMatrix& array2)
{
    if (array1.getHeight() != array2.getHeight() && array1.getWidth() != array2.getWidth())
    {
        throw std::invalid_argument("The number of columns in the first matrix must equal the number of rows in the second matrix.");
    }
    std::vector<std::vector<double>> result(array1.getHeight(), std::vector<double>(array2.getWidth()));
    for (int i = 0; i < array1.getHeight(); ++i)
    {
        for (int j = 0; j < array2.getWidth(); ++j)
        {
            for (int k = 0; k < array1.getWidth(); ++k)
            {
                result[i][j] += array1[i][k] * array2[k][j];
            }
        }
    }
    return MyMatrix(result);
}
std::vector<std::vector<double>> MyMatrix::GetTransponedArray() const
{
    std::vector<std::vector<double>> result(getWidth(), std::vector<double>(getHeight()));
    for (int i = 0; i < getHeight(); ++i)
    {
        for (int j = 0; j < getWidth(); ++j)
        {
            result[j][i] = m_matrix[i][j];
        }
    }
    return result;
}

MyMatrix MyMatrix::GetTransponedCopy() const
{
    return MyMatrix(GetTransponedArray());
}

void MyMatrix::TransponeMe()
{
    m_matrix = GetTransponedArray();
}

