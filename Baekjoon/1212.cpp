#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	char num8[333334];
	vector<int> total;
	vector<int> temp;

	scanf("%s", num8);

	int num = (int)num8[0] - 48;

	while(num > 1)
	{
		temp.push_back(num % 2);
		num /= 2;
	}
	temp.push_back(num);

	while(temp.size() > 0)
	{
		total.push_back(temp.back());
		temp.pop_back();
	}

	for(int i = 1; num8[i] != '\0'; i++)
	{
		num = (int)num8[i] - 48;
		while(num > 1)
		{
			temp.push_back(num % 2);
			num /= 2;
		}
		temp.push_back(num);

		int remain = 3 - temp.size();
		for(int j = 0; j < remain; j++)
			total.push_back(0);

		while(temp.size() > 0)
		{
			total.push_back(temp.back());
			temp.pop_back();
		}
	}

	for(int i = 0; i < total.size(); i++)
		printf("%d", total[i]);
	
	return 0;
}
