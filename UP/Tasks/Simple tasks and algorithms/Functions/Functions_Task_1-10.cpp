#include <iostream>

//Sum two numbers
double sum(const double a, const double b) {
    return a + b;
}

//Check parity of a number
bool isEven(const int num) {
    return (num % 2 == 0) ? true : false;
}

//Get minimum of two numbers
double min(const double n1, const double n2) {
    return (n1 < n2) ? n1 : n2;
}

//Get absolute value of a number
double abs(const double value) {
    return (value >= 0) ? value : -value;
}

//Get the whole part of a number
int trunc(const double numToTrunc) {
    return (int) numToTrunc;
}

//Get the ascii value of a symbol
int ascii(const char symbol) {
    return (int) symbol;
}

//Calculate a power of whole number
int pow(const int num, const unsigned N) {
    int powerNum = 1;
    for (int i = 0; i < N; ++i) {
        powerNum *= num;
    }
    return powerNum;
}

//A simple whole number calculator
int calculate(const int a, const int b, char action) {
    if (action == '/' || action == '%') {
        if (b == 0) {
            std::cout << "Can't divide by zero!" << std::endl;
            return -1;
        }
    }
    switch (action) {
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '%':
            return a % b;
    }
    return a + b;
}

//Ask user for a number in an interval
double askUser(const int from, const int to) {
    double input;
    do {
        std::cout << "Please enter input in the interval from "
                  << from << " to " << to << ": ";
        std::cin >> input;
    } while (from > input || input > to);
    return input;
}

//Ask for n numbers and find their average
double average(const int N) {
    double sum = 0;
    for (int i = 0; i < N; ++i) {
        double input;
        std::cout << "Enter number " << i + 1 << ": " << std::endl;
        std::cin >> input;
        sum += input;
    }
    return (sum / N);
}

//Driver
int main() {
    //Used for testing the functions.
}