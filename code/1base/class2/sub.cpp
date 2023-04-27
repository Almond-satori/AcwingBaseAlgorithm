#include <iostream>
#include <vector>

using namespace std;

// A >= B ?
bool cmp(vector<int> &A,vector<int> &B)
{
    if(A.size() != B.size()) return A.size() > B.size();
    // AB等长
    for(int i = A.size() - 1; i >= 0; -- i)
    {
        if(A[i] != B[i]) return A[i] > B[i];
    }
    // A == B
    return true;
}

// A > B的情况下相减
vector<int> sub(vector<int> &A,vector<int> &B)
{
    vector<int> C;
    for(int i = 0,t = 0; i < A.size(); i ++)
    {
        t = A[i] - t;
        if(i < B.size()) t -= B[i];
        // t属于(-10,10) t>0 返回t;t<0 返回 10+t
        C.push_back((t + 10) % 10); 
        // 重置借位
        if(t >= 0) t = 0;
        else t = 1;
    }
    // 去掉高位0,除非只有一位0
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main()
{
    vector<int> A,B;
    string a,b;
    cin >> a >> b; 
    // 注意转换char为int
    for(int i = a.size() - 1; i >= 0; -- i) A.push_back(a[i] - '0'); 
    for(int i = b.size() - 1; i >= 0; -- i) B.push_back(b[i] - '0');
    vector<int> C;
    if(cmp(A,B)){
        C = sub(A,B);
    }
    else
    {
        printf("-");
        C = sub(B,A);
    }
    for(int i = C.size() - 1; i >= 0; i --) printf("%d",C[i]);
}