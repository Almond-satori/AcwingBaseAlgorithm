#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int m,n,b[N],a[N]; // 差分数列b

//构建差分(l == r)或者给区间[l,r]同时加c使用
void insert(int l,int r,int c)
{
    b[l] += c;
    b[r + 1] -= c;
}
int main ()
{
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i ++) scanf("%d",&a[i]);

    for(int i = 1; i <= n; i ++) insert(i,i,a[i]);

    while(m --){
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c);
        insert(l,r,c);
    }
    // 将b原地构建为答案
    for(int i = 1; i <= n; i ++) b[i] += b[i - 1];
    for(int i = 1; i <= n; i ++) printf("%d ",b[i]);
    return 0;
}