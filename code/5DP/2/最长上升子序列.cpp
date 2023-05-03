#include <iostream>

using namespace std;

const int N = 1010;
int f[N],a[N];
int n;

int main()
{
    scanf("%d",&n);

    for(int i = 1; i <= n; ++i) scanf("%d",&a[i]);

    int res = 0;
    // 单一数字的序列长度1
    for(int i = 1; i <= n; ++i) f[i] = 1;
    
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1 ; j < i; ++j)
            if(a[i] > a[j])
            {
                f[i] = max(f[j] + 1,f[i]);
            }
        res = max(f[i],res);
    }
    
    printf("%d",res);
    return 0;
}