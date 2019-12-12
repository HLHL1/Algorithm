import java.util.Scanner;

public class test1 {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        String ip;
        ip="123.456";
        String[] ips=ip.split("\\.");//因为java doc里已经说明, split的参数是reg, 即正则表达式, 如果用"|"分割, 则需使用"\\|"
        StringBuilder sb=new StringBuilder();
        int len=ips.length-1;
        for(int i=len;i>0;i--){
            sb.append(ips[i]);
            sb.append(".");
        }
        sb.append(ips[0]);
        System.out.println(sb.toString());
    }
}