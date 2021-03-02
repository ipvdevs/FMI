#include <iostream>

//Finding n-th fibonacci number
int fib(const int n) {
    if (n < 2) {
        return n;
    }
    return (fib(n - 1) + fib(n - 2));
}

//Sum of natural numbers using recursion
int sum(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sum(n - 1);
}

//Recursive Euclidean Algorithm 1
int gcd1(int a, int b) {
    if (a == b) {
        return a;
    }
    if (a > b) {
        return gcd1(a - b, b);
    }
    return gcd1(a, b - a);
}

//Recursive Euclidean Algorithm 1
int gcd2(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd2(b % a, a);
}

//Driver
int main() {
    int res = gcd2(8, 12);
    std::cout << res << std::endl;
    return 0;
}