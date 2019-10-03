#include <cstdio>
#include <cstring>

int main()
{
	int coin[100];
	int total[10001];

	memset(total, 10001, sizeof(total));

	int n, k;
	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &coin[i]);

		if(coin[i] <= 10000)
			total[coin[i]] = 1;
	}

	for(int i = 1; i <= k; i++)
	{
		int min = 10001;
		for(int j = 0; j < n; j++)
		{
			if(i - coin[j] < 1) continue;
	
			if(min > total[i - coin[j]])
				min = total[i - coin[j]];
		}
		if(total[i] > min + 1)
			total[i] = min + 1;
	}

	if(total[k] > 10000)
		printf("-1\n");
	else
		printf("%d\n", total[k]);

	return 0;
}
