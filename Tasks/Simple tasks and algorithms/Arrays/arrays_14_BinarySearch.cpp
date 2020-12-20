#include <iostream>

//Recursive binary search
int binarySearch(double sequence[], int leftIndex, int rightIndex, const int x) {
    if (rightIndex >= 1) {
        int middleIndex = (rightIndex + leftIndex) / 2;

        if (sequence[middleIndex] == x) {
            return middleIndex;
        }

        if (sequence[middleIndex] > x) {
            return binarySearch(sequence, leftIndex, middleIndex - 1, x);
        }

        return binarySearch(sequence, middleIndex + 1, rightIndex, x);
    }
    return -1;
}

int main() {
    const short MAX_SIZE = 51;
    double sequence[MAX_SIZE];
    int n;
    std::cout << "Enter array size (limitation (0,51)):" << std::endl;
    do {
        std::cin >> n;
    } while (n <= 0 || n >= 51);

    std::cout << "Enter array values:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> sequence[i];
    }

    double x;
    std::cout << "Enter value for x:" << std::endl;
    std::cin >> x;

    int elementIndex = binarySearch(sequence, 0, n - 1, x);
    if (elementIndex != -1) {
        std::cout << "The element is on index " << elementIndex << std::endl;
    } else {
        std::cout << "The element is not present in the sequence" << std::endl;
    }
    return 0;
}