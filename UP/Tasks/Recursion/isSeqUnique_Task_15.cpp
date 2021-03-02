#include <iostream>

const int MAX_SIZE = 50;

//Check if sequence is composed only of unique elements (Recursive)
bool isSeqUnique(int sequence[], unsigned i, const unsigned size) {
    if (i >= size - 1) {
        return true;
    }

    for (int j = i + 1; j < size; ++j) {
        if (sequence[i] == sequence[j]) {
            return false;
        }
    }

    return isSeqUnique(sequence, i + 1, size);
}

int main() {
    int sequence[MAX_SIZE];
    //Reading the size
    int n;
    do {
        std::cin >> n;
    } while (1 > n || n > MAX_SIZE);

    //Reading the sequence
    for (int i = 0; i < n; ++i) {
        std::cin >> sequence[i];
    }

    bool res = isSeqUnique(sequence, 0, n);
    std::cout << res << std::endl;
    return 0;
}