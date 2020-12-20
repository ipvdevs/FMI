#include <iostream>

unsigned getStrLen(const char str[]){
    unsigned length = 0;
    while (str[length] != '\0'){
        ++length;
    }
    return length;
}


int main(){
    char S1[] = "abcde";
    char S2[] = "aefhd";

    unsigned s1Len = getStrLen(S1);
    unsigned s2Len = getStrLen(S2);


    for (size_t i = 0; i < s1Len; i++)
    {
        bool isUnique = true;
        bool isLower = S1[i] >= 'a' && S1[i] < 'z';

        if (!isLower)
        {
            continue;
        }

        for (size_t j = 0; j < s2Len; j++)
        {
            if (S1[i] == S2[j])
            {
                isUnique = false;
                break;
            }
        }

        if (isUnique && isLower)
        {
            std::cout << S1[i];
        }
    }
    std::cout << std::endl;
    return 0;
}