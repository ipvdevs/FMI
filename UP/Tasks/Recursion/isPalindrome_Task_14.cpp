#include <iostream>

const int MAX_SIZE = 51;

unsigned getStrLen(const char str[]) {
    unsigned counter = 0;
    while (str[counter] != '\0') {
        ++counter;
    }
    return counter;
}

bool isStrPalindrome(const char str[], unsigned begin, unsigned end) {
    if (end <= begin) {
        return true;
    }
    if (str[begin] != str[end]) {
        return false;
    }
    return isStrPalindrome(str, ++begin, --end);
}

int main() {
    char str[MAX_SIZE];
    std::cin.getline(str, MAX_SIZE);
    unsigned strLen = getStrLen(str);
    bool result = isStrPalindrome(str, 0, strLen - 1);
    std::cout << result;
    return 0;
}