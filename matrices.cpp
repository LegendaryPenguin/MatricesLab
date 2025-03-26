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
            }
        }
    }
}

