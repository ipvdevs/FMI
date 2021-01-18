#include <iostream>

unsigned getStrLen(const char S1[]) {
    unsigned len = 0;
    while (S1[len] != '\0') {
        ++len;
    }
    return len;
}

unsigned countOccurrences(const char S1[], const char S2[]) {
    unsigned counter = 0;
    unsigned S1Len = getStrLen(S1);
    unsigned S2Len = getStrLen(S2);

    if (S1Len < S2Len) {
        std::cout << "S2 is shorter than S1";
        return 0;
    }

    for (int i = 0; i < S1Len; ++i) {
        bool diff = false;
        for (int j = 0; j < S2Len; ++j) {
            if (S1[i] != S2[j]) {
                diff = true;
                break;
            } else {
                ++i;
            }
        }
        if (!diff) {
            ++counter;
        }
    }

    return counter;
}

int main() {
    char S1[] = "How much wood would a woodchuck chuck if a woodchuck could chuck wood?\n"
                "He would chuck, he would, as much as he could, and chuck as much wood\n"
                "As a woodchuck would if a woodchuck could chuck wood";
    char S2[] = "wood";

    unsigned counter = countOccurrences(S1, S2);

    std::cout << counter;

    return 0;
}

