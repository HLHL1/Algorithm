//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֡�
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int cup=0;//ƿ����
    int water=0;//�ȵ�����ˮ��
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

