#include <iostream>

//Count occurrences of digit k in a number
unsigned countOccurrences(int number, const int k) {
    if (number == 0 && k == 0) {
        return 1;
    }
    unsigned occurrencesCounter = 0;
    while (number != 0) {
        if (number % 10 == k) {
            ++occurrencesCounter;
        }
        number /= 10;
    }
    return occurrencesCounter;
}

int main() {
    int k;
    do {
        std::cin >> k;
    } while (0 > k || k > 9);

    int specialNumsCount = 0;
    int input;
    std::cin >> input;
    while (input > 0) {
        unsigned occurrencesCount = countOccurrences(input, k);
        if (occurrencesCount >= 2) {
            ++specialNumsCount;
        }
        std::cin >> input;
    }

    std::cout << specialNumsCount << std::endl;
    return 0;
}