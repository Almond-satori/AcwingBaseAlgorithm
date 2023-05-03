#include <iostream>

using namespace std;

const int N = 1010;
// g用于记录状态转移的方案
int f[N],a[N],g[N];
int n;

int main()
{
    scanf("%d",&n);

    for(int i = 1; i <= n; ++i) scanf("%d",&a[i]);

    // 单一数字的序列长度1
    for(int i = 1; i <= n; ++i) f[i] = 1;
    
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1 ; j < i; ++j)
            if(a[i] > a[j])
            {
                if(f[j] + 1 > f[i]) {
                    g[i] = j; // 将当前转移到的j记录
                    f[i] = f[j] + 1; 
                }
            }
    }

    // 选择最优解
    int k = 0; // f[k]初始为0
    for(int i = 1; i <= n; ++i)
    {
        if(f[i] > f[k])
        {
            k = i;
        }
    }

    // 最优解中有f[k]个数 
    int len = f[k];
    for(int i = 0; i < len; ++i)
    {
        printf("%d ",a[k]);
        k = g[k];
    }
    
    return 0;
}