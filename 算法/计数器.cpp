/*
链接：https://www.nowcoder.com/acm/contest/160/A
来源：牛客网

有一个计数器，计数器的初始值为0，每次操作你可以把计数器的值加上a1,a2,...,an中的任意一个整数，操作次数不限（可以为0次），问计数器的值对m取模后有几种可能。
输入描述:
第一行两个整数n,m
接下来一行n个整数表示a1,a2,...,an
1≤n≤100
1≤m,a1,a2,...,an≤1000000000
输出描述:
输出一个整数表示答案
*/
/*
题解：假设K1为A1取的个数；根据题意题目变成a1*k1+a2*k2+a3*k3+a4*k4+....an*kn=P;
让我们求P的可能性，

用到了https://blog.csdn.net/huayunhualuo/article/details/52215182
在数论中，裴蜀等式或裴蜀定理是一个关于最大公约数（或最大公约式）的定理。裴蜀定理得名于法国数学家艾蒂安·裴蜀，说明了对任何整数a、b和它们的最大公约数d，关于未知数x和y的线性丢番图方程（称为裴蜀等式）：


ax+by=m
有整数解时当且仅当m是d的倍数。裴蜀等式有解时必然有无穷多个整数解，每组解x、y都称为裴蜀数，可用扩展欧几里得算法求得。
例如，12和42的最大公约数是6，则方程12x+42y=6有解。事实上有(-3)×12 + 1×42 = 6及4×12 + (-1)×42 = 6。特别来说，方程 ax+by=1 有整数解当且仅当整数a和b互素。

所以这题求N个数关于M的余数；就把N个数的gcd求出来然后求小于M的GCD的倍数的个数就是答案；
*/
#include<iostream>
#include<cstdio>
#include<cstring>


#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define inf 0x3f3f3f3f

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    int t,n,m,i,j,k;
    while(scanf("%d%d",&n,&m)!=EOF){
        LL ans=m,a;
        for(i=1;i<=n;++i){
            scanf("%lld",&a);
            ans=gcd(ans,a);
        }
        cout<<m/ans<<endl;
    }
    return 0;
}
