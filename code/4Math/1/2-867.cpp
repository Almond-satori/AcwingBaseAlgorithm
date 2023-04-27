#include <iostream>

using namespace std;

void divide(int x)
{
    // 大于sqrt(x)的质因子最多只会有1个
    // 如果有两个,两者相乘一定大于x

    // 枚举到i的时候[2,i-1]的质因子已经被除掉
    // 合数可以被分解为质数相乘,[2,i-1]的合数也被除掉
    for(int i = 2; i <= x / i; ++i)
    {   
        int s = 0; //当前质数的指数
        while(x % i == 0)
        {   
            ++s;
            // 将x一直除等于i,把i这个质因子除掉
            x /= i;
        }
        if(s != 0) {
            // cout << "x 除了质因子" << i << "共" << s << "次" << endl;
            // cout << "current x is:" << x << endl;
            printf("%d %d\n",i,s);
        }
    }
    
    // 最后x无法除到1,因为剩余一个质因子
    if(x > 1) printf("%d %d\n",x,1);
    puts("");
}

int main()
{
    int n,a;
    scanf("%d",&n);

    while(n--)
    {
        scanf("%d",&a);
        divide(a);
    }

    return 0;
}