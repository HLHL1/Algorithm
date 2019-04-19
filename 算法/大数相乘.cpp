#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1024
int* reverse(char* nums, int len) {
    int* ans = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < len; ++i) {
        ans[len - i - 1] = (nums[i] - '0');
    }
    return ans;
}
char* BigNumMul(char* a, char *b) {
    int lena = strlen(a);
    int lenb = strlen(b);
    int* na = reverse(a, lena);
    int* nb = reverse(b, lenb);
    int nans[N] = {0};
    char* ans = (char*)malloc(N);
    nans[0] = lena + lenb;
    for (int i = 0; i < lena; ++i) {
        for (int j = 0; j < lenb; ++j) {
            nans[i + j + 1] += na[i] * nb[j];
        }
    }
    for (int i = 1; i <= nans[0]; ++i) {
        if (nans[i] < 10) continue;
        nans[i + 1] += nans[i] / 10;
        nans[i] %= 10;
        nans[0] += (i == nans[0]);
    }
    int flag = 1;
    int cnt = 0;
    for (int i = nans[0]; i >= 1; --i) {
        if (nans[i] == 0 && flag) {
            if (i == 1) return "0";
            continue;
        }
        ans[cnt++] = nans[i] + '0';
        flag = 0;
    }
    return ans;
}
int main(){
    char a[N] = {0}, b[N] = {0};
    while (~scanf("%s %s", a, b)) {
        printf("%s\n", BigNumMul(a, b));
    }
    return 0;
}
