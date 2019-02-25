/*
小易老师是非常严厉的,它会要求所有学生在进入教室前都排成一列,并且他要求学生按照身高不递减的顺序排列。有一次,n个学生在列队的时候,小易老师正好去卫生间了。学生们终于有机会反击了,于是学生们决定来一次疯狂的队列,他们定义一个队列的疯狂值为每对相邻排列学生身高差的绝对值总和。由于按照身高顺序排列的队列的疯狂值是最小的,他们当然决定按照疯狂值最大的顺序来进行列队。现在给出n个学生的身高,请计算出这些学生列队的最大可能的疯狂值。小易老师回来一定会气得半死。
输入描述:
输入包括两行,第一行一个整数n(1 ≤ n ≤ 50),表示学生的人数
第二行为n个整数h[i](1 ≤ h[i] ≤ 1000),表示每个学生的身高
输出描述:
输出一个整数,表示n个学生列队可以获得的最大的疯狂值。

如样例所示:
当队列排列顺序是: 25-10-40-5-25, 身高差绝对值的总和为15+30+35+20=100。
这是最大的疯狂值了。
示例1
输入

5
5 10 25 40 25
输出

100
 */

/**
 * 解题思路：
 *    先放最大的数，然后两边放最小的数，再两边放次大和次次大的数，再两边放小的数…直到放完，最后要检查一下两边的元素位置是否合适,不合适的话移动一下。
 *    最后调整两边元素其实是在调整中间是最小还是最大情况。
 */

import java.util.*;
import java.util.Arrays;
public class Main{
    public static final long _Max=Long.MAX_VALUE;
    public static int[] x;
    public static int[]y;
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        int n=cin.nextInt();
        int[] arr=new int[n];
//        int n=7;
//        int[] arr={5,10 ,25, 40, 26,50,61};
        for(int i=0;i<n;i++){
            arr[i]=cin.nextInt();
        }
        Arrays.sort(arr);
        int beg=0;
        int end=arr.length-2;
        int[] ans=new int[n];
        int mid=n/2;
        ans[mid]=arr[n-1];
        int i=0;
        while(mid-i>=0||mid+i<n){
            i++;
            if(mid-i>=0)ans[mid-i]=arr[beg++];
            if(mid+i<n)ans[mid+i]=arr[beg++];
            i++;
            if(mid-i>=0)ans[mid-i]=arr[end--];
            if(mid+i<n)ans[mid+i]=arr[end--];
        }
        int a=Math.abs(ans[n-1]-ans[n-2]);
        int b=Math.abs(ans[0]-ans[n-1]);
        a=Math.max(a,b);

        int sum=0;
        for(int j=1;j<n-1;j++){
            sum+=Math.abs(ans[j]-ans[j-1]);
        }
        System.out.println(sum+a);
    }
}