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

//Check if an element is present in a matrix.
void findElement(double matrix[][MAX_SIZE], const int m, const int n, const double x) {
    bool isElementPresent = false;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == x) {
                std::cout << "The element is present in the matrix at index "
                          << i + 1 << "x" << j + 1;
                std::cout << std::endl;
                isElementPresent = true;
                break;
            }
        }
        if (isElementPresent) {
            break;
        }
    }
    if (!isElementPresent) {
        std::cout << "The element is not present in the matrix." << std::endl;
    }
}

int main() {
    int m, n;
    double matrix[MAX_SIZE][MAX_SIZE];
    readSize(m, n);
    readMatrix(matrix, m, n);
    double x;
    std::cout << "Enter x=";
    std::cin >> x;
    findElement(matrix, m, n, x);
    return 0;
}