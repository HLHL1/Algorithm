#include<iostream>
using namespace std;
int put(int arr[], int l, int r, int key)//在arr[l...r]中二分查找插入位置
{
    int mid;
    if (arr[r] <= key)
        return r + 1;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        if (arr[mid] <= key)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

int LIS(int A[], int n)
{
    int i = 0, len = 1 ,next;
    int* B = (int *)alloca(sizeof(int) * (n + 1));
    B[1] = A[0];
    for (i = 1;i < n;i++)
    {
        int next = put(B, 1, len, A[i]);
        B[next] = A[i];
        if (len < next)    len = next;
    }
    return len;
}
//int main()
//{
//    int a[1000]={0};
//    int b[1000]={0};
//    b[0]=a[0];
//    int flag=0;
//    int len=1;
//    for(int i=1;i<n;i++)
//    {
//        if(a[i]>=b[flag])
//        {
//            b[++flag]=a[i];
//            len=++;
//        }
//        else{
//            b[flag]=a[i];
//        }
//    }
//    return 0;
//}
