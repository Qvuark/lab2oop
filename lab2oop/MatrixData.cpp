#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include "lab2oop.h"


MyMatrix::MyMatrix(const MyMatrix& someMatrix) 
{
    m_matrix = someMatrix.m_matrix;
}
MyMatrix::MyMatrix(const std::vector<std::vector<double>>& Array) 
{
    m_matrix = Array;
}
MyMatrix::MyMatrix(std::vector<std::vector<double>>& jaggedArray) 
{
    makeJaggedArrayNormal(jaggedArray);
    m_matrix = jaggedArray;
}
MyMatrix::MyMatrix(const std::vector<std::string>& stringArray) 
{
    std::vector<std::vector<double>> tempArray = turnStringArrayIntoNormal(stringArray);
    m_matrix = tempArray;
}
MyMatrix::MyMatrix(const std::string& stringArray) 
{
    std::vector<std::vector<double>> tempArray = turnStringArrayIntoNormal(stringArray);
    m_matrix = tempArray;
}
MyMatrix MyMatrix::getMatrix() const
{
    return m_matrix;
}
int MyMatrix::getHeight() const 
{
    return m_matrix.size();
}
int MyMatrix::getWidth() const 
{
    return m_matrix[0].size();
}
std::vector<double>& MyMatrix::operator[](int row) 
{
    determinantCached = false;
    if (row < 0 || row >= getHeight()) 
    {
        throw std::out_of_range("Row index out of range");
    }
    return m_matrix[row];
}

const std::vector<double>& MyMatrix::operator[](int row) const
{
    if (row < 0 || row >= getHeight()) 
    {
        throw std::out_of_range("Row index out of range");
    }
    return m_matrix[row];
}
std::string MyMatrix::toString() const 
{
    std::ostringstream oss;
    for (const auto& row : m_matrix) 
    {
        for (const auto& elem : row) 
        {
            oss << elem << "\t";
        }
        oss << "\n";
    }
    return oss.str();
}
std::vector<std::vector<double>> MyMatrix::turnStringArrayIntoNormal(const std::vector<std::string>& array) 
{
    std::vector<std::vector<double>> doubleArray;
    for (const auto& line : array) 
    {
        std::vector<double> row;
        std::istringstream stream(line);
        double number;
        while (stream >> number) 
        {
            row.push_back(number);
        }
        doubleArray.push_back(row);
    }
    return doubleArray;
}
std::vector<std::vector<double>> MyMatrix::turnStringArrayIntoNormal(const std::string& array) 
{
    std::vector<std::vector<double>> doubleArray;
    std::istringstream lineStream(array);
    std::string line;
    while (std::getline(lineStream, line)) 
    {
        if (line.empty()) continue;
        std::vector<double> row;
        std::istringstream rowStream(line);
        double number;
        while (rowStream >> number) 
        {
            row.push_back(number);
        }
        doubleArray.push_back(row);
    }
    return doubleArray;
}
void MyMatrix::makeJaggedArrayNormal(std::vector<std::vector<double>>& jaggedArray) 
{
    int sizeOfArray = 0;
    for (const auto& rows : jaggedArray) 
    {
        sizeOfArray += rows.size();
    }
    if (sizeOfArray % jaggedArray.size() == 0) 
    {
        int cols = sizeOfArray / jaggedArray.size();
        std::vector<double> tempArray;
        for (int i = 0; i < jaggedArray.size(); ++i) 
        {
            for (int j = 0; j < jaggedArray[i].size(); ++j) 
            {
                tempArray.push_back(jaggedArray[i][j]);
            }
        }
        int index = 0;
        for (int i = 0; i < jaggedArray.size(); ++i) 
        {
            jaggedArray[i].resize(cols);
            for (int j = 0; j < cols; ++j) 
            {
                jaggedArray[i][j] = tempArray[index++];
            }
        }
    }
    else 
    {
        throw std::invalid_argument("The jagged array can't be transformed into a normal one");
    }
}
std::ostream& operator<<(std::ostream& os, const MyMatrix& matrix) 
{
    os << matrix.toString();
    return os;
}
