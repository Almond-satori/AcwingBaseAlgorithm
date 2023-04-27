#include <iostream>

using namespace std;

const int N = 50010;
// 并查集,当p[i] == i,认为是一个集合的根 
// v[x]表示x到根的距离
int p[N],v[N];

// 查找x的根节点,使用路径压缩
int find(int x)
{
    if(p[x] != x) 
    {
        int temp = find(p[x]);
        v[x] += v[p[x]];
        p[x] = temp;
    }
    return p[x];
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);

    // 初始化并查集
    for(int i = 1; i <= n; ++i){
        p[i] = i;
        // v[]初始值为0
    }

    int res = 0;
    while(k--)
    {
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        
        if(x > n || y > n) ++res;
        else   
        {   
            // 对合法的xy,做距离更新,并返回其根节点
            int px = find(x),py = find(y);
            if(op == 1)
            {
                // xy在同一集合中,且xy不是同类
                if(px == py && (v[x] - v[y]) % 3) ++res;
                else if(px != py)
                {   
                    // xy不在同一集合,是真话,将x的根节点合并到py
                    p[px] = py; 
                    // 修改px到py的距离
                    v[px] = v[y] - v[x];
                    // 原来px集合中的元素在下次find时被更新
                    // 这里不能改变v[px] = v[x] - v[y];
                }
            }
            else
            {
                // xy在同一集合,v[x]在模3的意义上大v[y] 1表示x 吃 y 
                if(px == py && (v[x] - v[y] - 1) % 3) ++res;
                else if(px != py)
                {
                    // 真话,将x的根节点合并到py
                    p[px] = py;
                    v[px] = v[y] - v[x] + 1;
                }
            }   
        }
    }
    printf("%d\n",res);

    return 0;
}