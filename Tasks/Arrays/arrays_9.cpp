#include <iostream>

int main() {
    const short MAX_SIZE = 50;
    int sequence[MAX_SIZE] = {};
    int n;
    std::cout << "Enter sequence size (limitation (0,50)):" << std::endl;
    do {
        std::cin >> n;
    } while (n <= 0 || n >= 50);


    std::cout << "Enter sequence values:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> sequence[i];
    }

    bool isMonotonicDecreasing = true;
    for (int i = 0; i < n-1; ++i) {
        if (sequence[i] < sequence[i+1]){
            isMonotonicDecreasing = false;
            break;
        }
    }

    if (isMonotonicDecreasing){
        std::cout << "The sequence is monotonic decreasing" << std::endl;
    } else {
        std::cout << "The sequence is not monotonic decreasing" << std::endl;
    }

    return 0;
}