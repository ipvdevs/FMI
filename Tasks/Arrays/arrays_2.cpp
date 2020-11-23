#include <iostream>

int main() {
    const int MAX_SIZE = 24;
    int sequence[MAX_SIZE];

    int N;
    do {
        std::cin >> N;
    } while (N <= 0 || N >= 24);

    for (int i = 0; i < N; ++i) {
        std::cin >> sequence[i];
    }

    int positiveSum = 0, negativeCount = 0;
    for (int i = 0; i < N; ++i) {
        if (sequence[i] > 0) {
            positiveSum += sequence[i];
        } else {
            ++negativeCount;
        }
    }
    std::cout << positiveSum + negativeCount << std::endl;

    return 0;
}