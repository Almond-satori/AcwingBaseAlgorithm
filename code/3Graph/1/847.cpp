#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;
int n,m;
// 注意不要忘记给h赋初值-1
int h[N],e[N],ne[N],idx;
int d[N];

// a->b
void add(int a, int b)
{
    e[idx] = b;ne[idx] = h[a];h[a] = idx++;
}

// 返回u到n节点的最小距离
void bfs()
{   
    int u = 1;
    // -1标记未使用节点
    memset(d,-1,sizeof d);
    int q[N],tt = -1,hh = 0;
    q[++tt] = u;
    d[u] = 0;
    while(hh <= tt)
    {
        int x = q[hh++];
        for(int i = h[x]; i != -1; i = ne[i])
        {
            int j = e[i];
            // j已经使用,跳过
            if(d[j] != -1) continue;
            q[++tt] = j;
            // 更新距离的时候,自动将节点设置为已使用
            d[j] = d[x] + 1;
        }
    }
}

int main()
{
    memset(h,-1,sizeof h);
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i = 0; i < m; ++i){
        scanf("%d%d",&a,&b);
        // 建立a->b
        add(a,b); 
    }
    bfs();
    printf("%d",d[n]);
}