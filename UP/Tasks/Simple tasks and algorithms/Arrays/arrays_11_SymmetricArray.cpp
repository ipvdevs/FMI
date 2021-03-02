#include <iostream>

int main() {
    const short MAX_SIZE = 50;
    char charArray[MAX_SIZE];
    int n;
    std::cout << "Enter array size (limitation (0,50)):" << std::endl;
    do {
        std::cin >> n;
    } while (n <= 0 || n >= 50);


    std::cout << "Enter array values:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> charArray[i];
    }

    bool isSymmetric = true;

    for (int i = 0; i < n/2; ++i) {
        if (charArray[i] != charArray[n - 1 - i]){
            isSymmetric = false;
            break;
        }
    }

    if (isSymmetric){
        std::cout << "The array is symmetric." << std::endl;
    } else {
        std::cout << "The array is not symmetric." << std::endl;
    }

    return 0;
}
