#include <iostream>

using namespace std;

const int N = 110;
// w[i][j]表示第i组j个物品的权重,s[N]记录每组的元素个数
int w[N][N],v[N][N],s[N];
int f[N];

int main()
{   
    int n,m;
    scanf("%d%d",&n,&m);

    // 分组从1开始的
    for(int i = 1; i <= n; ++i)
    {   
        // s[i]是i组物品数量
        scanf("%d",&s[i]); 
        // 对于每一组的可选物品存储在[0,s[i] - 1]
        for(int j = 0; j < s[i]; ++j)
        {
            scanf("%d%d",&v[i][j],&w[i][j]);
        }
    }

    for(int i = 1; i <= n; ++i)
        for(int j = m; j > 0; --j)
            for(int k = 0; k < s[i]; ++k)
                //这个条件不能写在循环中,会提前终止循环,而循环必须遍历所有选项
                if(j >= v[i][k]) 
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);

    printf("%d",f[m]);
    return 0;
}