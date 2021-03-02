#include <iostream>

//Check if digit k is present in a natural number
bool isDigitPresent(int number, int digit) {
    if (number == 0) {
        return false;
    }
    if (number % 10 != digit) {
        return isDigitPresent(number / 10, digit);
    }
    return true;
}

//Driver function
int main() {
    int inputNumber;
    do {
        std::cin >> inputNumber;
    } while (inputNumber <= 0);

    int k;
    do {
        std::cin >> k;
    } while (k < 0 || k > 9);

    bool result = isDigitPresent(inputNumber, k);
    std::cout << result << std::endl;
    return 0;
}