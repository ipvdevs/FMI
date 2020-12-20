#include <iostream>

int main() {
    const int MAX_SIZE = 50;
    int A_set[MAX_SIZE] = {}, B_set[MAX_SIZE] = {};

    int N;
    std::cout << "Enter arrays/sets size: ";
    do {
        std::cin >> N;
    } while (N <= 0 || N >= 50);

    std::cout << "Enter array/set A elements: " << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cin >> A_set[i];
    }

    std::cout << "Enter array/set A elements: " << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cin >> B_set[i];
    }

    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum = sum + (A_set[i]*B_set[i]);
    }

    std::cout << "The sum of a0.b0 + a1.b1 + ... + an-1.bn-1 is: " << std::endl;
    std::cout << sum << std::endl;
    return 0;
}