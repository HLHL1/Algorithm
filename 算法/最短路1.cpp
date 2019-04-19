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
double dis[maxn];
bool vis[maxn];
int n, m, sx, ex;
void init(){
	memset(head, -1, sizeof(head));
	cnt = 0;
}

void add(int u, int v, double w)
{
	egde[cnt].next = head[u];
	egde[cnt].to = v;
	egde[cnt].w = w;
	head[u]=cnt++;
}
double dijkstra(int sx, int ex){
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




double Len(int x1,int y1, int x2,int y2)
{
	int x = x1 - x2, y = y1 - y2;
	double len = sqrt(pow(x, 2) +pow(y, 2));
	return len;
}
int main(){
	int t;
	int flag = 0;
	while (scanf("%d", &t),t!=0)
	{
		init();
		n = t;
		for (int i = 1; i <= t; i++)
		{
			scanf("%d%d", &pos[i].x, &pos[i].y);
		}
		for (int i = 1; i <= t; i++)
		{
			for (int j = i+1; j <= t; j++)
			{
				double w=Len(pos[i].x, pos[i].y, pos[j].x, pos[j].y);

				add(i, j,w );
				add(j, i, w);
			}
		}
		printf("Scenario #%d\n", ++flag);
		printf("Frog Distance = %.3f\n\n", dijkstra(1, 2));

	}

	return 0;
}
