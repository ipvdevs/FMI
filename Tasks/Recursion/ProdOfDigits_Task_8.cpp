#include <iostream>

//Find digits product of a number (Recursion)
unsigned findDigitsProduct(int number) {
    if (number / 10 == 0) {
        return number % 10;
    }
    return number % 10 * findDigitsProduct((number / 10));
}


//Driver function
int main() {
    int inputNumber;
    do {
        std::cin >> inputNumber;
    } while (inputNumber <= 0);

    unsigned product = findDigitsProduct(inputNumber);
    std::cout << product << std::endl;
    return 0;
}