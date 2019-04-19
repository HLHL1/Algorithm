//1.一个数组中只有两个数字是出现一次，其他所有数字都出现了两次,找出这两个数字
思路：
1.我们都知道如果两个相同的数进行异或会相互抵消结果为0，所以我们先将数组里的所有数进行异或，得到的结果是数组中两个只出现一次的不同的数的异或结果(记为ret)
2.ret的二进制数中，是1的位表示两个数的不同位，是0的位表示两个数的相同位
3.我们任意找一个ret是1的位数（代码里我们取第一个是1的位数，记pos),两个数中必定有一个数的pos位是1
4.遍历数组，若第i个元素右pos位并且&1不为0，则可能是两个数中的一个（但也有可能是相同数里面的）所以再进行异或就可以得到不同数中的一个数
#include<stdio.h>
void Find_Num(int* arr,int sz,int* num1,int* num2)
{
    int ret=0;
    int tmp=0;
    int pos=0;
    for(int i=0;i<sz;i++)
    {
        ret^=arr[i];
    }
    tmp=ret;
    while(ret)
    {
        if(ret%2!=0)
        {
            break;
        }
        pos++;
        ret=ret/2;
    }
    for(int i=0;i<sz;i++)
    {
        if((arr[i]>>pos)&1)
        {
            *num1^=arr[i];
        }
    }
    *num2=*num1^tmp;
}
int main()
{
           int num1 = 0;
           int num2 = 0;
           int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 8 };
           int sz = sizeof (arr) / sizeof(arr[0]);
          Find_Num(arr, sz, &num1, &num2);
          printf( "%d,%d\n", num1, num2);
           return 0;
}


