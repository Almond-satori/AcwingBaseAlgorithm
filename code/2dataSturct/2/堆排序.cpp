#include <iostream>

using namespace std;

const int N = 100010;
int h[N],m,n,sz;

// 将下标为x的元素做down操作
void down(int x)
{
    int u = x;
    if(2 * x <= sz && h[u] > h[2 * x]) u = 2 * x;
    if(2 * x + 1 <= sz && h[u] > h[2 * x + 1]) u = 2 * x + 1;
    if(u != x) {
        swap(h[x],h[u]);
        down(u);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    // 数组建堆从1开始,左节点是2*x,右节点是2*x+1
    for(int i = 1; i <= n; ++ i) scanf("%d",&h[i]);
    sz = n;

    // 建立堆,堆是完全二叉树,最后一行不用down
    // 从倒数第二行开始执行down操作
    // 时间复杂度是O(n)
    for(int i = n / 2; i; -- i){
        down(i);
    }
    while(m -- ){
        // 数组中删除头元素很难,但删除末尾元素容易
        printf("%d ",h[1]);
        swap(h[1],h[sz--]);
        down(1);
    }
    return 0;
}