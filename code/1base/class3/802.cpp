#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// n次插入操作,m次询问,每次询问是一个区间,数据量是n+2m
const int N = 300010;
int a[N],s[N]; // 前缀和中的原数组a和前缀和数组s

int n,m;

vector<pair<int,int>> add; // 读取插入
vector<pair<int,int>> query; // 读取询问
vector<int> alls; // 存储数字

// 查找x对应在a数组的下标
int find_index(int x)
{
    int l = 0,r = alls.size() - 1;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(x < alls[mid]) r = mid - 1; 
        else l = mid;   
    }
    return r + 1; // 前缀和数组下标从1开始
}

// vector<int>::iterator unique(vector<int> &a){
//     int j = 0;
//     for(int i = 0; i < a.size(); ++i){
//         if(!i || a[i] != a[i - 1])
//             a[j ++] = a[i];
//     }
//     return a.begin() + j;
// }

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        int x,c;
        cin >> x >> c;
        add.push_back({x,c});
        alls.push_back(x);
    }

    for(int i = 0; i < m; ++i){
        int l,r;
        cin >> l >> r;
        query.push_back({l,r});
        // 左右区间也要插入a数组中
        alls.push_back(l);
        alls.push_back(r);
    }
    
    // 对存储的数字排序去重
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    
    // 处理插入
    for(auto item : add){
        int r = find_index(item.first);
        a[r] += item.second;
    }
    
    // 生成前缀和数组
    for(int i = 1; i <= alls.size(); ++i){
        s[i] = s[i - 1] + a[i];
    }
    
    // 处理查询
    for(auto p : query){
        int l = find_index(p.first);
        int r = find_index(p.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}
