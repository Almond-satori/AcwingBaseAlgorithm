#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int>> segs;

void merge(vector<pair<int,int>> &segs)
{   
    // pair按照first,然后second(first相等)的方式排序
    sort(segs.begin(),segs.end());

    // 定义一个最小值,最小数据是-1e9
    int bg = -2e9,ed = -2e9;
    // 存储当前待处理的区间
    vector<pair<int,int>> ans;
    for(auto seg : segs){
        if(ed < seg.first){
            if(ed != -2e9) ans.push_back({bg,ed});
            bg = seg.first;
            ed = seg.second;
        }else{
            ed = max(ed,seg.second);
        }
    }
    // 防止segs为空
    if(bg != -2e9) ans.push_back({bg,ed});
    
    segs = ans;
}

int main()
{
    cin >> n;
    while(n --){
        int l,r;
        cin >> l >> r;
        segs.push_back({l,r});
    }

    merge(segs);

    cout << segs.size();
    return 0;
}