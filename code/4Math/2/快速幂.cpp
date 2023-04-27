#include <iostream>

using namespace std;

typedef long long LL;

// a^k mod p
LL qmi(int a,int k,int p)
{
    LL res = 1;
    // 将k按二进制位进行mod p
    while(k)
    {   
        // a每次平方,得到当前的权值
        // k 查找当前位是否为1 
        if(k & 1) res = res * a % p;
        k >>= 1;
        a = a * a;
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    while(n -- )
    {
        int a,k,p;
        scanf("%d%d%d",&a,&k,&p);

        printf("%lld\n", qmi(a,k,p));
    }

    return 0;
}