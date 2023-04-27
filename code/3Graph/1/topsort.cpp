#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010;

int e[N],ne[N],h[N],idx;
int d[N]; // 记录入度
int n,m;
int q[N]; // 队列

// a->b
void add(int a,int b)
{
    e[idx] = b;ne[idx] = h[a];h[a] = idx++;
}

// 1.有向无环图一定有一个入度为0的点,
// 2.假设图是一个有向无环图,其子图也是有向无环图
// 删除所有入度为0点的出度(即得到一个子图),这个子图也是有向无环图
// 子图也会有入度为0的点,这样不断循环,如果所有点都加入过队列,说明是有向无环图
bool topsort()
{
    int tt = -1,hh = 0;
    // 将入度为0的点加入队列,作为起点
    for(int i = 1;i <= n; ++i)
        if(!d[i]) q[++tt] = i;

    while(hh <= tt)
    {
        int u = q[hh++];
        for(int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            // 每次删除掉u->j的边
            --d[j];
            // 如果j入度为0,加入队列
            if(!d[j])
            { 
                q[++tt] = j;
            }
        }
    }
    return tt == n - 1;
}

int main()
{
    scanf("%d%d",&n,&m);

    memset(h,-1,sizeof h);

    int a,b;
    for(int i = 0; i < m; ++i)
    {
        scanf("%d%d",&a,&b);
        add(a,b);
        ++d[b];
    }
    
    if(topsort())
    {   
        // q[] 虽然hh == n,tt == n-1,但q[0,n-1]的元素还在
        for(int i = 0; i < n; ++ i)
        {
            printf("%d ",q[i]);
        }
    }
    else printf("-1");
    return 0;
}