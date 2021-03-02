#include <iostream>

//Count digits of a number (Recursion)
unsigned countDigits(int number) {
    if (number == 0) {
        return 0;
    }
    return 1 + countDigits((number / 10));
}


//Driver function
int main() {
    int inputNumber;
    do {
        std::cin >> inputNumber;
    } while (inputNumber <= 0);

    unsigned count = countDigits(inputNumber);
    std::cout << count << std::endl;
    return 0;
}