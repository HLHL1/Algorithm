#include<stdio.h>
#include<string.h>

char a[10010];
int p[30];
int main()
{

    int t;
    while(t--)
    {
        scanf("%s",a);
        int sum=0;
        int len=strlen(a);
        for(int i=0;i<len;i++)
        {

            if(a[i]-'a'==0)
            {
                sum++;
                a[i]=1;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
