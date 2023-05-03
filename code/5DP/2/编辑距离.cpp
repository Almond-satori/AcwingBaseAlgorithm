#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010,M = 15;
char str[N][M];
char s[M];
int n,m;
int f[M][M];

int calc_dist(char a[],char b[])
{
    int la = strlen(a + 1),lb = strlen(b + 1);
    // init f
    for(int i = 1; i <= la; ++i) f[i][0] = i;
    for(int i = 1; i <= lb; ++i) f[0][i] = i;

    for(int i = 1; i <= la; ++i)
        for(int j = 1; j <= lb; ++j)
        {
            f[i][j] = min(f[i - 1][j] + 1,f[i][j - 1] + 1);
            if(a[i] == b[j]) f[i][j] = min(f[i][j],f[i - 1][j - 1]);
            else f[i][j] = min(f[i][j],f[i - 1][j - 1] + 1);
        }

    return f[la][lb];
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; ++i)
    {
        scanf("%s",str[i] + 1);
    }

    for(int i = 0; i < m; ++i)
    {   
        int x,count = 0;
        scanf("%s%d",s + 1,&x);

        for(int j = 0; j < n; ++j)
        {
            int ans = calc_dist(s,str[j]);
            if(ans <= x) ++ count;
        }
        printf("%d\n",count);
    }

    return 0;
}
