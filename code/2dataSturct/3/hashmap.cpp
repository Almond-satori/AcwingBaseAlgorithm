#include <iostream>
#include <cstring>

using namespace std;
// N定义为质数,且远离2的次幂
const int N = 100003; 

// h为hashmap,其余部分维护hashmap上每个节点的链表  
int h[N],e[N],ne[N],idx; 

bool find(int x)
{
    int k = (x % N + N) % N;
    for(int i = h[k]; i != -1; i = ne[i])
        if(e[i] == x) return true;
    return false;
}   

void insert(int x)
{   
    // 将[1e-9,1e9] 映射到 [0,N - 1]
    // x % N 可能是负数,因此再加N模N
    int k = (x % N + N) % N;
    // h[k] 指向链表中第一个元素,h[k]初始化的-1会被传递给链表末尾
    e[idx] = x;ne[idx] = h[k];h[k] = idx++;
}

int main()
{
    int n;
    scanf("%d",&n);

    // 定义-1是空指针
    memset(h,-1,sizeof h);

    while(n--)
    {
        char op[2];int x;
        scanf("%s%d",&op,&x);
        if(*op == 'I')
        {
            insert(x);
        }
        else
        {
            if(find(x)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}