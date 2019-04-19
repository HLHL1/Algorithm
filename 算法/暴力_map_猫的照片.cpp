
/*
1
8
2 1 1 2 2
2 1 1 1 4
2 1 1 2 2
2 2 2 1 4
0
0
1 1 1
1 1 1


3
*/
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAX 100010
struct Node{
	int x, y;
	int cnt;
}node[MAX];
int k[MAX];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--){
		memset(node, 0, sizeof( node));
		int n;
		cin >> n;
		int id = 0,ans=0;
		for (int i = 1; i <= n; i++){
			scanf("%d", &k[i]);
			int x, y;
			int r = id,cnt=0;
			for (int j = 0; j < k[i]; j++){
				scanf("%d%d", &x, &y);
				cnt = 1;
				for (int l = r - k[i - 1]; l < r; l++){
					if (x == node[l].x&&y == node[l].y){
						cnt += node[l].cnt;
						break;
					}
				}
				node[id].x = x;
				node[id].y = y;
				node[id].cnt = cnt;
				ans = max(ans, cnt);
				id++;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
