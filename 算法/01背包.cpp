#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
/*1 <= n <=100
����1 <= wi <= 10^7
����1 <= vi <= 100
����1 <= W <= 10^9
����
����������ݡ�
ÿ��������ݵ�һ�����룬n �� W ����������n�У�ÿ�������������������i����Ʒ��wi �� vi��
���
�������������ֵ��ÿ���������ռһ�С�
��������
4 5
2 3
1 2
3 4
2 2
�������
7*/
#define MAXN 0x3f3f3f3f
//�����������
int n,W,mi;
struct P{
 int w;
 int v;
};
P p[100];
//������������Ż��߲���
void dfs(int i,int we,int ve)
{
    if(i>=n||we>W)
    {
        return ;
    }
    //int vee=ve;
    if(ve>mi)
    {
        mi=ve;
    }
    //��
    dfs(i+1,we+p[i].w,ve+p[i].v);
    //����
    dfs(i+1,we,ve);

}
int main()
{
    while(scanf("%d%d",&n,&W)!=EOF)
    {

        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&p[i].w,&p[i].v);
        }
        mi=0;
        dfs(0,0,0);
        printf("%d\n",mi);
    }
    return 0;
}
////using namespace std;
////int dp[10005];
////int value[105];
////int weight[105];
////int main(){
////	int n,w,i,j,sum;
////    while(scanf("%d%d",&n,&w)==2){
////    	sum=0;
////    	for(i=1;i<=n;i++){
////		cin>>weight[i]>>value[i];
////		sum+=value[i];
////	}
////	for(i=1;i<=sum;i++)
////	//�����ʼ��Ϊ�����
////        dp[i]=MAXN;
////	dp[0]=0;
////	for(i=1;i<=n;i++){
////		for(j=sum;j>=value[i];j--){
////			dp[j]=min(dp[j],dp[j-value[i]]+weight[i]);
////		}
////	}
////	for(i=sum;i>=0;i--){
////		if(dp[i]<=w){
////			cout<<i<<endl;
////			break;
////		}
////	}
////    }
////	return 0;

//#include<bits/stdc++.h>
//using namespace std;
//#define MAX 110
//int n;
//int w[MAX]={0};
//int v[MAX]={0};
//int dp[MAX][MAX];
//int rec(int i,int j)
//{
//    //�Ѿ�������Ļ���ֱ��ʹ��֮ǰ�Ľ��
//    if(dp[i][j]>=0){
//        return dp[i][j];
//    }
//    int res;
//    //���1���Ѿ�����n�Σ�����������
//    if(i==n){
//        res=0;
//    }
//    else{
//            //���2����Ʒ������̫���޷���ȡ
//        if(j<w[i]){
//            res=rec(i+1,j);
//        }
//    else{
//            //���Ͳ������������������һ��
//        res=max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);
//    }
//    }
//    return dp[i][j]=res;
//
//}
//int main()
//{
//    int W;
//    while(scanf("%d%d",&n,&W)!=EOF)
//    {
//        for(int i=0;i<n;i++)
//        {
//            scanf("%d%d",&w[i],&v[i]);
//        }
//        memset(dp,-1,sizeof(dp));
//       cout<<rec(0,W)<<endl;
//    }
//    return 0;
//}
