/*
Name: Nischay Rawal
Lab: Software Engineering Lab 08
Date: 03/26/2025
Last Modified: 03/26/2025
Program Description: This program performs basic matrix operations using data from a user-specified file. 
The file starts with an integer N, representing the size of two N × N matrices. The program reads these matrices, 
then allows the user to add, multiply, and calculate the sum of their diagonals. It also supports swapping rows or 
columns and updating individual elements. The results are displayed in a formatted way which makes it easy to work with and manipulate matrices.
*/
#include <iostream>   // This line includes the iostream library for input and output operations
#include <fstream>    // This line includes the fstream library to handle file input/output
#include <vector>     // This line includes the vector library to use vectors (dynamic arrays) in the program
#include <iomanip>    // This line includes the iomanip library for controlling input/output formatting

using namespace std;  // This line allows the program to use standard C++ functions and objects without needing to prefix them with "std::"


// This function reads a matrix from a file
// This function loads the matrices and prints them
void readMatrixFromFile(const string& filename, vector<vector<int>>& matrixA, vector<vector<int>>& matrixB, int& N) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file!" << endl;
        exit(1);
    }

    file >> N;
    matrixA.resize(N, vector<int>(N));
    matrixB.resize(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            file >> matrixA[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            file >> matrixB[i][j];
        }
    }

    file.close();
}

// This function prints a matrix with formatted output
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << setw(5) << val;
        }
        cout << endl;
    }
}

// This function adds two matrices and prints the result
void addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& result, int N) {
    result.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// This function multiplies two matrices and prints the result
void multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& result, int N) {
    result.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                result[i][j] += A[i][k] * B[k][j];
                // cout << A[i][k] * B[k][j] <<endl;
            }
            // exit(0);
        }
    }
}

// This function calculates and prints the sum of diagonal elements
void sumDiagonals(const vector<vector<int>>& matrix, int N) {
    int mainDiagonal = 0, secondaryDiagonal = 0;
    for (int i = 0; i < N; ++i) {
        mainDiagonal += matrix[i][i];
        secondaryDiagonal += matrix[i][N - i - 1];
    }
    cout << "Main diagonal sum: " << mainDiagonal << endl;
    cout << "Secondary diagonal sum: " << secondaryDiagonal << endl;
}

// This function swaps two rows in a matrix and prints the result
void swapRows(vector<vector<int>>& matrix, int row1, int row2, int N) {
    if (row1 >= 0 && row1 < N && row2 >= 0 && row2 < N) {
        swap(matrix[row1], matrix[row2]);
    }
}

// This function swaps two columns in a matrix and prints the result
void swapColumns(vector<vector<int>>& matrix, int col1, int col2, int N) {
    if (col1 >= 0 && col1 < N && col2 >= 0 && col2 < N) {
        for (int i = 0; i < N; ++i) {
            swap(matrix[i][col1], matrix[i][col2]);
        }
    }
}

// This function updates a specific element in the matrix and prints the result
void updateElement(vector<vector<int>>& matrix, int row, int col, int newValue, int N) {
    if (row >= 0 && row < N && col >= 0 && col < N) {
        matrix[row][col] = newValue;
    }
}

void clean_results(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            matrix[i][j]=0;
        }
    }
}

int main() {
    vector<vector<int>> matrixA, matrixB, result;
    int N;
    
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;
    
    readMatrixFromFile(filename, matrixA, matrixB, N);
    
    cout << "Matrix A:" << endl;
    printMatrix(matrixA);
    
    cout << "Matrix B:" << endl;
    printMatrix(matrixB);
    
    addMatrices(matrixA, matrixB, result, N);
    cout << "Matrix Addition Result:" << endl;
    printMatrix(result);
    clean_results(result);
    
    multiplyMatrices(matrixA, matrixB, result, N);
    cout << "Matrix Multiplication Result:" << endl;
    printMatrix(result);
    clean_results(result);

    sumDiagonals(matrixA, N);
    clean_results(result);
    
    swapRows(matrixA, 0, 1, N);
    cout << "Matrix A after swapping row 0 and row 1:" << endl;
    printMatrix(matrixA);
    clean_results(result);

    swapColumns(matrixA, 0, 1, N);
    cout << "Matrix A after swapping column 0 and column 1:" << endl;
    printMatrix(matrixA);
    clean_results(result);

    updateElement(matrixA, 0, 0, 99, N);
    cout << "Matrix A after updating element (0,0) to 99:" << endl;
    printMatrix(matrixA);
    
    return 0;
}