import java.util.Scanner;
import java.util.Arrays;
public class Main {
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        int n=cin.nextInt();
        int a[]=new int[n];
        for(int i=0;i<n;i++){
            a[i]=cin.nextInt();
        }
        Arrays.sort(a);
        int ans=a[n-1]*a[n-2];
        int tmp=a[n-1]+a[n-2];
        for(int i=n-3;i>=0;i--){
            ans+=tmp*a[i];
            tmp+=a[i];
        }
        System.out.println(ans);
    }
}