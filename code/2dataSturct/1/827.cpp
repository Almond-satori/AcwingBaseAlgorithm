#include <iostream>

using namespace std;

const int N = 100010;
int l[N],r[N],e[N],idx;

// 下标0代表head,下标1代表tail
void init()
{
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

// 删除节点k
void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

// 在k节点的右边插入一个x
void insert(int k,int x)
{
    e[idx] = x;
    l[idx] = k;r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx++;
}

int main()
{
    init();

    int m,x,k;
    string op; // 注意op是字符串
    cin >> m;
    while(m -- ){
        cin >> op;
        if(op == "L"){
            cin >> x;
            insert(0,x);
        }else if(op == "R"){
            cin >> x;
            insert(l[1],x);
        }else if(op == "D"){
            cin >> k;
            // 第1个插入的数下标为2
            remove(k + 1);
        }else if(op == "IL"){
            cin >> k >> x;
            // 查找左边元素用l[]
            insert(l[k + 1],x);
        }else {
            cin >> k >> x;
            insert(k + 1,x);    
        }
    }
    for(int i = r[0]; i != 1; i = r[i]) cout << e[i] << " ";
    cout << endl;
    
    return 0;
}