#include <iostream>
#include <vector>

int main() {
    //Reading the size with simple validation
    int n;
    do {
        std::cin >> n;
    } while (n <= 0);
	
    //Reading the elements of the first vector.
    std::vector<int> numbers;
    for (int i = 0; i < n; ++i) {
        int inputNumber;
        std::cin >> inputNumber;
        numbers.push_back((inputNumber));
    }

    //Generating the second vector with random integers in it.
    std::vector<int> randomNumbers;
    for (int i = 0; i < n; ++i) {
        int randomInteger = rand();
        randomNumbers.push_back((randomInteger));
    }

    //Finding all the special indexes.
    //A special index is an index of an element
    //that is bigger than its relevant element in the random generated vector.
    std::vector<int> specialIndexes;
    for (int i = 0; i < n; ++i) {
        if (numbers[i] > randomNumbers[i]) {
            specialIndexes.push_back(i);
        }
    }

    //Printing all the special indexes.
    for (int i = 0; i < specialIndexes.size(); ++i) {
        std::cout << specialIndexes[i] << ' ';
    }
    std::cout << std::endl;
}
