/*

给定一个无序数组，包含正数、负数和0，要求从中找出3个数的乘积，使得乘积最大，要求时间复杂度：O(n)，空间复杂度：O(1)
输入描述:
无序整数数组A[n]
输出描述:
满足条件的最大乘积
示例1
输入
3 4 1 2
输出
24

*/

/*
题解：这个题难点就在在时间和空间复杂度的掌控上，不可以排序，所以我们只能利用5个变量来保存最大最小值
      分两种情况：
               1.如果全为正或者全为负，最大积都是三个最大值的乘积
               2.如果一半正数或者一半负数,值为三个最大值乘积或者，最小的两个负数和最大的一个正数乘积
*/


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

