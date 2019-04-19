



#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define eps 1e-8
#define N 1100
struct Node
{
    double x,y;
}p[N],stack[N];
double mulit(Node a,Node b,Node c)
{
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
double dist(Node a,Node b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int cmp(Node a,Node b)
{
    if(mulit(p[0],a,b)>0)
        return 1;
    if(mulit(p[0],a,b)==0&&(dist(p[0],a)-dist(p[0],b))<eps)
        return 1;
    return 0;
}
int Graham(int n)
{
    sort(p+1,p+n,cmp);
    stack[0]=p[0];
    stack[1]=p[1];
    stack[2]=p[2];
    int l=3;
    while(l<n&&mulit(stack[0],stack[1],stack[2])==0)
    {
        stack[1]=stack[2];
        stack[2]=p[l++];
    }
    if(l==n)
        return -1;
    int top=2;
    for(int i=l;i<n;i++)
    {
        while(top>=1&&mulit(stack[top-1],p[i],stack[top])>=0)
            top--;
        stack[++top]=p[i];
    }
    return top;
}
int Pointonline(Node a,Node b,Node c)
{
    if(mulit(b,a,c)!=0)
        return 0;
    if(a.x<=max(b.x,c.x)&&a.y<=max(b.y,c.y)&&a.x>=min(b.x,c.x)&&a.y>=min(b.y,c.y))
        return 1;
    return 0;
}
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf %lf",&p[i].x,&p[i].y);
        if(n<6)
        {
            printf("NO\n");
            continue;
        }

        //找基点，按y从小到大，如果y相同，按x从左到右
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(p[k].y>p[i].y||(p[k].y==p[i].y&&p[k].x>p[i].x))
                k=i;
        }
        swap(p[0],p[k]);

        int top=Graham(n);
        if(top==-1)
        {
            printf("NO\n");
            continue;
        }
        stack[top+1]=stack[0];
        int flag;
        for(int i=0;i<=top;i++)
        {
            flag=0;
            for(int j=0;j<n;j++)
            {
                if(p[j].x==stack[i].x&&p[j].y==stack[i].y)
                    continue;
                if(p[j].x==stack[i+1].x&&p[j].y==stack[i+1].y)
                    continue;
                if(Pointonline(p[j],stack[i],stack[i+1]))
                    flag=1;
            }
            if(!flag)
                {
                    flag=-1;
                    break;
                }
        }
        if(flag==-1)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
