/*
Sample Input
2
0 0
3 4

3
17 4
19 4
18 5

0
Sample Output
Scenario #1
Frog Distance = 5.000

Scenario #2
Frog Distance = 1.414

*/




#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;
const int maxn = 210;
const int inf = 0x3f3f3f3f;
struct EGDE{
	int next, to;
	double w;
}egde[100000];
struct pos{
	int x, y;
}pos[210];
int head[maxn],cnt;
int dis[maxn];
bool vis[maxn];
int n, m, sx, ex;
void init(){
	memset(head, -1, sizeof(head));
	cnt = 0;
}

void add(int u, int v, int w)
{
	egde[cnt].next = head[u];
	egde[cnt].to = v;
	egde[cnt].w = w;
	head[u]=cnt++;
}
int dijkstra(){
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < maxn; i++)
	{
		dis[i] = 100000000000;
	}
	dis[sx] = 0;
	for (int u = 1; u <= n; u++){
		int minD = inf, k = -1;
		for (int i = 1; i <= n; i++){
			if (!vis[i] && dis[i] < minD){
				k = i;
				minD = dis[i];
			}
		}
		/*if(k == ex)
		    return dis[ex];*/
		vis[k] = true;

		//找当前这个点到各个点之间的最小路径
		for (int i = head[k]; i!=-1; i=egde[i].next){
			int v = egde[i].to;
			if (!vis[v] && max(dis[k] , egde[i].w) < dis[v]){
				dis[v] = max(dis[k] , egde[i].w);
			}
		}
	}
	return dis[ex];
}


int main(){
	int k,m;
	scanf("%d%d%d%d",&k,&m,&sx,&ex);
	int flag = 0;
		init();
		n = m;
		for (int i = 1; i <= m; i++)
		{
		    int a,b;
		    scanf("%d%d%d",&a,&b);
				add(a, b,w );

		}
		printf("Frog Distance = %d\n\n", dijkstra());

	return 0;
}
