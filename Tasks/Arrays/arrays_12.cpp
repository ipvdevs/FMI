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

    bool consecutiveZeros = false;

    for (int i = 0; i < n - 1; ++i) {
        int leftElement = sequence[i];
        int rightElement = sequence[i+1];
        if (leftElement == 0 && leftElement == rightElement){
            consecutiveZeros = true;
            break;
        }
    }

    if (consecutiveZeros){
        std::cout << "The array contains two consecutive zeros." << std::endl;
    } else {
        std::cout << "The array doesn't contain two consecutive zeros." << std::endl;
    }

    return 0;
}