#include <iostream>

unsigned getStrLen(const char str[]){
    unsigned length = 0;
    while (str[length] != '\0'){
        ++length;
    }
    return length;
}

bool isStrPalindrome(const char str[]){
    unsigned strLen = getStrLen(str);
    for (size_t i = 0; i < strLen; i++)
    {
        if (str[i] != str[strLen - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int main(){
    char str[] = "nolemonnomelon";

    bool result = isStrPalindrome(str);

    std::cout << (result ? "true" : "false") << std::endl;
    return 0;
}