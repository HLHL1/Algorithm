//һ�����������͹������������ʼ�㣬���������

/*
bool cmp0(const point& a, const point& b) // ����complex�ఴ���Ǵ�С��������
{
    complex<double> c1(a.x,a.y);                   //ͷ�ļ� #include<complex>
    complex<double> c2(b.x,b.y);
    if( arg(c1) == arg(c2))
        return a.x<b.x;
    return arg(c1) < arg(c2);
}
bool cmp2(point a,point b) //���ò�������Ǵ�С��������
{
    point c;//ԭ��
    c.x = 0;
    c.y = 0;
    if(compare(c,a,b)==0)
        return a.x<b.x;
    else return compare(c,a,b)>0;
}

 sort(p + 1, p + n, cmp1);
*/

 //һ�����������͹������������ʼ�㣬���������
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct point
{
	int x, y;
}A[55];



int cp(point p1, point p2, point p3)
{
	return (p1.x*p3.y - p3.x*p1.y) - (p2.x*p3.y - p3.x*p2.y);
}
bool cmp(point a, point b)
{
	return cp(A[0], a, b)<0;
}
int main()
{
	int n = 0;
	while (scanf("%d%d", &A[n].x, &A[n].y) != EOF)
		n++;
	sort(A + 1, A + n, cmp);
	for (int i = 0; i<n; i++)
	{
		printf("(%d,%d)\n", A[i].x, A[i].y);
	}
	return 0;
}
