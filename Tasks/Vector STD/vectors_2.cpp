#include <iostream>
#include <vector>

//Calculating the average of numbers.
double calcAverage(std::vector<int> numbers);

int main() {
    //Reading the size with simple validation
    int n;
    do {
        std::cin >> n;
    } while (n <= 0);

    //Generating vector with random integers in it.
    std::vector<int> randomNumbers;
    for (int i = 0; i < n; ++i) {
        int randomInteger = rand();
        randomNumbers.push_back((randomInteger));
    }

    //Checking for special indexes.
    //A special index is an index of number that
    //is bigger than the set average.
    double average = calcAverage(randomNumbers);
    std::vector<unsigned> specialIndexes;
    for (int i = 0; i < n; ++i) {
        if (randomNumbers[i] > average) {
            specialIndexes.push_back(i);
        }
    }

    //Printing all the special indexes.
    for (int i = 0; i < specialIndexes.size(); ++i) {
        std::cout << specialIndexes[i] << ' ';
    }
    std::cout << std::endl;
}

double calcAverage(std::vector<int> numbers) {
    int sum = 0;
    for (int i = 0; i < numbers.size(); ++i) {
        sum += numbers[i];
    }
    return (double) sum / numbers.size();
}
