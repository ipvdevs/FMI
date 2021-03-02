//Да се напише функция на С++,
//която приема като параметри параметри цяло число N
//и двумерна числова квадратна матрица А с размери NxN и
//връща като резултат транспонираната матрица на А.
#include <iostream>

double **transposeMatrix(double **matrix, const int N) {
    auto **transposedMatrix = new double *[N];

    for (int row = 0; row < N; ++row) {
        transposedMatrix[row] = new double[N];
    }

    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            transposedMatrix[row][col] = matrix[col][row];
        }
    }

    return transposedMatrix;
}

int main() {
    //Read and validate matrix size
    int N;
    do {
        std::cin >> N;
    } while (N <= 0);

    auto **matrix = new double *[N];

    //Allocate memory and fill the matrix
    for (int row = 0; row < N; ++row) {
        matrix[row] = new double[N];
        for (int col = 0; col < N; ++col) {
            std::cin >> matrix[row][col];
        }
    }

    //Print Matrix
    std::cout << "Matrix: " << std::endl;
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            std::cout << matrix[row][col] << ' ';
        }
        std::cout << std::endl;
    }

    double **transposedMatrix = transposeMatrix(matrix, N);
    std::cout << "Transpose: " << std::endl;

    //Print transpose matrix
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            std::cout << transposedMatrix[row][col] << ' ';
        }
        std::cout << std::endl;
    }


    //Delete the allocated memory
    for (int row = 0; row < N; ++row) {
        delete[] matrix[row];
        delete[] transposedMatrix[row];
    }

    delete[] matrix;
    delete[] transposedMatrix;
    return 0;
}