#include <iostream>
#include <vector>

//Read a sequence of numbers with n elements
void readSequence(std::vector<int> &seq) {
    int size;
    std::cout << "Enter sequence size:";
    do {
        std::cin >> size;
    } while (size <= 0);

    for (int i = 0; i < size; ++i) {
        int input;
        std::cin >> input;
        seq.push_back(input);
    }
}

//Get absolute value of a number
unsigned getAbs(const int value) {
    return (value >= 0) ? value : -value;
}

//Euclidean algorithm for greatest common divisor
unsigned gcd(int a, int b) {
    a = getAbs(a);
    b = getAbs(b);
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

//Finding least common multiple using gcd
unsigned lcm(int a, int b) {
    a = getAbs(a);
    b = getAbs(b);
    return a * b / gcd(a, b);
}

//Find greatest common divisor of elements in a sequence
unsigned findSeqGCD(const std::vector<int> &sequence) {
    int result = sequence[0];
    for (int i = 1; i < sequence.size(); ++i) {
        result = gcd(result, sequence[i]);
    }
    return result;
}

//Find least common multiple of elements in a sequence
unsigned findSeqLCM(const std::vector<int> &sequence) {
    int result = sequence[0];
    for (int i = 1; i < sequence.size(); ++i) {
        result = lcm(result, sequence[i]);
    }
    return result;
}

//Driver
int main() {
    std::vector<int> sequence;
    readSequence(sequence);

    unsigned gcdResult = findSeqGCD(sequence);
    unsigned lcmResult = findSeqLCM(sequence);
    std::cout << "gcd = " << gcdResult << std::endl;
    std::cout << "lcm = " << lcmResult << std::endl;
    return 0;
}