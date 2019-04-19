//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水。编程实现。
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int cup=0;//瓶子数
    int water=0;//喝到的汽水数
    water+=n;
    cup=n;
    while(cup>1)
    {
        water+=cup/2;
        if(cup%2==0)
        {
            cup=cup/2;

        }
        else{
            cup=cup/2+1;
        }
    }
    printf("%d\n",water);
    return 0;
}

