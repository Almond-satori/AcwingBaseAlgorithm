#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1000010;

typedef pair<int,int> PII;
// 稀疏图使用邻接表
int h[N],e[N],ne[N],w[N],idx;
bool used[N]; // 存储结点是否加入集合
int dist[N]; // 记录当前情况下,起点到某一个点的最小距离
int n,m;

// a->b
void add(int a,int b,int v)
{
    e[idx] = b;w[idx] = v;ne[idx] = h[a];h[a] = idx++;
}

int dijkstra_pq()
{
    // <点到集合的距离,该点>
    priority_queue<PII,vector<PII>,greater<PII>> pq;
    pq.push({0,1});
    dist[1] = 0;
    
    while(pq.size())
    {
        // 取出最短边
        PII p = pq.top(); pq.pop();
        int distance = p.first,point = p.second;

        // 点不在集合中,使用该点更新边,否则跳过
        if(!used[point])
        {
            for(int i = h[point]; i != -1; i = ne[i])
            {   
                int point2 = e[i];
                if(w[i] + distance < dist[point2])
                {
                    dist[point2] = w[i] + distance;
                    // 不删除值较大的边,因为是小堆,会优先取边权值小的边
                    pq.push({w[i] + distance,point2});
                }
            }
        }
        used[point] = true; //标识该点已经被使用
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    memset(dist,0x3f,sizeof dist);
    memset(h,-1,sizeof h);

    scanf("%d%d",&n,&m);
    int x,y,z;
    for(int i = 0; i < m; ++i)
    {
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }
    int ans = dijkstra_pq();
    printf("%d\n",ans);
    return 0;
}