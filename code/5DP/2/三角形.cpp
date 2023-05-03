#include <iostream>

using namespace std;

const int N = 510,INF = 0x3f3f3f3f;
int f[N][N];
int a[N][N];
int n;

int main()
{
    scanf("%d",&n);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= i ; ++j)
            scanf("%d",&a[i][j]);
    
    for(int i = 1; i <=n; ++i)
        // 当j是本行最后一列j,上一行并没有这个列,需要初始化为-INF
        for(int j = 0; j <= i + 1; ++j) f[i][j] = -INF;
    
    // 初始状态
    // f[2][1] = f[1][1] + a[2][1]
    // f[2][2] = = f[1][1] + a[2][2]
    f[1][1] = a[1][1];
    for(int i = 2; i <= n; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            f[i][j] = max(f[i-1][j],f[i-1][j-1]) + a[i][j];
        }
    }
    
    int res = -INF;
    for(int i = 1; i <= n; ++i) res = max(res,f[n][i]);
    
    printf("%d",res);
    
    return 0;
}