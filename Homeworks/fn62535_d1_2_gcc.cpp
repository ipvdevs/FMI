/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Ivan Penev
* @idnumber 62535
* @task 2
* @compiler GCC
*
*/


#include <iostream>

int main() {
    int number;
    std::cin >> number;
    int biggest = 0;
    int secondBiggest = 0;

    while (number > 0) {
        if (number > biggest) {
            secondBiggest = biggest;
            biggest = number;
        }
        if (number > secondBiggest && number < biggest) {
            secondBiggest = number;
        }
        std::cin >> number;
    }

    if (secondBiggest != 0) {
        std::cout << secondBiggest << std::endl;
    } else {
        std::cout << "-1" << std::endl;
    }

    return 0;
}
