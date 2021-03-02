#include <iostream>

int main() {
    const short MAX_SIZE = 51;
    int sequence[MAX_SIZE];
    int n;
    std::cout << "Enter array size (limitation (0,51)):" << std::endl;
    do {
        std::cin >> n;
    } while (n <= 0 || n >= 51);

    std::cout << "Enter array values:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> sequence[i];
    }

    //Simple Bubble Sort
    bool isSwapped = false;
    do {
        isSwapped = false;
        for (int i = 0; i < n - 1; ++i) {
            if (sequence[i] > sequence[i+1]){
                std::swap(sequence[i], sequence[i+1]);
                isSwapped = true;
            }
        }
    } while (isSwapped);

    std::cout << "The sorted sequence in increasing order is: " << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << sequence[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}