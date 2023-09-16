#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 12,M = 1 << N;
long long f[N][M];
int n,m;
bool st[M]; // 存储当前值表示的状态是否符合当前列连续0的个数为偶数的情况
vector<int> state[M]; // 存有可以转移到当前状态的前一列所有状态

int main(){
    while(cin >> n >> m, n || m)    
    {
        // 预处理st
        // 对于每列的情况 是一个二进制数
        for(int i = 0; i < 1 << n ; ++ i)
        {   
            int cnt = 0; // 连续0数量
            bool valid = true;
            // 将每行的连续0计算,把这个二进制数每一个位拿出来计算0的个数
            for(int j = 0; j < n; ++ j)
            {   
                // 当前数为1,检查前面的连续0是否合法
                if(i >> j & 1)
                {
                    if(cnt & 1)
                    {   
                        // 一旦连续0不合法直接退出
                        valid = false;
                        break;
                    }
                    // 连续0在此中断,清零
                    cnt = 0;
                }
                else {
                    ++ cnt;
                }
            }
            // 处理二进制数的最后一位
            if(cnt & 1) valid = false;
            st[i] = valid;
        }

        // 计算state,计算i列时,有哪些i-1的列可合法地转移到i的状态
        for(int i = 0; i < 1 << n; ++ i)
        {
            // 因为有多组输入数据,需要清空state 
            state[i].clear();
            for(int j = 0; j < 1 << n ; ++ j)
            {   
                // 两列的1不在同一行,两列凑成的连续0为偶数
                if(!(i & j) && st[i | j])
                {
                    state[i].push_back(j);
                }
            }
        }

        memset(f,0,sizeof f);
        // 前一列-1不存在,不填入任何方块的情况为1
        f[0][0] = 1; 

        for(int i = 1; i <= m; ++ i)
        {
            for(int j = 0; j < 1 << n; ++ j)
            {
                for(auto k : state[j])
                    f[i][j] += f[i - 1][k];
            }
        }
        // 最后一列没有填任何方块
        cout << f[m][0] << endl; 
    }
    return 0;
}
