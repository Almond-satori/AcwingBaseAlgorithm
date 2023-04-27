#include <iostream>
#include <cstring>

using namespace std;

const int N = 510,M = 10010;
int n,m,k;
// dist记录经过当前循环个边能到达的点的最小距离
// backup记录上次循环的dist,因为本次循环会破坏上次的内容
int dist[N],backup[N];

struct{
    // a->b
    int a,b,w;
}edge[M];

int bellman_ford()
{
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;

    // 每次循环i + 1可以代表从起点出发可以经过边的个数
    for(int i = 0; i < k; ++i)
    {      
        // 提前存储上一次的数组
        memcpy(backup,dist,sizeof dist);
        for(int j = 0; j < m; ++j)
        {
            int a = edge[j].a,b = edge[j].b,w = edge[j].w;
            if(dist[b] > backup[a] + w) {
                dist[b] = backup[a] + w;
            }
        }
    }
    return dist[n];
}

int main()
{
    scanf("%d%d%d", &n,&m,&k);
    int x,y,z;
    for(int i = 0; i < m; ++i)
    {
        scanf("%d%d%d",&x,&y,&z);
        edge[i].a = x;edge[i].b = y;edge[i].w = z;
    }   
    int ans = bellman_ford();
    
    // 边权值可能为负数,因此可能将数据更新为 无穷-w
    if(ans >= 0x3f3f3f3f / 2) puts("impossible");
    else printf("%d\n",ans);
    
    return 0;
}