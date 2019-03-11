/**
 * 二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，网格的列编号为0~W-1。每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
 * 对于两个格子坐标(x1,y1),(x2,y2)的欧几里得距离为:
 * ( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) 的算术平方根
 * 小易想知道最多可以放多少块蛋糕在网格盒子里。
 * 输入描述:
 * 每组数组包含网格长宽W,H，用空格分割.(1 ≤ W、H ≤ 1000)
 *
 *
 * 输出描述:
 * 输出一个最多可以放的蛋糕数
 * 示例1
 * 输入
 * 3 2
 * 输出
 * 4
 *
 */


/**
 * 解题思路：
 * 1 1 x x 1 1
 * 1 1 x x 1 1
 * x x 1 1 x x
 * x x 1 1 x x
 *就是找规律题，1表示可以放蛋糕，x表示不可以放
 *
 */

import java.util.Scanner;
public class MyThread1 {
    public static final int MAX=1000000000;
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int w=cin.nextInt();
        int h=cin.nextInt();
        int a=w/4*2+((w%4)<2?(w%4):2);
        int b=(w-2)/4*2+(((w-2)%4)<2?((w-2)%4):2);
        int ans=h/4*(a+b)*2;
        if(h%4>0)ans+=a;
        if(h%4>1)ans+=a;
        if(h%4>2)ans+=b;
        System.out.println(ans);
    }
}
