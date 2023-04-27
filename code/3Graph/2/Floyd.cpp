#include <iostream>

using namespace std;

const int N = 210,INF = 0x3f3f3f3f;
int d[N][N];
int m,n,k;

void floyd()
{
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    
    int x,y,z;
    while(m --)
    {
        scanf("%d%d%d",&x,&y,&z);
        d[x][y] = min(d[x][y],z);
    }

    floyd();

    while(k --)
    {
        scanf("%d%d",&x,&y);
        if(d[x][y] > INF / 2) puts("impossible");
        else printf("%d\n",d[x][y]);
    }

    return 0;
}