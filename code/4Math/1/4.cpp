#include <iostream>

using namespace std;

const int N = 1000010;
int primes[N],cnt;
bool st[N]; // 标识是否被删除

void get_primes(int n)
{   
    for(int i = 2; i <= n; ++i)
    {
        if(!st[i]) primes[cnt++] = i; 
        // 筛除 primes[j]*i ,如果筛除大于x的数就没有意义了
        for(int j = 0; primes[j] <= n / i ; ++j)
        {   
            cout << "当前i是 " << i << " 使用质数集中的 " << primes[j] << " 筛除数字 " << primes[j] * i << endl;
            st[primes[j] * i] = true; 
            // 当 primes[j] 是i的最小质因数时,跳出
            // 如果继续循环,会筛 primes[j + 1] * i,但不是用最小质因数删除的会重复删除
            if(i % primes[j] == 0) break; 
        }
    }
}   

int main()
{
    int n;
    scanf("%d",&n);

    get_primes(n);

    printf("%d",cnt);
    
    return 0;
}