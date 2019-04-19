

#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#define MAX 5050
using namespace std;

//定义点
struct Point
{
	double x;
	double y;
}_point[5];

//判断是否共线
bool none()
{
	//(p2-p1)X(p3-p1)=0

	double x1 = _point[2].x - _point[1].x;
	double y1 = _point[2].y - _point[1].y;
	double x2 = _point[3].x - _point[1].x;
	double y2 = _point[3].y - _point[1].y;
	return (x1*y2 - x2*y1) == 0.0;

}

//判断是否平行
bool line()
{
	//((p1.x-p2.x)*(p3.y-p4.y)-(p1.y-p2.y)*(p3.x-p4.x))==0
	return ((_point[1].x - _point[2].x)*(_point[3].y - _point[4].y) - (_point[1].y - _point[2].y)*(_point[3].x - _point[4].x)) == 0.0;
}
double x, y;
//判断相交并且求交点
void Point_b()
{
	//(y1-y2)x0+(x2-x1)y0+x1y2-x2y1=0
	//(y3 - y4)x0 + (x4 - x3)y0 + x3y4 - x4y3 = 0
	//a1x+b1y+c1=0;
	//a2x + b2y + c2 = 0
	//x=(c1*b2-c2*b1)/(a2*b1-a1*b2);
	//y = (a2*c1 - a1*c2) / (a1*b2 - a2*b1);
	double a1 = _point[1].y - _point[2].y;
	double b1 = _point[2].x - _point[1].x;
	double c1 = _point[1].x*_point[2].y - _point[2].x*_point[1].y;
	double a2 = _point[3].y - _point[4].y;
	double b2 = _point[4].x - _point[3].x;
	double c2 = _point[3].x*_point[4].y - _point[4].x*_point[3].y;
	x = (c1*b2 - c2*b1) / ((a2*b1 - a1*b2)*1.0);
	y = (a2*c1 - a1*c2) / ((a1*b2 - a2*b1)*1.0);

}

int main()
{
	int n;
	scanf("%d", &n);
	printf("INTERSECTING LINES OUTPUT\n");
	while (n--)
	{
		for (int i = 1; i <= 4; i++)
		{
			scanf("%lf%lf", &_point[i].x, &_point[i].y);
		}
		if (line())
		{
			if (none())
			{
				printf("LINE\n");
			}
			else
			{
				printf("NONE\n");
			}
		}
		else
		{
			Point_b();
			printf("POINT %.2f %.2f\n", x, y);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
