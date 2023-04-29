#include <iostream>

using namespace std;

const int N = 1010;
int w[N],v[N]; // w权重,v体积
int f[N][N];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d%d",&v[i],&w[i]);
    }

    // f[0][x] f[x][0] 初始化为0
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            f[i][j] = f[i-1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j],f[i][j - v[i]] + w[i]);
        }

    printf("%d",f[n][m]);

    return 0;
}
