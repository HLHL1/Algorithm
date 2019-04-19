题目大意：
      小 Bo 有 n 个正整数 a1..an，以及一个权值序列 w1…wn，现在他定义
      现在他想知道  的值，需要你来帮帮他。你只需要输出答案对 109+7 取模后的值

题解：

题目要求的是

 







...



即







可以发现每一行的对应列的w因数相同，对应相加可得







但是这样求的话也是需要两重循环来求......于是再来一次前缀和（S[n]为sum的前缀）

即  
#include <cstdio>
#include <cstring>
#include <cmath>
#include<algorithm>
#include<iostream>
#define mod 1000000007
using namespace std;
typedef long long ll;
ll sum[300010];
ll S[300010];
int a[300010],w[300010];
int main()
{
    //freopen("input.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;++i)
        scanf("%d",&w[i]);
    for(int i=1;i<=n;++i)
        S[i]=S[i-1]+sum[i],S[i]%=mod;
    ll ans=0;
    for(int i=1;i<=n;++i)
    {
        ans+=((S[n]-S[n-i]-S[i-1]+mod)%mod*w[i]%mod)%mod;
        ans%=mod;
    }
    printf("%lld\n",ans);
    return 0;
}

