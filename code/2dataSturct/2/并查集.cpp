#include <iostream>

using namespace std;

// p[x]表示x的父节点,当p[x]==x时,代表找到了根节点,
// 此时x属于集合p[x]
const int N = 100010;
int p[N],n,m;

// 查找x的所属集合,使用路径压缩优化
int find(int x)
{
    // 将路径上的所有节点的指针都指向同一个根节点
    if(x != p[x]) p[x] = find(p[x]);
    return p[x]; // 将当前查找节点的父指针返回
}

int main()
{
    scanf("%d%d",&n,&m);
    // 初始化每个数各成一个集合
    for(int i = 1; i <= n; ++ i){
        p[i] = i;
    }
    while(m--){
        char op[2];
        int a,b;
        scanf("%s%d%d",&op,&a,&b);
        if(*op == 'M'){
            p[find(a)] = find(b);
        }else {
            if(find(a) == find(b)){
                puts("Yes");
            }else {
                puts("No");
            }
        }
    }
    return 0;
}