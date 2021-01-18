/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Ivan Penev
* @idnumber 62535
* @task 1
* @compiler GCC
*
*/


#include <iostream>

bool isIncreaseFixPossible(const int *seq, const int M, int N) {
    int *seqLenArr = new int[M];

    for (int i = 0; i < M; ++i) {
        seqLenArr[i] = 1;
    }

    for (int i = 1; i < M; ++i) {
        for (int j = 0; j < i; ++j) {
            if ((seq[j] <= seq[i]) && (seqLenArr[j] + 1 > seqLenArr[i])) {
                seqLenArr[i] = seqLenArr[j] + 1;
            }
        }
    }

    int maxLength = seqLenArr[0];
    for (int i = 1; i < M; ++i) {
        if (seqLenArr[i] > maxLength) {
            maxLength = seqLenArr[i];
        }
    }

    delete[] seqLenArr;

    return (M - maxLength <= N);
}

int main() {
    int N;
    std::cin >> N;
    if (N <= 0) {
        std::cout << "-1" << std::endl;
        return 0;
    }

    int M;
    std::cin >> M;
    if (M <= 0) {
        std::cout << "-1" << std::endl;
        return 0;
    }

    int *seq = new int[M];

    for (int i = 0; i < M; ++i) {
        int input;
        std::cin >> input;
        if (input <= 0) {
            std::cout << "-1" << std::endl;
            return 0;
        }
        *(seq + i) = input;
    }

    bool result = isIncreaseFixPossible(seq, M, N);

    delete[] seq;

    std::cout << result << std::endl;
    return 0;
}