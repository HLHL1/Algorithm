
/*#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int a[20], k, n;
int flag[20], j = 0;
bool dfs(int i, int sum,int t)
{
    //���ǰn���Ѿ�������ˣ��ͷ���sum�Ƿ���k���
	if (i == n)
	{
		j = t;
		return sum==k;
	}
	//����a[i]�����
	if (dfs(i + 1, sum,t))
	{

		return true;
	}
	//����a[i]�����
	if (dfs(i + 1, sum + a[i],t+1))
	{
		flag[t] = a[i];
		return true;
	}
	return false;
}
int main()
{
	while (scanf("%d%d", &n, &k) != EOF)
	{
		memset(a, 0, sizeof(a));
		memset(flag, 0, sizeof(flag));
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		if (dfs(0, 0, 0) == false)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
			for (int i = 0; i + 1 < j; i++)
			{
				printf("%d ", flag[i]);
			}
			printf("%d\n", flag[j - 1]);
		}
	}
	return 0;
}
*/
