#include <iostream>

using namespace std;

const int N = 100010;
int A[N],B[N];
int m,n,t;

int main()
{
    scanf("%d%d%d",&m,&n,&t);
    
    for(int i = 0; i < m; ++i) scanf("%d",&A[i]);
    for(int i = 0; i < n; ++i) scanf("%d",&B[i]);
    
    // j是B数组的最大数字下标,i是A数组中最小数字下标
    // 在移动中,i始终指向A中待判断的最小数字,j始终指向B中待判断的最大数字
    int j = n - 1;
    for(int i = 0; i < m; ++i) {
        while(A[i] + B[j] > t) --j;
        if(j > -1 && A[i] + B[j] == t){
            printf("%d %d ",i,j);
            return 0;
        }
    }
    return 0;
}