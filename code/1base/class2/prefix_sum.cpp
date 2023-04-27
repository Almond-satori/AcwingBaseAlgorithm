#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n,m;
int a[N],s[N];

int main ()
{
    scanf("%d%d",&n,&m);
    // 将数据读入到a[1:n]
    for(int i = 1; i <= n; i ++) scanf("%d",&a[i]);
    // s[0]为0,定义s[0:n],实际数值从下标1开始记录,
    // 求a[1,10] = s[10] - s[0]不需要判断边界
    for(int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];
    
    while(m --){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",s[r] - s[l - 1]);
    }
    return 0;
}