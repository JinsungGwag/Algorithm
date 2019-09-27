#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    
    int num[100000];
    for(int i = 0; i < N; i++)
        scanf("%d", &num[i]);
    
    sort(num, num + N);
    
    int M;
    int first, last, mid;
    int check;
    scanf("%d", &M);
    
    for(int i = 0; i < M; i++)
    {
        scanf("%d", &check);
        
        first = 0;
        last = N - 1;
        while(first <= last)
        {
            mid = (first + last) / 2;
            if(num[mid] == check)
                break;
            else if(num[mid] > check)
                last = mid - 1;
            else
                first = mid + 1;
        }
        
        if(num[mid] == check)
            printf("1\n");
        else
            printf("0\n");
    }
    
    return 0;
}
