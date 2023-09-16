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
	
	// ������˵����� 
	sort(range,range + n);
	// С���Ѵ洢�������е����ұ߶˵� 
	priority_queue<int,vector<int>,greater<int> > minHeap;
	for(int i = 0; i < n; ++ i)
	{	
		auto x = range[i];
		// �����ǰ��˵�С�ڶ�����С��ֵ(��ÿ��������Ҷ˵㶼С,��������)�½�һ�� 
		if(minHeap.empty() || minHeap.top() >= x.l)
		{
			minHeap.push(x.r);
		}
		else
		{
			minHeap.pop();
			// û�н���,����ǰ���Ҷ˵������� 
			minHeap.push(x.r);
		}
	}
	
	printf("%d\n",minHeap.size());
	
	return 0;
}

