/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Ivan Penev
* @idnumber 
* @task 1
* @compiler GCC
*
*/

#include <iostream>

int main() {
    int nBirthday;
    do {
        std::cin >> nBirthday;
    } while (nBirthday <= 0);

    double xLaptopPrice;
    do {
        std::cin >> xLaptopPrice;
    } while (xLaptopPrice <= 0);

    double mToyPrice;
    do {
        std::cin >> mToyPrice;
    } while (mToyPrice <= 0);

    double giftedMoney = 30, savedMoney = 0;

    for (unsigned int i = 1; i <= nBirthday; ++i) {
        if (0 == i % 2) {
            savedMoney += giftedMoney;
            savedMoney -= 5;
            giftedMoney += 30;
        } else {
            savedMoney += mToyPrice;
        }
    }

    if (savedMoney >= xLaptopPrice) {
        std::cout << "yes" << std::endl;
        std::cout << (savedMoney - xLaptopPrice) << std::endl;
    } else {
        std::cout << "no" << std::endl;
        std::cout << (xLaptopPrice - savedMoney) << std::endl;
    }
    return 0;
}
