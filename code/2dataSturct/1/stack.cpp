#include <iostream>

using namespace std;

// tt指向栈顶元素,有效元素从1开始
const int N = 100010;
int stk[N],tt;

// void push(int x)
// {
//     stk[++tt] = x;
// }

// void pop()
// {
//     --tt;
// }

// bool empty()
// {
//     return tt == 0;
// }

// int top()
// {
//     return stk[tt];
// }

int main()
{
    int m,x;
    cin >> m;
    string op;
    while(m --){
        cin >> op;
        if(op == "push"){
            cin >> x;
            stk[++tt] = x;
        }else if(op == "pop"){
            --tt;
        }else if(op == "query"){
            cout << stk[tt] << endl;
        }else {
            if(tt == 0) cout << "YES";
            else cout << "No";
            cout << endl;
        }
    }
}
