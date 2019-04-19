#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
void Tarjan ( int x ) {
         dfn[ x ] = ++dfs_num ;
         low[ x ] = dfs_num ;
         vis [ x ] = true ;//是否在栈中
         stack [ ++top ] = x ;
         for ( int i=head[ x ] ; i!=0 ; i=e[i].next ){
                  int temp = e[ i ].to ;
                  if ( !dfn[ temp ] ){
                           Tarjan ( temp ) ;
                           low[ x ] = gmin ( low[ x ] , low[ temp ] ) ;
                 }
                 else if ( vis[ temp ])low[ x ] = gmin ( low[ x ] , dfn[ temp ] ) ;
         }
         if ( dfn[ x ]==low[ x ] ) {//构成强连通分量
                  vis[ x ] = false ;
                  color[ x ] = ++col_num ;//染色
                  while ( stack[ top ] != x ) {//清空
                           color [stack[ top ]] = col_num ;
                           vis [ stack[ top-- ] ] = false ;
                 }
                 top -- ;
         }
}





/*

Sample Input
3 3
1 2
2 1
2 3
Sample Output
1
*/



#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 50100;



/*
7 9
1 3
1 2
3 5
5 6
7 7
4 6
3 4
4 1
2 4


*/
struct EDGE{
	int next, to, w;
}edge[maxn << 4];
int head[maxn];
int cnt,dfn[maxn],low[maxn],vis[maxn],Stack[maxn],color[maxn];
int dfs_num,top,col_num;
void init_add(){
	cnt = 0;
	memset(head, -1, sizeof(head));
}
void add(int u, int v){
	edge[cnt].next = head[u];
	edge[cnt].to = v;
	head[u] = cnt++;
}

void init_Tarjan()
{
	dfs_num = 0;
	top = 0;
	col_num = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(vis,false , sizeof(vis));
	memset(Stack, 0, sizeof(Stack));
	memset(color, 0, sizeof(color));
}
void Tarjan(int x) {
	dfn[x] = ++dfs_num;
	low[x] = dfs_num;
	vis[x] = true;//是否在栈中
	Stack[++top] = x;
	for (int i = head[x]; i != -1; i = edge[i].next){
		int temp = edge[i].to;
		if (!dfn[temp]){
			Tarjan(temp);
			low[x] = min(low[x], low[temp]);
		}
		else if (vis[temp])
			low[x] = min(low[x], dfn[temp]);
	}

	if (dfn[x] == low[x]) {//构成强连通分量
		vis[x] = false;
		color[x] = ++col_num;//染色
		while (Stack[top] != x) {//清空
			color[Stack[top]] = col_num;
			vis[Stack[top--]] = false;
		}
		top--;
	}
}


int main()
 {
	int n, m;
	scanf("%d%d", &n, &m);

	init_add();
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
	}
	init_Tarjan();
	for (int i = 1; i <= n; i++)
	{
		if (!color[i])
		{
			Tarjan(i);
		}
	}
	int dgree[maxn] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		for (int u = head[i]; u != -1; u = edge[u].next)
		{
			if (color[i] != color[edge[u].to])
			{
				dgree[color[i]]++;
			}
		}
	}
	int ret = 0,flag=0,kk;
	for (int i = 1; i <=col_num ; i++)
	{
		if (dgree[i] == 0)
		{
			flag++;
			kk = i;
		}
	}
	if (flag > 1 || flag == 0)
	{
		ret = 0;
	}
	else
	{
		for (int j = 1; j <= n; j++)
		{
			if (color[j] == kk)
			{
				ret++;
			}
		}
	}
	printf("%d\n", ret);
	system("pause");
	return 0;
}
