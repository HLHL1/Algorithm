import java.util.Scanner;
public class MyThread1 {
    public static final int MAX=1000000000;
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int x=cin.nextInt();
        int y=cin.nextInt();
        int a=x;
        int b=y;
        while(b!=0){
            int tmp=a%b;
            a=b;//最大公因数
            b=tmp;
        }
        System.out.println(x*y/a);//最小公倍数
    }
}
