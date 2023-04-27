#include <iostream>

using namespace std;

typedef unsigned long long ULL;

// p数组预处理各个位上字母的权值
const int P = 131,N = 100010;
ULL h[N],p[N];
char s[N];

ULL get(int l,int r)
{
    return h[r] - h[l - 1]*p[r - l + 1];
}

int main()
{
    int n,m;
    scanf("%d%d%s",&n,&m,s + 1);

    p[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1] * P;
        // 将数据左移一位,低位补当前值
        h[i] = h[i - 1] * P + s[i];
    }
    while(m--)
    {
        int l1,l2,r1,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(get(l1,r1) == get(l2,r2)) puts("Yes");
        else puts("No");
    }
    return 0;
}