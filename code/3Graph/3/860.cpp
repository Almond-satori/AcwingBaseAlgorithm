#include <cstring>
#include <iostream>

using namespace std;

// 无向图开两倍
const int N = 100010,M = 200010;

int color[N]; // 记录每个节点染色情况,0未染色,1集合1,2集合2
int h[N],e[M],ne[M],idx;
int n,m;

void add(int x,int y)
{
    e[idx] = y,ne[idx] = h[x],h[x] = idx++;
}

bool dfs(int p,int c)
{   
    color[p] = c;
    for(int i = h[p]; i != -1; i = ne[i])
    {
        int j = e[i];
        // j未染色
        if(!color[j]) 
        {
            // 3-1=2 3-2=1 实现两个集合的染色
            if(!dfs(j,3 - c)) return false;
        }else if(color[j] == c) return false;
    }
    return true;
}

int main()
{
    memset(h,-1,sizeof h);
    scanf("%d%d",&n,&m);
    int u,v;
    for(int i = 0; i < m; ++i)
    {
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }

    // 二分图不一定是连通图,因此要循环处理所有节点
    bool flag = false;
    for(int i = 1; i <= n; ++i)
    {   
        // 遇到尚未填色的点,说明该点和之前已经处理的所有点不连通,颜色可以任取
        if(!color[i]) 
            if(!dfs(i,1)) 
            {   
                // 标识失败,直接退出循环
                flag = false;
                break;
            }
    }

    if(flag) puts("Yes");
    else puts("No");

    return 0;
}