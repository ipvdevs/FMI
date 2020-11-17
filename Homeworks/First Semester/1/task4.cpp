/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Ivan Penev
* @idnumber 
* @task 4
* @compiler GCC
*
*/


#include <iostream>

int main() {
    unsigned int n;
    do{
        std::cin >> n;
    }while(n < 1);

    int m,p,q;
    int leastFactorSum = n + 2;

    for (int i = 1; i*i <= n ; ++i) {
        for (int j = 1; j*j <= n ; ++j) {
            if (n % (i*j) == 0){
                int k = n / (i * j);
                if ((i*j*k == n) && (i+j+k <= leastFactorSum)){
                    m = i;
                    p = j;
                    q = k;
                    leastFactorSum = i + j + k;
                }
            }
        }
    }

    int temp;
    if (m > p){
        temp = m;
        m = p;
        p = temp;
    }
    if (m > q){
        temp = m;
        m = q;
        q = temp;
    }
    if (p > q){
        temp = p;
        p = q;
        q = temp;
    }

    std::cout << m << ' ' << p << ' ' << q << std::endl;
    return 0;
}
