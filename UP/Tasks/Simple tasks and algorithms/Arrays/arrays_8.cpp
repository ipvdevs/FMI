#include <iostream>

int main() {

    const short MAX_SIZE = 100;
    int sequence[MAX_SIZE] = {};
    int n, x;
    std::cout << "Enter array size (limitation (0,100)):" << std::endl;
    do {
        std::cin >> n;
    } while (n <= 0 || n >= 100);

    std::cout << "Enter value for x:" << std::endl;
    std::cin >> x;

    std::cout << "Enter array values:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> sequence[i];
    }

    bool elementOccurs = false;
    for (int i = 0; i < n; ++i) {
        if (sequence[i] == x) {
            elementOccurs = true;
            break;
        }
    }

    if (elementOccurs) {
        std::cout << "The element " << x << " occurs in the sequence." << std::endl;
    } else {
        std::cout << "The element " << x << " doesn't occur in the sequence." << std::endl;
    }
    return 0;
}