/*
//区间覆盖&离散化
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<string>
using namespace std;




//#define ll long long int




#define L(rt) (rt<<1)
#define R(rt) (rt<<1|1)

const int N = 100010;     //注意范围,否则RE

int flag;

struct Tree{
	int l, r;
	bool vis;   //vis 是这块区域是否完全被覆盖
}tree[N << 2];

struct Point{
	int id, x;
}post[N << 2];

int cmp1(Point a, Point b){
	return a.x<b.x;
}

int cmp2(Point a, Point b){
	if (a.id == b.id)
		return a.x<b.x;
	return a.id>b.id;
}

void PushUp(int rt){
	tree[rt].vis = tree[L(rt)].vis && tree[R(rt)].vis;
}

void build(int L, int R, int rt){
	tree[rt].l = L;
	tree[rt].r = R;
	tree[rt].vis = 0;
	if (tree[rt].l == tree[rt].r)
		return;
	int mid = (L + R) >> 1;
	build(L, mid, L(rt));
	build(mid + 1, R, R(rt));
}

void query(int L, int R, int rt){
	if (tree[rt].vis)
		return;
	if (tree[rt].l == L && tree[rt].r == R){
		tree[rt].vis = 1;
		flag = 1;
		return;
	}
	int mid = (tree[rt].l + tree[rt].r) >> 1;
	if (R <= mid)
		query(L, R, L(rt));
	else if (L >= mid + 1)
		query(L, R, R(rt));
	else{
		query(L, mid, L(rt));
		query(mid + 1, R, R(rt));
	}
	PushUp(rt);
}

int main(){


	int t, n;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 0; i<2 * n; i += 2){
			scanf("%d%d", &post[i].x, &post[i + 1].x);
			post[i].id = post[i + 1].id = i;
		}
		sort(post, post + 2 * n, cmp1);
		int tot = 0, pre = 0;
		for (int i = 0; i<2 * n; i++){     //离散化，
			if (post[i].x == pre)
				post[i].x = tot;
			else{
				pre = post[i].x;
				post[i].x = ++tot;
			}
		}
		build(1, 2 * n, 1);
		sort(post, post + 2 * n, cmp2);     //排序，从后往前贴
		int ans = 0;
		for (int i = 0; i<2 * n; i += 2){
			int l = post[i].x;
			int r = post[i + 1].x;
			flag = 0;
			query(l, r, 1);
			if (flag)
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}




//区间修改---懒惰标记


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<string>
using namespace std;




#define ll long long int
struct node{
	int l;
	int r;
	ll w;
	ll f;
}tree[4 * 100000 + 1];

ll x, y,a, m, ans;
//建树
void build(int l, int r, int k)
{
	tree[k].l = l, tree[k].r = r;
	if (l == r){
		cin >> tree[k].w;
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, k * 2);
	build(mid + 1, r, k * 2 + 1);
	tree[k].w = tree[k * 2].w + tree[k * 2 + 1].w;
}

void down(int k)
{
	tree[k * 2].f += tree[k].f;
	tree[k * 2 + 1].f += tree[k].f;
	tree[k * 2].w += tree[k].f*(tree[k * 2].r - tree[k * 2].l + 1);
	tree[k * 2 + 1].w += tree[k].f*(tree[k * 2 + 1].r - tree[k * 2 + 1].l + 1);
	tree[k].f = 0;
}

//区间查询
void Sum(int k)
{
	if (tree[k].l >= x&&tree[k].r <= y)
	{
		ans+=tree[k].w;
		return;
	}down(k);
	int mid = (tree[k].l + tree[k].r) / 2;
	if (tree[k].f) {
		//懒标记下传，唯一需要更改的地方
	}
	if (x <= mid){
		Sum(k * 2);
	}
	if (y > mid){
		Sum(k * 2 + 1);
	}
}

void add(int k)
{
	if (tree[k].l >= x&&tree[k].r <= y)//当前区间全部对要修改的区间有用
	{
		tree[k].w += (tree[k].r - tree[k].l + 1)*a;//(r-1)+1区间点的总数
		tree[k].f += a;
		return;
	}
	if (tree[k].f) down(k);//懒标记下传。只有不满足上面的if条件才执行，所以一定会用到当前节点的子节点
	int m = (tree[k].l + tree[k].r) / 2;
	if (x <= m) add(k * 2);
	if (y>m) add(k * 2 + 1);
	tree[k].w = tree[k * 2].w + tree[k * 2 + 1].w;//更改区间状态
}
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{

		build(1, n, 1);
		while (m--)
		{
			char c;
			getchar();
			scanf("%c", &c);

			if (c == 'Q'){
				int i, j;
				scanf("%d%d", &i, &j);
				ans = 0;
				x = i, y = j;
				Sum(1);
				printf("%lld\n", ans);
			}
			else{
				int i, j, k;
				scanf("%d%d%d", &i, &j, &k);
				x = i, y = j, a = k;
				add(1);
			}
		}

	}
		system("pause");
	return 0;
}






void init()//新建一个线段树
{
	int i, k;
	for (k = 1; k < n; k <<= 1){
		;
	}
	for (i = k; i<2 * k; i++)
	{
		a[i].l = a[i].r = i - k + 1;
		a[i].n = 0;
	}
	for (i = k - 1; i>0; i--)
	{
		a[i].l = a[2 * i].l;
		a[i].r = a[2 * i + 1].r;
		a[i].n = 0;
	}
}

void insert(int i, int x, int m)//线段树的插入
{
	if (x >= a[i].l && x <= a[i].r)
		a[i].n += m;
	if (a[i].l == a[i].r)
		return;
	int mid = (a[i].l + a[i].r) / 2;
	if (x>mid)
		insert(2 * i + 1, x, m);
	else
		insert(2 * i, x, m);
}

*/

//敌兵布阵

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<string>
using namespace std;



#define ll long long int
struct node{
	int l;
	int r;
	int w;
}tree[4 * 50000+1];

int x, y, m,ans;
//建树
void build(int l, int r, int k)
{
	tree[k].l = l, tree[k].r = r;
	if (l == r){
		cin >> tree[k].w;
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid,k*2);
	build(mid + 1, r,k*2+1);
	tree[k].w = tree[k * 2].w + tree[k * 2 + 1].w;
}

//区间查询
void Sum(int k)
{
	if (tree[k].l >= x&&tree[k].r <= y)
	{
		ans += tree[k].w;
		return;
	}
	int mid = (tree[k].l + tree[k].r) / 2;
	if (x <= mid){
		Sum(k * 2);
	}
	if (y > mid){
		Sum(k * 2 + 1);
	}
}

//单点修改
void add(int k)
{
	if (tree[k].l == tree[k].r){
		tree[k].w += y;
		return;
	}
	int mid = (tree[k].l + tree[k].r) / 2;
	if (x <= mid){
		add(k * 2);
	}
	else{
		add(k * 2 + 1);
	}
	tree[k].w = tree[k * 2].w + tree[k * 2 + 1].w;
}
int main()
{
	int T;
	//scanf("%d", &T);
	//for (int t = 1; t <= T; t++)
	//{
		//printf("Case %d:\n", t);
		int n;
		cin >> n;
		build(1, n, 1);
		while (1)
		{
			char s[10];
			int i, j;
			scanf("%s", s);
			if (strcmp(s,"End")==0){
				break;
			}
			cin>> i >> j;
			if (strcmp(s, "Query") == 0){
				x = i, y = j;
				ans = 0;
				Sum(1);
				printf("%d\n", ans);
			}
			else if (strcmp(s, "Add") == 0){
				x = i, y = j;
				add(1);
			}
			else if (strcmp(s, "Sub") == 0){
				x = i, y = -j;
				add(1);
			}

		}

//	}

	return 0;
}
