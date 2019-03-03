import java.util.*;
import java.util.Arrays;

public class Interview {

    public static boolean aBoolean(int n){
        for(int i=2;i<=Math.sqrt(n);i++){
            if(n%i==0)return false;
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        int l=cin.nextInt();
        int r=cin.nextInt();

        //int l=101,r=150;
        int ans=0;
        for(int i=l;i<=r;i++){
            if(aBoolean(i)){
                //System.out.println(i);
                StringBuilder str=new StringBuilder();
                str.append(i);
                String oldStr=str.toString();
                String reStr=str.reverse().toString();
                if(reStr.equals(oldStr)){
                    ans++;
                }
            }
        }
        System.out.println(ans);
    }
}