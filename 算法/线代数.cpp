




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
���ӣ�https://www.nowcoder.com/acm/contest/213/A
��Դ��ţ����

һ��������ô��û�д�ģ����qwq��SKY_magician��˵�����ɱ�������˿ˡ�UNO��ɱ���ϵȵȣ�������������Щģ��д����̫���ˣ��������������һ���϶����ᳬ��1500�еĴ�ģ�⣨��������

��������һ��4*n�����̺�һ��ض������ƣ���Щ���ƶ���1*2�ġ���������ù�����ȫ����������̵ķ�������mȡģ��ֵ��

��������:
��һ��һ��T��ʾ��������

����ÿ����������n��m��n��m�������Ŀ������
�������:
�����
ʾ��1
����
����
3
1 10000
3 10000
5 10000
���
����
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
