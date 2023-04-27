#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n,q[N],temp[N];
long long res; // c++ long int(即long)和int一样

void merge_sort(int q[],int l,int r)
{
    if(l >= r) return;

    int mid = l + r >> 1;
    merge_sort(q,l,mid); merge_sort(q,mid + 1,r);
    int i = l,j = mid + 1,k = 0;
    while(i <= mid && j <= r)
    {   
        // 等于的情况不是逆序
        if(q[i] <= q[j]) temp[k++] = q[i++];
        else{
            // q[i:mid]都大于q[j],都是逆序对
            res += mid - i + 1;
            temp[k++] = q[j++];
        }
    }
    while(i <= mid) temp[k++] = q[i++];
    while(j <= r) temp[k++] = q[j++];
    for(k = 0,i = l;i <= r; ++i,++k) q[i] = temp[k];
}


int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n; ++i)
    {
        scanf("%d",&q[i]);
    }
    merge_sort(q,0,n - 1);
    cout << res << endl;
}