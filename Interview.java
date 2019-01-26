package hhh.Test;

import java.util.Scanner;

import java.util.Scanner;
import java.math.*;
public class Main{
    public static void main(String[] args){
        long Max1=Long.MIN_VALUE;
        long Max2=Long.MIN_VALUE;
        long Max3=Long.MIN_VALUE;
        long Min1=Long.MAX_VALUE;
        long Min2=Long.MAX_VALUE;
        Scanner cin=new Scanner(System.in);
        int k;
        k=cin.nextInt();
        while((k--)!=0){
            long n=cin.nextLong();
            //求三个最大值
            if(n>Max1){
                Max3=Max2;
                Max2=Max1;
                Max1=n;
            }else if(n>Max2){
                Max3=Max2;
                Max2=n;
            }else if(n>Max3){
                Max3=n;
            }
            //求两个最小值
            if(n<Min1){
                Min2=Min1;
                Min1=n;
            }else if(n<Min2){
                Min2=n;
            }
        }
        //如果全为正或者全为负，最大积都是三个最大值的乘积
        long Max_ans=Max1*Max2*Max3;
        //如果一半正数或者一半负数,值为三个最大值乘积或者，最小的两个负数和最大的一个正数乘积
        long Min_ans=Min1*Min2*Max1;
        long ans=Math.max(Max_ans,Min_ans);
        System.out.println(ans);
    }
}

//    public static int MAX=10000000;
//    public static int n;
//    public static int[] a=new int[505];
//    public static void main(String[] args){
//        Scanner cin=new Scanner(System.in);
//        n=cin.nextInt();
//        for(int i=0;i<n;i++){
//            a[i]=cin.nextInt();
//        }
//        int ans=0;
//        for(int i=0;i<n;i++){
//            for(int j=i+1;j<n;j++){
//                for(int k=j+1;k<n;k++){
//                    int num=0;
//                    if((num=a[i]*a[j])>=MAX)continue;
//                    else if((num*=a[k])>=MAX)continue;
//                    else if(If(num)) ans++;
//                }
//            }
//        }
//        System.out.println(ans);
//    }
//    public static boolean If(int num){
//        for(int i=0;i<n;i++){
//            if(a[i]==num){
//                return true;
//            }
//        }
//        return false;
//    }

