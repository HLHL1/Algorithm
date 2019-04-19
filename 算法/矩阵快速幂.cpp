



/*C.���� f(x).
 �� x < 10 f(x) = x.
 ��x >= 10 f(x) = a0 * f(x-1) + a1 * f(x-2) + a2 * f(x-3) + ���� + a9 * f(x-10);
  ai(0<=i<=9) ֻ��Ϊ 0 �� 1 .

��֪ a0 ~ a9 ������������ k �� m ���� f(k)%m.

����

��������������������
 ��ÿ������£��������С�
 �ڵ�һ����������������k��m��(k < 2 * 10 ^ 9 m < 10 ^ 5)
 �ڵڶ����У���10����������a0 ~ a9
 */

/*
#include<iostream>
#include<cstring>
using namespace std;
#define N 10
//#define M 1000000009
long long tmp[N][N];
int M, k;
void multi(long long a[][N], long long b[][N], long long n)
{
	memset(tmp, 0, sizeof tmp);
	for (long long i = 0; i<n; i++)
	for (long long j = 0; j<n; j++)
	for (long long k = 0; k<n; k++)
		tmp[i][j] += ((a[i][k] % M) * (b[k][j] % M)) % M;
	for (long long i = 0; i<n; i++)
	for (long long j = 0; j<n; j++)
		a[i][j] = tmp[i][j] % M;
}
long long res[N][N];
void Pow(long long a[][N], long long n)
{
	memset(res, 0, sizeof res);//n���ݣ�N�Ǿ����С
	for (long long i = 0; i<N; i++) res[i][i] = 1;
	while (n)
	{
		if (n & 1)
			multi(res, a, N);//res=res*a;����ֱ����multi����ʵ���ˣ�
		multi(a, a, N);//a=a*a
		n >>= 1;
	}
}
int main()
{
	while (cin >> k >> M)
	{
		long long a[10][10];
		for (int i = 0; i < 10; i++)
		{
			cin >> a[0][i];
		}
		if (k < 10)
		{
			cout << k << endl;
		}
		else
		{
			for (int i = 1; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (i - j == 1)
					{
						a[i][j] = 1;
					}
					else
					{
						a[i][j] = 0;
					}
				}
			}
			Pow(a, k - 9);
			long long ret = 0;
			for (int i = 0; i < 10; i++)
			{
				ret = ret%M;
				ret += res[0][i] * (9 - i);
			}
			cout << ret << endl;
		}
	}
	return 0;
}
*/


/*B.��Ŀ����

����K������������{ N1N2 ... NK }�����������������пɱ�ʾΪ{ NiNi+1 ...
 Nj }������ 1<= i <= j <= K���������������������������������Ԫ�غ�����һ����
 �����������{ -211 -4 13 -5 -2 }�����������������Ϊ{ 11 -4 13 }������
 Ϊ20��
 �ڽ�������ݽṹ�����У�Ҫ���д����õ����ͣ���������һ��Ҫ�󣬼�����Ҫ�����
 �����еĵ�һ�������һ��Ԫ�ء�

����

��������������ɲ���������ÿ����������ռ2�У���1�и���������K(< 10000 )����2�и���K���������м��ÿո�ָ�����KΪ0ʱ�������������������������

���

��ÿ��������������1����������͡�������������еĵ�һ�������һ��Ԫ
 �أ��м��ÿո�ָ������������������в�Ψһ����������i��j��С���Ǹ��������������ĵ�2��3�飩��������K��Ԫ�ض��Ǹ���������������Ϊ0������������е���βԪ�ء�
*/
/*
#include <cstdio>
#include <iostream>
using namespace std;

int a[10010];

struct node {
	int sum, left, right;
};

node recursionMax(int left, int right)
{
	if (left == right) return{ a[left], left, right };

	int mid = (left + right) / 2;

	node maxLeft = recursionMax(left, mid);
	node maxRight = recursionMax(mid + 1, right);
	int left_sum = -0x7fffffff, right_sum = -0x7fffffff, li = mid, ri = mid + 1;
	int tmp = 0;
	for (int i = mid; i >= left; i--)
	{
		tmp += a[i];
		if (left_sum <= tmp) {
			left_sum = tmp;
			li = i;
		}
	}

	tmp = 0;
	for (int j = mid + 1; j <= right; j++)
	{
		tmp += a[j];
		if (right_sum < tmp) {
			right_sum = tmp;
			ri = j;
		}
	}
	node ret = maxLeft.sum >= maxRight.sum ? maxLeft : maxRight;
	if (ret.sum > left_sum + right_sum) {
		return ret;
	}
	else if (ret.sum == left_sum + right_sum && ret.left < li) {
		return ret;

	}
	else {
		return{ left_sum + right_sum, li, ri };
	}
}

int main()
{
	int  n;
	while (cin >> n,n!=0) {
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		node ret = recursionMax(0, n - 1);
		if (ret.sum < 0)
		{
			printf("%d %d %d\n", 0, a[0], a[n-1]);
		}
		else
		{
			printf("%d %d %d\n", ret.sum, a[ret.left], a[ret.right]);
		}
	}
	return 0;
}
*/

/*A.쳲��������еĶ������£�



F(0) = 0

F(1) = 1

F(n) = F(n - 1) + F(n - 2) (n >= 2)



(1 1 2 3 5 8 13 21 34 55 89 144 233 377 ...)

����n����F(n)�����ڽ���ܴ����F(n) % 1000000009�Ľ�����ɡ�
*/
/*
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
#define N 2
#define M 1000000009
long long tmp[N][N];
void multi(long long a[][N], long long b[][N], long long n)
{
	memset(tmp, 0, sizeof tmp);
	for (long long  i = 0; i<n; i++)
	for (long long j = 0; j<n; j++)
	for (long long k = 0; k<n; k++)
		tmp[i][j] += ((a[i][k]%M) * (b[k][j]%M))%M;
	for (long long i = 0; i<n; i++)
	for (long long j = 0; j<n; j++)
		a[i][j] = tmp[i][j]%M;
}
long long res[N][N];
void Pow(long long a[][N], long long n)
{
	memset(res, 0, sizeof res);//n���ݣ�N�Ǿ����С
	for (long long i = 0; i<N; i++) res[i][i] = 1;
	while (n)
	{
		if (n & 1)
			multi(res, a, N);//res=res*a;����ֱ����multi����ʵ���ˣ�
		multi(a, a, N);//a=a*a
		n >>= 1;
	}
}
int main()
{
	long long n;
	while (cin >> n)
	{
		long long a[2][2] = { 1, 1, 1, 0 };
		Pow(a, n-1);
		long long ret = res[0][0] % M;
		cout << ret << endl;
	}
	return 0;
}*/
