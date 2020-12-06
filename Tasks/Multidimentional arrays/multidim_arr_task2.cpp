#include <iostream>
const int MAX_SIZE = 100;

//Reading size of matrix (mxn) with simple validation
void readSize(int& m, int& n){
    do {
        std::cout << "Enter size for rows, m=";
        std::cin >> m;
    }while(m < 0 || m > MAX_SIZE );
    do {
        std::cout << "Enter size for columns, n=";
        std::cin >> n;
    }while(n < 0 || n > MAX_SIZE );
}

//Reading a matrix
void readMatrix(double matrix[][MAX_SIZE], const int m,const int n){
    for (int i = 0; i < m; ++i) {
        std::cout << "Enter elements for row " << i + 1 << std::endl;
        for (int j = 0; j < n; ++j) {
        std::cin >> matrix[i][j];
        }
    }
}

//Counting the negative elements in each row of a matrix.
void matrixNegativeCount(double matrix[][MAX_SIZE], const int m, const int n){
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] < 0){
                std::cout << matrix[i][j] << ' ';
            }
        }
        std::cout << std::endl;
    }
}

int main(){
    int m,n;
    double matrix[MAX_SIZE][MAX_SIZE];
    readSize(m,n);
    readMatrix(matrix, m, n);
    matrixNegativeCount(matrix, m, n);
    return 0;
}