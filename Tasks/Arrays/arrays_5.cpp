#include <iostream>

int main() {
    const int MAX_SIZE = 50;
    double arr[MAX_SIZE] = {};

    int N;
    std::cout << "Enter array size: ";
    do {
        std::cin >> N;
    } while (N <= 0 || N >= 50);

    std::cout << "Enter array elements: " << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    double max = arr[0], indexMaxValue = 0;
    for (int i = 1; i < N; ++i) {
        if (arr[i] > max){
            max = arr[i];
            indexMaxValue = i;
        }
    }

    std::cout << "Array's maximal element with index " << indexMaxValue << " is: " << std::endl;
    std::cout << max << std::endl;
    return 0;
}