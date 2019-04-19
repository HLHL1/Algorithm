#include<stdio.h>


int tab[]={2, 3, 5, 7};
long long qpow(int a, int b, int r)  //(a^b)%r  快速幂取模
{
    long long ret = 1, tmp = a;
    while(b)
    {
        if (b&1)
            ret = ret*tmp%r;
        tmp = tmp*tmp%r;
        b >>= 1;
    }
    return ret;
}
bool  Miller_Rabbin(int n, int a)//米勒拉宾素数测试
{
    int r = 0, s = n-1, j;
    long long k;
    if(n%a == 0)    return false;
    while((s&1) == 0)
    {
        s >>= 1;
        r++;
    }
    k = qpow(a, s, n);
    if(k == 1)  return true;
    for (j = 0; j < r; j++, k=k*k%n)
        if (k == n-1)
            return true;
    return false;
}
bool Isprime(int n)//判断是否是素数
{
    for (int i = 0; i < 4; i++)
    {
        if (n == tab[i])
            return true;
        if (!Miller_Rabbin(n, tab[i]))
            return false;
    }
    return true;
}
int main()
{

    int m,n;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&n);
        if(Isprime(n))
        {
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
