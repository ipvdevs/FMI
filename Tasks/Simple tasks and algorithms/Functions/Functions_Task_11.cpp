#include <iostream>

const int MAX_INTERVAL_VALUE = 100000;

void readInterval(int &a, int &b) {
    do {
        std::cin >> a;
    } while (a <= 0 || a >= MAX_INTERVAL_VALUE);
    do {
        std::cin >> b;
    } while (b <= 0 || b >= MAX_INTERVAL_VALUE);
}

//Print all numbers that has two equal consecutive digits.
void printSpecialNumbers(const int a, const int b) {
    for (int i = a; i < b; ++i) {
        int currentNumber = i;
        while ((currentNumber != 0) && ((currentNumber % 10) != (currentNumber / 10) % 10)) {
            currentNumber /= 10;
        }
        if (currentNumber != 0) {
            std::cout << i << ' ';
        }
    }
}

int main() {
    int a, b;
    readInterval(a, b);
    printSpecialNumbers(a, b);
    return 0;
}