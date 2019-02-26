/*

假设一个探险家被困在了地底的迷宫之中，要从当前位置开始找到一条通往迷宫出口的路径。迷宫可以用一个二维矩阵组成，有的部分是墙，有的部分是路。迷宫之中有的路上还有门，每扇门都在迷宫的某个地方有与之匹配的钥匙，只有先拿到钥匙才能打开门。请设计一个算法，帮助探险家找到脱困的最短路径。如前所述，迷宫是通过一个二维矩阵表示的，每个元素的值的含义如下 0-墙，1-路，2-探险家的起始位置，3-迷宫的出口，大写字母-门，小写字母-对应大写字母所代表的门的钥匙
输入描述:
迷宫的地图，用二维矩阵表示。第一行是表示矩阵的行数和列数M和N
后面的M行是矩阵的数据，每一行对应与矩阵的一行（中间没有空格）。M和N都不超过100, 门不超过10扇。
输出描述:
路径的长度，是一个整数

输入
5 5
02111
01a0A
01003
01001
01111

输出
7


*/

/*
解题思路：其实就是简单的BFS上加了一个钥匙的状态，因为钥匙不超过十把，所以用二进制来表示此条路上有多少种钥匙的状态，也就是说每个点的钥匙状态有1024种
*/

#include<stdio.h>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;
char G[105][105];
int book[105][105][1200], N, M;
int Next[4][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };
int bfs(int, int);
struct node{
	int x, y, k, step;
	node(int x, int y, int k, int step) :x(x), y(y), k(k), step(step){}
};
int main(){
	int i, j;
	//freopen("input.txt","r",stdin);
	while (scanf("%d%d", &N, &M) != EOF){
		for (i = 0; i<N; i++) scanf("%s", G[i]);
		memset(book, 0, sizeof(book));
		int flag = 0;
		for (i = 0; i<N; i++){
			if (flag == 1) break;
			for (j = 0; j<M; j++)
			if (G[i][j] == '2'){
				flag = 1;
				book[i][j][0] = 1;
				printf("%d\n", bfs(i, j));
				break;
			}
		}
	}
}
int bfs(int startX, int startY){
	queue<node> Q;
	Q.push(node(startX, startY, 0, 0));
	while (!Q.empty()){
		node head = Q.front(); Q.pop();
		if (G[head.x][head.y] == '3') return head.step;
		for (int i = 0; i<4; i++){
			int nx = head.x + Next[i][0], ny = head.y + Next[i][1];
			if (nx >= N || nx<0 || ny >= M || ny<0 || G[nx][ny] == '0') continue;
			int key = head.k;
			if ('a' <= G[nx][ny] && G[nx][ny] <= 'z') key = key | (1 << (G[nx][ny] - 'a'));
			if ('A' <= G[nx][ny] && G[nx][ny] <= 'Z' && (key&(1 << (G[nx][ny] - 'A'))) == 0) continue;
			if (!book[nx][ny][key]){
				book[nx][ny][key] = 1;
				Q.push(node(nx, ny, key, head.step + 1));
			}
		}
	}
	return 0;
}

