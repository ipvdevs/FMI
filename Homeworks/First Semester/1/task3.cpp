/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Ivan Penev
* @idnumber 
* @task 3
* @compiler GCC
*
*/

#include <iostream>

int main() {
    int digit1, digit2, digit3;

    do {
        std::cin >> digit1;
    } while (digit1 < 0 || digit1 > 9);
    do {
        std::cin >> digit2;
    } while (digit2 < 0 || digit2 > 9);
    do {
        std::cin >> digit3;
    } while (digit3 < 0 || digit3 > 9);

    int temp;
    if (digit1 > digit3) {
        temp = digit1;
        digit1 = digit3;
        digit3 = temp;
    }
    if (digit1 > digit2) {
        temp = digit1;
        digit1 = digit2;
        digit2 = temp;
    }
    if (digit2 > digit3) {
        temp = digit2;
        digit2 = digit3;
        digit3 = temp;
    }
    unsigned int palindrome;
    if ((digit1 != digit2) && (digit2 != digit3)) {
        if (digit1 == 0){
            palindrome = digit2 + digit1 * 10 + digit3 * 100 + digit1 * 1000 + digit2 * 10000;
        } else {
            palindrome = digit1 + digit2 * 10 + digit3 * 100 + digit2 * 1000 + digit1 * 10000;
        }
    } else {
        if((digit1 == digit2) && (digit2 == digit3)){
            palindrome = digit1 + digit2 * 10 + digit3 * 100;
        } else {
            if (digit1 == digit2){
                if(digit1 != 0 && digit2 != 0){
                    palindrome = digit1 + digit3*10 + digit2*100;
                } else {
                    palindrome = digit3 + digit1*10 + digit2*100 + digit3*1000;
                }
            }
            if (digit2 == digit3){
                if(digit2 != 0 && digit3 != 0){
                    palindrome = digit2 + digit1*10 + digit3*100;
                } else {
                    palindrome = digit1 + digit2*10 + digit3*100 + digit1*1000;
                }
            }
        }
    }
    std::cout << palindrome << std::endl;
    return 0;
}
