#include <iostream>

using namespace std;

typedef long long LL;

const int N = 20;
int primes[N];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i = 0; i < m; ++i) scanf("%d",&primes[i]);

    // i遍历每个多项式,使用i的二进制位标识是否选择某个数
    // 多项式个数为 2^m - 1个
    int res = 0;
    for(int i = 1; i < 1 << m; i++)
    {   
        int ans = 1,cnt = 0;
        // 对于每个质数,判断其是否在当前集合中
        for(int j = 0; j < m; ++j)
        {    
            if(i >> j & 1)
            {
                ++ cnt;
                // 该方案不可行
                if((LL)ans * primes[j] > n)
                {
                    cnt = -1;
                    break;
                }
                // 该乘积<= n,所以不会爆int
                ans = ans * primes[j];   
            }
        }
        if(cnt != -1)
        {
            if(cnt % 2) res += n / ans;
            else res -= n / ans;
        }
    }

    printf("%d\n",res);

    return 0;
}