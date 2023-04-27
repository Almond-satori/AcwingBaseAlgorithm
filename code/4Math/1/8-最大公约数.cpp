#include <iostream>

using namespace std;

// 这里判断b是否是0,如果a是0的情况,会调用gcd(b,0)
int gcd(int a,int b)
{
    return b ? gcd(b,a % b) : a;
}

int main()
{   
    int n;
    cin >> n;
    while(n--)
    {
        int a,b;
        cin >> a >> b;
        cout << gcd(a,b) << endl;
    }
    
    return 0;
}