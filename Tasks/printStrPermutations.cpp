#include <iostream>

int getStrLen(const char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        ++len;
    }
    return len;
}

void swapChars(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void printPermutations(char str[], int l, int r) {
    if (l == r) {
        std::cout << str << std::endl;
        return;
    }

    for (int i = l; i <= r; ++i) {
        swapChars(str[l], str[i]);
        permute(str, l + 1, r);
        swapChars(str[l], str[i]);
    }
}


int main() {
    char str[] = "123";
    int strLen = getStrLen(str);
    printPermutations(str, 0, strLen - 1);
    return 0;
}

