#include <iostream>

using namespace std;

// s[1:n],p[1:n]为字符串范围
const int N = 100010,M = 1000010;
char s[M],p[N];
int m,n,ne[N];

int main()
{
    cin >> n >> p + 1 >> m >> s + 1;
    // 生成next数组,ne[1] = 0;
    // 计算前后缀,前后缀长度小于串的长度,
    // 当前子串至少长度为2才有计算的必要
    for(int i = 2,j = 0; i <= n; ++i){
        while(j && p[i] != p[j + 1]) j = ne[j];
        if(p[i] == p[j + 1]) ++j;
        ne[i] = j;
    }

    // 模式匹配,j=0代表不能回退的状态
    for(int i = 1,j = 0; i <= m; ++i){
        // 如果失配,j向前回退,直到匹配或者不能再退 
        while(j && s[i] != p[j + 1]) j = ne[j];
        if(s[i] == p[j + 1]) ++j;
        if(j == n){
            // 匹配成功
            // 要求返回的下标是从0开始计算的
            printf("%d ",i - n);
            j = ne[j];
        }
    }
    return 0;
}