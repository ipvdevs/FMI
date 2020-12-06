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

//Find the sum of all elements above the main diagonal (including)
double findSumAboveDiag(double matrix[][MAX_SIZE], const int k) {
    double sum = 0;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            if (i >= j) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

int main() {
    int k;
    double matrix[MAX_SIZE][MAX_SIZE];
    readSize(k);
    readMatrix(matrix, k);
    double result = findSumAboveDiag(matrix, k);
    std::cout << result << std::endl;
    return 0;
}