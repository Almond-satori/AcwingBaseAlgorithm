#include <iostream>

using namespace std;

const int N = 100010;
int a[N],b[N];

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < m; ++i) cin >> b[i];

    int j = 0; // j在指向a数组中的值,在匹配成功后向右移动
    // i遍历数组b,为a数组创造新的匹配值
    for(int i = 0; i < m; ++i){
        if(b[i] == a[j]){
            ++j;
            if(j == n) {
                cout << "Yes";
                return 0;
            }   
        }   
    }
    cout << "No";
    return 0;
}   