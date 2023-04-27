#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 2010,M = 10010;
int e[M],w[M],ne[M],h[N],idx; // 注意边要开M个
int n,m;
bool st[N];
int dist[N],cnt[N]; // 存储各个点到起点的距离,当前集合中点的个数

void add(int x,int y,int z)
{
    e[idx] = y;w[idx] = z;ne[idx] = h[x];h[x] = idx++;
}

bool spfa()
{
    queue<int> q;
    // 起点不一定能连通负数环的点,将所有点都加入队列判断
    for(int i = 1; i <= n; ++i)
    {
        q.push(i);
        st[i] = true;
        // dist[i] 默认初始化为0
    }

    while(q.size())
    {
        int p1 = q.front();
        q.pop();
        st[p1] = false;

        for(int i = h[p1]; i != -1; i = ne[i])
        {
            int p2 = e[i]; 
            // 由于dist初始化为0,只会记录负数边
            // 存在负数环,就会循环将负数环的元素加入队列,每次计算dist都会更小,直到计数到n
            if(dist[p2] > dist[p1] + w[i])
            {
                dist[p2] = dist[p1] + w[i];
                // 更新边的个数 
                cnt[p2] = cnt[p1] + 1;
                // 如果边有n条,点有n+1个,一定有环
                if(cnt[p2] >= n) return true;
                if(!st[p2])
                {
                    q.push(p2);
                    st[p2] = true;
                }
            }
        }   
    }
    
    return false;
}

int main()
{
    memset(h,-1,sizeof h);

    scanf("%d%d",&n,&m);
    int x,y,z;
    for(int i = 0; i < m; ++i)
    {
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }
    if(spfa()) puts("Yes");
    else puts("No");

    return 0;
}