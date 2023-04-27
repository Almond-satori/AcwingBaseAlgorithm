#include <iostream>
#include <cstdio>

using namespace std;

int exgcd(int a,int b,int &x,int &y)
{    
    // 先在递归结束位置给x,y赋值
    // gcd(a,0) = a, 1*a + 0*b = a
    if(!b) 
    {   
        x = 1,y = 0;
        return a;
    }
    // 翻转系数,传入y,x
    // 将得到 by + x(a mod b)的x和y的值
    int d = exgcd(b,a % b,y,x);
    // 将上述x和y的值转换为待求的(即ax + by中的x和y值)
    y -= a / b * x;

    return d;
}

int main()
{
    int n;
    scanf("%d",&n);

    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        int x = 1,y = 1;
        int res = exgcd(a,b,x,y);
        printf("%d %d\n",x,y);
    }

    return 0;
}