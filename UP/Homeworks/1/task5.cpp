/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Ivan Penev
* @idnumber
* @task 5
* @compiler GCC
*
*/

#include <iostream>

int main() {
    int n;
    do {
        std::cin >> n;
    } while (n < 2 || n > 1E9);

    int copyN = n;
    int pow2 = 0, pow5 = 0;
    while (copyN % 2 == 0) {
        copyN /= 2;
        ++pow2;
    }
    while (copyN % 5 == 0) {
        copyN /= 5;
        ++pow5;
    }
    if (copyN == 1) {
        std::cout << ((pow2 > pow5) ? pow2 : pow5) << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}
