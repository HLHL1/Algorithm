#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#define N 50
using namespace std;
int visit[N];//��������Ƿ񱻷���
int ring[N];//�����������������������
int n;//�������Ĵ�С
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
    if(l==n&&isprime(ring[l]+ring[1]))//���һ�Σ������ݹ飬���������
        {
            for(int i=1;i<n;i++)
                printf("%d ",ring[i]);
                printf("%d\n",ring[n]);
                return;
        }
    for(int j=2; j<=n; j++)//��Ϊ��ĿҪ���ӡ��������Ҫ�����ֵ������У����Դ�С�����������
        if(!visit[j]&&isprime(ring[l]+j))//δ�����ʹ���������������һ�μ�¼������֮��Ϊ����
        {
            visit[j]=1;//��Ǹ������ѱ�����
            ring[l+1]=j;//���ļ�¼������������һ�����������ж�
            dfs(l+1);//�ݹ�ʵ�֣�������ʾ�Ѿ��ҵ��������������������ĸ���
            visit[j]=0;//���ݣ���Ϊ��һ�ο���Ҫ�õ���������
        }
}
int main()
{
    int cased=1;
    while(scanf("%d",&n)!=EOF)
    {
        memset(ring,0,sizeof(ring));//��0
        memset(visit,0,sizeof(visit));//��ʼ��Ϊ0
        ring[1]=1;//��һ������Ϊ1
        printf("Case %d:\n",cased++);
        if(n%2==0&&n>1)//��֦�����Ϊ�����϶�û����������ֻ��ż���ſ�����������
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
