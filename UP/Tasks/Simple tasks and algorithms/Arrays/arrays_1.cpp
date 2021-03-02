#include <iostream>
#include <iomanip>

int main() {
    const int SIZE = 50;
    double grades[SIZE] = {};

    //Grades count input and some simple validations.
    int gradesCount;
    std::cout << "Please enter total grades count in the interval [0, 50]:" << std::endl;
    do {
        std::cin >> gradesCount;
        if (gradesCount < 0 || gradesCount > 50) {
            std::cout << "Invalid input. Please enter grades count again:" << std::endl;
        }
    } while (gradesCount < 0 || gradesCount > 50);

    //Adding the input grades to the array
    for (int i = 0; i < gradesCount; ++i) {
        double inputGrade;
        //Current input grade validation
        std::cout << "Please enter grade " << i + 1 << " where grade is in the interval [2.00, 6.00]:" << std::endl;
        do {
            std::cin >> inputGrade;
            if (inputGrade < 2.00 || inputGrade > 6.00) {
                std::cout << "Invalid input. Please enter a valid grade between 2.00 and 6.00:" << std::endl;
            }
        } while (inputGrade < 2.00 || inputGrade > 6.00);
        grades[i] = inputGrade;
    }

    double gradesSum = 0;
    //Calculating the grades sum;
    for (double grade : grades) {
        gradesSum += grade;
    }
    double averageGrade = gradesSum / gradesCount;

    std::cout << "The average grade is: "
              << std::setprecision(2) << std::fixed
              << averageGrade << std::endl;
    return 0;
}