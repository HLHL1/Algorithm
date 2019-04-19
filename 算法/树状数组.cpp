

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;

int A[100010], c[100010];
int n;
int lowbit(int n)
{
	return n&-n;
}

int Find(int x)
{
	int ans=0;
	for (int i = x; i >0; i -= lowbit(i))
	{
		ans += c[i];
	}
	return ans;
}

void add(int x,int y)
{
	for (int i = x; i <= n; i += lowbit(i))
	{
		c[i]+= y;
	}
}

int main()
{
	int q;
	scanf("%d%d", &n, &q);
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &A[i]);
		add(i,A[i]);
	}

	for (int i = 0; i < q; i++)
	{
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		if (a == 1)
		{
			printf("%d\n",Find(d)-Find(b-1));
		}
		else
		{
			int k = d - A[b];
			add(b,k);
		}
	}
	system("pause");
	return 0;
}

/*
样例输入 复制
5 3
1 2 3 4 5
1 1 3
2 5 0
1 4 5
样例输出 复制
10
8

*/

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<map>
#define ll long long int
using namespace std;

ll A[100110];
ll c[100110], ce[100110];
int n;
int lowbit(int n)
{
	return n&(-n);
}

ll Find(int x,ll c[])
{
	ll ans=0;
	for (int i = x; i >0; i -= lowbit(i))
	{
		ans += c[i];
	}
	return ans;
}

void add(int x,ll y,ll c[])
{
	for (int i = x; i <= n; i += lowbit(i))
	{
		c[i]+= y;
	}
}

int main()
{
	int q;
	scanf("%d%d", &n, &q);
	memset(c, 0, sizeof(c));
	memset(ce, 0, sizeof(ce));
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &A[i]);
		add(i,A[i],c);
		add(i,(n-i+1)*A[i], ce);
	}

	for (int i = 0; i < q; i++)
	{
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		if (a == 1)
		{
			ll ans1 = (Find(d, c) - Find(b - 1, c))*(n-d);
			ll ans2 = Find(d, ce) - Find(b - 1, ce);
			printf("%lld\n",ans2-ans1);
		}
		else
		{
			ll k = d - A[b];
			add(b,k,c);
			add(b, k*(n + 1 - b), ce);
			A[b] = d;
		}
	}
	system("pause");
	return 0;
}
