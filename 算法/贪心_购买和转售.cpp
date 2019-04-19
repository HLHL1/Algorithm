/* ���⣺��n������,ÿ�����ж����Լ��ļ�ֵ��ÿ��һ�����п������������Ҫ��õ���������󣬽��״�����С
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

��⣺
������Ʒ��Ϊ���֣�һ����һ�����Ʒtype=0����һ���Ǻ�ڵĵȼ���type=1��
�赱ǰ���м۸�Ϊ p
���������Ǽ�ֵΪ q ��һ����Ʒʱ������м���һ����ֵΪ p �ĺ�ڵȼ��
���������Ǽ�ֵΪ q �ĺ�ڵȼ���ʱ������м���һ����ֵΪ p �ĺ�ڵȼ����һ����ֵΪ q ����ͨ��Ʒ��
Ϊ������⣬������Ϊ������˼ά��
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
