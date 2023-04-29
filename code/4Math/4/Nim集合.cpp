#include <iostream>
#include <cstring>
#include <unordered_set>

using namespace std;

const int N = 100,M = 10010;
int s[N]; // 存储当前节点可以进行的选择
int k; // 选项的数量
int f[M]; // 存储每个节点的sg函数值

// 求出当前堆的起点的sg值
int sg(int x)
{   
    // 当前状态已经计算过,直接返回
    if(f[x] != -1) return f[x];

    // 存储当前节点可以到达的下一节点的sg值
    unordered_set<int> S;
    for(int i = 0; i < k; ++i)
    {
        if(x >= s[i]) S.insert(sg(x - s[i]));
    }

    // 计算当前节点的sg值
    int i = 0;
    while(S.count(i) != 0){
        ++i;
    }
    f[x] = i;
    return i;
}

int main()
{
    int n;
    scanf("%d",&k);
    for(int i = 0; i < k; ++i) scanf("%d",&s[i]);
    scanf("%d",&n);

    memset(f,-1,sizeof f);
    int res = 0;
    for(int i = 0; i < n; ++i)
    {   
        int x;
        scanf("%d",&x);
        
        res ^= sg(x);
    }

    if(res) puts("Yes");
    else puts("No");

    return 0;
}