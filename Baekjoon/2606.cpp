#include <cstdio>
#include <cstring>

int C;
int total = 0;

bool map[101][101];
bool infect[101];
	
void spread(int index)
{
	for(int i = 1; i <= C; i++)
	{
		if(map[index][i] && !infect[i])
		{
			infect[i] = true;
			total++;

			spread(i);
		}
	}
}

int main()
{
	for(int i = 1; i < 101; i++)
		memset(map[i], false, sizeof(map[i]));
	memset(infect, false, sizeof(infect));

	scanf("%d", &C);

	int N;
	scanf("%d", &N);

	int C1, C2;

	while(N--)
	{
		scanf("%d %d", &C1, &C2);

		map[C1][C2] = true;
		map[C2][C1] = true;
	}

	infect[1] = true;
	spread(1);

	printf("%d\n", total);
	
	return 0;
}
