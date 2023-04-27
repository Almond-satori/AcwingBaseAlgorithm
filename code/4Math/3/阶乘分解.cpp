#include <iostream>

using namespace std;

const int N = 1000010;
int primes[N],cnt;
bool st[N]; // 表示是否被删除
int n;

void get_primes()
{
    for(int i = 2; i <= n; ++i)
    {   
        // false代表i是质数则加入表
        if(!st[i]) primes[cnt++] = i; 
        // 注意等号
        for(int j = 0; primes[j] <= n / i; ++j)
        {   
            // pj 小于i的最小质因子,pj是pj*i的最小质因子,将pj*i标识为非质数
            // pj 等于i的最小质因子,pj也是pj*i的最小质因子
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main()
{
    scanf("%d",&n);
    get_primes();
    
    for(int i = 0; i < cnt; ++i)
    {
        int p = primes[i];
        int s = 0,t = n;
        // t/(p^2) 转换为计算 (t/p) / p
        // 计算p的平方可能会爆int
        while(p <= t)
        {
            s += t / p;
            t /= p;
        }

        printf("%d %d\n",primes[i],s);
    }

    return 0;
}