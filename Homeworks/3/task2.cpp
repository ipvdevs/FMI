/**
*  
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Ivan Penev
* @idnumber 62535
* @task 2
* @compiler GCC
*
*/

#include <iostream>

const unsigned MAX_SIZE = 151;

unsigned getStrLength(char inputStr[]) {
    unsigned counter = 0;
    while (inputStr[counter] != '\0') {
        ++counter;
    }
    return counter;
}

bool validateLowerLetters(char inputStr[]) {
    int i = 0;
    while (inputStr[i] != '\0') {
        if (inputStr[i] < 'a' || inputStr[i] > 'z') {
            return false;
        }
        ++i;
    }
    return true;
}

void sortStr(char inputStr[]) {
    unsigned strLen = getStrLength(inputStr);
    for (int i = 0; i < strLen - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < strLen; ++j) {
            if (inputStr[j] < inputStr[min]) {
                min = j;
            }
        }
        char temp = inputStr[i];
        inputStr[i] = inputStr[min];
        inputStr[min] = temp;
    }
}

bool compareStrings(char buffer[], char thirdStr[]) {
    int i = 0;
    while (thirdStr[i] != '\0') {
        if (buffer[i] != thirdStr[i]) {
            return false;
        }
        ++i;
    }
    return true;
}

void trimString(char source[], unsigned begin, unsigned end, char destination[]) {
    int j = 0;
    for (int i = begin; i < end; ++i, ++j) {
        destination[j] = source[i];
    }
    destination[j] = '\0';
}

int stringsSieve(char firstStr[], char secondStr[], char thirdStr[]) {
    unsigned firstStrLen = getStrLength(firstStr);
    unsigned secondStrLen = getStrLength(secondStr);
    unsigned thirdStrLen = getStrLength(thirdStr);

    bool loweLettersValidation = validateLowerLetters(firstStr)
                                 && validateLowerLetters(secondStr)
                                 && validateLowerLetters(thirdStr);
    if (!loweLettersValidation) {
        return -1;
    }

    if (firstStrLen + secondStrLen != thirdStrLen) {
        return 0;
    }

    sortStr(firstStr);
    sortStr(secondStr);

    char firstPart_1[MAX_SIZE], secondPart_1[MAX_SIZE];
    trimString(thirdStr, 0, firstStrLen, firstPart_1);
    trimString(thirdStr, firstStrLen, thirdStrLen, secondPart_1);
    sortStr(firstPart_1);
    sortStr(secondPart_1);
    bool firstTry = compareStrings(firstStr, firstPart_1)
                    && compareStrings(secondStr, secondPart_1);
    if (firstTry) {
        return 1;
    }

    char firstPart_2[MAX_SIZE], secondPart_2[MAX_SIZE];
    trimString(thirdStr, 0, secondStrLen, firstPart_2);
    trimString(thirdStr, secondStrLen, thirdStrLen, secondPart_2);
    sortStr(firstPart_2);
    sortStr(secondPart_2);
    bool secondTry = compareStrings(secondStr, firstPart_2)
                     && compareStrings(firstStr, secondPart_2);
    if (secondTry) {
        return 1;
    }

    return 0;
}

int main() {
    char firstStr[MAX_SIZE];
    char secondStr[MAX_SIZE];
    char thirdStr[MAX_SIZE];

    std::cin >> firstStr;
    std::cin >> secondStr;
    std::cin >> thirdStr;

    int result = stringsSieve(firstStr, secondStr, thirdStr);
    std::cout << result << std::endl;
    return 0;
}