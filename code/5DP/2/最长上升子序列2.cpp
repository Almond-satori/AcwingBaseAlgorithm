#include <iostream>

using namespace std;

const int N = 100010;
int q[N]; // q[x]记录长度为x的上升子序列的最后一个数
int a[N],n;

int main()
{
    scanf("%d",&n);

    for(int i = 0; i < n; ++i) scanf("%d",&a[i]);

    int len = 0; // 当前处理到子序列长度为len的情况
    for(int i = 0; i < n; ++i)
    {   
        // 在q[0,len]中寻找小于a[i]的最大值
        int l = 0,r = len;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(a[i] > q[mid]) l = mid;
            else r = mid - 1;
        }
        // 当前长度的序列末尾值是小于a[i]的最大值,下标为r
        // 更新已求得的递增子序列长度为r+1, 
        // 如果r+1小于当前len则仍使用当前len
        // cout << "len = " << len << " r = " << r << " i = " << i << " a[i] =" << a[i] << endl;
        len = max(len,r + 1);
        q[r + 1] = a[i]; 
        // cout << "q[" << r + 1 << "]=" << a[i] << endl;
    }   

    printf("%d\n",len);

    return 0;
}