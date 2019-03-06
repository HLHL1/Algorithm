/*
  ?????
  
*/


#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=100004;
int father[maxn];
void make_set(int y)
{
	for(int i=1;i<=y;i++)
	{
		father[i]=i;
	}
}
int find_father(int x)
{
	if(x!=father[x])
	{
		father[x]=find_father(father[x]);
	}
	return father[x];	
}
void join(int x,int y)
{
	int p,q;
	p=find_father(x);
	q=find_father(y);
	if(q!=p)
	{
		father[q]=p;
	}
}
int main()
{
	int n,m;
	int a,b;
	while(cin>>n)
	{
		if(n==0) break;
		cin>>m;
		make_set(n);
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			join(a,b);
		}
		int ans=-1;
		for(int i=1;i<=n;++i)
		{
			if(i==father[i]) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
