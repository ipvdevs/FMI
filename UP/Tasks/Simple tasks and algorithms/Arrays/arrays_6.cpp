#include <iostream>

int main() {
    const int MAX_SIZE = 100;
    double sequence_A[MAX_SIZE] = {}, sequence_B[MAX_SIZE] = {};

    int k;
    std::cout << "Enter sequences size: ";
    do {
        std::cin >> k;
    } while (k <= 0 || k >= 100);

    std::cout << "Enter first sequence elements: " << std::endl;
    for (int i = 0; i < k; ++i) {
        std::cin >> sequence_A[i];
    }

    std::cout << "Enter second sequence elements: " << std::endl;
    for (int i = 0; i < k; ++i) {
        std::cin >> sequence_B[i];
    }

    unsigned short counter = 0;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            if (sequence_A[i] == sequence_B[j]){
                ++counter;
            }
        }
    }
    std::cout << "Equalities (ai = bj) count in this array is: " << counter << std::endl;
    return 0;
}