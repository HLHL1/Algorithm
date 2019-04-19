
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1000;
const int inf = 0x3f3f3f3f;
//int rode[maxn][maxn];
struct EGDE{
	int next, to, w;
}egde[maxn<<4];
int head[maxn],cnt;
int dis[maxn];
bool vis[maxn];
int n, m, sx, ex;
void init(){
	//memset(egde, inf, sizeof(egde));
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
int dijkstra(int sx, int ex){
	memset(vis, false, sizeof(vis));
	memset(dis, inf, sizeof(dis));
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
			if (!vis[v] && dis[k] + egde[i].w < dis[v]){
				dis[v] = dis[k] + egde[i].w;
			}
		}
	}
	return dis[ex];
}

//建立邻接矩阵
void read(){
	int u, v, w;
	sx = 1, ex = n;//设置源点和终点
	for (int i = 0; i < m; i++){
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
		/*egde[u][v] = min(egde[u][v], w);
		egde[v][u] = min(egde[v][u], w); */ //双向边
	}
}
void solve(){
	printf("%d\n", dijkstra(sx, ex));
}
int main(){
	while (~scanf("%d%d", &m, &n)){
		init();
		read();
		solve();

	}

	return 0;
}








#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;
const int maxn = 200;
const int inf = 0x3f3f3f3f;
struct EGDE{
	int next, to;
	int w;
}egde[maxn<<4];
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

int SPFA(int sx,int ex){
	memset(vis, false, sizeof(vis));
	memset(dis, inf, sizeof(dis));
	dis[sx] = 0;
	queue<int>que;
	que.push(sx);
	while (!que.empty())
	{
		int kk = que.front();
		que.pop();
		vis[kk] = false;
		for (int i = head[kk]; i != -1; i = egde[i].next)
		{
			int v = egde[i].to;
			if (dis[kk]+ egde[i].w< dis[v]){
				dis[v] = dis[kk] + egde[i].w;
				if (vis[v] == false)
				{
					que.push(v);
					vis[v] = true;
				}
			}

		}

	}
	return dis[ex];
}
void read(){
	int u, v, w;
	sx = 1, ex = n;//设置源点和终点
	for (int i = 0; i < m; i++){
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);

	}
}
void solve(){
	printf("%d\n", SPFA(sx, ex));
}
int main(){
	while (~scanf("%d%d", &m, &n)){
		init();
		read();
		solve();

	}

	return 0;
}
