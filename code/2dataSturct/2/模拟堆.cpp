#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;
// p2h[x]表示第x个插入的元素在heap的哪个节点
// h2p[x]表示heap中下标为x的元素是第几个插入的
int h[N],p2h[N],h2p[N],sz;

// 交换两个节点,更新两个映射数组
void heap_swap(int a,int b)
{
    swap(p2h[h2p[a]],p2h[h2p[b]]);
    swap(h2p[a],h2p[b]);
    swap(h[a],h[b]);
}

// 对节点x做down
void down(int x)
{
    int u = x;
    // 用h[u]比较,因为u在中途可能改变
    if(2 * x <= sz && h[2 * x] < h[u]) u = 2 * x;
    if(2 * x + 1 <= sz && h[2 * x + 1] < h[u]) u = 2 * x + 1;
    if(u != x){ 
        heap_swap(u,x);
        down(u);
    }
}

// 对节点x做up
void up(int x)
{
    while(x / 2 && h[x / 2] > h[x]){
        heap_swap(x / 2,x);
        x /= 2;
    }
}

int main()
{
    int n,p = 0;
    char op[5];
    scanf("%d",&n);
    while(n --){
        int k,x;
        scanf("%s",&op);
        if(!strcmp(op,"I")){
            scanf("%d",&x);
            ++sz;
            ++p;
            p2h[p] = sz,h2p[sz] = p;
            h[sz] = x;
            up(sz);
        }else if(!strcmp(op,"PM"))
        {
            printf("%d\n",h[1]);
        }else if(!strcmp(op,"DM"))
        {
            heap_swap(1,sz); 
        // 注意sz操作要在down,up之前
            --sz;
            down(1);
        }else if(!strcmp(op,"D"))
        {
            scanf("%d",&k);
            k = p2h[k];
            heap_swap(k,sz);
            --sz;
            up(k);
            down(k);
        }else
        {
            scanf("%d%d",&k,&x);
            k = p2h[k];
            h[k] = x;
            up(k);
            down(k);
        }
    }
    return 0;
}