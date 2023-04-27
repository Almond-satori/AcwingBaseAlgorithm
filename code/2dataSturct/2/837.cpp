#include <iostream>

using namespace std;

const int N = 100010;
// 只有根节点的size才是有效的
int p[N],n,m,sz[N];

// 查找x的根节点值,定义根节点值=所属集合的值,并采用路径压缩
int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d",&n,&m);
    
    // 初始化并查集
    for(int i = 1; i <= n; ++i){
        p[i] = i;
        sz[i] = 1;
    }
    char op[5];
    int a,b;
    while(m --){
        scanf("%s",&op);
        if(*op == 'C'){
            // 连通a和b,实际上就是合并两者所在集合
            scanf("%d%d",&a,&b);
            // 不能合并在同一个连通块的元素,size会重复合并
            if(find(a) != find(b)) {
                sz[find(b)] += sz[find(a)];
                p[find(a)] = find(b);
            }
        }else if(op[1] == '1'){
            scanf("%d%d",&a,&b);
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }else {
            scanf("%d",&a);
            printf("%d\n",sz[find(a)]);
        }
    }
    return 0;   
}