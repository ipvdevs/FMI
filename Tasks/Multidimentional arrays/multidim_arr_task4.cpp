#include <iostream>

const int MAX_SIZE = 100;

//Reading size of matrix (mxn) with simple validation
void readSize(int &m, int &n) {
    do {
        std::cout << "Enter size for rows, m=";
        std::cin >> m;
    } while (m < 0 || m > MAX_SIZE);
    do {
        std::cout << "Enter size for columns, n=";
        std::cin >> n;
    } while (n < 0 || n > MAX_SIZE);
}

//Reading a matrix
void readMatrix(double matrix[][MAX_SIZE], const int m, const int n) {
    for (int i = 0; i < m; ++i) {
        std::cout << "Enter elements for row " << i + 1 << std::endl;
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

//Check if there is a negative element in the matrix.
void findNegative(double matrix[][MAX_SIZE], const int m, const int n) {
    bool isThereNegative = false;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] < 0) {
                std::cout << "There is a negative element in the matrix at index "
                          << i + 1 << "x" << j + 1;
                std::cout << std::endl;
                isThereNegative = true;
                break;
            }
        }
        if (isThereNegative) {
            break;
        }
    }
    if (!isThereNegative) {
        std::cout << "There is no negative element in the matrix." << std::endl;
    }
}

int main() {
    int m, n;
    double matrix[MAX_SIZE][MAX_SIZE];
    readSize(m, n);
    readMatrix(matrix, m, n);
    findNegative(matrix, m, n);
    return 0;
}