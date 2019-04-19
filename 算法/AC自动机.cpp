

//�кܶ��ַ��� ����һ�����������������ǲ�������������Ӵ�

#include<stdio.h>
#include<string.h>
#include<queue>
#include<string>
#include<iostream>
#define maxlen 100005
using namespace std;
int n;
    int nxt[maxlen][30],FAIL[maxlen],edd[maxlen],root,L;//nxt��¼�ڵ㣬������eddָ������Ե�ǰ�ڵ�Ϊ�ַ���β���ַ�������
    int mark[maxlen];
	int newnode()
    {
        for(int i=0;i<26;i++)
            nxt[L][i]=-1;//�ڵ����ӵı߳�ʼ��Ϊ-1
        edd[L]=0;
        mark[L]=0;
        return L++;
    }
    void init()
    {
        L=0;
        root=newnode();
    }

    void insert(char buf[],int l)//trie���Ľ���
    {
        int now=root;
        for(int i=0;i<l;i++)
        {
            if(nxt[now][buf[i]-'a']==-1)nxt[now][buf[i]-'a']=newnode();
            now=nxt[now][buf[i]-'a'];
        }
        edd[now]++;
    }
    void build()//����ac�Զ���
    {
        queue<int>que;
        for(int i=0;i<26;i++)
        {
            if(nxt[root][i]==-1)nxt[root][i]=root;
            else                                 //���������򽫽ڵ������� ������FAILָ��ָ��root
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
                if(nxt[now][i]==-1)            //�������ߣ��򽫸ñ�ָ��ǰ�ڵ�FAILָ��ָ�����Ӧ�ַ����ӵĽڵ�
                    nxt[now][i]=nxt[FAIL[now]][i];
                else                            //�������ߣ��򽫶��ӽڵ��FAILָ��ָ��ǰ�ڵ�FAILָ��ָ����Ӧ�ַ��ӵĽڵ�
                {
                    FAIL[nxt[now][i]]=nxt[FAIL[now]][i];
                    que.push(nxt[now][i]); //������м�������
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
            while(temp!=root&&mark[temp]==0)//������ĿҪ��ı���ʽ
            {
                res+=edd[temp];
                edd[temp]=0;
                mark[temp]=1;
                temp=FAIL[temp];
            }
        }
        return res; //�����ﷵ�ص���ƥ�䵽��ģʽ��������
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
