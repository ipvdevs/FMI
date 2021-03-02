#include <iostream>

const int MAX_SIZE = 50;

void readSize(size_t& size){
    do {
        std::cout << "Enter sequence size in the interval [1, 50]: ";
        std::cin >> size;
    } while (size < 1 || size > MAX_SIZE);
}

void readSequence(int sequence[MAX_SIZE], size_t size){

    std::cout << "Enter sequence elements: ";
    for (int i = 0; i < size; ++i) {
        int inputElement;
        std::cin >> inputElement;
        sequence[i] = inputElement;
    }
}

bool isElementPresent(int sequence[MAX_SIZE], size_t n, int x){
        if (n < 1)
        {
            return 0;
        }
        if (sequence[n - 1] != x)
        {
            return isElementPresent(sequence, n-1, x);
        }

        return 1;
}

//Driver function
int main() {
    int sequence[MAX_SIZE];
    size_t n;

    readSize(n);
    readSequence(sequence, n);

    int x;
    std::cout << "Enter value for x: ";
    std::cin >> x;

    bool isPresent = isElementPresent(sequence, n, x);
    std::cout << isPresent << std::endl;
    return 0;
}