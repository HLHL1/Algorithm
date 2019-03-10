/**
 *
 * 牛牛有4根木棍,长度分别为a,b,c,d。羊羊家提供改变木棍长度的服务,如果牛牛支付一个硬币就可以让一根木棍的长度加一或者减一。牛牛需要用这四根木棍拼凑一个正方形出来,牛牛最少需要支付多少硬币才能让这四根木棍拼凑出正方形。
 * 输入描述:
 * 输入包括一行,四个整数a,b,c,d(1 ≤ a,b,c,d ≤ 10^6), 以空格分割
 * 输出描述:
 * 输出一个整数,表示牛牛最少需要支付的硬币
 *
 * 示例1
 * 输入
 * 4 1 5 4
 * 输出
 * 4
 */

//解题思路：我们可以将四条边的长度映射成为是一条路上的几个坐标，我们只要找到在这条路上的一个点，使这个点满足其他四个点到这个点的距离和最短

import java.util.*;

public class Main{

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int[] arr=new int[4];
        for(int i=0;i<4;i++){
            arr[i]=cin.nextInt();
        }

        int min=1000000000;
        for(int i=0;i<4;i++){
            int sum=0;
            for(int j=0;j<4;j++){
                sum+=Math.abs(arr[i]-arr[j]);
            }
            min=Math.min(min,sum);
        }
        System.out.println(min);
    }
}
