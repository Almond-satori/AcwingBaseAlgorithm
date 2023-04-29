#include <iostream>

using namespace std;

const int N = 1010;
// v表体积,w表权重
int v[N],w[N];
int f[N]; // dp数组

int main()
{
    int n,m; // n物品数量,m背包容积
    scanf("%d%d",&n,&m);

    for(int i = 1; i <= n; ++i)
    {
        scanf("%d%d",&v[i],&w[i]);
    }
    // f[]默认初始化为0

    for(int i = 1; i <= n; ++i)
    {
        for(int j = m; j >= v[i]; --j)
        {
            f[j] = max(f[j],w[i] + f[j - v[i]]);
        }
    }
    printf("%d\n",f[m]);

    return 0;
}