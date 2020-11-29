#include <iostream>
#include <vector>

int main() {
    //Reading the sizes with simple validation
    int n;
    do {
        std::cin >> n;
    } while (n <= 0);

    //Reading the elements of the first coefficients vector.
    std::vector<double> a;
    for (int i = 0; i < n; ++i) {
        double inputNumber;
        std::cin >> inputNumber;
        a.push_back((inputNumber));
    }

    //Reading the elements of the second coefficients vector.
    std::vector<double> b;
    for (int i = 0; i < n; ++i) {
        double inputNumber;
        std::cin >> inputNumber;
        b.push_back((inputNumber));
    }

    //Finding all the solutions of ai*x + bi = 0 (0 <= i < n), where i is index.
    std::vector<double> solutions;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0) {
            double x = -(b[i] / a[i]);
            solutions.push_back(x);
        } else {
            std::cout << "Can't divide by zero!" << std::endl;
            std::cout << "Error on a" << i << std::endl;
            return 1;
        }
    }

    //Printing all the solutions.
    for (int i = 0; i < solutions.size(); ++i) {
        std::cout << solutions[i] << ' ';
    }
    std::cout << std::endl;
}
