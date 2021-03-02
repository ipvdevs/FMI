#include <iostream>

//Printing positive number reversed recursively
void printReversedDigits(int inputNumber) {
    std::cout << inputNumber % 10;
    if (inputNumber / 10 == 0) {
        return;
    }
    printReversedDigits(inputNumber / 10);
}

//Driver function
int main() {
    int inputNumber;
    do {
        std::cin >> inputNumber;
    } while (inputNumber <= 0);

    printReversedDigits(inputNumber);

    return 0;
}