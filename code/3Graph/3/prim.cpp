#include <iostream>
#include <cstring>

using namespace std;

const int N = 510,INF = 0x3f3f3f3f;
int g[N][N],dist[N]; // dist指当前点到集合的距离,而不是到起点的距离
int st[N]; // 标识当前点是否被使用
int n,m;

int prim()
{   
    memset(dist,0x3f,sizeof dist);

    int res = 0;
    // 循环n次每次循环在集合s中加入一个点
    for(int i = 0; i < n; ++i)
    {   
        int t = -1; // t表示目标点
        // 寻找距离集合最近的点
        for(int j = 1; j <= n; ++j)
        {
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
            {
                t = j;
            }
        }   
        // 起点的dist是INF,要特殊处理,但找其他点时,距离是INF,说明连通不到s集合直接返回
        if(i && dist[t] == INF) return INF;
        // t点加入集合,起点距离定义为INF,不计入总距离
        if(i) res += dist[t];
        st[t] = true;

        // 用t点更新其他点到集合的距离
        for(int j = 1; j <= n; ++j)
        {   
            // g[t][j]是j到集合的距离
            // 只对集合外的点进行更新
            if(!st[j] && dist[j] > g[t][j]) dist[j] = g[t][j];
        }
    }
    return res;
}

int main()
{   
    memset(g,0x3f,sizeof g);
    scanf("%d%d",&n,&m);
    int a,b,c;
    while(m -- )
    {
        scanf("%d%d%d",&a,&b,&c);
        // 可能有重边
        g[a][b] = g[b][a] = min(g[a][b],c);
    }

    int sum = prim();
    if(sum == INF) puts("impossible");
    else printf("%d\n",sum);

    return 0;
}