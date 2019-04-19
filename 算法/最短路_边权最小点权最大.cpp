#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxv = 1010;
const int inf = 100000000000;

int mp[maxv][maxv],weight[maxv];//�ڽӾ���mp��¼����ͼ��weight��¼��Ȩ
int m,n,st,ed,num[maxv],w[maxv],d[maxv];//n�ǵص������m�Ǳ�����st����㣬ed���յ㣬num�����·��������w������Ȩ�ͣ�d����̾���
bool vis[maxv]={false};//���ĳ���Ƿ񱻷���

void dijkstra(int s)
{
	fill(d,d+maxv,inf);
	memset(num,0,sizeof(num));
	memset(w,0,sizeof(w));
	d[s]=0;
	w[s]=weight[s];
	num[s]=1;

	for(int i = 0;i<n;i++)
	{
		int u = -1,min=inf;//u��d[u]��С��min����С��d[u]
		for(int j =0;j<n;j++)//��û�з��ʵĵ���d[]��С��
		{
			if(vis[j]==false&&d[j]<min)
			{
				u=j;
				min=d[j];
			}
		}
		if(u==-1) return;//�Ҳ���С��inf��d[u]��ʣ�µĵ����㲻��ͨ
		vis[u]=true;//u������
		for(int v=0;v<n;v++)
		{
			if(vis[v]==false&&mp[u][v]!=inf)//��vδ�����ʹ���uΪ�н������ɳ�d[v]
			{
				if(d[u]+mp[u][v]<d[v])
				{
					d[v]=mp[u][v]+d[u];
					w[v]=w[u]+weight[v];
					num[v]=num[u];
				}
				else if(d[u]+mp[u][v]==d[v])//�ҵ���һ����ͬ���ȵ�·��
				{
					if(w[u]+weight[v]>w[v])//��uΪ�н����ʹ��Ȩ�ͱ��
						w[v]=w[u]+weight[v];
					num[v]+=num[u];//�������·������
				}
			}
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i =0;i<n;i++)
	{
		scanf("%d",&weight[i]);
	}
	ed=n-1;//��Ϊ�Ǵ�0��ʼ���������յ�Ҫn-1
	int u,v;
	fill(mp[0],mp[0]+maxv*maxv,inf);//��ʼ���ڽӾ���
	scanf("%d",&m);
	for(int i =0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		scanf("%d",&mp[u-1][v-1]);//��Ϊ��Ŵ�0��ʼ������Ҫ����Ŀ����-1
		mp[v-1][u-1]=mp[u-1][v-1];
	}
	dijkstra(0);//��0��ʼ��dijkstra���
	if(w[ed]!=0)//����Ȩ�Ͳ���0����ζ�ſ����ߵ��յ�
		printf("%d %d\n",d[ed],w[ed]);
	else
		printf("impossible");

	return 0;
}
