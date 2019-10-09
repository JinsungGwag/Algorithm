#include <cstdio>
#include <cmath>

long long first = 0;
long long second = 0;

void longnumber(int N)
{
	while(N--)
	{
		first *= 2;
		second = second * 2 + 1;
		first += second / 1000000000000000000;
		second %= 1000000000000000000;
	}
}

void hanoi(int plate, int start, int end, int sub)
{
	if(plate == 1)
	{
		printf("%d %d\n", start, end);
		return;
	}

	hanoi(plate - 1, start, sub, end);
	
	// 본 원판 이동
	printf("%d %d\n", start, end);

	hanoi(plate - 1, sub, end, start);
}

int main()
{
	int N;
	scanf("%d", &N);

	longnumber(N);

	if(first > 0)
		printf("%lld%lld\n", first, second);
	else
		printf("%lld\n", second);

	if(N <= 20)	hanoi(N, 1, 3, 2);

	return 0;
}
