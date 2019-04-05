import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        int n=cin.nextInt();
        int a,b;
        int first=0,end=0;
        first=cin.nextInt();
        int min=first,max=first;
        a=first;
        int flag=0;//ÅĞ¶ÏÊÇ·ñÎªÉıĞò
        for(int i=1;i<n;i++){
            b=cin.nextInt();
            if(i==n-1){
                end=b;
            }
            if(b<a){
                flag=1;
            }
           min=Math.min(min,b);
            max=Math.max(max,b);
            a=b;
        }
        if(flag==0) System.out.println(0);
        else{
            if(min==first||max==end) System.out.println(1);
            else System.out.println(2);
        }
    }
}
