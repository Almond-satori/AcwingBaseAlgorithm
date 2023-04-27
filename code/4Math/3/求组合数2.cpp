#include <iostream>

using namespace std;

// N 很大,如果预处理C(0-N,0-N),计算量太大
const int N = 100010,mod = 1e9 + 7;
// fact存储c(a,b)中a的阶乘取模,infact存储阶乘的逆元取模
int fact[N],infact[N];
typedef long long LL;

// a ^ k % p
LL quick_mi(int a,int k,int p)
{   
    LL res = 1;
    while(k)
    {
        if(k & 1) res = res * a % p;
        k >>= 1;
        a = (LL) a * a % p;
    }
    return res;
}

void init()
{   
    fact[0] = infact[0] = 1;
    for(int i = 1; i < N; ++i)
    {
        fact[i] = (LL)fact[i - 1] * i % mod;
        // infact放入 i模mod的逆元的阶乘
        infact[i] = (LL)infact[i - 1] * quick_mi(i,mod - 2,mod) % mod;
    }
}

int main()
{   
    init();

    int n;
    scanf("%d",&n);

    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        
        printf("%d\n",(LL)fact[a] * infact[b] % mod * infact[a - b] % mod);
    }

    return 0;
}