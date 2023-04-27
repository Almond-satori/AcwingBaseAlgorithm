#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> get_divisors(int n)
{   
    vector<int> res;
    // 只枚举出约数中的较小值即可
    for(int i = 1; i <= n / i; ++i)
    {
        if(n % i == 0)
        {
            res.push_back(i);
            // 防止两个约数相同的情况
            if(i != n / i) res.push_back(n / i);
        }
    }
    // 对约数从小到大排序
    sort(res.begin(),res.end());
    
    return res;
}

int main()
{
    int n,a;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> a;
        auto v = get_divisors(a);
        for(auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}