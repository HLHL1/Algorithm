#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int data[5050];
int arr[5050];
int tmp[5050];

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
            arr[i] = data[i];
        }
        for (int length = 1; length <= n; length *= 2) {
            for(int beg = 0, mid = beg + length, end = mid + length; beg < n;
                beg += 2 * length, mid = beg + length, end = mid + length) {
                if (mid > n) {
                    mid = n;
                }
                if (end > n) {
                    end = n;
                }
                Merge(beg, mid, end);
            }
        }
        long long int ret = cnt;
        for (int i = 0; i < n; ++i) {

            cnt = cnt - arr[i] + n - 1 - arr[i];//有什么公式吧
            if (ret > cnt) ret = cnt;
        }
        cout << ret << endl;
    }

    return 0;
}
