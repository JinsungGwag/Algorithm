#include <cstdio>
#include <cstring>

int main()
{
    int alphabet[26];
    char word[1000000];
    
    memset(alphabet, 0, sizeof(alphabet));
    
    scanf("%s", word);
    
    int index = 0;
    while(word[index] != '\0')
    {
        if((int)word[index] >= 97)
            alphabet[(int)word[index] - 97]++;
        else
            alphabet[(int)word[index] - 65]++;
        
        index++;
    }
    
    int max = -1;
    int maxIndex = -1;
    for(int i = 0; i < 26; i++)
    {
        if(alphabet[i] > max)
        {
            max = alphabet[i];
            maxIndex = i;
        }
    }
    
    int maxCount = 0;
    for(int i = 0; i < 26; i++)
    {
        if(alphabet[i] == max)
            maxCount++;
    }
    
    if(maxCount > 1)
        printf("?\n");
    else
        printf("%c\n", (char)(maxIndex + 65));
    
    return 0;
}
