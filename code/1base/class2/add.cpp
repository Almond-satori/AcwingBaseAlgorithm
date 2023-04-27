#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> &A,vector<int> &B)
{
    vector<int> C;
    //保证A为较长的一个vector
    if(A.size() < B.size()) return add(B,A);
    int temp = 0;
    for(int i = 0; i < A.size(); i ++)
    {
        temp += A[i];
        if(i < B.size()) temp += B[i];
        C.push_back(temp % 10);
        temp /= 10;
    }
    if(temp) C.push_back(temp % 10);
    return C;
}   

int main()
{   
    string a,b; 
    vector<int> A,B;
    cin >> a >> b; //123456
    for(int i = a.size() - 1; i >= 0; -- i) A.push_back(a[i] - '0'); 
    for(int i = b.size() - 1; i >= 0; -- i) B.push_back(b[i] - '0');

    vector<int> C = add(A,B);
    for(int i = C.size() - 1; i >= 0; -- i) cout << C[i];
    return 0;
}