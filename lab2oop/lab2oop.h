#ifndef MYMATRIX_H
#define MYMATRIX_H

#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cmath>

class MyMatrix 
{
private:
    std::vector<std::vector<double>> m_matrix;
    mutable double cachedDeterminant = NAN;
    mutable bool determinantCached = false;

    std::vector<std::vector<double>> GetTransponedArray() const;
    void makeJaggedArrayNormal(std::vector<std::vector<double>>& jaggedArray);
    std::vector<std::vector<double>> turnStringArrayIntoNormal(const std::vector<std::string>& array);
    std::vector<std::vector<double>> turnStringArrayIntoNormal(const std::string& array);

public:
    MyMatrix(const MyMatrix& someMatrix);
    MyMatrix(const std::vector<std::vector<double>>& Array);
    MyMatrix(std::vector<std::vector<double>>& jaggedArray);
    MyMatrix(const std::vector<std::string>& stringArray);
    MyMatrix(const std::string& stringArray);

    MyMatrix getMatrix() const;
    int getHeight() const;
    int getWidth() const;
    std::string toString() const;
    friend MyMatrix operator+(const MyMatrix& array1, const MyMatrix& array2);
    friend MyMatrix operator*(const MyMatrix& array1, const MyMatrix& array2);
    std::vector<double>& operator[](int row);
    const std::vector<double>& operator[](int row) const;
    MyMatrix GetTransponedCopy() const;
    void TransponeMe();
    double CalcDeterminant() const;
};

std::ostream& operator<<(std::ostream& os, const MyMatrix& matrix);

#endif // MYMATRIX_H
