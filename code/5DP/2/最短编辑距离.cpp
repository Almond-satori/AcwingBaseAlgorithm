#include <iostream>

using namespace std;

const int N = 1010;
int n,m;
char a[N],b[N];
int f[N][N];

int main()
{
    scanf("%d%s",&n,a + 1);
    scanf("%d%s",&m,b + 1);

    // 初始化,将a[0:i]变为b[0](即空串)需要删除i次
    for(int i = 1; i <= n; ++i) f[i][0] = i;
    // 将空串变为b[0:i]需要增加i次
    for(int i = 1; i <= m; ++i) f[0][i] = i;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            // 删除和增加的情况
            f[i][j] = min(f[i - 1][j] + 1,f[i][j - 1] + 1);
            // 判断是否需要改变
            if(a[i] == b[j]) f[i][j] = min(f[i][j],f[i - 1][j - 1]);
            else f[i][j] = min(f[i][j],f[i - 1][j - 1] + 1);
        }

    printf("%d\n",f[n][m]);
    return 0;
}