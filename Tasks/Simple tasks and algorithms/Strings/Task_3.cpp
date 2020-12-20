#include <iostream>

unsigned getStrLen(const char str[]){
    unsigned length = 0;
    while (str[length] != '\0'){
        ++length;
    }
    return length;
}

int skipInitialSpaces(const char str[]){
    int index = 0;
    while (str[index] == ' '){
        ++index;
    }
    return index;
}

unsigned countWords(const char str[]){
    unsigned strLen = getStrLen(str);

    int i = skipInitialSpaces(str);

    unsigned wordsCounter = 0;
    while (i < strLen)
    {
        if (str[i] == ' ' && str[i - 1] != ' ')
        {
            ++wordsCounter;
        }
        ++i;
    }

    if (str[strLen - 1] != ' ')
    {
        return wordsCounter + 1;
    }
    return wordsCounter;
}

int main(){
    char str[] = "Count words in this sentence";

    unsigned result = countWords(str);

    std::cout << result << std::endl;
    return 0;
}