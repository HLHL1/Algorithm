#include<stdio.h>
#include<cstdio>
#include<cmath>
#include<algorithm>f
using namespace std;

const int maxn = 1e3;
double pi = 3.1415926;
int n;
struct tnode{
	int x, y;
}p[maxn + 10];

//两点之间的长度
double get_len(tnode a, tnode b)
{
	int dx = a.x - b.x, dy = a.y - b.y;
	return sqrt(dx*dx*1.0 + dy*dy);
}

//Graham扫描算法中，对幅角进行排序（如果幅度相同，按据p0的距离大小排序）
bool cmp_p(tnode a, tnode b)
{
	int dax = a.x - p[1].x, day = a.y - p[1].y;
	int dbx = b.x - p[1].x, dby = b.y - p[1].y;
	if (day*dbx == dax*dby)
		return get_len(p[1], a)<get_len(p[1], b);
	return day*dbx<dax*dby;
}

//判断线段顺时针转还是逆时针转
int get_cha(tnode a, tnode b, tnode c)
{
	int abx = b.x - a.x, aby = b.y - a.y;
	int acx = c.x - a.x, acy = c.y - a.y;
	return abx*acy - aby*acx;
}

void graham()
{
	int i, k;
	if (n <= 3)return;
	for (k = 1, i = 2; i <= n; i++)
	{
		if (p[i].y>p[k].y)continue;
		if (p[i].y<p[k].y || p[i].x<p[k].x)k = i;
	}
	swap(p[k], p[1]);
	sort(p + 2, p + 2 + n - 1, cmp_p);
	for (k = 3, i = 4; i <= n; i++)
	{
		while (k >= 3 && get_cha(p[k - 1], p[k], p[i])<0)
			k--;
		p[++k] = p[i];
	}
	n = k;
}

int main()
{
	int L, i; double ans;
	scanf("%d%d", &n, &L);
	for (i = 1; i <= n; i++)
		scanf("%d%d", &p[i].x, &p[i].y);
	//求凸包上的点
	graham();
	//计算凸包的周长
	ans = get_len(p[n], p[1]) + 2 * L*pi;
	for (i = 1; i < n; i++)
		ans += get_len(p[i], p[i + 1]);
	printf("%d\n", (int)(ans + 0.5));//四舍五入
     return 0;

}
