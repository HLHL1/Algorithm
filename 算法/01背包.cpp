#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
/*1 <= n <=100
　　1 <= wi <= 10^7
　　1 <= vi <= 100
　　1 <= W <= 10^9
输入
多组测试数据。
每组测试数据第一行输入，n 和 W ，接下来有n行，每行输入两个数，代表第i个物品的wi 和 vi。
输出
满足题意的最大价值，每组测试数据占一行。
样例输入
4 5
2 3
1 2
3 4
2 2
样例输出
7*/
#define MAXN 0x3f3f3f3f
//深度优先搜索
int n,W,mi;
struct P{
 int w;
 int v;
};
P p[100];
//分两种情况，放或者不放
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
    //放
    dfs(i+1,we+p[i].w,ve+p[i].v);
    //不放
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
////	//数组初始化为无穷大
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
//    //已经计算过的话就直接使用之前的结果
//    if(dp[i][j]>=0){
//        return dp[i][j];
//    }
//    int res;
//    //情况1：已经拿了n次，不能再拿了
//    if(i==n){
//        res=0;
//    }
//    else{
//            //情况2：物品的重量太大，无法拿取
//        if(j<w[i]){
//            res=rec(i+1,j);
//        }
//    else{
//            //挑和不挑的两种情况都尝试一下
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
