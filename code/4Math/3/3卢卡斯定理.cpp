#include <iostream>

using namespace std;
typedef long long LL;

LL q_mi(LL a,LL k,int p)
{
    LL res = 1;
    while(k)
    {
        if(k & 1) res = res * a % p;
        k >>= 1;
        a = a * a % p;
    }

    return res;
}

// 根据定义直接计算 c(a,b)模p的值
LL calc(LL a,LL b,int p)
{   
    if(a < b) return 0;

    LL res = 1;
    // 计算a(a-1)...(a-b+1)/1*2*...b 模p的值,分子分母都是b个数
    for(int i = 1,j = a; i <= b; ++i,--j)
    {
        res = res * j % p;
        res = res * q_mi(i,p - 2,p) % p;
    }
    return res;
}

LL lucas(LL a,LL b,int p)
{

    if(a < p && b < p) return calc(a,b,p);
    // a % p一定小于p,因此可以直接计算
    return lucas(a / p,b / p,p) * calc(a % p,b % p,p) % p;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        LL a,b;
        int p;
        scanf("%lld%lld%d",&a,&b,&p);

        printf("%lld\n",lucas(a,b,p));
    }

    return 0;
}