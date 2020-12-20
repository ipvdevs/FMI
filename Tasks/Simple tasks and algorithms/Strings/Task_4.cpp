#include <iostream>

unsigned getStrLen(const char str[]){
    unsigned length = 0;
    while (str[length] != '\0'){
        ++length;
    }
    return length;
}

void convertToLowerLetters(char str[]){
    unsigned strLen = getStrLen(str);

    for (size_t i = 0; i < strLen; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            //1 << 5 = 32 - difference between capital and lower letter
            str[i] = str[i] + (1 << 5); 
        }
    }
    
}


int main(){
    char str[] = "CONVERT TO LOWER LETTERS.";

    convertToLowerLetters(str);

    std::cout << str << std::endl;
    return 0;
}