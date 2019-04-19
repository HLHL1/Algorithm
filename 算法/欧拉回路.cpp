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
		memset(d, 0, sizeof(d));                //��������
		for (i = 1; i <= n; i++)
		{
			fa[i] = i;
		}
		scanf("%d", &m);
		for (i = 0; i < m; i++)
		{
			scanf("%d %d", &a, &b);
			d[a]++;
			d[b]++;                    //��¼ÿ����Ķ���
			f1(a, b);
		}
		cnt = 0; key = 0;
		for (i = 1; i <= n; i++)
		{
			if (d[i] % 2)        //�ж�ÿ���㶼��ż��
			{
				key = 1;
			}
			if (i == fa[i])        //�ж�û�ж����ĵ�
			{
				cnt++;
			}
		}
		if (cnt == 1)                //û�ж����ĵ�
		{
			if (key == 0)            //ÿ����Ķ�������ż��
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
