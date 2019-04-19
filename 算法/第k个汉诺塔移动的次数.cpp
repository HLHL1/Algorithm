#include<stdio.h>
#include<iostream>
using namespace std;
long long haio(int n, int k)
{
	if (n == k)
	{
		return 1;
	}
	if (n == 1)
	{
		return 0;
	}
	else
    {
        return 2 * haio(n - 1, k);
    }
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int n, k;
		scanf("%d%d",&n,&k);
		long long ret = haio(n, k);
		cout << ret << endl;//这个编译器好像不能输出long long型
		//printf("%lld\n",ret);
	}

}
