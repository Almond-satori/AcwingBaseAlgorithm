#include <iostream>

using namespace std;

const int N = 310,INF = 1e8;
int f[N][N],s[N];
int n;

int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i) scanf("%d",&s[i]);

    for(int i = 1; i <= n; ++i) s[i] += s[i - 1];

    // len是区间长度
    for(int len = 2; len <= n; ++len)
    {   
        // i是区间起始位置 
        for(int i = 1; i + len - 1 <= n; ++i)
        {      
            int l = i,r = i + len - 1;
            f[l][r] = INF;
            // k是分界点,k从l开始,表示l自成一组,剩余石子一组,f[l,l]被初始化为0
            for(int k = l; k < r; ++k)
            {
                f[l][r] = min(f[l][r],f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }

    printf("%d",f[1][n]);

    return 0;
}