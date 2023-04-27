#include <iostream>

using namespace std;
const int N = 100010;
int stk[N],tt;

int main()
{
    int n,x;
    cin >> n;
    while(n --){
        cin >> x;
        while(tt && x <= stk[tt]) --tt;
        if(tt == 0) cout << -1 << " ";
        else cout << stk[tt] << " ";
        stk[++tt] = x;
    }
    return 0;
}