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
        // 注意 使用 long long类型
        long long a = p.first,b = p.second;
        long t = 1;
        // 每次计算一个
        while(b --) t = (t * a + 1) % MOD;
        res = res * t % MOD;
    }
    
    printf("%lld\n",res);

    return 0;
}