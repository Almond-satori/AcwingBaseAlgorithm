#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

int exgcd(int a,int b,int &x,int &y)
{   
    // gcd(a,0) = a
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    // gcd(a,b) = gcd(b,a mod b)
    int d = exgcd(b,a % b,y,x);
    y -= a / b * x;
    
    return d;
}

int main()
{
    int n;
    scanf("%d",&n);

    while(n--)
    {
        int a,b,m;
        scanf("%d%d%d",&a,&b,&m);

        int x,y;
        int d = exgcd(a,m,x,y);
        if(b % d) puts("impossible");
        // 对于最后mod m,是保证x在mod m下的剩余系中
        else printf("%lld\n",(LL)x * b / d % m);
    }

    return 0;
}