#include <iostream>
#include <vector>

using namespace std;
const int N = 5010;

int primes[N],cnt;
bool st[N];

int sum[N]; // 记录每个质数的指数和

void get_primes()
{   
    int n = N;
    for(int i = 2; i < n; ++i)
    {
        if(!st[i]) primes[cnt ++] = i;
        for(int j = 0; primes[j] <= n / i; ++i)
        {
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int get_sum(int n,int p)
{
    int res = 0;
    // sum = x/p + (x/p)/p + x/p^3 + ...
    while(n)
    {
        res += n / p;
        n /= p;
    }
    return res;
}

vector<int> mul(vector<int> &res,int b)
{
    vector<int> c;
    int t = 0;
    for(int i = 0; i < res.size(); i++)
    {   
        t += res[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    // t最后还有数据,写入结果中
    while(t)
    {
        c.push_back(t % 10);
        t /= 10;
    }
    // 去掉前导0
    while(c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

int main()
{   
    int a,b;
    scanf("%d%d",&a,&b);

    for(int i = 0; i < cnt; ++i)
    {
        int p = primes[i];
        sum[i] = get_sum(a,p) - get_sum(b,p) - get_sum(a-b,p);
    }

    vector<int> res;
    res.push_back(1);

    for(int i = 0; i < cnt; i++)
    {     
        for(int j = sum[i]; j > 0; j--)
        {
            res = mul(res,primes[i]);
        }
    }

    for(int i = res.size() - 1; i >= 0; --i)
    {
        printf("%d",res[i]);
    }

    return 0;
}