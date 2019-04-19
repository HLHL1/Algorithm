//思路：
//
//简单的深搜，加边的时候要加入双向边。然后深搜每个点即可。
//
//将无根树化为有根树，对每个节点进行遍历，记录从起点开始的父节点。

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int pre[100005];
vector<int>v[100005];

void DFS(int cur)
{
	for(int i = 0; i < v[cur].size(); ++i)
	{
		if(pre[v[cur][i]]) continue; //若存在父节点则继续遍历
		pre[v[cur][i]] = cur; //相连节点的父节点为cur
		DFS(v[cur][i]); //深搜到底，把一条路上父节点全部找出
	}
}

int main()
{
	int ncase, num, cur, i, x, y;
	scanf("%d", &ncase);
	while(ncase--)
	{
		memset(v, 0, sizeof(v));
		memset(pre, 0, sizeof(pre));
		scanf("%d%d", &num, &cur);
		pre[cur] = - 1; //起点没有父节点
		for(i = 0; i < num - 1; ++i)
		{
			scanf("%d%d", &x, &y);
			v[x].push_back(y); //x与y相连
			v[y].push_back(x); //y与x也肯定相连
		}
		DFS(cur); //起点开始深搜
		for(i = 1; i <= num; ++i)
			printf("%d ", pre[i]); //每个节点的父节点都保存在pri数组，输出即可
	}
	return 0;
}
