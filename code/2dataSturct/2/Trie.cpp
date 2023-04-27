#include <iostream>

using namespace std;

// son相当于链表的next数组,idx给节点赋值,
// cnt是元素数组cnt[x]记录son[x]对应的字符串有几个
// son[0]表示起始节点,是空节点
// son[a][b]为0表示没有该节点
const int N = 100010;
int son[N][26],idx,cnt[N];
char str[N];

void insert(char str[])
{
    int p = 0;
    for(int i = 0; str[i]; ++i){
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx; // 指向son[++idx]的位置
        p = son[p][u]; // p作为第一个索引值,下次循环会索引到son[idx]处
    }
    ++cnt[p]; // p对应位置的元素自增
}

int query(char str[])
{
    int p = 0;
    for(int i = 0; str[i]; ++i){
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    int n;
    char op[2];
    scanf("%d",&n);    
    while(n -- ){
        scanf("%s%s",&op,&str); // c风格字符串末尾有'/0',不能直接和"I"比较
        if(*op == 'I'){
            insert(str);
        }else{ 
            cout << query(str) << endl;
        }
    }
    return 0;
}