#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define EPS 0.00000001
struct Point
{
	double x, y;
}_point[500];

struct line
{
	Point a, b;
}l;

//计算叉积 (P1-P0)x(P2-P0)
double xmult(Point p1, Point p2, Point p0)
{
	return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}
//double xmult(double x1, double y1, double x2, double y2, double x0, double y0)
//{
//	return (x1 - x0)*(y2 - y0) - (x2 - x0)*(y1 - y0);
//}

//判两点在线段异侧,点在线段上返回0
int opposite_side(Point p1, Point p2)
{
	return xmult(l.a, p1, l.b)*xmult(l.a, p2, l.b)<EPS;
}
//int opposite_side(point p1, point p2, point l1, point l2)
//{
//	return xmult(l1, p1, l2)*xmult(l1, p2, l2)<-eps;
//}


int n;

bool If()
{
	for (int i = 0; i < 2*n; i+=2)
	{
		if (!opposite_side(_point[i], _point[i+1]))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		/*for (int i = 0; i < 400; i++)
		{
			_point[i].x = 0;
			_point[i].y = 0;
		}*/
		scanf("%d", &n);
		for (int i = 0; i < 2 * n; i++)
		{
			scanf("%lf%lf", &_point[i].x, &_point[i].y);
		}
		int flag = 0;
		for (int i = 0; i < 2 * n; i++)
		{
			for (int j = i + 1; j < 2 * n; j++)
			{
				l.a.x = _point[i].x;
				l.a.y = _point[i].y;
				l.b.x = _point[j].x;
				l.b.y = _point[j].y;

				if ((fabs(l.a.x - l.b.x) < EPS) && (fabs(l.a.y - l.b.y) < EPS))
				{
					continue;
				}
				if (If())
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag==0)
		{
			printf("No!\n");
		}
		else
		{
			printf("Yes!\n");
		}

	}
	system("pause");
	return 0;
}
