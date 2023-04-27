#include <iostream>
#include <cstring>

using namespace std;

// 树的边比节点少一1,边有a->b和b->a,因此数量是节点两倍
const int N = 100010,M = N * 2;

// 邻接表存储图
// h[N]存每个节点的头指针
int h[N],e[M],ne[M],idx;
bool used[N];
int ans = N; //最小的删除重心后连通块点数的最大值
int n;

// 添加边a->b
void add(int a,int b)
{
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

// 从节点u开始对树中每个节点进行搜索,返回删除u后的连通块点数的最大值
int dfs(int u)
{
    used[u] = true;
    // 删除u后的各连通块点数的最大值为res,u以及其子树中连通块点数之和为sum
    int res = 0,sum = 1;
    // 从u的连通节点开始寻找(因为是无向图,会遍历整个树)
    for(int i = h[u]; i != -1; i = ne[i])
    {   
        // i是链表下标,递归中需要拿到下一个节点的节点编号,以查找头结点
        int j = e[i];
        // 保证不会扩展之前遍历的节点,这个节点的连通点数通过n-sum计算
        if(used[j]) continue;
        // 查找其中一个子节点的连通点数最大值
        int s = dfs(j);
        sum += s;
        res = max(res,s);
    }
    // 计算未扩展部分的连通点数
    res = max(res,n - sum);
    ans = min(ans,res);
    return sum;
}

int main()
{
    // h[x]==-1,表示不指向任何链表
    // memset按照字节赋值,-1补码是全1,因此可以这样赋值
    memset(h,-1,sizeof h);
    scanf("%d",&n);
    int a,b;
    for(int i = 0; i < n; ++i){
        scanf("%d%d",&a,&b);
        add(a,b),add(b,a);
    }
    dfs(1);
    printf("%d",ans);
    return 0;
}