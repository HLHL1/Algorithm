#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
/*
Given an integer nn, we only want to know the sum of 1/k^21/k 2where kk from 11 to nn.
*/

#include<string.h>
#include<queue>
using namespace std;
//注意这一句话：The input file is at most 1M.
//数据有可能会很大
const int maxn=2e6+10;
char s[maxn];
long long int a;
double sum;
double b[maxn];
void solve()
{
	    b[0]=0.0;
        for(long long int i=1;i<=maxn;i++)
        {
        	b[i]=b[i-1]+1.0/(i*i*1.0);
		}
}
int main()
{
	solve();
	while(scanf("%s",s)!=EOF)
	{
		sum=0.0;
		a=0;
		int len=strlen(s);
		if(len>6)
		{
			puts("1.64493");
			continue;
		}
		for(int i=0;i<len;i++)
		{
		 a=a*10+(s[i]-'0');
		}

		printf("%.5lf\n",b[a]);
		memset(s,0,sizeof(s));
	}
	return 0;
}


