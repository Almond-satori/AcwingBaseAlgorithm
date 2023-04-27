#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int q;
int n,a[N];

int main()
{
    scanf("%d",&n);
    scanf("%d",&q);
    for(int i = 0;i < n; ++i)
    {
        scanf("%d",&a[i]);
    }
    while(q--)
    {
        int target;
        scanf("%d",&target);

        int re1,re2;
        int l = 0,r = n - 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(target > a[mid]) l = mid + 1; 
            else r = mid;
        }
        re1 = l;
        if(a[re1] != target) {
            printf("%d %d\n",-1,-1);
            continue;
        }
        
        l = 0,r = n - 1;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(target < a[mid]) r = mid - 1;
            else l = mid;
        }
        re2 = r;
        printf("%d %d\n",re1,re2);
    }
}