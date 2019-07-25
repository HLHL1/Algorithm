/**
 * 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
 */
public class test{

    //方法一：递归实现
    public static int Sum_Solution1(int n) {
        int ans=0;
        boolean tmp=(ans>0)&&((ans+=ans+Sum_Solution1(n-1))>0);
        return ans;
    }

    //方法二：利用Math函数
    public static int Sum_Solution2(int n) {
        return (int) (Math.pow(n, 2) + n) >> 1;
    }

    //方法三：n(n+1)/2,递归实现n(n+1)；
//    先参考使用while的例子，再转换
//    原理是把a拆成2的幂的和，a = 2^e0 + 2^e1 + 2^e2....
//    那么 a * b = (2^e0 + 2^e1 + 2^e2+...) * b 
//                      = b * 2^e0 + b * 2^e1 + b * 2^e2 + ...
//            = (b << e0) + (b << e1) + ....
    public static int Sum_Solution3(int n) {
        int res = 0;
        int a = n;//若a=2=10
        int b = n + 1;//b=3=11
        while (a != 0) {
            if ((a & 1) == 1)//a在第二位==1的时候才更新res=0+110=6
                res += b;
            a >>= 1;//a右移1位 1
            b <<= 1;//b左移动1位 110
        }
        return res>>=1;//n(n+1)/2   
    }
    //接下来，用(a & 1) == 1和(a != 0)来代替判断语句
    public static int Sum(int n) {
        int res = multi(n, n + 1);//n*(n-1)
        return res>>=1;//n*(n-1)/2
    }

    private static int multi(int a, int b) {
        int res = 0;
        //循环体内部, if ((a & 1) == 1), res += b;
        boolean flag1 = ((a & 1) == 1) && (res += b) > 0;
        a >>= 1;
        b <<= 1;
        // while (a != 0) {}循环条件
        boolean flag2 = (a != 0) && (res += multi(a,b)) > 0 ;
        return res;
    }

    public static void main(String[] args) {

        System.out.println(Sum_Solution2(5));
    }
}