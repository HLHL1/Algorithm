#include<cstdio>
#include<string.h>
int n, m, cnt, key, a, b, fa[1010], d[1010], i;
int find(int a)
{
	if (a == fa[a])
	{
		return a;
	}
	else
	{
		return fa[a] = find(fa[a]);
	}
}
void f1(int x, int y)
{
	int nx, ny;
	nx = find(x);
	ny = find(y);
	if (nx != ny)
	{
		fa[ny] = nx;
	}
}
int main()
{
	while (scanf("%d", &n) && n)
	{
		memset(d, 0, sizeof(d));                //数组清零
		for (i = 1; i <= n; i++)
		{
			fa[i] = i;
		}
		scanf("%d", &m);
		for (i = 0; i < m; i++)
		{
			scanf("%d %d", &a, &b);
			d[a]++;
			d[b]++;                    //记录每个点的度数
			f1(a, b);
		}
		cnt = 0; key = 0;
		for (i = 1; i <= n; i++)
		{
			if (d[i] % 2)        //判断每个点都是偶度
			{
				key = 1;
			}
			if (i == fa[i])        //判断没有独立的点
			{
				cnt++;
			}
		}
		if (cnt == 1)                //没有独立的点
		{
			if (key == 0)            //每个点的度数都是偶数
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}
