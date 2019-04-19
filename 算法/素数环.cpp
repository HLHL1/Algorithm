#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#define N 50
using namespace std;
int visit[N];//标记整数是否被访问
int ring[N];//用来存放满足素数环的整数
int n;//素数环的大小
int p[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
int isprime(int x)
{
	for (int i = 0; i<8; i++)
	{
		if (p[i] == x)
		{
			return 1;
		}
	}
	return 0;
}
void dfs(int l)
{
    if(l==n&&isprime(ring[l]+ring[1]))//最后一次，跳出递归，输出素数环
        {
            for(int i=1;i<n;i++)
                printf("%d ",ring[i]);
                printf("%d\n",ring[n]);
                return;
        }
    for(int j=2; j<=n; j++)//因为题目要求打印的素数环要按照字典序排列，所以从小到大遍历整数
        if(!visit[j]&&isprime(ring[l]+j))//未被访问过，并且满足与上一次记录的整数之和为素数
        {
            visit[j]=1;//标记该整数已被访问
            ring[l+1]=j;//更改记录整数，用作下一次素数环的判断
            dfs(l+1);//递归实现，参数表示已经找到的满足素数环的整数的个数
            visit[j]=0;//回溯，因为下一次可能要用到该整数。
        }
}
int main()
{
    int cased=1;
    while(scanf("%d",&n)!=EOF)
    {
        memset(ring,0,sizeof(ring));//置0
        memset(visit,0,sizeof(visit));//初始化为0
        ring[1]=1;//第一个整数为1
        printf("Case %d:\n",cased++);
        if(n%2==0&&n>1)//剪枝，如果为奇数肯定没有素数环，只有偶数才可能有素数环
        {
            dfs(1);

        }
        else
        {
           printf("No Answer\n");

        }
    }
    return 0;
}
