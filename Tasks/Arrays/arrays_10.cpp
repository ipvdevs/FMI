#include <iostream>
#include <vector>

bool UniqueSequenceCheck(std::vector<int> sequence){
    for (int i = 0; i < sequence.size() - 1; ++i) {
        for (int j = i + 1; j < sequence.size(); ++j) {
            if (sequence[i] == sequence[j]){
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::vector<int> sequence;
    int n;
    std::cout << "Enter sequence size (limitation (0,50)):" << std::endl;
    do {
        std::cin >> n;
    } while (n <= 0 || n >= 50);


    std::cout << "Enter sequence values:" << std::endl;
    for (int i = 0; i < n; ++i) {
        int input;
        std::cin >> input;
        sequence.push_back(input);
    }

    bool isSequenceUnique = UniqueSequenceCheck(sequence);


    if (isSequenceUnique){
        std::cout << "The sequence contains only unique elements." << std::endl;
    } else {
        std::cout << "The sequence doesn't contain only unique elements." << std::endl;
    }

    return 0;
}