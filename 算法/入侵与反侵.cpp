#include<iostream>

//using namespace std;
//int LIS(int A[],int n)
//{
//    int d[20002]={0};
//    int len=1;
//    for(int i=0;i<n;i++)
//    {
//        d[i]=1;
//        for(int j=0;j<i;j++)
//        {
//          if(A[i]>=A[j]&&d[j]+1>=d[i])
//          {
//              d[i]=d[j]+1;
//          }
//        }
//        len=max(len,d[i]);
//    }
//
//}
//int LIS(int A[],int n)
//{
//    int* d = new int[n];
//    int len = 1;
//    int i,j;
//    for(i=0;i<n;i++)
//    {
//        d[i]=1;
//        for(j=0;j<i;j++)
//        {
//            if(A[j]>=A[i] && (d[j]+1)>=d[i])
//                d[i]=d[j]+1;
//        }
//        if(d[i]>len) len=d[i];
//    }
//    delete []d;
//    return len;
//}

//int main()
//{
//    int T;
//    cin>>T;
//    while(T--)
//    {
//        int n;
//        cin>>n;
//        int A[20001]={0};
//        for(int i=0;i<n;i++)
//        {
//            cin>>A[i];
//        }
////        int flag=1,_max=0;
////        for(int i=0;i<n;i++)
////        {
////            int _min=a[i];
////            flag=1;
////            for(int j=i;j<n;j++)
////            {
////                if(_min>a[j])
////                {
////                    _min=a[j];
////                    flag++;
////                }
////            }
////            _max=max(_max,flag);
////        }
//
//        cout<<n-LIS(A,n)<<endl;
//    }
//    return 0;
//}
