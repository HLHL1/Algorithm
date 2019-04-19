/*
Examples
inputCopy
4 5 3
3 5 1 2
outputCopy
3
3 1 1 2
inputCopy
10 10 1
10 5 7 4 6 3 2 1 9 8
outputCopy
2
2 1 1 2 2 1 2 1 1 2
*/


#include<bits/stdc++.h>
#define N 200005
using namespace std;
inline int read(){
    int ans=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
    return ans;
}
int n,m,d,q[N],ans[N],tot=0,hd,tl;
struct Node{int v,id;}a[N];
inline bool cmp(Node a,Node b){return a.v<b.v;}
int main(){
    n=read(),m=read(),d=read();
    for(int i=1;i<=n;++i)a[i].v=read(),a[i].id=i;
    sort(a+1,a+n+1,cmp);
    hd=1,tl=0;
    q[++tl]=1,ans[a[1].id]=++tot;
    for(int i=2;i<=n;++i){
        if(a[i].v-d-1>=a[q[hd]].v)ans[a[i].id]=ans[a[q[hd]].id],++hd;
        else ans[a[i].id]=++tot;
        q[++tl]=i;
    }
    cout<<tot<<'\n';
    for(int i=1;i<=n;++i)cout<<ans[i]<<' ';
    return 0;
}
