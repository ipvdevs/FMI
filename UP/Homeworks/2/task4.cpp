/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Ivan Penev
* @idnumber 
* @task 4
* @compiler GCC
*
*/

#include <iostream>
#include <vector>

bool ValidatePresentElements(const int currentInput, std::vector<int> sequence){
    for (int elementID = 0; elementID < sequence.size(); ++elementID) {
        if (sequence[elementID] == currentInput) {
            return true;
        }
    }
    return false;
}
int CountZeroSums (std::vector<int> sequence){
    int zeroSumsCount = 0;
    for (int k = 0; k < sequence.size() - 2; ++k) {
        for (int m = k+1; m < sequence.size() - 1; ++m) {
            for (int n = m+1; n < sequence.size(); ++n) {
                bool isSumPositive = (sequence[k] + sequence[m] + sequence[n]) == 0;
                if (isSumPositive){
                    ++zeroSumsCount;
                }
            }
        }
    }
    return zeroSumsCount;
}

int main(){
    int N;
    do {
        std::cin >> N;
    }while(N < 3 || N > 100);

    std::vector<int> sequence;

    for (int i = 0; i < N; ++i) {
        int currentInput;
        std::cin >> currentInput;
        bool isAlreadyPresent = ValidatePresentElements(currentInput, sequence);
        if (!isAlreadyPresent){
            sequence.push_back(currentInput);
        } else {
            --i;
        }
    }

    int zeroSumsCount = CountZeroSums(sequence);
    std::cout << zeroSumsCount << std::endl;
    return 0;
}