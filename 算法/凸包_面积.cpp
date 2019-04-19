#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n, top;
struct point
{
	int x, y;
} p[1005], s[1005], t;


//求向量t1t2和向量t3t4的叉积
double cross(point t1, point t2, point t3, point t4)
{
	return (t2.x - t1.x)*(t4.y - t3.y) - (t2.y - t1.y)*(t4.x - t3.x);
}

//求距离-点到p0
double dis(point t1, point t2)
{
	double z = (t2.x - t1.x)*(t2.x - t1.x) + (t2.y - t1.y)*(t2.y - t1.y);
	return sqrt(z);
}

//
bool cmp(point t1, point t2)
{
	double z = cross(p[0], t1, p[0], t2);
	return z ? z>0:dis(p[0], t1)>dis(p[0], t2);
}

//找基点，按y从小到大，如果y相同，按x从左到右
void findpoint()
{
	int i, j = 0;
	t = p[0];
	for (i = 1; i<n; i++)
	{
		if (t.y>p[i].y || (t.y == p[i].y&&t.x>p[i].x))
		{
			j = i;
			t = p[i];
		}
	}
	t = p[0];
	p[0] = p[j];
	p[j] = t;
}
void scanner()
{
	int i;
	findpoint();
	sort(p + 1, p + n, cmp);
	s[0] = p[0];
	s[1] = p[1];
	top = 1;
	for (i = 2; i<n; i++)
	{
		while (cross(s[top - 1], s[top], s[top], p[i])<0)
			top--;
		top++;
		s[top] = p[i];
	}
}

double area(point  p0, point p1, point p2)
{
	return ((p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y)) / 2;
}

int main()
{
	while (~scanf("%d", &n))
	{
		for (int i = 0; i<n; i++)
		{
			scanf("%d%d", &p[i].x, &p[i].y);
		}
		top = 0;
		scanner();

		double ans=0,flag;
		for (int i = 2; i <= top; i++)
		{
			flag = area(s[0], s[i - 1], s[i]);
			ans += flag;
		}
		ans = ans / 50;
		printf("%d\n",(int) ans);


	}
	return 0;
}
