#include <iostream>

using namespace std;

const int N = 1000010;
int primes[N],cnt; // 质数表
int euler[N]; // 存储每个数的欧拉函数
bool st[N]; // 标识是否是质数

void get_euler(int n)
{   
    //小于等于1的正整数中唯一和1互质的数就是1本身
    euler[1] = 1;
    for(int i = 2; i <= n; ++i)
    {   
        if(!st[i])
        {
            // i是质数 
            primes[cnt++] = i;
            // 质数与[1,i-1]的数互质
            euler[i] = i - 1; 
        }
        // 枚举质数表注意等号
        for(int j = 0; primes[j] <= n / i; ++j)
        {    
            // pj*i 不是质数
            st[primes[j] * i] = true; 
            if(i % primes[j] == 0) // pj是i的最小质因子
            {
                // pj是i的最小质因子,pj*i的最小质因子还是pj
                euler[primes[j] * i] = primes[j] * euler[i];
                break;
            }
            // pj是小于i的最小质因子的数,pj*i的最小质因子是pj
            euler[primes[j] * i] = (primes[j] - 1) * euler[i];
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    get_euler(n);
    
    // 注意结果使用long long
    long long res = 0;
    for(int i = 1; i <= n; ++i)
        res += euler[i];
    
    printf("%lld\n",res);

    return 0;
}