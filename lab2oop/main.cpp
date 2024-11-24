#include <iostream>
#include "lab2oop.h"
#include <string>

int main() {
    std::vector<std::vector<double>> array1 = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    std::vector<std::vector<double>> array2 = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };

    MyMatrix matrix1(array1);
    MyMatrix matrix2(array2);

    MyMatrix sumMatrix = matrix1 + matrix2;
    MyMatrix productMatrix = matrix1 * matrix2;

    std::cout << "Matrix 1:\n" << matrix1;
    std::cout << "Matrix 2:\n" << matrix2;
    std::cout << "Sum Matrix:\n" << sumMatrix;
    std::cout << "Product Matrix:\n" << productMatrix;

    MyMatrix transposedMatrix = matrix1.GetTransponedCopy();
    std::cout << "Transposed Matrix:\n" << transposedMatrix;
    matrix1.TransponeMe();
    std::cout << "Transposed Matrix (in-place):\n" << matrix1;

    return 0;
}
