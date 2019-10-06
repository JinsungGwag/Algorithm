#include <cstdio>

struct Student
{
	int match;
	int love[5];
};

bool compare(Student st, int before, int after)
{
	for(int i = 0; i < 5; i++)
	{
		if(st.love[i] == before)
			return false;
		else if(st.love[i] == after)
			return true;
	}

	return false;
}

int main()
{
	int T;
	scanf("%d", &T);

	Student boys[6];
	Student girls[11];

	boys[1].love[0] = 6;
	boys[1].love[1] = 7;
	boys[1].love[2] = 8;
	boys[1].love[3] = 9;
	boys[1].love[4] = 10;

	int best;

	while(T--)
	{
		best = -1;

		for(int i = 1; i <= 5; i++)
			boys[i].match = -1;
		for(int i = 6; i <= 10; i++)
			girls[i].match = -1;

		for(int i = 2; i <= 5; i++)
			scanf("%d %d %d %d %d", &boys[i].love[0], &boys[i].love[1], &boys[i].love[2], &boys[i].love[3], &boys[i].love[4]);

		for(int i = 6; i <= 10; i++)
			scanf("%d %d %d %d %d", &girls[i].love[0], &girls[i].love[1], &girls[i].love[2], &girls[i].love[3], &girls[i].love[4]);

		bool isMatch = false;

		while(!isMatch)
		{
			for(int i = 6; i <= 10; i++)
			{
				// 매칭이 안된 여학생일 경우
				if(girls[i].match == -1)
				{
					for(int j = 0; j < 5; j++)
					{
						// 여학생 선호가 태현이일 경우 비교
						if(girls[i].love[j] == 1)
						{
							if(best == -1) 
								best = i;
							else
							{
								if(compare(boys[1], best, i))
									best = i;
							}
						}

						if(boys[girls[i].love[j]].match == -1)
						{
							girls[i].match = girls[i].love[j];
							boys[girls[i].love[j]].match = i;

							break;
						}
						else if(compare(boys[girls[i].love[j]], boys[girls[i].love[j]].match, i))
						{
							girls[i].match = girls[i].love[j];
							girls[boys[girls[i].love[j]].match].match = -1;
							boys[girls[i].love[j]].match = i;

							break;
						}
					}
				}
			}

			isMatch = true;
			for(int i = 6; i <= 10; i++)
			{
				if(girls[i].match == -1)
				{
					isMatch = false;
					break;
				}
			}

			// 태현이의 가능성 모색
			if(isMatch)
			{
				if(compare(boys[1], boys[1].match, best))
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
	}

	return 0;
}
