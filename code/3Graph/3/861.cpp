#include <iostream>
#include <cstring>

using namespace std;

const int N = 510,M = 100010;
int h[N],e[M],ne[M],idx;
int match[N]; // 存储B集合中节点匹配的A集合节点,0代表未匹配
int st[N]; // 标识B集合节点是否已经使用
int n1,n2,m;

void add(int a,int b)
{
    e[idx] = b;ne[idx] = h[a];h[a] = idx++;
}

// 为x匹配一个右侧节点
bool find(int x)
{
    for(int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        // 如果j没有使用过,在递归的情况下,st[j]已经被赋值true
        if(!st[j])
        {
            // 考虑递归调用find的情况,即让j的原持有者更换j,此时的st[j]必须是true的
            // 否则将无限递归
            st[j] = true;
            // j节点未被使用,或者j的使用者可以更换指向
            if(!match[j] || find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    memset(h,-1,sizeof h);
    scanf("%d%d%d",&n1,&n2,&m);

    int u,v;
    while(m--)
    {   
        scanf("%d%d",&u,&v);
        add(u,v);
    }

    int res = 0;
    for(int i = 1; i <= n1; ++i)
    {
        memset(st,false,sizeof st);
        if(find(i)) ++res;
    }

    printf("%d\n", res);
    
    return 0;
}