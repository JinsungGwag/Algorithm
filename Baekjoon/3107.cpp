#include <cstdio>
#include <cstring>
#include <Windows.h>

int main()
{
	char ipv6[8][5];
	char input[40];

	for(int i = 0; i < 8; i++)
		memset(ipv6[i], '\0', sizeof(ipv6[i]));

	scanf("%s", input);

	int start = 0;
	int index = 0;
	for(int i = 0; true; i++)
	{
		if(input[i] ==	':')
		{
			if(start == i)
				strcpy(ipv6[index], "");
			else
				strncpy(ipv6[index], input + start, i - start);
			
			index++;
			start = i + 1;
		}

		if(input[i] == '\0')
		{
			if(start == i)
				strcpy(ipv6[index], "");
			else
				strncpy(ipv6[index], input + start, i - start);

			break;
		}
	}

	// :: 예외 처리
	int blank = 0;
	for(int i = 0; i < 8; i++)
	{
		if(strcmp(ipv6[7 - i], "\0"))
		{
			blank = i;
			break;
		}
	}

	for(int i = 0; i < 8; i++)
	{
		if(!strcmp(ipv6[i], "\0"))
		{
			strcpy(ipv6[i], "0000");
		}
		else
		{
			int size = strlen(ipv6[i]);
			if(size < 4)
			{
				ipv6[i][4] = '\0'; 
				for(int j = 3; j > 3 - size; j--)
					ipv6[i][j] = ipv6[i][j - (4 - size)];
				for(int j = 0; j <= 3 - size; j++)
					ipv6[i][j] = '0';
			}
		}
	}

	if(blank > 0)
	{
		for(int i = 7; i > 7 - blank; i--)
		{
			strcpy(ipv6[i], ipv6[i - blank]);
			strcpy(ipv6[i - blank], "0000");
		}
	}
	
	for(int i = 0; i < 8; i++)
		printf("%s\n", ipv6[i]);

	system("pause");
	return 0;
}
