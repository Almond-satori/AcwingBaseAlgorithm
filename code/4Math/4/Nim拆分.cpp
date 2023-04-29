#include <iostream>
#include <cstring>
#include <unordered_set>

using namespace std;

const int N = 110;
int f[N];

int sg(int a)
{   
    if(f[a] != -1) return f[a];

    unordered_set<int> s;
    // 枚举所有可转换的子状态
    for(int i = 0; i < a; ++i)
        for(int j = 0; j <= i; ++j)
            s.insert(sg(i) ^ sg(j));

    for(int i = 0;;++i)
        if(s.count(i)) return f[a] = i;
}

int main()
{
    int n;
    scanf("%d",&n);

    memset(f,-1,sizeof f);
    int res = 0;
    for(int i = 1; i <= n; ++i)
    {
        int a;
        scanf("%d",&a);
        res ^= sg(a);
    }

    if(res) puts("Yes");
    else puts("No");

    return 0;
}