#include<iostream>
#include<stdio.h>
using namespace std;
long long  a[2];
long long a0, a1, m0, m1, c, M, k;
long long f(long long a0, long long a1)
{
	long long a2 = (((m0*a1) % M) + ((m1*a0) % M) + c) % M;
	a[0] = a1%M;
	a[1] = a2%M;
	return a2%M;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld%ld%ld%ld%ld%ld", &a0, &a1, &m0, &m1, &c, &M);
		scanf("%ld",&k);
		a[0] = a0;
		a[1] = a1;
		long long sum = 0;
		if (k<2)
		{
			for (int i = 0; i<2; i++)
			{
				sum += a[i];
			}
		}
		else
		{
			sum = (a0%M)*(a1%M);
			for (int i = 1; i<k; i++)
			{
				sum = (sum*f(a[0], a[1])) % M;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
