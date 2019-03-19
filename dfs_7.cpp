#include<cmath>
#include<cstdio>
#include<cstring> 
#include<algorithm>
using namespace std;
const int maxn=12; 
int map[maxn][maxn];
int ans,n;
int ans_arr[maxn];
void dfs(int ithqueue);
int main()
{
	for(n=1;n<maxn;++n)     		//n????? 
	{				
		ans=0; 
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)map[i][j]=0;			
		}
		dfs(1);						//??????? 
		ans_arr[n]=ans;
	}
	int q;
	while(~scanf("%d",&q),q){
		printf("%d\n",ans_arr[q]);
	}
	return 0;	
}
void dfs(int ithqueue){         	   //ithqueue????????? 
	if(ithqueue==n+1){				   //??????n+1?,?????? 
		ans++;
		return ;
	}
	for(int col=1;col<=n;++col)                 //?????????????,col?1?n????,????????????? 
	{				
		if(map[ithqueue][col]==0)			    //??0,????? 
		{
			for(int i=1;i<=n;++i)				//???????????0????? 
			{			
				for(int j=1;j<=n;++j)
				{
					if(( i==ithqueue || col==j ||  abs(i-ithqueue)==abs(col-j) ) && map[i][j]==0)
					{
						map[i][j]=ithqueue;
					} 
				}
			} 
			dfs(ithqueue+1);					//?????? 
			
			for(int i=1;i<=n;++i)				//?? 
			{
				for(int j=1;j<=n;++j)
				{
					if(map[i][j]==ithqueue) map[i][j]=0;
				}
			}	
		}	
	}
}
--------------------- 
??:HL_HLHL 
??:CSDN 
??:https://blog.csdn.net/HL_HLHL/article/details/88185017 
????:?????????,?????????!