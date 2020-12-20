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

std::vector<double> MergeAndSortTwoArrays(std::vector<double> first_arr, std::vector<double> second_arr){
    std::vector<double> mergedArray;
    while (first_arr.size() > 0 && second_arr.size() > 0){
        if (first_arr[0] < second_arr[0]){
            mergedArray.push_back(first_arr[0]);
            first_arr.erase(first_arr.begin());
        } else {
            mergedArray.push_back(second_arr[0]);
            second_arr.erase(second_arr.begin());
        }

    }
    if (first_arr.size() > second_arr.size()){
        mergedArray.insert(mergedArray.end(), first_arr.begin(), first_arr.end());
    } else {
        mergedArray.insert(mergedArray.end(), second_arr.begin(), second_arr.end());
    }
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