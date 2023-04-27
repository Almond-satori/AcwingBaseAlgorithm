#include <iostream>

using namespace std;

int lowbit(int x)
{
    return x & -x;
}

int main()
{
    int n;
    cin >> n;
    while( n--){
        int x,c = 0;
        cin >> x;
        while(x > 0){
            x -= lowbit(x);
            ++c;
        }
        cout << c << " ";
    }
    return 0;
}