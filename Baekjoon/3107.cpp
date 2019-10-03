#include <cstdio>
#include <cstring>

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

	int blank = 0;
	for(int i = 0; i < 8; i++)
	{
		if(strcmp(ipv6[7 - i], "\0"))
		{
			blank = i;
			break;
		}
	}

	// ::가 뒤에 있는지 판별
	bool behind = false;
	int back = -1;
	for(int i = 0; i < 8; i++)
	{
		if(!strcmp(ipv6[i], "\0"))
		{
			back = i;
			break;
		}
	}
	if(back != 0 && (back == 7 || !strcmp(ipv6[back + 1], "\0")))
		behind = true;

	bool change = false;
	bool check = false;
	start = 0;
	for(int i = 0; i < 8; i++)
	{
		if(!strcmp(ipv6[i], "\0"))
		{
			strcpy(ipv6[i], "0000");
			if(!check) change = true;
		}
		else
		{
			if(change)
			{
				start = i;
				change = false;
				check = true;
			}

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

	if(blank > 0 && !behind)
	{
		int repeat = 7 - start - blank;

		for(int i = start + repeat; i >= start; i--)
		{
			strcpy(ipv6[i + blank], ipv6[i]);
			strcpy(ipv6[i], "0000");
		}
	}
	
	for(int i = 0; i < 7; i++)
		printf("%s:", ipv6[i]);
	printf("%s\n", ipv6[7]);

	return 0;
}
