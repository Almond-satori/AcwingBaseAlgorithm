#include <iostream>

using namespace std;
typedef long long LL;

// 快速幂求 a^k mod p
LL q_mi(int a,int k,int p)
{
    LL res = 1;
    while(k)
    {
        if(k & 1) res = res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }
    
    return res;
}   

int main()
{
    int n;
    scanf("%d",&n);

    while(n --)
    {
        int a,p;
        scanf("%d%d",&a,&p);

        LL res = q_mi(a,p-2,p);
        // a不能是p的倍数
        if(a % p == 0) puts("impossible");
        else printf("%d\n",res);
    }

    return 0;
}