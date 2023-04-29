#include <iostream>

using namespace std;

// N是打包后的物品总数 N*logs
const int N = 11000;
int n,m;
int f[N],v[N],w[N];

int main()
{
    scanf("%d%d",&n,&m);

    int cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        int a,b,c; // 体积价值数量
        scanf("%d%d%d",&a,&b,&c);

        int k = 1;
        while(k < c) 
        {
            ++cnt;
            v[cnt] = k * a;
            w[cnt] = k * b;
            c -= k;
            k <<= 1;
        }
        // 生成最后一个组
        if(c > 0)
        {   
            ++cnt;
            v[cnt] = c * a;
            w[cnt] = c * b;
        }
    }

    // f[0][x] f[x][0]初始化为0
    // 物品从1开始
    for(int i = 1; i <= cnt; ++i)
        for(int j = m; j >= v[i]; --j)
        {
            f[j] = max(f[j],f[j - v[i]] + w[i]);
        }

    printf("%d",f[m]);
    return 0;
}