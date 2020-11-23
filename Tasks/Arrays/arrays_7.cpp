#include <iostream>

int main() {
    const int MAX_SIZE = 100;
    double sequence[MAX_SIZE] = {};

    int n;
    std::cout << "Enter sequences size limitation (0,50): ";
    do {
        std::cin >> n;
    } while (n <= 0 || n >= 100);

    int x;
    std::cout << "Enter value for x (x is an integer number):" << std::endl;
    std::cin >> x;

    std::cout << "Enter array elements:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> sequence[i];
    }

    unsigned short counter = 0;
    for (int i = 0; i < n; ++i) {
        if (sequence[i] == x){
           ++counter;
        }
    }
    std::cout << "The element x = " << x << " occurs " << counter << " times." << std::endl;
    return 0;
}