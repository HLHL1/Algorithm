/*
��һ���ַ����Ƿ�����ɻ��ģ������������ɵĻ��ĸ���


 ����Ԫ�ص�һ��͵Ľ׳˳���ÿ��Ԫ��һ��ĵĽ׳˼��Ǵ𰸡�
*/




#include<cstdio>
#include<cstring>
#include<iostream>
const int maxn = 1111;
int num[maxn];
char s[maxn];
typedef long long ll;
const int mod = 1e9 + 7;
using namespace std;
ll f[maxn];

//��׳�
void init()
{
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i<maxn; i++)
		f[i] = f[i - 1] * i%mod;
}

//��������������ԭ
ll cal(ll x)
{
	ll res = 1;
	int k = mod - 2;
	while (k)
	{
		if (k & 1)
		{
			res *= x;
			res %= mod;
		}
		x *= x;
		x %= mod;
		k >>= 1;
	}
	return res;
}
int main()
{
	int T;
	init();
	cin >> T;
	while (T--)
	{
		scanf("%s", s);
		int n = strlen(s);
		memset(num, 0, sizeof(num));
		for (int i = 0; i<n; i++)
			num[s[i] - 'a']++;
		int len = 0;
		for (int i = 0; i<26; i++)
		if (num[i] % 2)
			len++;
		if (len>1)
		{
			printf("0\n");
			continue;
		}
		int total = 0;
		for (int i = 0; i<26; i++)
		{
			num[i] /= 2;
			total += num[i];
		}
		ll res = f[total];
		for (int i = 0; i<26; i++)
		if (num[i])
		{
			res = res*cal(f[num[i]]) % mod;
		}
		printf("%lld\n", res);
	}
	return 0;
}
