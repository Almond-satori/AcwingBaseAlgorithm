#include <iostream>

using namespace std;

// qu[he:ta]为队列
const int N = 100010;
int qu[N],he,ta = -1;

int main()
{   
    int m,x;
    cin >> m;
    string op;
    while(m --){
        cin >> op;
        if(op == "push"){
            cin >> x;
            qu[++ ta] = x;
        }else if(op == "pop"){
            ++he;
        }else if(op == "query"){
            cout << qu[he] << endl;
        }else {
            cout << (he > ta ? "YES":"NO") << endl;
        }
    }
}