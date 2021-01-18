#include <iostream>

unsigned getStrLen(const char str[]){
    unsigned length = 0;
    while (str[length] != '\0'){
        ++length;
    }
    return length;
}

void sortStr(char str[], const unsigned strLen){    
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (size_t i = 0; i < strLen - 1; i++)
        {
            if (str[i] > str[i + 1])
            {
                std::swap(str[i], str[i + 1]);
                swapped = true;
            }
        }
    }
}

int areLettersDifferent(char str[]){
    unsigned strLen = getStrLen(str);
    
    if (strLen == 0)
    {
       std::cout << "There are no symbols!" << std::endl; 
       return -1;
    }
    
    sortStr(str, strLen);

    for (size_t i = 0; i < strLen - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            return 0;
        }
    }

    return 1;
}


int main(){
    char str[] = "abcdefgha";

    int result = areLettersDifferent(str);

    if (result != -1)
    {
        std::cout << (result ? "Yes!" : "No!") << std::endl;
    }
    
    return 0;
}