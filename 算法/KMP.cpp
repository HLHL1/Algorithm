
#include<cstdio>
#include<iostream>
using namespace std;

int next[100];
void GetNext(char* p)
{
    int pLen = strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen - 1)
    {
        //p[k]��ʾǰ׺��p[j]��ʾ��׺
        if (k == -1 || p[j] == p[k])
        {
            ++k;
            ++j;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}
int KmpSearch(char* s, char* p)
{
    int i = 0;
    int j = 0;
    int sLen = strlen(s);
    int pLen = strlen(p);
    while (i < sLen && j < pLen)
    {
        //�����j = -1�����ߵ�ǰ�ַ�ƥ��ɹ�����S[i] == P[j]��������i++��j++
        if (j == -1 || s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            //�����j != -1���ҵ�ǰ�ַ�ƥ��ʧ�ܣ���S[i] != P[j]�������� i ���䣬j = next[j]
            //next[j]��Ϊj����Ӧ��nextֵ
            j = next[j];
        }
    }
    if (j == pLen)
        return i - j;
    else
        return -1;
}



#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
char str1[maxn],str2[maxn];
int a[maxn];

void getnext()
{
	int i=0,j=-1,len=strlen(str2);
		a[0]=-1;
		while(i<len)
		{
			if(j==-1||str2[i]==str2[j])
				a[++i]=++j;
			else
				j=a[j];
		}
}

int kmp()
{
	int ans=0,i=0,j=0,l1=strlen(str1),l2=strlen(str2);
	while(i<l1)
	{
		if(j==-1||str1[i]==str2[j])
			i++,j++;
		else
			j=a[j];
		if(j==l2)ans++;
	}
	return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>str2>>str1;
		getnext();
		cout<<kmp()<<endl;
	}
}


#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
string str1,str2,str3;
int a[maxn];

void getnext()
{
	int i=0,j=-1,len=str3.size();
		a[0]=-1;
		while(i<len)
		{
			if(j==-1||str3[i]==str3[j])
				a[++i]=++j;
			else
				j=a[j];
		}
}
int main()
{
	while(cin>>str1>>str2)
	{

		str3=str1+str2;
		int lena=str1.size();
		int lenb=str2.size();
		int lenc=str3.size();
		int ab=min(lena,lenb);
		getnext();
		while(a[lenc]>ab)
			lenc=a[lenc];
		if(a[lenc])
			{
				for(int i=0;i<a[lenc];i++)
							cout<<str1[i];
					cout<<" "<<a[lenc]<<endl;
			}
		else
		{
			cout<<a[lenc]<<endl;
		}
		str1.clear();
		str2.clear();
		str3.clear();
	}
}


����һ���ַ������ҳ����������Ӵ���ʹ��ʼ���м䡢��β���ٶ���������

˼·��

�Ӵ�Сö���Ӵ����ȣ����жϽ�β�Ϳ�ʼ�Ƿ�һ�������һ������ʹ��kmp�ж��м��Ƿ����Ӵ�������о��Ǵ�

���룺
#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int nxt[1000005];
int len;
set<int> st;
void getnxt()
{
    memset(nxt,-1,sizeof(nxt));
    nxt[0] = -1; int j = -1;
    for(int i = 0; i < len;){
        if(j == -1||s[i] == s[j])nxt[++i] = ++j;
        else j = nxt[j];
    }
}

void getback()
{
    int p = nxt[len-1];
    while(p>=0){
        if(s[len-1] == s[p]){
            st.insert(p+1);
        }
        p = nxt[p];
    }
}

void solve()
{
    int ans = 0;
    for(int i = len-2;i>=0;--i){
        int p = nxt[i];
        while(p>=0){
            if(s[i] == s[p] && st.find(p+1)!=st.end()){
                if(len - 1 -p > i && p < i-p){
                    ans = max(ans,p+1);
                }
            }
            p = nxt[p];
        }
    }
    printf("%d\n",ans);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        cin>>s;
        st.clear();
        len = strlen(s);
        getnxt();
        getback();
        solve();
    }
    return 0;
}



3
aaa
12
aabaabaabaab
0
ʾ�����

Test case #1
2 2
3 3
Test case #2
2 2
6 2
9 3
12 4

#include <stdio.h>
#include <stdlib.h>
char str[1000002] ;
int next[1000002] ;
void getnext(int l)
{
    int j = 0 , k = -1 ;
    next[0] = -1 ;
    while(j < l)
    {
        if(k==-1 || str[j]== str[k])
        {
            j++; k++;
            next[j] = k ;
        }
        else
            k = next[k] ;
    }
}
int main()
{
    int i , j , l , ll ,count = 0 ;
    while(scanf("%d", &l)&&l)
    {
        scanf("%s", str);
        count++;
        getnext(l);
        printf("Test case #%d\n", count);
        for(j = 2 ; j <= l ; j++)
        {
            ll = j - next[j] ;
            if(j % ll == 0 && j/ll != 1)
                printf("%d %d\n", j, j/ll);
        }
        printf("\n");
    }
    return 0;
}
