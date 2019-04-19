Feeling hungry, a cute hamster decides to order some take-away food (like fried chicken for only 3030 Yuan).

However, his owner CXY thinks that take-away food is unhealthy and expensive. So she demands her hamster to fulfill a mission before ordering the take-away food. Then she brings the hamster to a wall.

The wall is covered by square ceramic tiles, which can be regarded as a n * mn∗m grid. CXY wants her hamster to calculate the number of rectangles composed of these tiles.

For example, the following 3 * 33∗3 wall contains 3636 rectangles:



Such problem is quite easy for little hamster to solve, and he quickly manages to get the answer.

Seeing this, the evil girl CXY picks up a brush and paint some tiles into black, claiming that only those rectangles which don't contain any black tiles are valid and the poor hamster should only calculate the number of the valid rectangles. Now the hamster feels the problem is too difficult for him to solve, so he decides to turn to your help. Please help this little hamster solve the problem so that he can enjoy his favorite fried chicken.

Input
There are multiple test cases in the input data.

The first line contains a integer TT : number of test cases. T \le 5T≤5.

For each test case, the first line contains 33 integers n , m , kn,m,k , denoting that the wall is a n \times mn×m grid, and the number of the black tiles is kk.

For the next kk lines, each line contains 22 integers: x\ yx y ,denoting a black tile is on the xx-th row and yy-th column. It's guaranteed that all the positions of the black tiles are distinct.

For all the test cases,

1 \le n \le 10^5,1\le m \le 1001≤n≤10
5
 ,1≤m≤100,

0 \le k \le 10^5 , 1 \le x \le n, 1 \le y \le m0≤k≤10
5
 ,1≤x≤n,1≤y≤m.

It's guaranteed that at most 22 test cases satisfy that n \ge 20000n≥20000.

Output
For each test case, print "Case #xx: ansans" (without quotes) in a single line, where xx is the test case number and ansans is the answer for this test case.

Hint
The second test case looks as follows:



样例输入 复制
2
3 3 0
3 3 1
2 2
样例输出 复制
Case #1: 36
Case #2: 20
题目来源
ACM-ICPC 2018 南京赛区网络预赛

#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 100002;
bool flag[N][105];
int up[105];
int main()
{
	int T, n, m, k, x, y;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++){
		memset(flag, false, sizeof(flag));
		memset(up, 0, sizeof(up));
		scanf("%d%d%d", &n, &m, &k);
		while (k--){
			scanf("%d%d", &x, &y);
			flag[x][y] = true;
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++){
			//更新up数组
			for (int j = 1; j <= m; j++)
			if (flag[i][j])
				up[j] = i;//第j列中为黑块的行（在1~i行中取最大行标

			for (int j = 1; j <= m; j++){//统计以(i,j)为右下角的矩阵的个数
				int h = INF;//统计矩阵长为k时高最大为多少
				for (int k = 1; k <= j; k++){//枚举矩阵的长
					//j-k+1表示以(i,j)为右下角长为k的矩阵的左边界下标
					if (h > i - up[j - k + 1]){
						h = i - up[j - k + 1];//i-up[j-k+1]表示此列能取得的最大高
					}
					ans += h;
				}
			}
		}
		printf("Case #%d: %lld\n", t, ans);
	}
	return 0;
}
