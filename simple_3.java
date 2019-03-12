import java.util.Scanner;



public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        String str=cin.nextLine();
        StringBuffer sb=new StringBuffer();
        sb.append(str);
        System.out.println(sb.reverse());
    }
}