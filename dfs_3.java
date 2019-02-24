/*
小易将n个棋子摆放在一张无限大的棋盘上。第i个棋子放在第x[i]行y[i]列。同一个格子允许放置多个棋子。每一次操作小易可以把一个棋子拿起并将其移动到原格子的上、下、左、右的任意一个格子中。小易想知道要让棋盘上出现有一个格子中至少有i(1 ≤ i ≤ n)个棋子所需要的最少操作次数.
        输入描述:
        输入包括三行,第一行一个整数n(1 ≤ n ≤ 50),表示棋子的个数
        第二行为n个棋子的横坐标x[i](1 ≤ x[i] ≤ 10^9)
        第三行为n个棋子的纵坐标y[i](1 ≤ y[i] ≤ 10^9)

        输出描述:
        输出n个整数,第i个表示棋盘上有一个格子至少有i个棋子所需要的操作数,以空格分割。行末无空格
        如样例所示:
        对于1个棋子: 不需要操作
        对于2个棋子: 将前两个棋子放在(1, 1)中
        对于3个棋子: 将前三个棋子放在(2, 1)中
        对于4个棋子: 将所有棋子都放在(3, 1)中

        示例1
        输入
        4
        1 2 4 9
        1 1 1 1
        输出
        0 1 3 10
*/

/**
 * 解题思路：
 * 首先明确曼哈顿距离：
 * 坐标（x1, y1）的i点与坐标（x2, y2）的j点的曼哈顿距离为：
 * d(i,j)=|X1-X2|+|Y1-Y2|.
 *
 * 暴力求解：我们知道要找到一个格子来存放i个点，那么这个格子的坐标必然不会超过所有棋子构成的最大矩形范围
 *           所以我们可以遍历这个矩阵内所有点，分别计算其与所有棋子坐标的距离，选出所有可能汇聚点到每个坐标最小值，即为所求。
 *          但是由于题目要求数据过大，暴力求解会超时。
 * 优化：因为格子的坐标可以缩小为，棋子在横坐标和纵坐标上的点组成，所以只需要遍历这些点就可以求出结果。
 */

import java.util.*;
import java.util.Arrays;

public class dfs_3{
    public static final long _Max=Long.MAX_VALUE;
    public static int[] x;
    public static int[]y;
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        int n=cin.nextInt();
        x=new int[n];
        y=new int[n];
        for(int i=0;i<n;i++){
            x[i]=cin.nextInt();
        }
//        int xMax=x[0],xMin=x[0];
//        for(int i=0;i<n;i++){
//            if(x[i]>xMax)xMax=x[i];
//            if(x[i]<xMin)xMin=x[i];
//        }
        for(int i=0;i<n;i++){
            y[i]=cin.nextInt();
        }
//        int yMax=y[0],yMin=y[0];
//        for(int i=0;i<n;i++){
//            if(y[i]>yMax)yMax=y[i];
//            if(y[i]<yMin)yMin=y[i];
//        }
        Queue<Integer>pq=new PriorityQueue<>();
        long[] ans=new long[n];
        for(int i=0;i<n;i++){
            ans[i]=_Max;
        }
//        for(int i=xMin;i<=xMax;i++){
//            for(int j=yMin;j<=yMax;j++){
//                for(int k=0;k<n;k++){
//
//                    Integer tmp=Math.abs(x[k]-i)+Math.abs(y[k]-j);
//                    pq.add(tmp);
//                }
//                long sum=0;
//                int ansIndex=0;
//                for(int p=0;p<n;p++){
//                    sum+=pq.remove();
//                    ans[ansIndex]=Math.min(ans[ansIndex],sum);
//                    ansIndex++;
//                }
//            }
//        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){

                    Integer tmp=Math.abs(x[k]-x[i])+Math.abs(y[k]-y[j]);
                    pq.add(tmp);
                }
                long sum=0;
                int ansIndex=0;
                for(int p=0;p<n;p++){
                    sum+=pq.remove();
                    ans[ansIndex]=Math.min(ans[ansIndex],sum);
                    ansIndex++;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(i==n-1){
                System.out.println(ans[i]);
                break;
            }
            System.out.print(ans[i]+" ");
        }

    }
}