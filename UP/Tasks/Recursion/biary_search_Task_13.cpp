#include <iostream>

const unsigned MAX_SIZE = 50;

//Reading size of a sequence
void readSize(int &size)
{
    std::cout << "Enter sequence size in the interval [1,50]: ";
    do
    {
        std::cin >> size;
    } while (size < 1 || size > MAX_SIZE);
}

//Reading a sequence with set size
void readSequence(int sequence[], int n)
{
    std::cout << "Enter a sequence with " << n << " elements: ";
    for (size_t i = 0; i < n; i++)
    {
        int inputNumber;
        std::cin >> inputNumber;
        sequence[i] = inputNumber;
    }
}

//Selection sort
void sortSequence(int sequence[], const int n)
{
    for (size_t i = 0; i < n - 1; ++i)
    {
        int min = i;
        for (size_t j = i + 1; j < n; ++j)
        {
            if (sequence[min] > sequence[j])
            {
                min = j;
            }
        }

        int temp = sequence[i];
        sequence[i] = sequence[min];
        sequence[min] = temp;
    }
}

//Check if sequence is sorted
bool checkSort(int sequence[], const int n)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        if (sequence[i] > sequence[i + 1])
        {
            return false;
        }
    }
    return true;
}

//Recursive binary search
int binarySearch(int sequence[], int begin, int end, const int x)
{
    if (end >= begin)
    {
        int mid = (begin + end) / 2;

        if (sequence[mid] == x)
        {
            return mid;
        }

        if (sequence[mid] > x)
        {
            return binarySearch(sequence, begin, mid - 1, x);
        }
        return binarySearch(sequence, mid + 1, end, x);
    }

    return -1;
}

//Driver function for tests
int main()
{
    int n;
    readSize(n);
    int sequence[MAX_SIZE] = {};
    readSequence(sequence, n);

    bool isSequenceSorted = checkSort(sequence, n);
    if (!isSequenceSorted)
    {
        sortSequence(sequence, n);
    }

    int x;
    std::cout << "Enter an element to find: ";
    std::cin >> x;

    int foundIndex = binarySearch(sequence, 0, n - 1, x);
    if (foundIndex != -1)
    {
        std::cout << "The element " << x
                  << " is found in the sequence on index " << foundIndex << '.';
    }
    else
    {
        std::cout << "The element " << x << " is not found in the sequence.";
    }

    std::cout << std::endl;
    return 0;
}