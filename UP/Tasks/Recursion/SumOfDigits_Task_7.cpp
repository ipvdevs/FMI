#include <iostream>

//Find digits sum of a number (Recursion)
unsigned findDigitsSum(int number) {
    if (number / 10 == 0) {
        return number % 10;
    }
    return number % 10 + findDigitsSum((number / 10));
}


//Driver function
int main() {
    int inputNumber;
    do {
        std::cin >> inputNumber;
    } while (inputNumber <= 0);

    unsigned sum = findDigitsSum(inputNumber);
    std::cout << sum << std::endl;
    return 0;
}