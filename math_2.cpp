#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 1100;
int vis[maxn];
void is_prime()
{
	memset(vis,0,sizeof(vis));
	vis[1] = 1;
	for(int i = 2;i < maxn;i++)
	{
		if(vis[i]) continue;
		for(int j = i;j <= maxn/i;++j)
		{
			vis[i*j]=1;
		}
	}
}
int main()
{
	int n,ans;
	is_prime();
	while(cin>>n)
	{
		ans=0;
		for(int i = 2;i <= n/2;++i)
		{
			if(!vis[i] && !vis[n-i])
			{
				ans++;
			}
		}
		cout<<ans<<endl;	
	}
	return 0;
}
