/**
*  
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Ivan Penev
* @idnumber 62535
* @task 5
* @compiler GCC
*
*/

#include <iostream>
#include <fstream>

const unsigned MAX_LINE_SIZE = 150;
const unsigned MAX_MSG_SIZE = 1001;

char decryptLine(const char encryptedLine[], const unsigned charsLineCount) {
    char minLineChar = encryptedLine[0];
    for (int i = 1; i < charsLineCount; ++i) {
        if (encryptedLine[i] < minLineChar) {
            minLineChar = encryptedLine[i];
        }
    }

    if (minLineChar == 'z') {
        return '.';
    }

    char decryptedSymbol = (minLineChar != 'Z') ? (char) (minLineChar + 1) : 'a';
    for (int i = 0; i < charsLineCount; ++i) {
        if (encryptedLine[i] == decryptedSymbol) {
            if (encryptedLine[i] == 'z') {
                return '.';
            }
            if (encryptedLine[i] == 'Z') {
                decryptedSymbol = 'a';
            } else {
                decryptedSymbol += 1;
            }
            i = -1;
        }
    }
    return decryptedSymbol;
}

int main() {
    std::ifstream encryptedFile;
    encryptedFile.open("message.txt", std::ios::in);

    if (!encryptedFile.is_open()) {
        std::cout << -2 << std::endl;
        return 0;
    }

    char decryptedMessage[MAX_MSG_SIZE] = "";
    int messageIndex = 0;
    char currentChar;
    unsigned charsLineCount = 0;
    char encryptedLine[MAX_LINE_SIZE] = "";

    while (!encryptedFile.eof()) {
        currentChar = encryptedFile.get();
        if (charsLineCount >= MAX_LINE_SIZE) {
            while (currentChar != '\n') {
                encryptedFile.get(currentChar);
            }
        }

        if (currentChar == '\n' || currentChar == -1) {
            if (charsLineCount != 0) {
                char decryptedLetter = decryptLine(encryptedLine, charsLineCount);
                decryptedMessage[messageIndex] = decryptedLetter;
                ++messageIndex;
            }
            charsLineCount = 0;
            continue;
        }

        bool isLetter = (currentChar >= 'A' && currentChar <= 'Z') ||
                        (currentChar >= 'a' && currentChar <= 'z');
        if (!isLetter) {
            std::cout << -1 << std::endl;
            return 0;
        }
        encryptedLine[charsLineCount] = currentChar;
        ++charsLineCount;
    }
    std::cout << decryptedMessage << std::endl;
    encryptedFile.close();
    return 0;
}