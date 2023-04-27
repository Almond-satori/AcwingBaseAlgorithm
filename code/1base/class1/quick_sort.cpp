#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int q[N];
int n; //用于存输入的数据规模

void quick_sort(int q[],int l,int r){
    if(l >= r) return;
    int pivot = q[l + r >> 1],i = l - 1,j = r + 1;
    while(i < j){
        do ++i; while(q[i] < pivot);
        do --j; while(q[j] > pivot);
        if(i < j) swap(q[i],q[j]);
    }

    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&q[i]);
    }
    quick_sort(q,0,n-1);

    for(int i = 0; i < n; i++){
        printf("%d ",q[i]);
    }
}