#include <iostream>
#include <unordered_map>

using namespace std;
long long MOD = 1e9 + 7;
unordered_map<int,int> primes;

void get_primes(int n)
{   
    // 注意<=
    for(int i = 2; i <= n / i; ++i)
    {
        while(n % i == 0)
        {
            ++primes[i];
            n /= i;
        }
    }

    if(n > 1) ++primes[n];
}       

int main()
{
    int n,a;
    scanf("%d",&n);

    for(int i = 0; i < n; ++i)
    {
        scanf("%d",&a);
        get_primes(a);
    }   

    long long res = 1;
    for(auto p : primes)
    {   
        // 注意这里一定要先算 res * (p.second + 1) 得到一个很大的数,再取模
        // 对一个约束个数(很小的数)取模再乘res是没有意义的
        res = res * (p.second + 1) % MOD;
    }
    // 注意输出lld
    printf("%lld\n",res);

    return 0;
}