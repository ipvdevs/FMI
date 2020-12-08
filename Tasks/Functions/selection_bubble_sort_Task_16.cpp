#include <iostream>

const int MAX_SIZE = 50;

void readArray(int arr[MAX_SIZE], const int n) {
    std::cout << "Enter array elements:";
    for (int i = 0; i < n; ++i) {
        int input;
        std::cin >> input;
        arr[i] = input;
    }
}

void bubbleSort(int arr[MAX_SIZE], const int n) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

void selectionSort(int arr[MAX_SIZE], const int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        std::swap(arr[i], arr[min]);
    }
}

int main() {
    int n;
    do {
        std::cout << "Enter array size:";
        std::cin >> n;
    } while (n <= 0);

    int arr[MAX_SIZE];
    readArray(arr, n);

    selectionSort(arr, n);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}