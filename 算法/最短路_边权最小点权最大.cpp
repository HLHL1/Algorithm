#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxv = 1010;
const int inf = 100000000000;

int mp[maxv][maxv],weight[maxv];//邻接矩阵mp记录无向图，weight记录点权
int m,n,st,ed,num[maxv],w[maxv],d[maxv];//n是地点个数，m是边数，st是起点，ed是终点，num是最短路径条数，w是最大点权和，d是最短距离
bool vis[maxv]={false};//标记某点是否被访问

void dijkstra(int s)
{
	fill(d,d+maxv,inf);
	memset(num,0,sizeof(num));
	memset(w,0,sizeof(w));
	d[s]=0;
	w[s]=weight[s];
	num[s]=1;

	for(int i = 0;i<n;i++)
	{
		int u = -1,min=inf;//u让d[u]最小，min存最小的d[u]
		for(int j =0;j<n;j++)//找没有访问的点里d[]最小的
		{
			if(vis[j]==false&&d[j]<min)
			{
				u=j;
				min=d[j];
			}
		}
		if(u==-1) return;//找不到小于inf的d[u]，剩下的点和起点不连通
		vis[u]=true;//u被访问
		for(int v=0;v<n;v++)
		{
			if(vis[v]==false&&mp[u][v]!=inf)//若v未被访问过且u为中介点可以松弛d[v]
			{
				if(d[u]+mp[u][v]<d[v])
				{
					d[v]=mp[u][v]+d[u];
					w[v]=w[u]+weight[v];
					num[v]=num[u];
				}
				else if(d[u]+mp[u][v]==d[v])//找到了一条相同长度的路径
				{
					if(w[u]+weight[v]>w[v])//若u为中介可以使点权和变大
						w[v]=w[u]+weight[v];
					num[v]+=num[u];//更新最短路径条数
				}
			}
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i =0;i<n;i++)
	{
		scanf("%d",&weight[i]);
	}
	ed=n-1;//因为是从0开始读的所以终点要n-1
	int u,v;
	fill(mp[0],mp[0]+maxv*maxv,inf);//初始化邻接矩阵
	scanf("%d",&m);
	for(int i =0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		scanf("%d",&mp[u-1][v-1]);//因为编号从0开始，所以要把题目给的-1
		mp[v-1][u-1]=mp[u-1][v-1];
	}
	dijkstra(0);//从0开始的dijkstra入口
	if(w[ed]!=0)//最大点权和不是0，意味着可以走到终点
		printf("%d %d\n",d[ed],w[ed]);
	else
		printf("impossible");

	return 0;
}
