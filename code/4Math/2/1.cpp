#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while(n --)
    {
        int a;
        cin >> a;

        int res = a;
        for(int i = 2; i <= a / i; ++i)
        {   
            if(a % i == 0)
            {   
                // res = res * (1 - 1 / i);
                // 需要整除,先除后乘防止溢出,把1/i提出来
                res = res / i * (i - 1);
                while(a % i == 0)
                {
                    a /= i;
                }
            }
        }
        if(a > 1) res = res / a * (a - 1);
        
        cout << res << endl;
    }
}