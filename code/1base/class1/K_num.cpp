#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int q[N];
int n,k;

int quick_select(int l,int r,int k)
{
    if(l >= r) return q[l];
    int pivot = q[l + r >> 1],i = l - 1,j = r + 1;
    while(i < j){
        do ++i; while(q[i] < pivot);
        do --j; while(q[j] > pivot);
        if(j > i) swap(q[i],q[j]);
    }
    // 左区间长度
    int s1 = j - l + 1;
    // 注意取等号
    if(s1 >= k) quick_select(l,j,k);
    else quick_select(j + 1,r,k - s1);
}

int main()
{
    scanf("%d",&n);
    scanf("%d",&k);     
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&q[i]);
    }
    cout << quick_select(0,n-1,k);
}