/*
01����
��v����ʾ�����е����ϵ������ܺ�sum��һ��,��v=sum/2������һ��������������
������������������������Ϊv�ı����ﾡ���ܶ��װ��Ʒ(����)��
�õ�һ��������װ��v������dp[v];
������������֮�����СֵΪ(sum-dp[v])-dp[v];
dp[j]ָ������Ϊjʱ������װ��ȥ�����������
��j>zl[i]ʱ�򣬿�����װ������ϺͲ�װ������ѡ��ѡ����ŵĽ��
״̬ת�Ʒ���dp[j]=max(dp[j],dp[j-zl[i]]+zl[i]);
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
		// ����
		memset(dp,0,sizeof(dp));

		dp[0][weight[0]] = 1;
		for(i=1;i<N;i++)
		{
			for(j=0;j<=sumWeight;j++)
			{
				// ��ϳ����� i �����ϵ����з��䷽��
				if(dp[i-1][j] == 1)
				{
					dp[i][j] = 1;
					dp[i][j + weight[i]] = 1;
				}
			}
		}
		result = sumWeight;
		// �ҳ�����С�ķ���
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
//ֻ����Ҫ�Ͳ�Ҫ
void dfs(int i,int temp )
{
    if(i==n)
    {
        return ;
    }
    int t=abs(sum-temp-temp);//�������ϵ�������
    if(t<mi)
    {
        mi=t;
    }
    //�ӵ����
    dfs(i+1,temp+a[i]);
    //���ӵ����
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
