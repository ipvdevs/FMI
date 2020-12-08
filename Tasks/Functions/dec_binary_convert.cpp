#include <iostream>

//Convert decimal to binary number
long long decToBinary(long long x) {
    long long binary = 0;
    long long i = 1;
    while (x > 0) {
        binary += (x % 2) * i;
        x /= 2;
        i *= 10;
    }
    return binary;
}

//Convert binary to decimal number
long long binaryToDec(long long x) {
    long long decimal = 0;
    long long base = 1;
    while (x != 0) {
        decimal += base * (x % 10);
        x /= 10;
        base *= 2;
    }
    return decimal;
}

//Driver
int main() {
    int x;
    std::cout << "Enter value for x: ";
    std::cin >> x;

    long long xInBinary = decToBinary(x);
    long long xInDecimal = binaryToDec(xInBinary);
    std::cout << "The number x in binary form is: " << xInBinary << std::endl;
    std::cout << "The number x in decimal form is: " << xInDecimal << std::endl;
    return 0;
}