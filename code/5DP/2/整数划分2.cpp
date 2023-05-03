#include <iostream>

using namespace std;

const int N = 1010,mod = 1e9 + 7;
int f[N][N];

int main()
{
    int n;
    scanf("%d",&n);

    // 拼出数字0,使用0个数的方案为1
    f[0][0] = 1;
    
    // 凑成数字i,在循环中,状态转移时,使用的数字不包含0
    for(int i = 1; i <= n; ++i)
    {   
        // 使用j个数字拼出i
        for(int j = 1; j <= i; ++j)
        {
            // 情况2中f[0][j]恒等于0,因为j和i相等时,只有全选1的情况
            f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % mod;
        }
    }

    int res = 0;
    for(int i = 1; i <= n; ++i) res = (res + f[n][i]) % mod;

    printf("%d\n",res);
    return 0;
}