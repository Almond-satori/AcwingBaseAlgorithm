#include <iostream>

using namespace std;

const int N = 1010;
int num[N][N],n,m,q,prefix[N][N];

int main()
{
    scanf("%d%d%d",&n,&m,&q);

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            scanf("%d",&num[i][j]);
    
    //生成前缀和
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            prefix[i][j] = 
                prefix[i - 1][j] 
                + prefix[i][j - 1] 
                - prefix[i - 1][j - 1] 
                + num[i][j];

    while(q --){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n",
            prefix[x2][y2] 
            - prefix[x1 - 1][y2] 
            - prefix[x2][y1 - 1] 
            + prefix[x1 - 1][y1 - 1]
        );
    }
    return 0;
}
