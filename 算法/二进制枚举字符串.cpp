#include<bits/stdc++.h>
using namespace std;
#define line cout<<"------------"<<endl
const int N = 33;

map<string, int>mp,vis;
map<int, string>ms;
vector<string>ve;
int n;
string s,u, str;
bool cmp(string a, string b)
{
    if(a.length() != b.length())
        return a.length() > b.length();
    else
        return a < b;
}
// �����posλ�ÿ�ʼ���ַ���
void change(int pos)
{
    str.clear();
    string temp = s.substr(pos);
    str += temp;
    temp = s.substr(0,pos);
    str += temp;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        mp.clear();
        ve.clear();
        int nn=n;
        while(nn--)
        {
            vis.clear();
            cin>>s;
            int len=s.length();
            for(int k=0; k<len; k++)
            {
                change(k);
                // ���ַ������ж�����ö�٣�ÿ�������г��ֵĴ�����map���
                for(int i=1;i < (1<<len); i++)
                {
                    for(int j=0; j<len; j++)
                    {
                        if(i >> j & 1)
                           u += str[j];
                    }
                    if(vis[u]==0)
                    {
                       mp[u]++;
                       vis[u]=1;
                    }
                    u.clear();
                }
            }
        }
        int flag=0;
        for(auto i: mp)
        {
            // �ҳ����г��ִ���Ϊn�������У����vector
            if(i.second == n)
            {
                ve.push_back(i.first);
                flag = 1;
            }
        }
        // ��vector��������
        sort(ve.begin(),ve.end(),cmp);
        if(flag==0)
            cout<<0<<endl;
        else cout << ve[0] << endl;
    }
    return 0;
}
