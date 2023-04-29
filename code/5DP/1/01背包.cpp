#include <iostream>

using namespace std;

const int N = 1010;
// v表体积,w表权重
int v[N],w[N];
int f[N][N]; // dp数组

int main()
{
    int n,m; // n物品数量,m背包容积
    scanf("%d%d",&n,&m);

    for(int i = 1; i <= n; ++i)
    {
        scanf("%d%d",&v[i],&w[i]);
    }
    // f[0][x]和f[x][0] 默认初始化为0

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <=m; ++j)
        {
            f[i][j] = f[i - 1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j],w[i] + f[i - 1][j - v[i]]);
        }
    }
    printf("%d\n",f[n][m]);

    return 0;
}