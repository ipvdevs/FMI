/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Ivan Penev
* @idnumber 62535
* @task 3
* @compiler GCC
*
*/


#include <iostream>

struct fraction {
    long long numerator;
    long long denominator;
};

long long abs(long long num);

long long gcd(long long num1, long long num2);

long long lcm(long long num1, long long num2);

long long *calcFraction(fraction fraction_1, fraction fraction_2, char operation);

int main() {
    long long fract1Numerator, fract1Denominator;
    std::cin >> fract1Numerator >> fract1Denominator;
    if (fract1Denominator <= 0) {
        std::cout << "-1" << std::endl;
        return 0;
    }

    fraction fraction_1 = {fract1Numerator, fract1Denominator};

    char operation;
    std::cin >> operation;
    bool isOperationValid = (operation == '+' ||
                             operation == '-' ||
                             operation == '*' ||
                             operation == '/');
    if (!isOperationValid) {
        std::cout << "-1" << std::endl;
        return 0;
    }

    long long fract2Numerator, fract2Denominator;

    std::cin >> fract2Numerator >> fract2Denominator;
    if (fract2Denominator <= 0) {
        std::cout << "-1" << std::endl;
        return 0;
    }

    fraction fraction_2 = {fract2Numerator, fract2Denominator};

    long long *result = calcFraction(fraction_1, fraction_2, operation);

    std::cout << result[0] << ' ' << result[1] << std::endl;
    delete[] result;
    return 0;
}

long long abs(long long num) {
    return (num < 0 ? -num : num);
}

long long gcd(long long num1, long long num2) {
    if (num2 == 0) {
        return num1;
    }

    return gcd(num2, num1 % num2);
}

long long lcm(long long num1, long long num2) {
    return (num1 * num2) / gcd(num1, num2);
}

long long *calcFraction(fraction fraction_1, fraction fraction_2, const char operation) {
    long long *result = new long long[2];
    long long lcmDenominators = lcm(fraction_1.denominator, fraction_2.denominator);
    long long resultNumerator, resultDenominator;

    switch (operation) {
        case '+':
            resultNumerator = fraction_1.numerator * (lcmDenominators / fraction_1.denominator)
                              + fraction_2.numerator * (lcmDenominators / fraction_2.denominator);
            resultDenominator = lcmDenominators;
            break;
        case '-':
            resultNumerator = fraction_1.numerator * (lcmDenominators / fraction_1.denominator)
                              - fraction_2.numerator * (lcmDenominators / fraction_2.denominator);
            resultDenominator = lcmDenominators;
            break;
        case '*':
            resultNumerator = fraction_1.numerator * fraction_2.numerator;
            resultDenominator = fraction_1.denominator * fraction_2.denominator;
            break;
        case '/':
            int sign = 1;
            if (fraction_1.numerator < 0 || fraction_2.numerator < 0) {
                if (fraction_1.numerator < 0 && fraction_2.numerator < 0) {
                    sign = 1;
                } else {
                    sign = -1;
                }
            }
            resultNumerator = sign * abs(fraction_1.numerator * fraction_2.denominator);
            resultDenominator = abs(fraction_1.denominator * fraction_2.numerator);
            break;
    }

    long long resultGcd = abs(gcd(resultNumerator, resultDenominator));

    result[0] = resultNumerator / resultGcd;
    result[1] = resultDenominator / resultGcd;
    return result;
}