#include <iostream>

using namespace std;

const int N = 100010;
int a[N],s[N];
int n;

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++ i){
        scanf("%d",&a[i]);
    }

    int j = 0,res = 0;
    for(int i = 0; i < n; ++ i){
        ++ s[a[i]];
        // 如果新引入的数据有重复,这里不需要限制j的范围(while条件隐含限制了范围)
        while(s[a[i]] > 1){
            -- s[a[j]];
            ++ j;
        }
        res = max(res,i - j + 1);
    }
    printf("%d",res);
}