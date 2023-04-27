#include <iostream>

using namespace std;

// 找出>=n的最小质数
int main()
{
    int n = 200000;
    for(int i = n;;++i)
    {
        bool flag = true;
        for(int j = 2; j * j <= i; ++j)
        {
            if(i % j == 0)
            {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
