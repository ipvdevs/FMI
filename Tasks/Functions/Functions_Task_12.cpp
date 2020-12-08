#include <iostream>

const int MAX_INTERVAL_VALUE = 1000000;

void readInterval(int &a, int &b) {
    do {
        std::cin >> a;
    } while (a <= 0 || a >= MAX_INTERVAL_VALUE);
    do {
        std::cin >> b;
    } while (b <= 0 || b >= MAX_INTERVAL_VALUE);
}

//Count digits in a number
unsigned countDigits(int number) {
    unsigned digitsCount = 0;
    while (number != 0) {
        ++digitsCount;
        number /= 10;
    }
    return digitsCount;
}

//Find average of digits in a number
double findDigitsAverage(int currentNumber) {
    double sum = 0;
    unsigned digitsCount = countDigits(currentNumber);
    while (currentNumber != 0) {
        sum += currentNumber % 10;
        currentNumber /= 10;
    }
    return sum / digitsCount;
}

//Printing numbers in the interval [a,b] with bigger digits average than k
void printBiggerAvgNums(const int a, const int b, const int k) {
    for (int i = a; i < b; ++i) {
        int currentNumber = i;
        double digitsAverage = findDigitsAverage(currentNumber);

        if (digitsAverage >= k) {
            std::cout << i << ' ';
        }
    }
}

int main() {
    int a, b;
    readInterval(a, b);

    int k;
    do {
        std::cin >> k;
    } while (0 >= k || k >= 10);

    printBiggerAvgNums(a, b, k);
    return 0;
}