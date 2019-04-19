//实质是求逆序对

//冒泡排序也可以做，但是复杂度O(n)会超时
//所以利用归并排序，优化


//#include<stdio.h>
//int main()
//{
//    int n;
//    while(scanf("%d",&n)!=EOF)
//    {
//        int a[10000];
//        int flag=0;
//        for(int i=0;i<n;i++)
//        {
//            scanf("%d",&a[i]);
//        }
//        for(int i=0;i<n;i++)
//        {
//
//            for(int j=i+1;j<n;j++)
//            {
//
//                if(a[i]>a[j])
//                {
//
//                    flag++;
//                }
//            }
//        }
//       printf("%d\n",flag);
//    }
//    return 0;
//}



#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int data[10000010];
int tmp[10000010];

long long int cnt;
void Merge(int beg, int mid, int end) {
    if (end <= beg)
        return;

    int i = 0;
    int beg1 = beg, beg2 = mid;
    while (beg1 < mid && beg2 < end) {
        if (data[beg1] <= data[beg2]) {
            tmp[i++] = data[beg1++];
        } else {
            tmp[i++] = data[beg2++];
            cnt += mid - beg1;
        }
    }
    while (beg1 < mid) {
        tmp[i++] = data[beg1++];
    }
    while (beg2 < end) {
        tmp[i++] = data[beg2++];
    }
    memcpy(data + beg, tmp, sizeof(int) * (end - beg));
}

int main(int argc, const char * argv[]) {

    int n;
    while (cin >> n) {
        cnt = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &data[i]);
        }
        for (int length = 1; length <= n; length *= 2) {
            int beg = 0, mid = beg + length, end = mid + length;
            for(; beg < n; beg += 2 * length,
                           mid = beg + length, end = mid + length) {
                if (mid > n) {
                    mid = n;
                }
                if (end > n) {
                    end = n;
                }
                Merge(beg, mid, end);
            }
        }
        cout << cnt << endl;
    }

    return 0;
}

