#define _CRT_SECURE_NO_WARNINGS 
#include<Windows.h>
#include<stdio.h>  
#include<string.h> 
#include<stdlib.h>

//�Ӵ���
//#define maxn 1000000+10  
//int a[maxn], ans[maxn];
//int max(int x, int y)
//{
//	return x>y ? x : y;
//}
//int main()
//{
//	int T, n, i, mark;
//	scanf("%d", &T);
//	while (T--)
//	{
//		scanf("%d", &n);
//		for (i = 0; i<n; i++)
//			scanf("%d", &a[i]);
//		memset(ans, 0, sizeof(ans));
//		ans[0] = mark = a[0];
//		for (i = 1; i<n; i++)
//		{
//			ans[i] = max(ans[i - 1] + a[i], a[i]);//����һ���м����飬����ÿ��i��ǰ�����ֵ����ÿ��ˢ�����ֵ
//			if (mark<ans[i])
//				mark = ans[i];
//		}
//		printf("%d\n", mark);
//	}
//	system("pause");
//	return 0;
//}
////�����������
//
//int dp[1001][1001];
//int main()
//{
//	int T, i, l1, l2, j;
//	char str1[1001], str2[1001];
//	cin >> T;
//	while (T--)
//	{
//		cin >> str1;
//		l1 = strlen(str1);
//		cin >> str2;
//		l2 = strlen(str2);
//		for (i = 0; i <= l1; i++)
//			dp[i][0] = 0;
//		for (j = 0; j <= l2; j++)
//			dp[0][j] = 0;
//		for (i = 1; i <= l1; i++)
//		{
//			for (j = 1; j <= l2; j++)
//			{
//				if (str1[i - 1] == str2[j - 1])
//					dp[i][j] = dp[i - 1][j - 1] + 1;
//				else if (dp[i - 1][j]>dp[i][j - 1])
//					dp[i][j] = dp[i - 1][j];
//				else
//					dp[i][j] = dp[i][j - 1];
//			}
//		}
//		cout << dp[l1][l2] << endl;
//	}
//	system("pause");
//	return 0;
//}
//����
//int main()
//{
//	int N, num[100][100] = { 0 }, dp[100][100] = { 0 };
//	int i = 0,j = 0;
//	scanf("%d", &N);
//	for (i = 0; i < N; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			scanf("%d", &num[i][j]);
//			dp[i][j] = num[i][j];
//		}
//	}
//	for (i = N-2; i >=0; --i)
//	{
//		for (j = 0; j <= i; ++j)
//		{
//
//			int max = dp[i + 1][j] > dp[i + 1][j + 1] ? dp[i + 1][j] : dp[i + 1][j + 1];
//			dp[i][j] = max + num[i][j];
//		}
//	}
//	printf("%d\n", dp[i + 1][j - 1]);
//	int node_value;
//	j = 0;
//	for (int i = 1; i < N; ++i)
//	{
//		node_value = dp[i - 1][j] - num[i - 1][j];
//		if (node_value == dp[i][j + 1])
//			++j;
//		cout << "->" << num[i][j];
//	}
//	
//	system("pause");
//	return 0;
//}
//#define N 20 
//void MatrixChain(int p[N],int n,int m[N][N],int s[N][N])
//{  
//int i,j,t,k;    
//int r;             //��¼��˵ľ���������� 
//for(i=1;i<=n;i++)
//{    
//	m[i][i]=0;         //��һ���������ʱ����˴���Ϊ 0   
//}     //���������������ʼһ�ε���   
//for(r=2;r<=n;r++)
//{     //��ĳ������ʼ        
//	for(i=1;i<=n-r+1;i++)
//	{       //��ĳ������Ľ���        
//		j=i+r-1;       //�õ��� i �� j �������˵Ĵ���        
//		m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];       //�õ��������˶Ͽ���λ��     
//		s[i][j]=i;       //Ѱ�Ҽ����Ų�ͬ���������˴�������Сֵ���޸� m ���飬�ͶϿ���λ�� s ����      
//		for(k=i+1;k<j;k++)
//		{        
//			t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];        
//			if(t<m[i][j])
//			{          
//				m[i][j]=t;          
//				s[i][j]=k;     
//			}     
//		}   
//	}  
//} 
//}  
//int main( )
//{   
//	int n,n1,m1,i,j=2;  
//	int p[N]={0};          //�洢������к�������    
//	int m[N][N]={0};        //�洢�����������˵���С����  
//	int s[N][N]={0};        //�洢�����������˶Ͽ���λ��   
//	printf("������������:\n");   
//	scanf("%d",&n);  
//	for(i=1;i<=n;i++)
//	{    
//		printf("�������%d��������к���(n1*m1 ��ʽ):",i);    
//		scanf("%d*%d",&n1,&m1);   
//		if(i==1)
//		{      
//			p[0]=n1;       
//			p[1]=m1;    
//		}    
//		else
//		{      
//			p[j++]=m1;    
//		}   
//	}   
//	printf("\n��¼�����к���:\n");  
//	for(i=0;i<=n;i++)
//	{    
//		printf("%d ",p[i]);  
//	} 
//	printf("\n");  
//	MatrixChain(p,n,m,s); 
//	printf("\n������˵���С��������Ϊ:\n"); 
//	for(i=1;i<=n;i++)
//	{    
//		for(j=1;j<=n;j++)
//		{      
//			printf("%d  ",m[i][j]);    
//		}    
//		printf("\n");  
//	}  
//	printf("\n������˶Ͽ���λ�þ���Ϊ:\n");  
//	for(i=1;i<=n;i++)
//	{    
//		for(j=1;j<=n;j++)
//		{       
//			printf("%d ",s[i][j]);  
//		}    
//		printf("\n"); 
//	}   
//	printf("������С��˴���Ϊ:%d\n",m[1][n]);   
//    return 0; 
//} 
////#include<stdio.h>
////#define MAX(a,b) a>b?a:b
////int n;
////int D[100][100];
////int MaxSum(int i, int j)
////{
////	int x = 0;
////	int y = 0;
////	if (i == (n-1))
////	{
////		return D[i][j];
////	}
////	x = MaxSum(i + 1, j);
////	y = MaxSum(i + 1, j + 1);
////	return MAX(x, y) + D[i][j];
////}
////int main()
////{
////	int i = 0;
////	int j = 0;
////	int n = 0;
////	int D[100][100] = { 0 };
////	scanf("%d", &n);
////	for (i = 0; i < n; i++)
////	{
////		for (j = 0; j <= i; j++)
////		{
////			scanf("%d", &D[i][j]);
////		}
////	}
////	printf("%d\n", MaxSum(0, 0));
////	system("pause");
////	return 0;
////}