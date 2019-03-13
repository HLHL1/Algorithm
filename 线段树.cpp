#include<iostream>
#include<algorithm>
using namespace std;
        const int SIZE = 1e5+5;
//建树 
        struct SegmentTree
        {
        int l,r;			//区间的左右边界
        int dat;			//区间和
        }t[SIZE*4];
        int a[SIZE];
        void build(int p,int l,int r)
        {
        t[p].l=l;
        t[p].r=r;
        if(l==r)
        {
        t[p].dat=a[l];
        return ;
        }
        int mid=(l+r)/2;
        build(p*2,l,mid);
        build(p*2+1,mid+1,r);
        t[p].dat=max(t[p*2].dat,t[p*2+1].dat);
        }
      /*  1
        2
        3
        4
        5
        6
        7
        8
        9
        10
        11
        12
        13
        14
        15
        16
        17
        18
        19
        20
        21
        22
        23
        24
        25
        线段树的单点修改

//线段树的单点修改
//将a[x]改为v。 
*/

        void change(int p,int x,int v)
        {
        if(t[p].l==t[p].r)
        {
        t[p].dat=v;
        return ;
        }
        int mid=(t[p].l+t[p].r)/2;
        if(x<=mid)
        {
        change(p*2,x,v);
        }else change(p*2+1,x,v);
        t[p].dat=max(t[p*2].dat,t[p*2+1].dat);
        }
  /*      1
        2
        3
        4
        5
        6
        7
        8
        9
        10
        11
        12
        13
        14
        15
        16
      //  线段树的区间查询

//区间查询 
*/
        int ask(int p,int l,int r)
        {
        if(l<=t[p].l && r>=t[p].r)
        {
        return t[p].dat;
        }
        int mid=(t[p].l+t[p].r)/2;
        int val=-(1<<30);
        if(l<=mid)
        {
        val=max(val,ask(p*2,l,r));
        }
        if(r>mid)
        {
        val=max(val,ask(p*2+1,l,r));
        }
        return val;
        }
       