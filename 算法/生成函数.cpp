/*

"Well, it seems the first problem is too easy. I will let you know how foolish you are later." feng5166 says.

"The second problem is, given an positive integer N, we define an equation like this:
  N=a[1]+a[2]+a[3]+...+a[m];
  a[i]>0,1<=m<=N;
My question is how many different equations you can find for a given N.
For example, assume N is 4, we can find:
  4 = 4;
  4 = 3 + 1;
  4 = 2 + 2;
  4 = 2 + 1 + 1;
  4 = 1 + 1 + 1 + 1;
so the result is 5 when N is 4. Note that "4 = 3 + 1" and "4 = 1 + 3" is the same in this problem. Now, you do it!"



*/


#include <iostream>
using namespace std;
// Author: Tanky Woo
// www.wutianqi.com
const int _max = 10001;
// c1是保存各项质量砝码可以组合的数目
// c2是中间量，保存每一次的情况
int c1[_max], c2[_max];
int main()
{   //int n,i,j,k;
	int nNum;   //
	int i, j, k;

	while (cin >> nNum)
	{
		for (i = 0; i <= nNum; ++i)   // ---- ①
		{
			c1[i] = 1;
			c2[i] = 0;
		}
		for (i = 2; i <= nNum; ++i)   // ----- ②
		{

			for (j = 0; j <= nNum; ++j)   // ----- ③
			for (k = 0; k + j <= nNum; k += i)  // ---- ④
			{
				c2[j + k] += c1[j];
			}
			for (j = 0; j <= nNum; ++j)     // ---- ⑤
			{
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
		cout << c1[nNum] << endl;
	}

	return 0;
}



/*

/*

假设有x1个字母A， x2个字母B,..... x26个字母Z，同时假设字母A的价值为1，字母B的价值为2,..... 字母Z的价值为26。那么，对于给定的字母，可以找到多少价值<=50的单词呢？单词的价值就是组成一个单词的所有字母的价值之和，比如，单词ACM的价值是1+3+14=18，单词HDU的价值是8+4+21=33。(组成的单词与排列顺序无关，比如ACM与CMA认为是同一个单词）。
Input
输入首先是一个整数N，代表测试实例的个数。
然后包括N行数据，每行包括26个<=20的整数x1,x2,.....x26.
Output
对于每个测试实例，请输出能找到的总价值<=50的单词数,每个实例的输出占一行。
Sample Input
2
1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
9 2 6 2 10 2 2 5 6 1 0 2 7 0 2 2 7 5 10 6 10 2 10 6 1 9


*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int  maxn = 50;

int num[maxn + 1];
int c1[maxn + 1], c2[maxn + 1];

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		for (int i = 1; i <= 26; i++)
			scanf("%d", &num[i]);
		memset(c1, 0, sizeof c1);
		memset(c2, 0, sizeof c2);
		for (int i = 0; i <= num[1]; i++)
			c1[i] = 1;
		for (int i = 2; i <= 26; i++){		//共有26个多项式
			if (num[i] == 0)
				continue;
			for (int j = 0; j <= maxn; j++){	//共有maxn+1项
				for (int k = 0; k <= num[i] && j + k*i <= maxn; k++)
					c2[j + k*i] += c1[j];
			}
			for (int j = 0; j <= maxn; j++){
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
		int sum = 0;
		for (int j = 1; j <= maxn; j++)
			sum += c1[j];
		printf("%d\n", sum);
	}
	return 0;
}



*/
