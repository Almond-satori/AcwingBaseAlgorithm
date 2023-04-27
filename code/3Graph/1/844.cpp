#include <iostream>

using namespace std;

const int N = 110;
int n,m;
int g[N][N]; // 记录当前图中的障碍以及走过的位置

int bfs()
{
    pair<int,int> queue[N*N];
    int head = 0,top = 0;

    // 每次移动的距离记录在两个数组中
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    queue[++top] = {0,0};
    while(head <= top)
    {   
        pair<int,int> lo = queue[++head];
        for(int i = 0; i < 4; ++i)
        {
            // 生成下一位置的坐标
            int x = lo.first + dx[i],y = lo.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && !g[x][y]) {
                g[x][y] = g[lo.first][lo.second] + 1;
                queue[++top] = {x,y};
            }
        }
    }
    return g[n - 1][m - 1];
}


int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        {  
            int x;
            scanf("%d",&x);
            // 将障碍位置设置为-1
            if(x == 1) g[i][j] = -1;
            else g[i][j] = x;
        }   
    printf("%d",bfs());
}