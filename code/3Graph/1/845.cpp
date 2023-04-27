#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;


int bsf(const string &start)
{
    // <状态,start 状态到该状态的步数>
    unordered_map<string,int> m;
    queue<string> q;
    string end = "12345678x";
    //定义移动方向
    int dx[] = {1,0,-1,0},dy[] = {0,1,0,-1};

    q.push(start);
    m[start] = 0;

    while(!q.empty())
    {
        string curr = q.front();
        q.pop();
        int distance = m[curr];
        // 设置终止状态
        if(curr == end) return distance;

        int k = curr.find('x');
        int x = k / 3,y = k % 3;
        for(int i = 0; i < 4; ++i)
        {
            int x2 = x + dx[i],y2 = y + dy[i];
            if(x2 >= 0 && x2 < 3 && y2 >=0 && y2 < 3)
            {
                swap(curr[k],curr[x2 * 3 + y2]);
                // 找到一个新状态
                if(!m.count(curr))
                {
                    m[curr] = distance + 1;
                    q.push(curr);
                }
                // 恢复状态
                swap(curr[k],curr[x2 * 3 + y2]);
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string start;
    for(int i = 0; i < 9; ++i)
    {
        char c;
        cin >> c;
        start += c;
    }
    cout << bsf(start) << endl;
}