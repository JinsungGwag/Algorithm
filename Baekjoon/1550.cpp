#include <cstdio>
#include <cmath>

int main()
{
	char num16[7];
	scanf("%s", num16);

	int size = 0;
	for(int i = 0; num16[i] != '\0'; i++)
		size++;
	
	int total = 0;
	for(int i = 0; i < size; i++)
	{
		if((int)num16[i] <= 70 && (int)num16[i] >= 65)
			total += ((int)num16[i] - 55) * pow((double)16, size - i - 1);
		else
			total += ((int)num16[i] - 48) * pow((double)16, size - i - 1);
	}

	printf("%d", total);

	return 0;
}
