#include <iostream>

unsigned getStrLen(const char str[]){
    unsigned length = 0;
    while (str[length] != '\0'){
        ++length;
    }
    return length;
}

unsigned countSpecialSymbols(const char str[], const char specialSymbols[]){
    unsigned strLen = getStrLen(str);
    unsigned specSymbsLen = getStrLen(specialSymbols);

    unsigned count = 0;
    for (size_t i = 0; i < strLen; i++)
    {
        char currentStrChar = str[i];
        for (size_t i = 0; i < specSymbsLen; i++)
        {
            char specialSymbol = specialSymbols[i];
            if (currentStrChar == specialSymbol)
            {
                ++count;
            }
        }
    }
    return count;
}

int main(){
    char str[] = "Hi, is this you? Yeah, it's me!";
    char specialSymbols[] = "!,?";

    unsigned result = countSpecialSymbols(str, specialSymbols);

    std::cout << result << std::endl;
    return 0;
}