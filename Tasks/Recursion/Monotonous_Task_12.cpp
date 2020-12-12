#include <iostream>

const unsigned MAX_SIZE = 50;

//Reading the size of a seqeunce
void readSize(int &n)
{
    do
    {
        std::cout << "Enter sequence size: ";
        std::cin >> n;
    } while (n < 1 || n > MAX_SIZE);
}

//Reading a sequence with set size
void readSeq(int sequence[], const unsigned n)
{
    std::cout << "Enter " << n << " sequence elements: ";
    for (size_t i = 0; i < n; i++) {
        int inputNumber;
        std::cin >> inputNumber;
        sequence[i] = inputNumber;
    }
}

//Recursive check if sequence is monotonically increasing
bool checkMonoIncr(int sequence[], const int n){
    //x1 < x2 -> f(x1) < f(x2)
    if (n < 2) {
        return 1;
    }
    if (sequence[n - 2] < sequence[n - 1]) { 
        return checkMonoIncr(sequence, n - 1);
    }
    return 0;
}


//Driver function
int main()
{
    int n;
    readSize(n);

    int sequence[MAX_SIZE];
    readSeq(sequence, n);

    bool isMonoIncr = checkMonoIncr(sequence, n);
    if (isMonoIncr)
    {
        std::cout << "The sequence is monotonically increasing";
    } else {
        std::cout << "The sequence is not monotonically increasing";
    }

    std::cout << std::endl;
    return 0;
}