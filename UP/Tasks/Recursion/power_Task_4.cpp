#include <iostream>

//Recursive function for finding x^n, where x is real and n is integer.
double power(double x, int n) {
    if (n != 0) {
        if (n > 0) {
            return x * power(x, n - 1);
        } else {
            return 1 / (power(x, -n));
        }
    } else {
        return 1;
    }
}

//Driver function for test
int main() {
    double x;
    std::cout << "Enter value for x (real): ";
    std::cin >> x;
    int n;
    std::cout << "Enter value for n (integer): ";
    std::cin >> n;
    double res = power(x, n);
    std::cout << res << std::endl;
    return 0;
}