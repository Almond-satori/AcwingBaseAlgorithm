#include <iostream>

using namespace std;

int main()
{
    float q;
    scanf("%f",&q);
    double l = -10000.0,r = 10000.0;
    //当l和r足够接近,视为相等,注意r必须大于l
    while(r - l >= 1e-7)
    {   
        double mid = (l + r) / 2; 
        if(mid*mid*mid < q) l = mid;
        else r = mid;
    }
    printf("%f",l);
    return 0;
}