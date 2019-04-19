#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
//���������
int r, c, n;//rΪ�����������cΪ�����������nΪ����̤�ĵ�����Ŀ

struct  PLANT
{
	int x;
	int y;
};
PLANT plants[5001];//���е��ӵ�����
PLANT  plant;//�������ӵ�����

int BinarySearch(PLANT pla, int a, int b);
int main()
{
	int i, j, steps;
	int px, py, dx, dy;
	int max = 2;
	printf("���뵾��������������Լ�����̤�ĵ��ӵ���Ŀ�����꣺\n");
	scanf_s("%d%d", &r, &c);
	scanf_s("%d", &n);
	for (i = 0; i < n; ++i)
		scanf_s("%d%d", &plants[i].x, &plants[i].y);
	sort(plants, plants + n);//������������������xС���ţ���x��ͬ��yС����
	for (i = 0; i < n; ++i)
		printf("%d%d\n", plants[i].x,plants[i].y);
	for (i = 0; i < n - 2; ++i)//i�ǵ�һ���㣬j�ǵڶ�����
		for (j = i + 1; j < n - 1; ++j)
		{
			dx = plants[j].x - plants[i].x;//����x���о�
			dy = plants[j].y - plants[i].y;//����y���о�
			px = plants[i].x - dx;//��һ��ˮ���ĺ�����
			py = plants[i].y - dy;//��һ��ˮ����������
			if (px <= r&&px >= 1 && py <= c&&py >= 1)
				continue;//����һ��ˮ���������ڵ������棬˵����һ���ļ��̫С�ˣ���Ҫ�䳤һЩ��ȡ��һ������Ϊ�ڶ���
			if ((plants[i].x + (max-1)*dx)>r)//���ڶ��������⣬��ѡȡ�Ĳ����ʣ�����ѡȡ��һ����
				break;//x������������,��һ�㲻����
			//lost
			int pY;
			pY = plants[i].y + (max - 1)*dy;
			if (pY > c || pY < 1)
				continue;//y�����������ˣ��ڶ��㲻����
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
		if (!binary_search(plants, plants + n,plant))//���ֲ��Һ����������õ���������������Ҫʹ��"operator<",��bool����
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
