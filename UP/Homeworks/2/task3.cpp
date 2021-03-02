/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Ivan Penev
* @idnumber 
* @task 3
* @compiler GCC
*
*/

#include <iostream>
#include <vector>

int main() {
    int N;
    do{
        std::cin >> N;
    }while(N < 3 || N > 1000);

    std::vector<int> sequence;

    for (unsigned int i = 0; i < N; ++i) {
        int digit;
        do {
            std::cin >> digit;
        }while (digit < 0 || digit > 9);
        sequence.push_back(digit);
    }

    int palindromesCounter = 0;
    std::vector<int> subsequence;

    for (int i = 0; i < N - 2; ++i) {
        for (int k = i; k < N; ++k) {
            subsequence.push_back(sequence[k]);

            int subseqSize = subsequence.size();
            bool isPalindrome = true;
            if (subseqSize >= 3) {
                for (int s = 0; s < subseqSize / 2; ++s) {
                    if (subsequence[s] != subsequence[subseqSize - s - 1]){
                        isPalindrome = false;
                        break;
                    }
                }
            }
            if (subseqSize >= 3 && isPalindrome){
                ++palindromesCounter;
            }
        }
        subsequence.clear();
    }

    if (palindromesCounter > 0){
        std::cout << palindromesCounter << std::endl;
    } else {
        std::cout << "-1" << std::endl;
    }
    return 0;
}