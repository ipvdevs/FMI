/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Ivan Penev
* @idnumber 
* @task 2
* @compiler GCC
*
*/

#include <iostream>

int main() {
    int N;
    do {
        std::cin >> N;
    } while (N < 3 || N > 365);

    const int SIZE = 400;
    const double MIN_STOCK_PRICE = 0.1;
    const double MAX_STOCK_PRICE = 100;
    double stocks[SIZE] = {};

    for (unsigned int i = 0; i < N; ++i) {
        double currentStockPrice;
        do {
            std::cin >> currentStockPrice;
        } while (currentStockPrice < MIN_STOCK_PRICE || currentStockPrice > MAX_STOCK_PRICE);
        stocks[i] = currentStockPrice;
    }

    double minPrice = stocks[0];
    double maxProfit = 0;
    double currentProfit = 0;
    for (unsigned int day = 1; day < N; ++day) {
        if (stocks[day - 1] <= stocks[day]) {
            currentProfit = stocks[day] - minPrice;
        } else {
            maxProfit += currentProfit;
            currentProfit = 0;
            minPrice = stocks[day];
        }
    }

    if (stocks[N - 1] > minPrice){
        maxProfit += stocks[N-1] - minPrice;
    }

    std::cout << maxProfit << std::endl;

    return 0;
}