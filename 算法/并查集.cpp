/*��ͨ����
http://acm.hdu.edu.cn/showproblem.php?pid=1232
Time Limit: 4000/2000 MS (Java/Others) Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 61184 Accepted Submission(s): 32757
Problem Description
ĳʡ�������ͨ״�����õ����г����·ͳ�Ʊ������г���ÿ����·ֱ����ͨ�ĳ���
ʡ��������ͨ���̡���Ŀ����ʹȫʡ�κ���������䶼����ʵ�ֽ�ͨ������һ����ֱ�ӵĵ�·������ֻҪ������ͨ����·�ɴＴ�ɣ��������ٻ���Ҫ�����������·��
Input
��������������ɲ���������ÿ�����������ĵ�1�и����������������ֱ��ǳ�����ĿN ( < 1000 )�͵�·��ĿM������M�ж�ӦM����·��ÿ�и���һ�����������ֱ��Ǹ�����·ֱ����ͨ����������ı�š�Ϊ������������1��N��š�
ע��:��������֮������ж�����·��ͨ,Ҳ����˵
3 3
1 2
1 2
2 1
��������Ҳ�ǺϷ���
��NΪ0ʱ�������������������������
Output
��ÿ��������������1����������ٻ���Ҫ����ĵ�·��Ŀ��
Sample Input
4 2
1 3
4 3
3 3
1 2
1 3
2 3
5 2
1 2
3 5
999 0
0
Sample Output
1
0
2
998*/
/*#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int pre[1000];
int total;

int find(int x){
	int r=x;
	while(pre[r]!=r)	//���r���ϼ������Լ�
		r=pre[r];		//��ôr��������ǰ���㣬����Ѱ�ң�ֱ���ҵ����ڵ�

	//���������·��ѹ��������
	int i=x; int j;
	while(i!=r)			//�����ǰ���ҵĳ����Ǹ���㣨preָ���Լ���
	{
		j=pre[i];		//jΪ�ó����ǰ����
		pre[i]=r;		//���¸ó����ǰ����ֱ��ָ����ڵ�
		i=j;			//��iָ����ǰ���㣬����һ��ѭ������ͻ������ǰ����ָ����ڵ�
	}
	return r;
}

void join(int p1,int p2){
	int f1,f2;
	f1 = find(p1);
	f2 = find(p2); //�ֱ������������ĸ��ڵ�
	//����ǲ���ͨ�ģ���ô����������֧������
	//��֧�������ͼ�����1�����轨��·Ҳ�ͼ���1
	if(f1!=f2)
	{
		pre[f2 ]=f1;
		total--;
	}
}

int main(){
	int  n,m,p1,p2;
	while((~scanf("%d",&n)) && n){
		total = n-1; //��������£��ܹ�Ҫ��n-1��·

		for(int i=1;i<=n;i++) { //��ʼ��pre���飬�����ǵ�ǰ���㶼��¼Ϊ�Լ������Լ�Ϊ���ڵ�
			pre[i]=i;
		}

		cin>>m;
		while(m--){
			cin>>p1>>p2; //������������������
			join(p1,p2);
		}
		printf("%d\n",total); //��������Ҫ�޵�·����
	}
	system("pause");
	return 0;
}*/


/*
��Ŀ����
��ʵ���ҳ��������Ȼ�������Ȼ���Լ��ĵ���������ʵ���������ʵ���ҵ���ʦ�Ѿ��Ѵ��������ˡ�������ǣ���û���Ǹ���ʦ�ĵ绰���롣�㿪ʼ����֪���������˴�绰��ѯ��������û����ʦ�ĵ绰�����û�У�����Ҳ�����Լ���ͬѧ��ѯ�ʵ绰���롣��ô��������ϵ����ʦ�����õ�������
��������:
���ڶ����������
ÿ�������ĵ�һ�зֱ�����������n(1<n<=50)��m(1<m<=2000)��n������Ŀ���г��ֵ�������������������1�ţ�ʵ������ʦ�������n��
��������m�У�ÿ������������x(1<=x<=n)��y(1<=y<=n)������x��y�ĵ绰���롣
�������:
����ÿ������������������������ϵ����ʦ�������Yes�������������No����
ʾ��1
����
5 5
1 3
2 3
3 4
2 4
4 5
���
Yes
ʾ��2
����
4 3
1 2
2 3
4 1
���
No
*/
/*
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int pre[2010];

int find(int x){
	int r=x;
	while(pre[r]!=r)
		r = pre[r];

	int i=x, j;
	while(i!=r){
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;
}

void join(int p1, int p2){
	int f1, f2;
	f1 = find(p1);
	f2 = find(p2);
	if(f2!=1){
		pre[f2] = f1;
	}
}

int main(){
	int n,m,p1,p2;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1; i<=n; i++){
			pre[i]=i;
		}

		while(m--){
			cin>>p1>>p2;
			join(p1, p2);
		}
		if(find(n)==1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
*/



/*
#include<iostream>
#include<cstdio>
using namespace std;
int C(int a,int b)
{
    int x=1,y=1;
    for(int i=0;i<b;i++)
    {
        x*=a;
        a--;
    }
    for(int i=0;i<b;i++)
    {
        y*=b;
        b--;
    }
    return x/y;

}
int main()
{
    int n,m,a,b;
    while(scanf("%d%d%d%d",&n,&m,&a,&b)!=EOF)
    {
        int ret=0;
        int x[3000]={0};
        int y[3000]={0};
        int sum[3000]={0};
        int flag=0;
        for(int i=a;i<n;i++)
        {
           x[flag]= C(n,i);
           int z=(n-a)*(m-b);
           int l=(min(n-a,m-b)-1)*max(n-a,m-b);
           for(int j=1;j<=l;j++)
           {
               sum[flag]+=C(z,j);
           }
           if(n-a==m-b)
           {
               sum[flag]=sum[flag]-((l+1-(n-i))*(n-i)*(n-i));
           }
           cout<<"x->"<<x[flag]<<endl;
           cout<<"sum->"<<sum[flag]<<endl;
           flag++;
        }
        flag=0;
        for(int j=b;j<m;j++)
        {
            y[flag++]=C(m,j);
            cout<<"y->"<<y[flag]<<endl;
        }
        for(int i=0;i<flag;i++)
        {
            ret+=x[i]*sum[i]*y[i];
        }
        cout<<ret<<endl;
    }
    return 0;
}
*/
