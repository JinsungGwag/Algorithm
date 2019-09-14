#include <cstdio>
#include <cstring>

int main() {
	
	int T;
	scanf("%d", &T);
	
	for(int i = 0; i < T; i++)
	{
		int N;
		scanf("%d", &N);
		
		int total = 0;
		
		for(int i = 0; i < N; i++)
		{
			int num;
			scanf("%d", &num);
			
			total += num;
		}
		
		printf("%d\n", total);
	}
	
	return 0;
}