



/*C.函数 f(x).
 若 x < 10 f(x) = x.
 若x >= 10 f(x) = a0 * f(x-1) + a1 * f(x-2) + a2 * f(x-3) + …… + a9 * f(x-10);
  ai(0<=i<=9) 只能为 0 或 1 .

已知 a0 ~ a9 和两个正整数 k 与 m 计算 f(k)%m.

输入

问题包含多个测试用例。
 在每种情况下，都有两行。
 在第一行中有两个正整数k和m。(k < 2 * 10 ^ 9 m < 10 ^ 5)
 在第二行中，有10个整数代表a0 ~ a9
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
	memset(res, 0, sizeof res);//n是幂，N是矩阵大小
	for (long long i = 0; i<N; i++) res[i][i] = 1;
	while (n)
	{
		if (n & 1)
			multi(res, a, N);//res=res*a;复制直接在multi里面实现了；
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


/*B.题目描述

给定K个整数的序列{ N1N2 ... NK }，其任意连续子序列可表示为{ NiNi+1 ...
 Nj }，其中 1<= i <= j <= K。最大连续子序列是所有连续子序列中元素和最大的一个，
 例如给定序列{ -211 -4 13 -5 -2 }，其最大连续子序列为{ 11 -4 13 }，最大和
 为20。
 在今年的数据结构考卷中，要求编写程序得到最大和，现在增加一个要求，即还需要输出该
 子序列的第一个和最后一个元素。

输入

测试输入包含若干测试用例，每个测试用例占2行，第1行给出正整数K(< 10000 )，第2行给出K个整数，中间用空格分隔。当K为0时，输入结束，该用例不被处理。

输出

对每个测试用例，在1行里输出最大和、最大连续子序列的第一个和最后一个元
 素，中间用空格分隔。如果最大连续子序列不唯一，则输出序号i和j最小的那个（如输入样例的第2、3组）。若所有K个元素都是负数，则定义其最大和为0，输出整个序列的首尾元素。
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

/*A.斐波那契数列的定义如下：



F(0) = 0

F(1) = 1

F(n) = F(n - 1) + F(n - 2) (n >= 2)



(1 1 2 3 5 8 13 21 34 55 89 144 233 377 ...)

给出n，求F(n)，由于结果很大，输出F(n) % 1000000009的结果即可。
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
	memset(res, 0, sizeof res);//n是幂，N是矩阵大小
	for (long long i = 0; i<N; i++) res[i][i] = 1;
	while (n)
	{
		if (n & 1)
			multi(res, a, N);//res=res*a;复制直接在multi里面实现了；
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
