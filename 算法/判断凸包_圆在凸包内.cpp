
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 111116
#define eps 1e-7
using namespace std;

//判断精度
int sgn(const double &x)
{
	return x < -eps ? -1 : (x > eps);
}


inline double sqr(const double &x)
{
	return x * x;
}

//点的一些运算符重载
struct Point
{
	double x, y;

	//构造函数
	Point()
	{}

	//拷贝构造
	Point(const double &x, const double &y)
		:x(x)
		, y(y)
	{}

	//
	Point operator - (const Point &a)const
	{
		return Point(x - a.x, y - a.y);
	}
	Point operator + (const Point &a)const
	{
		return Point(x + a.x, y + a.y);
	}
	Point operator / (const double &a)const
	{
		return Point(x / a, y / a);
	}

	//叉积
	friend double det(const Point &a, const Point &b)
	{
		return a.x * b.y - a.y * b.x;
	}

	//点积
	friend double dot(const Point &a, const Point &b)
	{
		return a.x * b.x + a.y * b.y;
	}

	//斜线长度
	friend double dist(const Point &a, const Point &b)
	{
		return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
	}

	//
	bool operator < (const Point &a)const
	{
		return sgn(x - a.x) < 0 || (sgn(x - a.x) == 0 && sgn(y - a.y) < 0);
	}

	void in()
	{
		scanf("%lf %lf", &x, &y);
	}

	void out()const
	{
		cout << x << " " << y << endl;
	}
};
struct Line
{
	Point s, t;

	Line()
	{}
	Line(const Point &s, const Point &t)
		:s(s)
		, t(t)
	{}

	//输入一条线的两个端点
	void in()
	{
		s.in();
		t.in();
	}

	//
	double pointDistLine(const Point &p)
	{
		if (sgn(dot(t - s, p - s)) < 0)
			return dist(p, s);
		if (sgn(dot(s - t, p - t)) < 0)
			return dist(p, t);
		return fabs(det(t - s, p - s)) / dist(s, t);
	}

	//判断点是否在线上
	bool pointOnLine(const Point &p)
	{
		return sgn(det(t - s, p - s)) == 0 && sgn(dot(s - p, t - p)) <= 0;
	}
};
struct Poly
{
	vector<Point>p;
	vector<Point>tb;// 逆时针凸包
	void in(int r)
	{
		p.resize(r);
		for (int i = 0; i < r; i++)
			p[i].in();
	}

	//判断点集是否为凸包
	bool isCanHull()
	{
		int n = p.size();
		int m = 0;
		sort(p.begin(), p.end());
		tb.resize(n + 1);
		for (int i = 0; i < n; i++)
		{
			while (m > 1 && sgn(det(tb[m - 1] - tb[m - 2], p[i] - tb[m - 2])) < 0)m--;
			tb[m++] = p[i];
		}
		int k = m;
		for (int i = n - 2; i >= 0; i--)
		{
			while (m > k && sgn(det(tb[m - 1] - tb[m - 2], p[i] - tb[m - 2])) < 0)m--;
			tb[m++] = p[i];
		}
		if (m) tb.resize(m - 1);
		return m - 1 == n;
	}

	//判断点t(圆心)是否在凸包内部，这个是O(logn)的算法
	bool isContainOlogn(const Point &t)
	{
		int n = tb.size();
		if (n < 3)return 0;
		Point g = (tb[0] + tb[n / 3] + tb[n * 2 / 3]) / 3.0;
		int l = 0, r = n;
		while (l + 1 < r)
		{
			int mid = (l + r) >> 1;
			int k = sgn(det(tb[l] - g, tb[mid] - g));
			int dl = sgn(det(tb[l] - g, t - g));
			int dr = sgn(det(tb[mid] - g, t - g));
			if (k > 0)
			{
				if (dl >= 0 && dr < 0) r = mid;
				else l = mid;
			}
			else
			{
				if (dl < 0 && dr >= 0) l = mid;
				else r = mid;
			}
		}
		r %= n;
		int res = sgn(det(tb[l] - t, tb[r] - t));
		if (res >= 0) return true;
		return false;
	}

	//判断点t是否在凸包内部，这个是O(n)的算法
	bool isContainOn(const Point &t)
	{
		int sign = 0;
		int n = tb.size();
		for (int i = 0; i < n; i++)
		{
			Line line(tb[i], tb[(i + 1) % n]);
			if (line.pointOnLine(t))return 2;
		}
		for (int i = 0; i < n; i++)
		{
			int signt = sgn(det(tb[i] - t, tb[(i + 1) % n] - t));
			if (signt)
			{
				if (!sign) sign = signt;
				else if (signt != sign) return false;
			}
		}
		return true;
	}
} poly;
struct Cir
{
	Point o;
	double r;
	void in() {
		scanf("%lf", &r);
		o.in();
	}

	//判断圆半径是否小于到多边形的最小边
	bool isInsectPoly(const Poly &poly)
	{
		int len = poly.tb.size();
		for (int i = 0; i < len; i++)
		{
			Line line = Line(poly.tb[i], poly.tb[(i + 1) % len]); //把凸包的点集扫一遍即可
			double dist = line.pointDistLine(o);
			if (sgn(dist - r) < 0) return true; //然后判断距离即可
		}
		return false;
	}
} cir;
int n;
void solve()
{
	if (!poly.isCanHull())
		puts("HOLE IS ILL-FORMED");
	else if (!poly.isContainOlogn(cir.o) || cir.isInsectPoly(poly))
		puts("PEG WILL NOT FIT");
	else puts("PEG WILL FIT");
}
int main()
{
	while (cin >> n, n > 2)
	{
		cir.in();
		poly.in(n);
		solve();
	}
	return 0;
}
