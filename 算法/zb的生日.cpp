/*
01背包
用v来表示将所有的西瓜的质量总和sum的一半,即v=sum/2来当做一个背包的容量，
接下来的任务就是向这个容量为v的背包里尽可能多的装物品(西瓜)。
得到一个尽可能装满v的重量dp[v];
所求结果的质量之差的最小值为(sum-dp[v])-dp[v];
dp[j]指当容量为j时背包能装进去的最大重量。
当j>zl[i]时候，可以有装入该西瓜和不装入两种选择，选择较优的结果
状态转移方程dp[j]=max(dp[j],dp[j-zl[i]]+zl[i]);
*/
/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int dp[20][200000];

int main()
{
	int weight[21];
	int sumWeight;
	int result ;

	int N;
	int i,j;
	while(scanf("%d",&N)!=EOF)
	{
		sumWeight = 0;
		for(i=0;i<N;i++)
		{
			scanf("%d",&weight[i]);
			sumWeight += weight[i];
		}
		// 清零
		memset(dp,0,sizeof(dp));

		dp[0][weight[0]] = 1;
		for(i=1;i<N;i++)
		{
			for(j=0;j<=sumWeight;j++)
			{
				// 组合出到第 i 个西瓜的所有分配方案
				if(dp[i-1][j] == 1)
				{
					dp[i][j] = 1;
					dp[i][j + weight[i]] = 1;
				}
			}
		}
		result = sumWeight;
		// 找出差最小的方案
		for(j=0;j<=sumWeight;j++)
		{
			if(dp[N-1][j] == 1 && (result > abs(sumWeight - 2*j) ) )
			{
				result = abs(sumWeight - 2*j);
			}
		}
		printf("%d\n",result);
	}
	return 0;
}*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,mi;
int a[20],sum;
//只考虑要和不要
void dfs(int i,int temp )
{
    if(i==n)
    {
        return ;
    }
    int t=abs(sum-temp-temp);//两堆西瓜的质量差
    if(t<mi)
    {
        mi=t;
    }
    //加的情况
    dfs(i+1,temp+a[i]);
    //不加的情况
    dfs(i+1,temp);
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        mi=1000000;
        dfs(0,0);
       printf("%d\n",mi);
    }
    return 0;
}
