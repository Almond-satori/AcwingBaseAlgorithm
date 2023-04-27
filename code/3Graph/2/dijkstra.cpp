#include <cstring>
#include <iostream>

using namespace std;

const int N = 510;
int g[N][N]; // 存储图的邻接矩阵
int dist[N]; // 存储当前起点到某点的最小距离
bool st[N]; // 标识一个点是否加入集合(是否被处理过) 
int n,m;

int dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;

    // 处理n次,每次将一个节点更新到集合
    for(int i = 0; i < n; ++i)
    {   
        int t = -1; // -1标识尚未找到点
        for(int j = 1; j <= n; ++j)
        {
            // 如果点j不在集合,尚未选择点或j点距离更小,选择点j
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
            {
                t = j;
            }
        }
        st[t] = true;

        for(int j = 1; j <= n; ++j)
        {
            // 环的dist计算是 dist[t]+环的距离,
            // 在计算环本身的节点时j==t 有dist[j] <= dist[t]
            // 因此环不会被计算
            dist[j] = min(dist[j],dist[t] + g[t][j]);
        }
    }
    // 判断是否连通 
    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}

int main()
{
    scanf("%d%d",&n,&m);
    // 使用0x3f3f3f3f作为正无穷
    memset(g,0x3f,sizeof g);
    while(m--)
    {
        int a,b,v;
        scanf("%d%d%d",&a,&b,&v);
        // 存在重边,使用min规避重边
        g[a][b] = min(g[a][b],v);
    }
    int ans = dijkstra();
    printf("%d\n",ans);
    return 0;
}