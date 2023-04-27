#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if(b == 0)
    {
        x = 1;y = 0;
        return a;
    }
    LL d = exgcd(b,a % b,y,x);
    // 先除后乘
    y -= a / b * x;

    return d;
}

int main()
{
    int n;
    cin >> n;
    
    LL a1,m1;
    cin >> a1 >> m1;

    bool has_ans = true;
    for(int i = 1; i < n; ++i)
    {
        LL a2,m2;
        cin >> a2 >> m2;
        
        LL k1,k2;
        LL d = exgcd(a1,a2,k1,k2);
        
        if((m2 - m1) % d)
        {
            has_ans = false;
            break;
        }
        // 转换结果
        k1 = (m2 - m1) / d * k1;
        LL t = a2 / d;
        k1 = (k1 % t + t)% t;
        
        // 先修改m1,m1依赖于a1
        m1 = a1 * k1 + m1;
        // a1改为正数便于记录结果
        a1 = abs(a1 / d * a2);
    }
    
    // x = m1 mod a1 
    // (m1 % a1 + a1) % a1 会将结果转化为正数
    if(has_ans) cout << (m1 % a1 + a1) % a1 << endl;
    else puts("-1");

    return 0;
}