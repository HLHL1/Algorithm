/*

0. ��ʼ����������㣬��˫ͷ��d��װ��P2,P0,P1,P2����˫ͷ������ָ��ֱ�Ϊb,t��
1.������i=i+1��ֱ��d[t+1],d[t],Pi������ת��d,d[b+1],Pi������ת
2.��������Щֱ��d[t+1],d[t],Pi����ת
�� t=t-1��
����Pi����ѹ��d��
����������Щֱ��d,d[b+1],Pi����ת
�� b=b+1��
�� ��Pi����ѹ��d
---------------------
���ߣ������ϵľ���
��Դ��CSDN
ԭ�ģ�https://blog.csdn.net/yangkunpengd/article/details/51336453?utm_source=copy
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�

*/



#include<stdio.h>

int g_result[240][2];

/*getResult()ʵ�ֹ��ܣ�������P0(x1,y1)��Pn(x2,y2)Ϊֱ�ߣ��ҳ�pack����������ֱ����Զ�ĵ�Pmax
*���ҳ�ֱ��P0Pmax��PmaxPn���ϰ������еݹ顣
*ע��Pack[0][0]��ŵ�ĸ�����pack[1]��ʼ��ŵ�����ꡣ
*ȫ�ֱ���g_result[][]�������͹���ϵĵ㣬��������Ҫ�Ĵ𰸡�ͬ��g_result[0][0]��ŵ������ҵ��ĵ�ĸ�����
**/
void getResult(int Pack[240][2], int x1, int y1, int x2, int y2)
{
    int i,t,x3,y3,R,Rmax,tmax;
    int ResultPack[240][2];
    ResultPack[0][0] = 0;
    if(Pack[0][0] <= 1)
        return;
    x3 = Pack[1][0];
    y3 = Pack[1][1];
    R = x1*y2 + x3*y1 + x2*y3 - x3*y2 - x2*y1 - x1*y3;
    Rmax = R;
    tmax = 1;
    for(i=2;i<=Pack[0][0];i++)
    {
        x3 = Pack[i][0];
        y3 = Pack[i][1];
        R = x1*y2 + x3*y1 + x2*y3 - x3*y2 - x2*y1 - x1*y3;
        if(R >= 0)
        {
            t = ++ResultPack[0][0];
            ResultPack[t][0] = x3;
            ResultPack[t][1] = y3;
        }
        if(R > Rmax)
        {
            Rmax = R;
            tmax = i;
        }
    }
    if(Rmax <= 0)
    {
        for(i=1;i<ResultPack[0][0];i++)
        {
            x3 = ResultPack[i][0];
            y3 = ResultPack[i][1];
            R = x1*y2 + x3*y1 + x2*y3 - x3*y2 - x2*y1 - x1*y3;
            if(R == 0 && !((x3==x2&&y3==y2)||(x3==x1&&y3==y1)))
            {
                t = ++g_result[0][0];
                g_result[t][0] = ResultPack[i][0];
                g_result[t][1] = ResultPack[i][1];
            }
        }
        return;
    }
    else
    {
        t = ++g_result[0][0];
        g_result[t][0] = Pack[tmax][0];
        g_result[t][1] = Pack[tmax][1];
        if(ResultPack[0][0] == 0)
            return;
    }
    getResult(ResultPack,x1,y1,Pack[tmax][0],Pack[tmax][1]);
    getResult(ResultPack,Pack[tmax][0],Pack[tmax][1],x2,y2);
}

int main()
{
    int Point[240][2];//Point�����е�
    int i=1,n;
    int x1,y1,x2,y2,x3,y3;
    g_result[0][0]=0;Point[0][0]=0;//Point�ĵ�һ�е�һ��Ԫ�ش�Ű������м����㡣��ʼ��Ϊ0��
    printf("���������е�ĸ��������꣺\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%d%d",&Point[i][0],&Point[i][1]);
    Point[0][0] = i-1;
    x1 = Point[1][0];
    y1 = Point[1][1];
    x2 = x1;
    y2 = y1;
    for(i=2;i<=Point[0][0];i++)
    {
        x3 = Point[i][0];
        y3 = Point[i][1];
        if(x3 < x1)
        {
            x1 = x3;
            y1 = y3;
        }
        else if(x3 > x2)
        {
            x2 = x3;
            y2 = y3;
        }
    }
    g_result[1][0] = x1;
    g_result[1][1] = y1;
    g_result[2][0] = x2;
    g_result[2][1] = y2;
    g_result[0][0] += 2;
    getResult(Point, x1, y1, x2, y2);
    getResult(Point, x2, y2, x1, y1);

    printf("\n\n����͹���ĵ��У�\n");
    for(i=1;i<=g_result[0][0];i++)
        printf("(%d,%d)\n",g_result[i][0],g_result[i][1]);
}

/* ����
14
30 30
50 60
60 20
70 45
86 39
112 60
200 113
250 50
300 200
130 240
76 150
47 76
36 40
33 35
���
(30,30)
(300,200)
(130,240)
(76,150)
(47,76)
(250,50)
(60,20)
*/
