#include <iostream>
#include <vector>

int main() {
    //Reading the size with simple validation
    int n;
    do {
        std::cin >> n;
    } while (n <= 0);

    //Reading the elements of the vector.
    std::vector<int> naturalNumbers;
    for (int i = 0; i < n; ++i) {
        int inputNumber;
        do {
            std::cin >> inputNumber;
        } while (n <= 0);
        naturalNumbers.push_back((inputNumber));
    }

    std::vector<int> repeatingElements;
    //Finding all the elements that occurs at least twice.
    for (int i = 0; i < naturalNumbers.size() - 1; ++i) {
        for (int j = i + 1; j < naturalNumbers.size(); ++j) {
            if (naturalNumbers[i] == naturalNumbers[j]) {
                repeatingElements.push_back(naturalNumbers[j]);
                break;
            }
        }
    }

    //Printing all the repeating elements.
    for (int i = 0; i < repeatingElements.size(); ++i) {
        std::cout << repeatingElements[i] << ' ';
    }
    std::cout << std::endl;
}
