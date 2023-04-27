#include <iostream>
#include <cmath>

using namespace std;

// 小于eps代表0
const int N = 110;
const double eps = 1e-8;
int n;
double a[N][N];

void out()
{
    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= n; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

int gauss()
{   
    int c,r;
    //  枚举每个列
    for(c = 0,r = 0; c < n; ++c)
    {   
        // 找当前列的绝对值最大的所在行,交换到当前的最小行(第一次是第0行,第二次是第1行)
        int t = r; // 当前从r开始寻找
        for(int i = r; i < n; ++i) 
            if(fabs(a[i][c]) > fabs(a[t][c]))
                t = i;
        out();
        // 如果绝对值的最大值为0,说明整列都是0,该列不处理
        if(fabs(a[t][c]) < eps) continue;
        // 从c列开始,将这一行移动到可以移动的最上面一行
        // 各行c列之前的元素都是0,没有交换的必要
        for(int i = c; i <= n; ++i) swap(a[t][i],a[r][i]);
        // 倒序将本行的c列置为1,注意当前行已经被交换到r
        for(int i = n; i >= c; --i) a[r][i] /= a[r][c];
        // 将t行以后的行的c列置为0
        for(int i = r + 1; i < n; ++i)
            for(int j = n; j >= c; --j)
                a[i][j] -= a[r][j] * a[i][c]; // a[t][c]是1 a[i][c]本身就是a[i][c]/a[t][c]

        ++r;
    }
    
    //out();

    // 无解和不唯一解
    if(r < n)
    {
        for(int i = r; i < n; ++i)
        {   
            // 左边列全是0,右边列有值
            if(fabs(a[i][n]) > eps) {
                return 2;
            } //无解
        }
        return 1; // 不唯一解
    }

    // 从下向上消去倒三角内部的值
    // 枚举每一行
    for(int i = n - 1; i >= 0; --i)
    {   
        // 最后一行跳过处理
        // 对于当前行,处理当前行后面所有行待消的值
        for(int j = i + 1; j < n; ++j)
        {
            a[i][n] -= a[i][j] * a[j][n]; 
        }
    }
    
    // 处理-0.0的情况
    for(int i = 0; i < n; ++i)
    {
        if(fabs(a[i][n]) < eps) a[i][n] = 0;
    }

    return 0; // 单一解
}

int main()
{
    scanf("%d",&n);

    for(int i = 0; i < n; ++i)
        for(int j = 0; j <= n; ++j)
            scanf("%lf",&a[i][j]);
    
    int ans = gauss();
   
    if(ans == 1) puts("Infinite group solutions");
    else if(ans == 2) puts("No solution");
    else {
        for(int i = 0; i < n; ++i) 
            printf("%.2lf\n",a[i][n]);
    }

    return 0;
}

