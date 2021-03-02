#include <iostream>

//Calculating binomial coefficient (m,n) recursively
int binomialCoeff(int m, int n) {
    if (m == 0 || n == m) {
        return 1;
    }
    return binomialCoeff(m - 1, n - 1) + binomialCoeff(m, n - 1);
}

//Driver function for test
int main() {
    std::cout << "Binomial coefficient calculator (recursive):" << std::endl;
    int n, m;
    do {
        std::cout << "Enter a non negative value for n: ";
        std::cin >> n;
    } while (n < 0);
    do {
        std::cout << "Enter value for m in the interval [0, n]: ";
        std::cin >> m;
    } while (m < 0 || m > n);

    int result = binomialCoeff(m, n);
    std::cout << result << std::endl;
    return 0;
}