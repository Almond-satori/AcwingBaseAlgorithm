#include <iostream>

using namespace std;

const int N = 1000010;
int primes[N],cnt;
bool st[N]; // 标识是否被删除

void get_primes(int x)
{   
    // 当遍历到i时,[2,i-1]的所有倍数都被删除
    for(int i = 2; i <= x; ++i)
    {
        if(!st[i])
        {
            primes[cnt ++] = i;
            // 将i的所有倍数全部删除
            cout << "删除" << i << "的倍数";
            for(int j = i + i; j <= x; j += i)
            { 
                cout << j << " ";
                st[j] = true;
            }
            cout << endl;
        }
    }
}   

int main()
{
    int n;
    scanf("%d",&n);

    get_primes(n);

    printf("%d",cnt);

    return 0;
}