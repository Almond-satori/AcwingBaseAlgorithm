#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;
int n;

struct Range
{
	int l,r;
	bool operator< (const Range &range) const
	{
		return l < range.l;
	}
}range[N];

int main()
{
	scanf("%d",&n);
	int a,b;	
	for(int i = 0; i < n; ++i)
	{
		scanf("%d%d",&a,&b);
		range[i] = {a,b};
	}
	
	// 按照左端点排序 
	sort(range,range + n);
	// 小根堆存储各个组中的最右边端点 
	priority_queue<int,vector<int>,greater<int> > minHeap;
	for(int i = 0; i < n; ++ i)
	{	
		auto x = range[i];
		// 如果当前左端点小于堆中最小的值(比每个组的最右端点都小,产生交叉)新建一组 
		if(minHeap.empty() || minHeap.top() >= x.l)
		{
			minHeap.push(x.r);
		}
		else
		{
			minHeap.pop();
			// 没有交叉,将当前组右端点放入堆中 
			minHeap.push(x.r);
		}
	}
	
	printf("%d\n",minHeap.size());
	
	return 0;
}

