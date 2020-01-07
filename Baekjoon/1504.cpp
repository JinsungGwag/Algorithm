#include <cstdio>
#include <cstring>

int N, E;
int map[801][801];
int shortest[801][801];

// 배열 초기화
void initArray()
{
    for(int i = 1; i <= N; i++)
        memset(shortest[i], -1, sizeof(int) * (N + 1));
}

// 시작점에서 목적지까지의 최단거리 탐색
void searchShort(int pre, int dis, int start, int end)
{
    // 시작이랑 끝이 동일할 때 경우 처리
    if(start == end)
    {
        shortest[start][end] = 0;
        return;
    }
    
    for(int i = 1; i <= N; i++)
    {
        if(map[pre][i] == -1)
            continue;
        
        if(shortest[start][i] == -1)
        {
            shortest[start][i] = dis + map[pre][i];
            if(i != end)
                searchShort(i, dis + map[pre][i], start, end);
        }
        else if(dis + map[pre][i] < shortest[start][i])
        {
            shortest[start][i] = dis + map[pre][i];
            if(i != end)
                searchShort(i, dis + map[pre][i], start, end);
        }
    }
}

int main()
{
    scanf("%d %d", &N, &E);
    initArray();
    
    // 맵 전체 초기화
    for (int i = 1; i <= N; i++)
        memset(map[i], -1, sizeof(int) * (N + 1));
    
    int n1, n2, dis;
    for(int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &n1, &n2, &dis);
        map[n1][n2] = dis;
        map[n2][n1] = dis;
    }
    
    scanf("%d %d", &n1, &n2);
    
    int way1 = 0;
    int way2 = 0;
    
    // 경로1의 최단거리 탐색
    searchShort(1, 0, 1, n1);
    if(shortest[1][n1] == -1)
        way1 = -1;
    else
    {
        way1 += shortest[1][n1];
        initArray();
        searchShort(n1, 0, n1, n2);
        if(shortest[n1][n2] == -1)
            way1 = -1;
        else
        {
            way1 += shortest[n1][n2];
            initArray();
            searchShort(n2, 0, n2, N);
            if(shortest[n2][N] == -1)
                way1 = -1;
            else
                way1 += shortest[n2][N];
        }
    }
    
    // 경로2의 최단거리 탐색
    initArray();
    searchShort(1, 0, 1, n2);
    if(shortest[1][n2] == -1)
        way2 = -1;
    else
    {
        way2 += shortest[1][n2];
        initArray();
        searchShort(n2, 0, n2, n1);
        if(shortest[n2][n1] == -1)
            way2 = -1;
        else
        {
            way2 += shortest[n2][n1];
            initArray();
            searchShort(n1, 0, n1, N);
            if(shortest[n1][N] == -1)
                way2 = -1;
            else
                way2 += shortest[n1][N];
        }
    }
    
    if (way1 == -1 && way2 == -1)
        printf("-1\n");
    else if(way1 == -1 || way2 == -1)
        printf("%d\n", way1 == -1 ? way2 : way1);
    else
        printf("%d\n", way1 <= way2 ? way1 : way2);
    
    return 0;
}
