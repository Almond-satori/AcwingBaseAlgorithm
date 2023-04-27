#include <iostream>

using namespace std;

typedef long long LL;

// mod是质数
const int mod = 1e9 + 7;

// a ^ k % p (p是质数)
int quick_mi(int a,int k,int p)
{
    int res = 1;
    while(k)
    {
        if(k & 1) res = (LL)res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

// c(a,b) % MOD 
int calc(int a,int b)
{
    int fact = 1;
    // a!/(a-b)!一起计算,计算范围[a,a-b)
    for(int i = a; i > a - b ; --i) fact = (LL)fact * i % mod;
    
    // 1/b! 
    for(int i = 1; i <= b; ++i) 
        fact = (LL)fact * quick_mi(i,mod - 2,mod) % mod;
    
    return fact;
}

int main()
{
    int n;
    scanf("%d",&n);

    int a = 2 * n,b = n;
    int res = calc(a,b);
    // 计算1/(n+1)
    res = (LL) res * quick_mi(n + 1,mod - 2, mod) % mod;
    
    printf("%d\n", res);
    
    return 0;
}