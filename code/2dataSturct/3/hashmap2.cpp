#include <iostream>
#include <cstring>

using namespace std;

// N要开数据量的两倍,定义一个不在[1e-9,1e9]的数据作为空闲位置的标记
const int N = 200003,null = 0x3f3f3f3f;
int h[N];

// 查找x,如果x不在哈希表中,返回一个它应该在的位置
int find(int x)
{
    int k = (x % N + N) % N;
    while(h[k] != null && h[k] != x)
    {
        ++k;
        // 当到hashmap末尾,将k定义回开头
        if(k == N) k = 0;
    }
    return k;
}

int main()
{
    int n;
    scanf("%d",&n);
    // 按照字节赋值,填充h
    memset(h,0x3f,sizeof h);

    while(n--)
    {
        char op[2];int x;
        scanf("%s%d",&op,&x);
        int r = find(x);
        if(*op == 'I')
        {   
            h[r] = x;            
        }
        else
        {
            if(h[r] != null) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
