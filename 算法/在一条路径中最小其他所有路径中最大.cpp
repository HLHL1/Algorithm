
/*

Sample Input
1
3 3
1 2 3
1 3 4
2 3 5
Sample Output
Scenario #1:
4
*/





#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;
const int maxn = 1010;
const int inf = 0x3f3f3f3f;
struct EGDE{
	int next, to;
	int w;
}egde[100000];
int head[maxn], cnt;
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
	head[u] = cnt++;
}
int dijkstra(int sx, int ex){
	memset(vis, false, sizeof(vis));
	memset(dis,0, sizeof(dis));
	for (int i = head[sx]; i!=-1;i=egde[i].next){
		dis[egde[i].to] = egde[i].w;	//这个时候d不代表从1到n的最短路径，而是最大承载量
	}
	for (int u = 1; u <= n; u++){
		int minD = -1, k = -1;
		for (int i = 1; i <= n; i++){
			if (!vis[i] && dis[i] > minD){
				k = i;
				minD = dis[i];
			}
		}
		/*if(k == ex)
		return dis[ex];*/
		vis[k] = true;

		for (int i = head[k]; i != -1; i = egde[i].next){
			int v = egde[i].to;
			if (!vis[v] && min(dis[k], egde[i].w) > dis[v]){
				dis[v] = min(dis[k], egde[i].w);
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
int main(){
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin  >> n>>m;
		init();
		read();

		printf("Scenario #%d:\n", i);
		printf("%d\n\n", dijkstra(sx, ex));


	}

	system("pause");
	return 0;
}
