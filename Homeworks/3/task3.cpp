/**
*  
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Ivan Penev
* @idnumber 62535
* @task 3
* @compiler GCC
*
*/

#include <iostream>

const unsigned MAX_SIZE = 100;

void readSize(int &N) {
    do {
        std::cin >> N;
    } while (1 >= N || N >= 1000);
}

void readMatrix(double matrix[MAX_SIZE][MAX_SIZE], const int N) {
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            double inputNumber;
            do {
                std::cin >> inputNumber;
            } while (inputNumber < 0 || inputNumber > 100);
            matrix[row][col] = inputNumber;
        }
    }
}


bool isMagicSquare(double matrix[MAX_SIZE][MAX_SIZE], const int N) {
    double magicSum;

    double mainDiagSum = 0, secondDiagSum = 0;
    for (int i = 0; i < N; ++i) {
        mainDiagSum += matrix[i][i];
        secondDiagSum += matrix[i][N - 1 - i];
    }

    if (mainDiagSum != secondDiagSum) {
        return false;
    }

    magicSum = mainDiagSum;

    for (int i = 0; i < N; ++i) {
        double rowSum = 0, colSum = 0;
        for (int j = 0; j < N; ++j) {
            rowSum += matrix[i][j];
            colSum += matrix[j][i];
        }
        bool checkEqual = (rowSum == magicSum) && (colSum == magicSum);
        if (!checkEqual) {
            return false;
        }
    }

    return true;
}

int main() {
    int N;
    readSize(N);
    double matrix[MAX_SIZE][MAX_SIZE];
    readMatrix(matrix, N);

    bool result = isMagicSquare(matrix, N);
    std::cout << (result ? "true" : "false") << std::endl;
    return 0;
}