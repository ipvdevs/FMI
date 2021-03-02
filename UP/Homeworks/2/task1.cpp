/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Ivan Penev
* @idnumber 
* @task 1
* @compiler GCC
*
*/

#include <iostream>

int FindAbsValue(int number) {
    return (number < 0) ? -number : number;
}

int main() {
    int N;
    do {
        std::cin >> N;
    } while (N < 3 || N > 100);

    const int SIZE = 150;
    int sequence[SIZE] = {};

    for (unsigned int i = 0; i < N; ++i) {
        int input;
        do {
            std::cin >> input;
        } while (input <= 0);
        sequence[i] = input;
    }

    bool isSequenceTriangle = true;
    for (int i = 0; i < (N / 2); ++i) {
        int leftDiffAbs = FindAbsValue(sequence[i] - sequence[i + 1]);
        int rightDiffAbs = FindAbsValue(sequence[N - i - 1] - sequence[N - i - 2]);
        if (leftDiffAbs != rightDiffAbs) {
            isSequenceTriangle = false;
            break;
        }
    }

    if (isSequenceTriangle) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
    return 0;
}