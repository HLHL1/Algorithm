
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int const INF = 0x6fffffff;
int n, top, cnt, ansSta;
struct POINT {
	int x, y;
}p[20], stk[20], base;

struct TREE {
	int x, y, val;
	double len;
}t[20];

//求两点之间的距离
double getDist(POINT p1, POINT p2) {
	return sqrt(1.0 * (p1.x - p2.x) * (p1.x - p2.x) + 1.0 * (p1.y - p2.y) * (p1.y - p2.y));
}


int getCross(POINT p0, POINT p1, POINT p2) {
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

bool cmp(POINT p1, POINT p2) {
	if (getCross(base, p1, p2) == 0) {
		return getDist(base, p1) < getDist(base, p2);
	}
	if (getCross(base, p1, p2) > 0) {
		return true;
	}
	return false;
}

void getConvex() {
	if (cnt == 1) {
		stk[0] = p[0];
		return;
	}
	base.x = p[0].x;
	base.y = p[0].y;
	int pos = 0;
	for (int i = 1; i < cnt; i++) {
		if (p[i].y < base.y || (p[i].y == base.y && p[i].x < base.x)) {
			base.x = p[i].x;
			base.y = p[i].y;
			pos = i;
		}
	}
	swap(p[0], p[pos]);
	sort(p + 1, p + cnt, cmp);
	top = 1;
	stk[0] = p[0];
	stk[1] = p[1];
	for (int i = 2; i < cnt; i++) {
		while (top > 0 && getCross(stk[top - 1], stk[top], p[i]) <= 0) {
			top--;
		}
		stk[++top] = p[i];
	}
}

//求凸包的周长
double getLen() {
	if (cnt == 1) {
		return 0;
	}
	stk[++top] = p[0];
	double ans = 0;
	for (int i = 0; i < top; i++) {
		ans += getDist(stk[i], stk[i + 1]);
	}
	return ans;
}


int main() {
	int ca = 1;
	while (scanf("%d", &n) != EOF && n) {
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d %lf", &t[i].x, &t[i].y, &t[i].val, &t[i].len);
		}
		int minVal = INF, minCnt = n, sumVal;
		double extra = 0, sumLen;
		for (int sta = 1; sta < (1 << n) - 1; sta++) {
			cnt = sumVal = 0;
			sumLen = 0;
			for (int i = 0; i < n; i++) {
				if ((1 << i) & sta) {   //cut
					sumLen += t[i].len;
					sumVal += t[i].val;
				}
				else {                  //don't cut
					p[cnt].x = t[i].x;
					p[cnt++].y = t[i].y;
				}
			}
			if (sumVal > minVal) {
				continue;
			}
			getConvex();
			double useLen = getLen();
			if (useLen <= sumLen) {
				if (minVal > sumVal || (minVal == sumVal && n - cnt < minCnt)) {
					minVal = sumVal;
					ansSta = sta;
					extra = sumLen - useLen;
					minCnt = n - cnt;
				}
			}
		}
		if (ca != 1) {
			printf("\n");
		}
		printf("Forest %d\n", ca++);
		printf("Cut these trees:");
		for (int i = 0; i < n; i++) {
			if ((1 << i) & ansSta) {
				printf(" %d", i + 1);
			}
		}
		printf("\nExtra wood: %.2f\n", extra);
	}
	return 0;
}
