#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100010;
int e[N],w[N],ne[N],h[N],idx;
bool used[N]; // 控制队列中没有重复元素
int dist[N];
int n,m;

// a->b
void add(int a,int b,int z)
{
    e[idx] = b;w[idx] = z;ne[idx] = h[a];h[a] = idx++;
}

int spfa()
{
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    used[1] = true; // 1已经在队列中

    while(q.size())
    {
        int point = q.front();
        q.pop();
        // point 不在队列中
        used[point] = false;

        for(int i = h[point]; i != -1; i = ne[i])
        {
            int p2 = e[i];
            if(dist[p2] > dist[point] + w[i])
            {
                dist[p2] = dist[point] + w[i];
                // 如果p2不在队列中,将其加入队列
                if(!used[p2]){
                    q.push(p2);
                    used[p2] = true;
                }
            }
        }
    }
    return dist[n];
}

int main()
{
    memset(h,-1,sizeof h);
    memset(dist,0x3f,sizeof dist);

    scanf("%d%d",&n,&m);
    int x,y,z;
    for(int i = 0; i < m; ++i)
    {
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }
    
    int ans = spfa();
    if(ans == 0x3f3f3f3f) puts("impossible");
    else printf("%d\n",ans);
    
    return 0;
}   