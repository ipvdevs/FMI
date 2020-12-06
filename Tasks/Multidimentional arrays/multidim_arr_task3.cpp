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

//Calculate the sum of elements in each row of a matrix.
void matrixRowsSum(double matrix[][MAX_SIZE], const int m, const int n){
    for (int i = 0; i < m; ++i) {
        double sum = 0;
        for (int j = 0; j < n; ++j) {
           sum += matrix[i][j];
        }
        std::cout << sum << std::endl;
    }
}

int main(){
    int m,n;
    double matrix[MAX_SIZE][MAX_SIZE];
    readSize(m,n);
    readMatrix(matrix, m, n);
    matrixRowsSum(matrix, m, n);
    return 0;
}