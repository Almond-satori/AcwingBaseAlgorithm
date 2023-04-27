#include <iostream>
#include <algorithm>

using namespace std;

const int M = 200010;
int n,m;
int p[M];

struct edge
{
    int a,b,w;
    // 返回true表示优先,w更小者优先
    bool operator<(const edge &e)
    {
        return w < e.w;
    }
}edges[M];

int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d",&n,&m);
    
    int a,b,w;
    for(int i = 0; i < m;++i)
    {   
        scanf("%d%d%d",&a,&b,&w);
        edges[i].a = a;edges[i].b = b;edges[i].w = w;
    }

    // 初始化并查集
    for(int i = 0; i < m; ++i) p[i] = i;

    sort(edges,edges + m);

    int res = 0,cnt = 0;
    for(int i = 0; i < m; ++i)
    {
        int a = edges[i].a,b = edges[i].b,w = edges[i].w;
        // ab不连通
        if(find(a) != find(b))
        {
            res += w;
            ++cnt;
            // 将a的根节点的父节点更新为b的根节点
            p[find(a)] = p[b]; 
        }
    }
    
    if(cnt != n - 1) puts("impossible");
    else printf("%d",res);
    
    return 0;
}