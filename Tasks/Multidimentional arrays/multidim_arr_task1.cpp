#include <iostream>

const int MAX_SIZE = 100;

//Reading the input
void read(double arr[MAX_SIZE][MAX_SIZE], int &rows, int &cols) {
    std::cout << "Enter matrix size (rows) x=";
    do {
        std::cin >> rows;
    } while (rows <= 0);
    std::cout << "Enter matrix size (columns) y=";
    do {
        std::cin >> cols;
    } while (cols <= 0);

    for (int i = 0; i < rows; i++) {
        std::cout << "Enter elements for row " << i + 1 << std::endl;

        for (int j = 0; j < cols; j++) {
            std::cin >> arr[i][j];
        }
    }
}

//Printing the minimal element on each row.
void printMinElements(double matrix[MAX_SIZE][MAX_SIZE], const int rows, const int cols) {

    for (int row = 0; row < rows; ++row) {
        int min = matrix[row][0];
        for (int col = 1; col < cols; ++col) {
            if (matrix[row][col] < min) {
                min = matrix[row][col];
            }
        }
        std::cout << min << ' ';
    }
    std::cout << std::endl;

};

int main() {
    int rows, cols;
    double matrix[MAX_SIZE][MAX_SIZE];
    read(matrix, rows, cols);
    printMinimalElements(matrix, rows, cols);
    return 0;
}


