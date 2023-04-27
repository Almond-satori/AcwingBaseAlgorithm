#include <iostream>

using namespace std;

const int N = 1000010;
int a[N],q[N],n,k;

int main()
{
    int hh = 0,tt = -1;

    scanf("%d%d",&n,&k);
    for(int i = 0;i < n; ++i) scanf("%d",&a[i]);

    for(int i = 0;i < n; ++i){
        // 滑动窗口左端先出队本题最多出队一个元素 
        // 而且队首是最可能出队的元素,因此用if
        if(hh <= tt && q[hh] < i - k + 1) ++hh;
        // 找到一个小于当前的元素的位置作为队尾
        while(hh <= tt && a[q[tt]] >= a[i]) --tt;
        q[++tt] = i;
        if(i >= k - 1) printf("%d ",a[q[hh]]);
    }
    puts("");


    hh = 0,tt = -1;
    for(int i = 0;i < n; ++i){
        // 滑动窗口左端先出队
        if(hh <= tt && q[hh] < i - k + 1) ++hh;
        // 找到一个大于当前的元素的位置作为队尾
        while(hh <= tt && a[q[tt]] <= a[i]) --tt;
        q[++tt] = i;
        if(i >= k - 1) printf("%d ",a[q[hh]]);
    }
    return 0;
}