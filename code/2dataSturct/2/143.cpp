#include <iostream>

using namespace std;

// M每个数最大31位,数据量为1e5
const int N = 100010,M = 31 * 1e5 + 10;
int son[M][2],idx,a[N];

// 按照从高位(31)到低位(1)的顺序插入数据x
void insert(int x)
{
    int p = 0;
    for(int i = 30; i >= 0; --i){
        int u = x >> i & 1;
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

// 在trie树中查找值y,使得x^y最大,
int query(int x)
{
    int res = 0,p = 0;
    // 从高位开始找,找与x当前位不同的位,这样异或值最大
    for(int i = 30; i >= 0; --i){
        int u = x >> i & 1;
        // 注意这里对u这一个位取反,使用!而不是~
        if(son[p][!u]){
            res |= (1 << i);
            p = son[p][!u];
        }else p = son[p][u];
        // trie树中左节点为空,右节点一定不为空,所有数据在31层(不计根节点)结束
    }
    return res;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d",&a[i]);
        insert(a[i]);
    }
    int res = 0;
    for(int i = 0; i < n; ++i){
        res = max(res,query(a[i]));
    }
    printf("%d",res);
    return 0;
}   