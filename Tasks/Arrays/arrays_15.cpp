#include <iostream>
#include <vector>

void FillArray(std::vector<double>& arr, const int SIZE){
    std::cout << "Enter the array elements: " << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        double input;
        std::cin >> input;
        arr.push_back(input);
    }
}

void ReadInput(std::vector<double>& first_arr, std::vector<double>& second_arr){
    int N,M;
    std::cout << "Enter the size of the first array (size >= 0): ";
    do {
        std::cin >> N;
    }while (N < 0);
    FillArray(first_arr, N);

    std::cout << "Enter the size of the second array (size >= 0): ";
    do {
        std::cin >> M;
    }while (M < 0);
    FillArray(second_arr, M);
}

void BubbleSort(std::vector<double>& array){
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < array.size() - 1; ++i) {
            if (array[i] > array[i + 1]){
                std::swap(array[i], array[i+1]);
                swapped = true;
            }
        }
    } while (swapped);
}

std::vector<double> MergeAndSortTwoArrays(std::vector<double> first_arr, std::vector<double> second_arr){
    std::vector<double> mergedArray;
    mergedArray.insert(mergedArray.begin(), first_arr.begin(), first_arr.end());
    mergedArray.insert(mergedArray.end(), second_arr.begin(), second_arr.end());

    BubbleSort(mergedArray);

    return mergedArray;
}

int main() {
    std::vector<double> first_array, second_array;
    ReadInput(first_array, second_array);
    std::vector<double> merged_array = MergeAndSortTwoArrays(first_array, second_array);

    for (double element : merged_array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;
    return 0;
}