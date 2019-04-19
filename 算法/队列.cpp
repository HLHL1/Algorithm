/*

Examples
inputCopy
4 5 3
3 5 1 2
outputCopy
3
3 1 1 2
inputCopy
10 10 1
10 5 7 4 6 3 2 1 9 8
outputCopy
2
2 1 1 2 2 1 2 1 1 2
*/





#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;



struct Node
{
	int _id;
	int _time;
	int _day;
}node[200010];

bool compare1(const Node &a, const Node &b)
{
	return a._time<b._time;   //升序排列，如果改为return a>b，则为降序

}
bool compare2(const Node &a, const Node &b)
{
	return a._id<b._id;   //升序排列，如果改为return a>b，则为降序

}
queue<Node>q;
int main()
{
	int n, m, d;
	cin >> n >> m >> d;
	memset(node, 0, sizeof(node));
	for (int i = 1; i <= n; i++)
	{
		node[i]._id = i;
		cin >> node[i]._time;
	}
	sort(node, node + n + 1, &compare1);
	int ans = 0;
	ans++;
	node[1]._day = ans;
	q.push(node[1]);
	for (int i = 2; i <= n; i++)
	{
		if (node[i]._time - q.front()._time > d)
		{
			node[i]._day = q.front()._day;
			q.pop();
			q.push(node[i]);
		}
		else
		{
			ans++;
			node[i]._day = ans;
			q.push(node[i]);
		}
	}
	printf("%d\n", ans);
	sort(node, node + n + 1, &compare2);
	for (int k = 1; k <= n; k++)
	{
		printf("%d ", node[k]._day);
	}
	printf("\n");
	system("pause");
	return 0;
}
