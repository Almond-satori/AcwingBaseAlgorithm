#include <iostream>

using namespace std;

const int N = 110;
int n;
int a[N][N];

// void out()
// {
//     for(int i = 0; i < n; ++i)
//     {   
//         for(int j = 0; j <= n; ++j)
//         {
//             cout << a[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

int gauss()
{
    int r,c;
    for(r = c = 0; c < n; ++c)
    {   
        // 从r行开始寻找当前列c是1的一行
        int t = r;
        for(int i = r; i < n; ++i)
            if(a[i][c])
            {
                t = i;
                break; // 找到直接跳出
            }
        // 寻遍所有行也没有当前列为1的一行
        if(!a[t][c]) continue;

        // 当前行有效部分交换到最上面
        for(int i = c; i <= n; ++i) swap(a[r][i],a[t][i]);
        // 将下面行的当前列消为0
        for(int i = r + 1; i < n; ++i) 
            for(int j = n; j >= c; --j)
                a[i][j] ^= a[r][j] & a[i][c];
        ++r;
    }

    if(r < n)
    {   
        for(int i = r; i < n; ++i) 
            if(a[i][n]) return 1; //无解
        return 2; //无穷解
    }

    // 从下向上消除多余项
    for(int i = r; i >= 0; --i)
        for(int j = i + 1; j < n; ++j)
            if(a[i][j]) a[i][n] = a[i][n] ^ a[j][n];

    return 0;
}

int main()
{

    scanf("%d",&n);

    for(int i = 0; i < n; ++i)
        for(int j = 0; j <= n; ++j)
            scanf("%d",&a[i][j]);
    int ans = gauss();

    if(ans == 2) puts("Multiple sets of solutions");
    else if(ans == 1) puts("No solution");
    else 
    {
        for(int i = 0; i < n; ++i)
            printf("%d\n",a[i][n]);            
    }

    return 0;
}