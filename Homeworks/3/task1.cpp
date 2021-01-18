/**
*  
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Ivan Penev
* @idnumber 62535
* @task 1
* @compiler GCC
*
*/


#include <iostream>

const int MAX_SIZE = 151;

int getStrLen(const char str[]) {
    int strLen = 0;
    while (str[strLen] != '\0') {
        ++strLen;
    }
    return strLen;
}

void sortCharArray(char str[], const int strLen) {
    for (int i = 0; i < strLen - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < strLen; ++j) {
            if (str[j] < str[min]) {
                min = j;
            }
        }
        char temp = str[i];
        str[i] = str[min];
        str[min] = temp;
    }
}

int equalCountCheck(const char str[], const int strLen) {
    int letterCounter = 0, lastCount = 0;
    for (int i = 0; i < strLen; ++i) {
        ++letterCounter;
        if (i == strLen - 1 || str[i] != str[i + 1]) {
            if (lastCount != 0 && letterCounter != lastCount) {
                return 0;
            }
            lastCount = letterCounter;
            letterCounter = 0;
        }
    }
    return 1;
}

void copyStr(const char src[], const int strLen, char dest[]) {
    for (int i = 0; i < strLen; ++i) {
        dest[i] = src[i];
    }
}

void crossOutLetter(char updatedStr[], const int strLen, const int indexToCross) {
    for (int i = 0; i < strLen; ++i) {
        if (i >= indexToCross) {
            updatedStr[i] = updatedStr[i + 1];
        }
    }

}

int isStrRight(char str[]) {
    int strLen = getStrLen(str);
    sortCharArray(str, strLen);

    int checkResult = equalCountCheck(str, strLen);
    if (checkResult == 1) {
        return 1;
    }

    char updatedStr[MAX_SIZE];
    copyStr(str, strLen, updatedStr);
    for (int indexToCross = 0; indexToCross < strLen; ++indexToCross) {
        crossOutLetter(updatedStr, strLen, indexToCross);
        checkResult = equalCountCheck(updatedStr, strLen - 1);
        if (checkResult == 1) {
            return 1;
        }
        copyStr(str, strLen, updatedStr);
    }
    return 0;
}

int main() {
    char str[MAX_SIZE];
    std::cin.getline(str, MAX_SIZE);
    int result = isStrRight(str);
    std::cout << result << std::endl;
    return 0;
}