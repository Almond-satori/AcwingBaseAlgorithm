#include <iostream>

using namespace std;

const int N = 110;
int n,m;
int w[N],v[N],s[N];
int f[N][N];

int main()
{
    scanf("%d%d",&n,&m);

    for(int i = 1; i <= n; ++i) scanf("%d%d%d",&v[i],&w[i],&s[i]);
    
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            // 不选的方案即k=0
            for(int k = 0; k <= s[i] && j >= k * v[i]; ++k)
            {
                f[i][j] = max(f[i][j],f[i - 1][j - k * v[i]] + k * w[i]);
            }
        }

    printf("%d",f[n][m]);
    return 0;
}