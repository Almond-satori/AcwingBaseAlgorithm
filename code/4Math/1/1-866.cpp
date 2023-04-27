#include <iostream>

using namespace std;

bool is_prime(int x)    
{   
    // 2 是最小的质数
    if(x < 2) return false;
    
    // 假设x = a * b,a和b中至少有一个>=sqrt(x),一个<=sqrt(x)
    // 只需要枚举出这个<=sqrt(x)的数即可
    // i * i < x 可能溢出
    for(int i = 2; i <= x / i; ++i)
        if(x % i == 0) return false;
    return true;
}

int main()
{
    int n,a;
    scanf("%d",&n);

    while(n--)
    {
        scanf("%d",&a);
        if(is_prime(a)) puts("Yes");
        else puts("No");
    }
}   
