#include <iostream>
#include "lab2oop.h"
#include <string>
#include <vector>
#include <sstream>

MyMatrix createMatrix();
MyMatrix copyOfMatrix(MyMatrix someMatrix);

int main() 
{
    bool shouldIContinue = false;
    do 
    {
        std::cout << "Enter data for 1 matrix:\n\n";
        MyMatrix matrix1 = createMatrix();
        std::cout << "Enter data for 2 matrix:\n\n";
//        MyMatrix matrix2 = copyOfMatrix(matrix1);
        MyMatrix matrix2(matrix1);
        std::cout << "Determinant of 1 matrix:" << matrix1.CalcDeterminant() << std::endl;
        std::cout << "Determinant of 1 matrix:" << matrix1.CalcDeterminant() << std::endl;
        matrix1.setElement(0, 1, 3.5);
        std::cout << "Determinant of 1 matrix:" << matrix1.CalcDeterminant() << std::endl;
        MyMatrix sumMatrix = matrix1 + matrix2;
        MyMatrix productMatrix = matrix1 * matrix2;

        std::cout << "Matrix 1:\n" << matrix1;
        std::cout << "Matrix 2:\n" << matrix2;
        std::cout << "Sum Matrix:\n" << sumMatrix;
        std::cout << "Product Matrix:\n" << productMatrix;

        sumMatrix = matrix1 + matrix2;
        productMatrix = matrix1 * matrix2;

        std::cout << "Matrix 1:\n" << matrix1;
        std::cout << "Matrix 2:\n" << matrix2;
        std::cout << "Sum Matrix:\n" << sumMatrix;
        std::cout << "Product Matrix:\n" << productMatrix;

        MyMatrix transposedMatrix = matrix1.GetTransponedCopy();
        std::cout << "Transposed first Matrix:\n" << transposedMatrix;
        matrix2.TransponeMe();
        std::cout << "Transposed second Matrix (in-place):\n" << matrix2;
        std::cout <<"Determinant of 1 matrix:" <<matrix1.CalcDeterminant() << std::endl;
        std::cout << "Determinant of 2 matrix:" << matrix2.CalcDeterminant() << std::endl;
        std::cout << "Should we continue with another matrixes?\n";
        std::string choiceForContinue;
        std::cin >> choiceForContinue;
        if (choiceForContinue == "yes") shouldIContinue = true;
        else break;
    } while (shouldIContinue);
    return 0;
}
MyMatrix createMatrix()
{
    std::cout << R"(How you want to initialize matrix:
1. Enter using normal array;
2. Enter using jagged array;
3. Enter using string array;
4. Enter using string.)"<<std::endl;
    int choiceForInitialization;
    std::cin >> choiceForInitialization;
    switch (choiceForInitialization) 
    {
    case 1: 
    {
        int rows, cols;
        std::cout << "Enter the number of rows and cols: ";
        std::cin >> rows >> cols;
        std::vector<std::vector<double>> normalDoubleArray(rows, std::vector<double>(cols));
        std::cout << "Enter the elements of the matrix:\n";
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                std::cin >> normalDoubleArray[i][j];
            }
        }
        return MyMatrix(normalDoubleArray);
    }
    case 2:
    {
        int rows;
        std::cout << "Enter the number of rows: ";
        std::cin >> rows;
        std::cin.ignore(); 
        std::vector<std::vector<double>> jaggedArray(rows);
        std::cout << "Enter the elements of jagged array separated by spaces:\n";
        for (int i = 0; i < rows; ++i)
        {
            std::string rowInput;
            std::getline(std::cin, rowInput);
            std::stringstream ss(rowInput);
            double value;
            while (ss >> value) 
            {
                jaggedArray[i].push_back(value);
            }
        }
        return MyMatrix(jaggedArray);
    }
    case 3: 
    {
        std::string input;
        std::cout << "Enter the matrix as a string array (rows separated by comas, elements by spaces): \n";
        std::cin.ignore();
        std::getline(std::cin, input);
        std::istringstream iss(input);
        std::string row;
        std::vector<std::vector<double>> stringArray;
        while (std::getline(iss, row, ','))
        {
            std::istringstream rowStream(row);
            std::vector<double> rowVector;
            double value;
            while (rowStream >> value) 
            {
                rowVector.push_back(value);
            }
            stringArray.push_back(rowVector);
        }
        return MyMatrix(stringArray);
    }
    case 4:
    {
        std::cout << "Enter number of rows and cols: ";
        int rows, cols;
        std::cin >> rows >> cols;
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::vector<std::vector<double>> stringArray(rows, std::vector<double>(cols));
        std::cout << "Enter the matrix as one string:\n";
        std::string input;
        std::getline(std::cin, input);
        std::istringstream ss(input);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                double value;
                ss >> value;
                stringArray[i][j] = value;
            }
        }
        return MyMatrix(stringArray);
    }
    default:
        throw std::invalid_argument("Invalid choice. Defaulting to normal array initialization.\n");
        std::vector<std::vector<double>> defaultArray = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
        return MyMatrix(defaultArray);
    }
}
MyMatrix copyOfMatrix(MyMatrix someMatrix)
{
    return someMatrix.getMatrix();
}