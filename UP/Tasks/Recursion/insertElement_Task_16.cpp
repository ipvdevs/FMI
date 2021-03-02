#include <iostream>
#include <vector>

//Insert element to sorted sequence with keeping the order
void insertElement(std::vector<int> &sequence, const int i, const int toInsert) {

    if (i >= sequence.size()) {
        sequence.push_back(toInsert);
        return;
    }

    if (sequence[i] > toInsert) {
        sequence.insert(sequence.begin() + i, toInsert);
        return;
    }

    insertElement(sequence, i + 1, toInsert);
}

int main() {
    std::vector<int> sequence;
    //Reading the size
    int n;
    do {
        std::cin >> n;
    } while (n < 0);

    //Reading the sequence
    for (int i = 0; i < n; ++i) {
        int element;
        std::cin >> element;
        sequence.push_back(element);
    }

    //Reading element to insert
    int x;
    std::cin >> x;
    insertElement(sequence, 0, x);

    //Printing the sequence with the inserted element.
    for (int i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}