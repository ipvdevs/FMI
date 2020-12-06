#include <iostream>

const int MAX_SIZE = 100;

//Reading size of matrix (kxk) with simple validation
void readSize(int &k) {
    do {
        std::cout << "Enter size kxk, k=";
        std::cin >> k;
    } while (k < 0 || k > MAX_SIZE);
}

//Reading a matrix
void readMatrix(double matrix[][MAX_SIZE], const int k) {
    for (int i = 0; i < k; ++i) {
        std::cout << "Enter elements for row " << i + 1 << std::endl;
        for (int j = 0; j < k; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

//Printing all negative elements on the diagonal of a matrix kxk.
void findDiagonalNegatives(double matrix[][MAX_SIZE], const int k) {
    for (int i = 0; i < k; ++i) {
        if (matrix[i][i] < 0) {
            std::cout << matrix[i][i] << std::endl;
        }
    }
}

int main() {
    int k;
    double matrix[MAX_SIZE][MAX_SIZE];
    readSize(k);
    readMatrix(matrix, k);
    findDiagonalNegatives(matrix, k);
    return 0;
}