#include <iostream>
#include <vector>

int main() {
    int n;
    do {
        std::cin >> n;
    } while (n <= 0);

    std::vector<int> numbers;
    for (int i = 0; i < n; ++i) {
        int input;
        std::cin >> input;
        numbers.push_back(input);
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += numbers[i];
    }

    std::cout << (sum / (double) numbers.size()) << std::endl;
}