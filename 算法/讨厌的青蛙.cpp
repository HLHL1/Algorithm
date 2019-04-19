#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
//讨厌的青蛙
int r, c, n;//r为稻田的行数，c为稻田的列数，n为被踩踏的稻子数目

struct  PLANT
{
	int x;
	int y;
};
PLANT plants[5001];//所有稻子的坐标
PLANT  plant;//单个稻子的坐标

int BinarySearch(PLANT pla, int a, int b);
int main()
{
	int i, j, steps;
	int px, py, dx, dy;
	int max = 2;
	printf("输入稻田的行数和列数以及被踩踏的稻子的数目和坐标：\n");
	scanf_s("%d%d", &r, &c);
	scanf_s("%d", &n);
	for (i = 0; i < n; ++i)
		scanf_s("%d%d", &plants[i].x, &plants[i].y);
	sort(plants, plants + n);//对输入的坐标进行排序，x小先排，若x相同则y小先排
	for (i = 0; i < n; ++i)
		printf("%d%d\n", plants[i].x,plants[i].y);
	for (i = 0; i < n - 2; ++i)//i是第一个点，j是第二个点
		for (j = i + 1; j < n - 1; ++j)
		{
			dx = plants[j].x - plants[i].x;//计算x的行距
			dy = plants[j].y - plants[i].y;//计算y的行距
			px = plants[i].x - dx;//上一颗水稻的横坐标
			py = plants[i].y - dy;//上一颗水稻的纵坐标
			if (px <= r&&px >= 1 && py <= c&&py >= 1)
				continue;//若第一课水稻的坐标在稻田里面，说明第一步的间距太小了，需要变长一些，取下一个点作为第二点
			if ((plants[i].x + (max-1)*dx)>r)//若第二步在田外，则选取的不合适，重新选取第一个点
				break;//x方向过早过界了,第一点不成立
			//lost
			int pY;
			pY = plants[i].y + (max - 1)*dy;
			if (pY > c || pY < 1)
				continue;//y方向过早过界了，第二点不成立
			steps = BinarySearch(plants[j], dx, dy);
			if (steps > max)
				max = steps;
		}
	if (max == 2)
		max = 0;
	printf("%d\n", max);
}

int BinarySearch(PLANT pla, int dx, int dy)
{
	int steps;
	plant.x = pla.x + dx;
	plant.y = pla.y + dy;
	steps = 2;
	while (plant.x <= r&&plant.x >= 1 && plant.y <= c&&plant.y >= 1)
	{
		if (!binary_search(plants, plants + n,plant))//二分查找函数，若是用到其他的数据则需要使用"operator<",是bool类型
		{
			steps = 0;
			break;
		}
		plant.x += dx;
		plant.y += dy;
		steps++;
	}
	return steps;
}

bool operator <(const PLANT &p1, const PLANT &p2)
{
	if (p1.x == p2.x)
		return p1.y < p2.y;
	return p1.x < p2.x;
}
