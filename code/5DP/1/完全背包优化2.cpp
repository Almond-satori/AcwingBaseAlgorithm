#include <iostream>

using namespace std;

const int N = 1010;
int w[N],v[N]; // w权重,v体积
int f[N];

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
        for(int j = v[i]; j <= m; ++j)
        {
            f[j] = max(f[j],f[j - v[i]] + w[i]);
        }

    printf("%d",f[m]);

    return 0;
}
