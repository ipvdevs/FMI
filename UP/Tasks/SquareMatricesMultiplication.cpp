//Multiply two given two square matrices with size NxN

#include <iostream>

int readSize() {
    int N;
    do {
        std::cin >> N;
    } while (N <= 0 || N >= 100);

    return N;
}

int **readMatrix(int size) {
    int **matrix = new int *[size];

    for (int row = 0; row < size; ++row) {
        matrix[row] = new int[size];
        for (int col = 0; col < size; ++col) {
            std::cin >> matrix[row][col];
        }
    }

    return matrix;
}

void printMatrix(int **ProductMatrix, int N) {
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            std::cout << ProductMatrix[row][col] << ' ';
        }
        std::cout << std::endl;
    }
}

int calcProductElement(int **A, int **B, int size, int row, int col) {
    int result = 0;
    for (int k = 0; k < size; ++k) {
        result += A[row][k] * B[k][col];
    }
    return result;
}

int **matrixMultiplication(int **A, int **B, int size) {
    int **product = new int *[size];

    for (int row = 0; row < size; ++row) {
        product[row] = new int[size];
    }


    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            int productElement = calcProductElement(A, B, size, row, col);
            product[row][col] = productElement;
        }
    }

    return product;
}

int main() {
    int N = readSize();

    int **A = readMatrix(N);
    int **B = readMatrix(N);

    int **ProductMatrix = matrixMultiplication(A, B, N);

    printMatrix(ProductMatrix, N);

    for (int row = 0; row < N; ++row) {
        delete[] A[row];
        delete[] B[row];
        delete[] ProductMatrix[row];
    }

    delete[] A;
    delete[] B;
    delete[] ProductMatrix;

    return 0;
}
