/* 题意：有n个城市,每个城市都有自己的价值，每到一个城市可以买或者卖，要求得到的利润最大，交易次数最小
Sample Input
3
4
1 2 10 9
5
9 5 9 10 5
2
2 1


Sample Output
16 4
5 2
0 0

题解：
堆中物品分为两种（一种是一般的物品type=0，另一种是后悔的等价物type=1）
设当前城市价格为 p
当卖出的是价值为 q 的一般物品时，向堆中加入一个价值为 p 的后悔等价物。
当卖出的是价值为 q 的后悔等价物时，向堆中加入一个价值为 p 的后悔等价物和一个价值为 q 的普通物品。
为加深理解，把它称为替罪羊思维。
*/

#include<cstdio>
#include<iostream>
#include<set>

using namespace std;
int n;
struct node
{
    int w;
    bool type;
    friend bool operator<(node x,node y)
    {
        if(x.w==y.w)
        {
            return x.type>y.type;
        }
        else
        {
            return x.w<y.w;
        }
    }
};
multiset<node>q;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long ans=0,cnt=0;
        q.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if(q.size()==0)
            {
                q.insert(node{x,0});
            }
            else
            {
                node ne=*q.begin();
                if(ne.w<x)
                {
                    q.erase(q.begin());
                    ans+=x-ne.w;
                    if(ne.type==0)
                    {
                        cnt+=2;
                        q.insert(node{x,1});
                    }
                    else
                    {
                        q.insert(node{ ne.w, 0 });
						q.insert(node{ x, 1 });

                    }

                }
                else
                {
                    q.insert(node{x,0});
                }
            }

        }
        cout << ans << ' ' << cnt << endl;
    }
    return 0;
}
