//1.һ��������ֻ�����������ǳ���һ�Σ������������ֶ�����������,�ҳ�����������

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
            *num1^=a[i];
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

//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֡�
//
//3.ģ��ʵ��strcpy
//4.ģ��ʵ��strcat
