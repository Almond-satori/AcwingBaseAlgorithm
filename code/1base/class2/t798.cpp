#include <iostream>

using namespace std;

const int N = 1010;
int n,m,q,num[N][N],pre[N][N];

void insert(int x1,int y1,int x2,int y2,int c)
{
    pre[x1][y1] += c;
    pre[x2 + 1][y1] -= c;
    pre[x1][y2 + 1] -= c;
    pre[x2 + 1][y2 + 1] += c;
}

int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            scanf("%d",&num[i][j]);
    
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            insert(i,j,i,j,num[i][j]); //初始化数组
    
    while(q --){
        int x1,y1,x2,y2,c;
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
        insert(x1,y1,x2,y2,c);
    }

    //在pre数组上还原num数组
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j)
            printf("%d ",pre[i][j]);
        printf("\n");
    }
    return 0;
}