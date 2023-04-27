#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> div(vector<int> &A,int b,int & r)
{   
    vector<int> C;
    // 除法从高位开始
    for(int i = A.size() - 1; i >= 0; i -- ){
        // 本轮要处理的数之和
        r = r * 10 + A[i]; 
        C.push_back(r / b);
        // 得到本轮余数
        r %= b;
    }
    // 去除前导0,因为从高向低计算,前导0在数组低位
    reverse(C.begin(),C.end());
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main()
{   
    string a;
    vector<int> A;
    int b;
    cin >> a >> b; // a = 123
    for(int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0'); //A = 321
    int r = 0; // 余数
    vector<int> C = div(A,b,r);

    for(int i = C.size() - 1; i >= 0; i --) printf("%d",C[i]);
    cout << endl << r << endl;
    return 0;
}