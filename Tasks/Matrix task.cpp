/* Matrix task:
 * Find all (main/secondary) diagonals  sums + (over/below diagonals sums)
*/

#include <iostream>

int main() {
    int size;
    do {
        std::cin >> size;
    } while (size <= 0);

    int **matrix = new int *[size];

    for (int row = 0; row < size; ++row) {
        matrix[row] = new int[size];
        for (int col = 0; col < size; ++col) {
            int element;
            std::cin >> element;
            matrix[row][col] = element;
        }
    }

    int mainDiagSum = 0, secondaryDiagSum = 0;
    int aboveMainDiagSum = 0, aboveSecondaryDiagSum = 0;
    int belowMainDiagSum = 0, belowSecondaryDiagSum = 0;

    for (int row = 0; row < size; ++row) {
        mainDiagSum += matrix[row][row];
        secondaryDiagSum += matrix[row][size - 1 - row];
        for (int col = 0; col < size; ++col) {
            if (col > row) {
                aboveMainDiagSum += matrix[row][col];
            } else if (col < row) {
                belowMainDiagSum += matrix[row][col];
            }

            if (col < size - 1 - row) {
                aboveSecondaryDiagSum += matrix[row][col];
            } else if (col > size - 1 - row) {
                belowSecondaryDiagSum += matrix[row][col];
            }
        }
    }

    std::cout << "Main diag sum: " << mainDiagSum << '\n'
              << "Above main diag sum: " << aboveMainDiagSum << '\n'
              << "Below main diag sum: " << belowMainDiagSum << '\n'
              << "Secondary diag sum: " << secondaryDiagSum << '\n'
              << "Above secondary diag sum: " << aboveSecondaryDiagSum << '\n'
              << "Below secondary diag sum: " << belowSecondaryDiagSum << '\n';


    for (int row = 0; row < size; ++row) {
        delete[] matrix[row];
    }

    delete[] matrix;
    return 0;
}