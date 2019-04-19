

//有很多字符串 ，找一个主串，看其他串是不是这个主串的子串

#include<stdio.h>
#include<string.h>
#include<queue>
#include<string>
#include<iostream>
#define maxlen 100005
using namespace std;
int n;
    int nxt[maxlen][30],FAIL[maxlen],edd[maxlen],root,L;//nxt记录节点，在这里edd指针代表以当前节点为字符串尾的字符串个数
    int mark[maxlen];
	int newnode()
    {
        for(int i=0;i<26;i++)
            nxt[L][i]=-1;//节点连接的边初始化为-1
        edd[L]=0;
        mark[L]=0;
        return L++;
    }
    void init()
    {
        L=0;
        root=newnode();
    }

    void insert(char buf[],int l)//trie树的建立
    {
        int now=root;
        for(int i=0;i<l;i++)
        {
            if(nxt[now][buf[i]-'a']==-1)nxt[now][buf[i]-'a']=newnode();
            now=nxt[now][buf[i]-'a'];
        }
        edd[now]++;
    }
    void build()//建立ac自动机
    {
        queue<int>que;
        for(int i=0;i<26;i++)
        {
            if(nxt[root][i]==-1)nxt[root][i]=root;
            else                                 //若有连边则将节点加入队列 ，并将FAIL指针指向root
            {
                FAIL[nxt[root][i]]=root;
                que.push(nxt[root][i]);
            }
        }
        while(!que.empty())
        {
            int now=que.front();
            que.pop();
            for(int i=0;i<26;i++)
            {
                if(nxt[now][i]==-1)            //若无连边，则将该边指向当前节点FAIL指针指向的相应字符连接的节点
                    nxt[now][i]=nxt[FAIL[now]][i];
                else                            //若有连边，则将儿子节点的FAIL指针指向当前节点FAIL指针指向相应字符接的节点
                {
                    FAIL[nxt[now][i]]=nxt[FAIL[now]][i];
                    que.push(nxt[now][i]); //加入队列继续遍历
                }
            }
        }
    }
    int query(char buf[],int l)
    {
        int now=root;
        int res=0;
        for(int i=0;i<l;i++)
        {
            now=nxt[now][buf[i]-'a'];
            int temp=now;
            while(temp!=root&&mark[temp]==0)//根据题目要求改变形式
            {
                res+=edd[temp];
                edd[temp]=0;
                mark[temp]=1;
                temp=FAIL[temp];
            }
        }
        return res; //在这里返回的是匹配到的模式串的数量
    }
char buf[maxlen],ans[maxlen];
string A[maxlen];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		init();
		int ma=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s",buf);
			int l=strlen(buf);
			if(ma<l)
			{
				ma=l;
				strcpy(ans,buf);
			}
			insert(buf,l);
		}
		build();
		int sum=query(ans,ma);
		if(sum==n) puts(ans);
		else puts("No");
	}
	return 0;
}
