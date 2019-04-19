
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#define lch(x) x<<1
#define rch(x) x<<1|1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define MAXN 55555
#define MAXM 555
#define INF 1000000007
using namespace std;
int n;
struct node
{
    int x, y;
    bool operator <(const node &cmp)const
    {
        if(x == cmp.x) return y > cmp.y;
        return x > cmp.x;
    }
}p[MAXN];
long long x[MAXN], y[MAXN];
long long f[MAXN];
int q[MAXN];
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d%d", &p[i].x, &p[i].y);
    sort(p, p + n);
    int cnt = 0;
    for(int i = 0; i < n; i++)
        if(!cnt || p[i].y > y[cnt])
        {
            ++cnt;
            x[cnt] = p[i].x;
            y[cnt] = p[i].y;
        }
    for(int i = 0; i < cnt; i++)
        x[i] = x[i + 1];
    int l = 1, r = 1;
    q[1] = 0; f[0] = 0;
    for(int i = 1; i <= cnt; i++)
    {
        while(l < r && y[i] * (x[q[l]] - x[q[l + 1]]) > f[q[l + 1]] - f[q[l]]) l++;
        f[i] = f[q[l]] + x[q[l]] * y[i];
        while(l < r && (f[q[r]] - f[q[r - 1]]) * (x[q[r]] - x[i]) > (f[i] - f[q[r]]) * (x[q[r - 1]] - x[q[r]])) r--;
        q[++r] = i;
    }
    printf("%lld\n", f[cnt]);
    return 0;
}
