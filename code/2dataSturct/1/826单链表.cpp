#include <iostream>

using namespace std;

const int N = 1e5 + 10;
// e表示元素,ne为存有下一个位置下标的数组,head指向第一个位置,idx是当前插入的尾后下标
int e[N],ne[N],head,idx;

void init()
{
    head = -1;
    // idx = 0;
}

void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

// 删除下标是k的节点的后一个数
void remove(int k)
{
    ne[k] = ne[ne[k]];
}

// 在下标是k的节点后插入一个元素
void add(int k,int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

int main()
{
    init();
    char op;
    int m,x,k;
    cin >> m;
    while(m --){
        cin >> op;
        if(op == 'H'){
            cin >> x;
            add_to_head(x);
        }else if(op == 'I'){
            cin >> k >> x;
            // 第1个数插入下标0的位置
            add(k - 1,x);
        }else{
            cin >> k;
            // 注意删除头结点指向元素的情况
            if(!k) head = ne[head];
            else remove(k - 1);
        }
    }

    for(int i = head; ne[i] != -1; i = ne[i]){
        cout << e[i] << " ";
    }
    cout << endl;
    return 0;
}