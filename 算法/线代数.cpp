




/*
const int Base[4][4]={
    1,1,0,0,
    5,0,1,0,
    1,0,0,1,
    -1,0,0,0
};
const int Ans[4][4]={
    1,0,0,0,
    0,1,0,0,
    0,0,1,0,
    0,0,0,1
};
链接：https://www.nowcoder.com/acm/contest/213/A
来源：牛客网

一场考试怎么能没有大模拟呢qwq，SKY_magician听说过猪国杀、德州扑克、UNO、杀蚂蚁等等，但是他觉得这些模拟写起来太短了，于是他就设计了一个肯定不会超过1500行的大模拟（划掉）。

现在你有一个4*n的棋盘和一坨地斗主骨牌，这些骨牌都是1*2的。请你求出用骨牌完全覆盖这个棋盘的方案数对m取模的值。

输入描述:
第一行一个T表示数据组数

对于每组数据输入n和m，n和m意义见题目描述。
输出描述:
输出答案
示例1
输入
复制
3
1 10000
3 10000
5 10000
输出
复制
1
11
95

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,s,t) for(int i=s;i<=t;++i)
using namespace std;
long long n, m;
struct node{
	long long a[5][5];
};
long long mod;
node mul(node x, node y){
	node z;
	memset(z.a, 0, sizeof(z.a));
	F(i, 0, 3){
		F(j, 0, 3){
			for (int k = 0; k<4; k++)
				z.a[i][j] += x.a[i][k] * y.a[k][j];
			z.a[i][j] %= mod;
		}
	}
	return z;
}
node pow(node x, node y, long long p){
	node z;
	memset(z.a, 0, sizeof(z.a));
	F(i, 0, 3)
		z.a[i][i] = 1;
	while (p){
		if (p & 1) z = mul(z, x);
		x = mul(x, x);
		p >>= 1;
	}
	z = mul(z, y);
	return z;
}
int main(){

	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		mod = m;
		int ans[5] = { 0, 1, 5, 11, 36 };
		if (n <= 4) printf("%d\n", ans[n]);
		else{
			node x;
			memset(x.a, 0, sizeof(x.a));
			x.a[0][0] = 1;
			x.a[0][1] = 5;
			x.a[0][2] = 1;
			x.a[0][3] = -1;
			x.a[1][0] = 1;
			x.a[2][1] = 1;
			x.a[3][2] = 1;
			node y;
			memset(y.a, 0, sizeof(y.a));
			y.a[0][0] = 36;
			y.a[1][0] = 11;
			y.a[2][0] = 5;
			y.a[3][0] = 1;
			node z;
			z = pow(x, y, n - 4);
			printf("%lld\n", (z.a[0][0] + mod) % mod);
		}
	}
	return 0;
}
